#include <sys/ipc.h>
#include <sys/msg.h>

class Decode{
public:
    Decode();
    void run();

private:
    key_t keyFromFetch;
    int msgIdFromFetch;
};