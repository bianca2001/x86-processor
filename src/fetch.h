#include <sys/ipc.h>
#include <sys/msg.h>

class Fetch {
public:
     Fetch();
     void run(key_t key);
private:
     key_t keyLoadStore;
     int msgIdLoadStore;
};