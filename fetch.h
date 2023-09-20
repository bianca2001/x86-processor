#include <sys/ipc.h>
#include <sys/msg.h>

class Fetch {
public:
     void run(key_t key);
};