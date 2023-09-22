#include <sys/ipc.h>
#include <sys/msg.h>

class Fetch {
public:
     Fetch();
     void run(key_t key);
private:
     static int instructionPointer;
     key_t keyToLoadStore;
     int msgIdToLoadStore;
     key_t keyFromLoadStore;
     int msgIdFromLoadStore;    

};

int Fetch::instructionPointer = 0;