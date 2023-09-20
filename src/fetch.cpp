#include "fetch.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
#include <iostream>
#include<unistd.h>
using namespace std;

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message_fetch;

void Fetch::run(key_t key)
{
    int msgid = msgget(key, 0666 | IPC_CREAT);

    cout << "fetching\n";
    msgrcv(msgid, &message_fetch, 100, 1, 0);

    cout << message_fetch.mesg_text << endl;

    sleep(1);
}