#include "fetch.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
#include <iostream>
#include<unistd.h>
#include "mesgBuffer.cpp"
using namespace std;


Fetch::Fetch()
{
    keyLoadStore = ftok("progfile", 1);
    msgIdLoadStore = msgget(keyLoadStore, 0666 | IPC_CREAT);
}

void Fetch::run(key_t key)
{
    mesg_buffer message_fetch;
    int msgid = msgget(key, 0666 | IPC_CREAT);

    cout << "fetching\n";
    msgrcv(msgid, &message_fetch, sizeof(message_fetch), 1, 0);

    cout << message_fetch.mesg_text << endl;

    

    mesg_buffer_fetch message_from_load;
    msgrcv(msgIdLoadStore, &message_fetch, sizeof(message_fetch), 1, 0);
    sleep(1);
}