#include <sys/ipc.h>
#include <sys/msg.h>

class Decode{
public:
    void run();

private:
    key_t keyFetch;
    int msgIdFetch;
};