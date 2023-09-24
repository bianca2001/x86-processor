#include <sys/ipc.h>
#include <sys/msg.h>
#pragma once

class Fetch {
public:
     Fetch();
     void run(key_t key);
private:
     key_t keyToLoad;
     int msgIdToLoad;
     key_t keyFromLoad;
     int msgIdFromLoad;    
     key_t keyToDecode;
     int msgIdToDecode;
};
