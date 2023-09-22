#include <sys/ipc.h>
#include <sys/msg.h>

//TODO: test load store
//TODO: test if fetch is sending data to queue and if load store is receiving it
class LoadStore {
public:
    LoadStore();
    void load(int address);
    void store(int address, char** data);
private:
    key_t keyFetch;
    int msgidFetch;
};