#ifndef TASK_H
#define TASK_H
#include "servercommand.h"
#include "mainwindow.h"
#include "pthread.h"

class Task {
public:
 Task(int port = 4001);
 ~Task();
 void start();
 static void * clientthread(void * arg);
private:
    int m_listenfd;
};


#endif // TASK_H
