#include <sys/ipc.h>
#include <sys/msg.h>
#pragma once

//TODO: test load store
//TODO: test if fetch is sending data to queue and if load store is receiving it
class LoadStore {
public:
    LoadStore();
    void load();
    void store();
private:
    key_t keyFromFetch;
    int msgIdFromFetch;
    key_t keyToFetch;
    int msgIdToFetch;
};