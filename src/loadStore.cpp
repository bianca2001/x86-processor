#include <iostream>
#include <string.h>
#include <unistd.h>
#include "loadStore.h"
#include "mesgBuffer.cpp"
#include "memory.h"
using namespace std;

LoadStore::LoadStore()
{
    keyFromFetch = ftok("/workspaces/codespaces-blank/message queues/fetchToLoad", 1);
    msgIdFromFetch = msgget(keyFromFetch, 0666 | IPC_CREAT);

    keyToFetch = ftok("/workspaces/codespaces-blank/message queues/loadToFetch", 2);
    msgIdToFetch = msgget(keyToFetch, 0666 | IPC_CREAT);

}

void LoadStore::load()
{
cerr<<"Load: Waiting for address from fetch\n";

    mesg_buffer_int pointer;

    msgrcv(msgIdFromFetch, &pointer, sizeof(pointer), 1, 0);

    mesg_buffer_char message;
    message.mesg_type = 1;

cerr << "Load: Received address " << pointer.mesg_text << " from fetch\n";

    //message.mesg_text = Memory::get_data(pointer.mesg_text);
    char* data = Memory::get_data(pointer.mesg_text);
    
    strcpy(message.mesg_text, data);

cerr<<"Load: Sending data "<< message.mesg_text <<" to fetch\n";

    msgsnd(msgIdToFetch, &message, sizeof(message), 0);

cerr<<"Load: Sent data "<< message.mesg_text <<" to fetch\n";

    return 0;
}

void LoadStore::store()
{
    
}

