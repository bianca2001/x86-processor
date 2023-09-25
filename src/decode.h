#include <sys/ipc.h>
#include <sys/msg.h>

class Decode{
public:
    Decode();
    void run();
    void decode();

private:
    key_t keyFromFetch;
    int msgIdFromFetch;
    key_t keyToExecute;
    int msgIdToExecute;
};