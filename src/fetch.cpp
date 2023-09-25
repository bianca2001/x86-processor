#include "fetch.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include "mesgBuffer.cpp"
#include "registers.h"
using namespace std;


Fetch::Fetch()
{
    keyToLoad = ftok("/workspaces/codespaces-blank/message queues/fetchToLoad", 1);
    msgIdToLoad = msgget(keyToLoad, 0666 | IPC_CREAT);

    keyFromLoad = ftok("/workspaces/codespaces-blank/message queues/loadToFetch", 2);
    msgIdFromLoad = msgget(keyFromLoad, 0666 | IPC_CREAT);

    keyToDecode = ftok("/workspaces/codespaces-blank/message queues/fetchToDecode", 3);
    msgIdToDecode = msgget(keyToDecode, 0666 | IPC_CREAT);
}


void Fetch::run(key_t key)
{
    while(1) {

        mesg_buffer_int pointer;
        pointer.mesg_type = 1;
        pointer.mesg_text = Registers::ip;

cerr<<"Fetch: Sending instruction pointer "<< pointer.mesg_text <<" to load\n";

        msgsnd(msgIdToLoad, &pointer, sizeof(pointer), 0);

cerr<<"Fetch: Waiting for message from load\n";

        mesg_buffer_char_matrix message_from_load;

        msgrcv(msgIdFromLoad, &message_from_load, sizeof(message_from_load), 1, 0);

cerr<<"Fetch: Received message ";
for(int i = 0; i < 4; i++) {
        cerr << message_from_load.mesg_text[i] << " ";
}
cerr<<"\n";

        msgsnd(msgIdToDecode, &message_from_load, sizeof(message_from_load), 0);

        if(Registers::ip + 8 < 65535)
            Registers::ip += 8;
        else
            Registers::ip = 0;
        
cerr<<"Fetch: Sent message to decode\n";

        sleep(10);
    }
    
    return;
}