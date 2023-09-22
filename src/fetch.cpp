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
    mesg_buffer_int pointer;
    pointer.mesg_type = 1;
    pointer.mesg_text = instructionPointer;

cerr<<"Fetch: Sending instruction pointer to load/store\n";

    msgsnd(msgIdLoadStore, &pointer, sizeof(pointer), 0);

cerr<<"Fetch: Waiting for message from load/store\n";

    mesg_buffer_matrix message_from_load;

    msgrcv(msgIdLoadStore, &message_from_load, sizeof(message_from_load), 1, 0);

cerr<<"Fetch: Received message from load/store\n";

    sleep(1);
}