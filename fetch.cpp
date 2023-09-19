#include "fetch.h"
#include <sys/ipc.h>
#include <sys/msg.h>

void run(key_t key)
{
    msgid = msgget(key, 0666 | IPC_CREAT);

}
