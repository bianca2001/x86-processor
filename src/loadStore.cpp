#include "loadStore.h"
#include "mesgBuffer.cpp"
#include "memory.h"

LoadStore::LoadStore()
{
    keyFetch = ftok("progfile", 1);
    msgidFetch = msgget(keyFetch, 0666 | IPC_CREAT);

}

void LoadStore::load(int address)
{
    mesg_buffer_fetch message;
    message.mesg_type = 1;
    char** aux = Memory::get_data(address);
    message.mesg_text = aux;

    msgsnd(msgidFetch, &message, sizeof(message), 0);
}

void LoadStore::store(int address, char **data)
{
    
}

