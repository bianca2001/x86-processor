#include "fetch.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
using namespace std;

void run(key_t key)
{
    int msgid = msgget(key, 0666 | IPC_CREAT);

    string message;

    msgrcv(msgid, &message, sizeof(message), 1, 0);
}
