#include "loadStore.h"
#include "mesgBuffer.cpp"
#include "memory.h"

LoadStore::LoadStore()
{
    keyFromFetch = ftok("progfile", 1);
    msgIdFromFetch = msgget(keyFetch, 0666 | IPC_CREAT);

    keyToFetch = ftok("progfile", 2);
    msgIdToFetch = msgget(keyFetch, 0666 | IPC_CREAT);
}

void LoadStore::load()
{
    mesg_buffer_int pointer;
    pointer.mesg_type = 1;

    msgrcv(msgidFetch, &pointer, sizeof(pointer), 1, 0);

    mesg_buffer_matrix message;
    message.mesg_type = 1;
    char** aux = Memory::get_data(address);
    message.mesg_text = aux;

    msgsnd(msgidFetch, &message, sizeof(message), 0);
}

void LoadStore::store(int address, char **data)
{
    
}

