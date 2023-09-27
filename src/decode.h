#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
using namespace std;

class Decode{
public:
    Decode();
    void run();
    void decode();

private:
    string instructionFetch = "";

    key_t keyFromFetch;
    int msgIdFromFetch;
    key_t keyToExecute;
    int msgIdToExecute;
};