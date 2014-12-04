#ifndef MESSAGESUBJECT_H
#define MESSAGESUBJECT_H

#include <iostream>
#include <string>
#include <set>
#include <QDebug>
#include <QDir>
#include <vector>
#include <errorpopup.h>

class MessageSubject {
    std::vector<ErrorPopup *> dialogList;
public:
    void attach(ErrorPopup * objectToUpdate) {
        dialogList.push_back(objectToUpdate);
    }

    void detach(ErrorPopup * objectToUpdate) {
        dialogList.erase(std::remove(dialogList.begin(), dialogList.end(), objectToUpdate), dialogList.end());
    }

    void notify(std::string message) {
        for(std::vector<ErrorPopup *>::const_iterator iter = dialogList.begin(); iter != dialogList.end(); ++iter)
        {
            if(*iter != 0)
            {
                (*iter)->update(message);
            }
        }
    }
};


#endif
