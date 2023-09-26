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

//TODO: load from multiple of 8 to multiple of 8 or something to simulate fetch window
void LoadStore::load()
{
cerr<<"Load: Waiting for address from fetch\n";

    while(1) {
        mesg_buffer_int pointer;

        msgrcv(msgIdFromFetch, &pointer, sizeof(pointer), 1, 0);

        mesg_buffer_char_matrix message;
        message.mesg_type = 1;

//cerr << "Load: Received address " << pointer.mesg_text << " from fetch\n";

        int p = pointer.mesg_text;
        message.mesg_text[0] = Memory::get_data(p);
        p += 2;
//cerr << "Load: Data " << message.mesg_text[0] << " from address " << p << "\n";
        message.mesg_text[1] = Memory::get_data(p);
        p += 2;
//cerr << "Load: Data " << message.mesg_text[1] << " from address " << p << "\n";
        message.mesg_text[2] = Memory::get_data(p);
        p += 2;
//cerr << "Load: Data " << message.mesg_text[2] << " from address " << p << "\n";
        message.mesg_text[3] = Memory::get_data(p);
//cerr << "Load: Data " << message.mesg_text[3] << " from address " << p << "\n";

        msgsnd(msgIdToFetch, &message, sizeof(message), 0);

        sleep(10);
    }
    return;
}

void LoadStore::store()
{
    
}

