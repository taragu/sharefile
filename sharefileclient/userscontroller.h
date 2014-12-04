#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H
#include <string>
#include <vector>

class UsersController {
private:
    bool signedIn;
    std::string username;
public:
    UsersController(): signedIn(false) {}
    UsersController(bool _signedIn) : signedIn(_signedIn) {}
    bool isSignedIn() {
        return signedIn;
    }

    void setSignedIn(bool _signedIn) {
        signedIn = _signedIn;
    }

    void removeFriend(std::string friendName);
    void shareFileWithFriend(std::string friendName, std::string fileName);
    void messageFriend(std::string friendName, std::string message);
    void addFriend(std::string friendName);
    void acceptFriendRequest(std::string friendName);
    std::vector<std::string> getFriends();
    std::string getUsername() {
        return username;
    }

    void setUsername(std::string _username) {
        username = _username;
    }
};
//bool UsersController::isSignedIn(){
//    return signedIn;
//}
//void UsersController::setSignedIn(bool _signedIn) {
//    signedIn = _signedIn;
//}

//void UsersController::removeFriend(std::string friendName){
//    //TODO call clientcommand's method to remove a friend
//}
//void UsersController::shareFileWithFriend(std::string friendName, std::string fileName){
//    //TODO call clientcommand's method
//}

//void UsersController::messageFriend(std::string friendName, std::string message){
//    //TODO call clientcommand's method
//}

//void UsersController::addFriend(std::string friendName){
//    //TODO call clientcommand's method
//}

//void UsersController::acceptFriendRequest(std::string friendName){
//    //TODO call clientcommand's method
//}

//std::vector<std::string> UsersController::getFriends(){
//    //TODO call clientcommand's method
//}

#endif // USERSCONTROLLER_H
