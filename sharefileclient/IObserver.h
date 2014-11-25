#ifndef IOBSERVER_H
#define IOBSERVER_H


class IObserver
{
public:
    virtual void update(std::string message) = 0;
};

#endif // IOBSERVER_H
