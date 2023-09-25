#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fstream>
#include <string>
#include "cpu.h"
#include "memory.h"

using namespace std;

ifstream fin("input.txt");

//class cpu : function fetch -> decode -> execute -> load/store(from memory)
//class memory : function load, store


//communication done through queues https://www.geeksforgeeks.org/ipc-using-message-queues/

//fetch/decode/execute/load/store parallelized

//TODO: clock
//TODO: modify to open all the modules at the same time instead
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
};

int main(){
    pid_t child;
    bool finished = false;
    int processes = 0;
    CPU cpu;
    key_t key;

    char* file = (char*)"input.txt";

    Memory::initialize();

    Memory::loadInstructionsFromFile(file);

    

    // key = ftok("progfile", 65);
    // int msgid = msgget(key, 0666 | IPC_CREAT);

    child = fork();

    if(child == 0){
        cpu.fetch.run(key);
        return 0;
    }

    child = fork();

    if(child == 0) {
        cpu.decode.run();
        return 0;
    }

    child = fork();

    if(child == 0) {
        cpu.execute.run();
        return 0;
    }

    child = fork();
    if(child == 0) {
        cpu.loadStore.load();
        return 0;
    }

    child = fork();
    if(child == 0) {
        cpu.loadStore.store();
        return 0;
    }

}