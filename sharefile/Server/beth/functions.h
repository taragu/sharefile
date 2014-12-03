int string_to_int(string myString) {
	int value = atoi(myString.c_str());
	return value;
}

string XOR_Encryption(string toBeEncrypted, string sKey){
    string sEncrypted(toBeEncrypted);
    unsigned int iKey(sKey.length()), iIn(toBeEncrypted.length()), x(0);

    for(unsigned int i = 0; i < iIn; i++){
        sEncrypted[i] = toBeEncrypted[i] ^ sKey[x] & 10;
        if(++x == iKey){ x = 0; }
    }
    return sEncrypted;
}

string timestamp(){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	string tm = asctime (timeinfo);
	size_t length;
	char buffer[20];
	length = tm.copy(buffer,20,11);
	buffer [length - 6] = '\0';
	return buffer;
}

void write_output(){
	mlOutput->readonly(0);
	mlOutput->value(streamOutput.str().c_str());
	mlOutput->readonly(1);
	Fl::check();
}

int get_IP(int, char **){
    char ac[80];
    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
        streamOutput << "[" << timestamp() << "] Winsock Error Occured Getting Host Name: " << WSAGetLastError() << endl;
		write_output();
        return 1;
    }
	tempHOST = ac;
	userName->value(tempHOST.c_str());
    struct hostent *phe = gethostbyname(ac);
    if (phe == 0) {
        streamOutput << "[" << timestamp() << "] Bad Host Look-Up" << endl;
		write_output();
        return 1;
    }
    for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
		streamOutput << "[" << timestamp() << "] Your IP Address [" << i << "] : " << inet_ntoa(addr) << endl;
		write_output();
    }
    return 0;
}

void send_host_name(){
	memset(msg, 0, sizeof(msg));
	size_t length;
	string str = userName->value();
	length = str.copy(msg,256,0);
	msg[length] = '\0';
	send(client, msg, sizeof(msg), 0);
	recv(client, msg, sizeof(msg), 0);
	Opponent->value(msg);
}

void connected() {
	PlaySound("data/wl.wav", NULL, SND_ASYNC);

	streamOutput << "[" << timestamp() << "] Connection Successful!" << endl;
	write_output();

	send_host_name();

	messageInput->activate();
	sendButton->activate();
	mlOutput->activate();

	hostButton->deactivate();
	ipConnect->deactivate();
	inPort->deactivate();
	joinButton->deactivate();
	userName->deactivate();

	Recv_Thread = CreateThread(NULL, 0, Recv_Threader, NULL, 0, 0);
	Fl::check();
}

void disconnected() {
	PlaySound("data/gb.wav", NULL, SND_ASYNC);

	streamOutput << "[" << timestamp() << "] Disconnected!" << endl;
	write_output();

	disconnectButton->hide();
	connectButton->show();

	hostButton->activate();
	joinButton->activate();
	messageInput->deactivate();
	mlOutput->deactivate();
	sendButton->deactivate();

	CloseHandle(Recv_Thread);
	CloseHandle(Send_Thread);

	CloseHandle(Client_Thread);
	CloseHandle(Server_Thread);

	closesocket(client);
    closesocket(server);

	Fl::check();
}

void client_function() {
	streamOutput << "[" << timestamp() << "] Connecting..." << endl;
	write_output();

    struct sockaddr_in endpoint;

    char ipAddr[15];

    int error = WSAStartup(MAKEWORD(2, 2), &wsData);

    memset(ipAddr, 0, sizeof(ipAddr));
    if (error != 0) {
		streamOutput << "[" << timestamp() << "] Winsock Error: " << WSAGetLastError() << endl;
		hostButton->activate();
		joinButton->activate();
		connectButton->show();
		disconnectButton->hide();
		write_output();
        WSACleanup();
        Sleep(2000);
		Fl::check();
    }
	else {
		size_t length;
		string str = ipConnect->value();
		length = str.copy(ipAddr,15,0);
		ipAddr[length] = '\0';

		string tempPort = inPort->value();
		int port = string_to_int(tempPort);

		client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		endpoint.sin_addr.s_addr = inet_addr(ipAddr);
		endpoint.sin_family      = AF_INET;
		endpoint.sin_port        = htons(port);

		if (connect(client, (struct sockaddr*)&endpoint, sizeof(endpoint)) != 0) {
			streamOutput << "[" << timestamp() << "] Winsock Error Connecting to Server: " << WSAGetLastError() << endl;
			hostButton->activate();
			joinButton->activate();
			connectButton->show();
			disconnectButton->hide();
			write_output();
			Sleep(2000);
			Fl::check();
		}
		else {
			connected();
		}
	}
}

void server_function() {
    struct sockaddr_in endpoint;

	string tempPort = inPort->value();
	int port = string_to_int(tempPort);
    int error = WSAStartup(MAKEWORD(2, 2), &wsData);

    if (error != 0) {
		streamOutput << "[" << timestamp() << "] Winsock Error: " << WSAGetLastError() << endl;
		hostButton->activate();
		joinButton->activate();
		connectButton->show();
		disconnectButton->hide();
		write_output();
        WSACleanup();
        Sleep(4000);
    }
	else {
		server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		endpoint.sin_addr.s_addr = htonl(INADDR_ANY);
		endpoint.sin_family      = AF_INET;
		endpoint.sin_port        = htons(port);

		if (bind(server, (struct sockaddr*)&endpoint, sizeof(endpoint)) != 0) {
			streamOutput << "[" << timestamp() << "] Winsock Error Binding Socket: " << WSAGetLastError() << endl;
			hostButton->activate();
			joinButton->activate();
			connectButton->show();
			disconnectButton->hide();
			write_output();
			Sleep(4000);
		}
		else {
			streamOutput << "[" << timestamp() << "] Awaiting Connection..." << endl;
			write_output();
			Fl::check();
			listen(server, 1);
			client = accept(server, NULL, NULL);
			if (client != INVALID_SOCKET){
				connected();
			}
			else {
				disconnected();
			}
		}
	}
}

void recieve_message(){
	tempOP = Opponent->value();
	while(1) {
		memset(msg, 0, sizeof(msg));
		if (recv(client, msg, sizeof(msg), 0) != sizeof(msg)) {
			disconnected();
			break;
		}
		else {
			size_t length;
			string str = msg;
			str = XOR_Encryption(str, sPrivateKey);
			length = str.copy(msg,256,0);
			msg[length] = '\0';
			PlaySound("data/im2.wav", NULL, SND_ASYNC);
			streamOutput << "[" << timestamp() << "] " << tempOP << ": " << msg << endl;
			write_output();
			Fl::check();
		}
	}
}

void send_message(){
	tempHOST = userName->value();
	memset(msg, 0, sizeof(msg));
	size_t length;
	string str = messageInput->value();
	streamOutput << "[" << timestamp() << "] " << tempHOST << ": " << str << endl;
	write_output();
	str = XOR_Encryption(str, sPrivateKey);
	length = str.copy(msg,256,0);
	msg[length] = '\0';
	messageInput->value("");
	send(client, msg, sizeof(msg), 0);
	Fl::check();
	PlaySound("data/im1.wav", NULL, SND_ASYNC);
}

void hostButton_CB(Fl_Widget *w, void *data) {
	userName->activate();
	inPort->activate();
	ipConnect->deactivate();
	connectButton->activate();
}

void joinButton_CB(Fl_Widget *w, void *data) {
	userName->activate();
	ipConnect->activate();
	inPort->activate();
	connectButton->activate();
}

void connectButton_CB(Fl_Widget *w, void *data) {
	string tempPort = inPort->value();
	string tempIP = ipConnect->value();
	string tempHost = userName->value();
	if (joinButton->value()) {
		if (tempPort == ""){
			MessageBox (NULL, "Please Enter A Port to Connect to!" , "chatterBox v1.0.0 Error", MB_OK);
		}
		else if (tempIP == "") {
			MessageBox (NULL, "Please Enter An IP Address to Connect to!" , "chatterBox v1.0.0 Error", MB_OK);
		}
		else if (tempHost == "") {
			MessageBox (NULL, "Please Enter A User Name!" , "chatterBox v1.0.0 Error", MB_OK);
		}
		else {
			connectButton->hide();
			ipConnect->deactivate();
			inPort->deactivate();
			hostButton->deactivate();
			joinButton->deactivate();
			userName->deactivate();
			disconnectButton->show();
			Client_Thread = CreateThread(NULL, 0, Client_Threader, NULL, 0, 0);
			CloseHandle(Client_Thread);
		}
	}
	else if (hostButton->value()) {
		if (tempPort == ""){
			MessageBox (NULL, "Please Enter A Port to Connect to!" , "chatterBox v1.0.0 Error", MB_OK);
		}
		else if (tempHost == "") {
			MessageBox (NULL, "Please Enter A User Name!" , "chatterBox v1.0.0 Error", MB_OK);
		}
		else {
			connectButton->hide();
			ipConnect->deactivate();
			inPort->deactivate();
			hostButton->deactivate();
			joinButton->deactivate();
			userName->deactivate();
			disconnectButton->show();
			Server_Thread = CreateThread(NULL, 0, Server_Threader, NULL, 0, 0);
			CloseHandle(Server_Thread);
		}
	}
}

void disconnectButton_CB(Fl_Widget *w, void *data) {
	closesocket(client);
    closesocket(server);
}

void sendButton_CB(Fl_Widget *w, void *data) {
	string temp = messageInput->value();
	if (temp == "") {
		MessageBox (NULL, "Please Enter A Message!" , "chatterBox v1.0.0 Error", MB_OK);
	}
	else {
		Send_Thread = CreateThread(NULL, 0, Send_Threader, NULL, 0, 0);
		CloseHandle(Send_Thread);
	}
}