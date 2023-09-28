#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fstream>
#include <string>
#include <vector>
#include "cpu.h"
#include "memory.h"
#include "registers.h"

using namespace std;

ifstream fin("input.txt");

//communication done through queues https://www.geeksforgeeks.org/ipc-using-message-queues/

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

    sleep(100);
    return 0;
}