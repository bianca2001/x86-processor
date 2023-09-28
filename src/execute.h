#include <sys/ipc.h>
#include <sys/msg.h>
#pragma once

class Execute{
public:
    Execute();
    void run();
private:
    key_t keyFromDecode;
    int msgIdFromDecode;

    void execute();
};