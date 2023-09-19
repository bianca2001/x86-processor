#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include "cpu.h"
using namespace std;


//class cpu : function fetch -> decode -> execute -> load/store(from memory)
//class memory : function load, store


//communication done through queues https://www.geeksforgeeks.org/ipc-using-message-queues/

//clock

//fetch/decode/execute/load/store parallelized



int main(){
    pid_t child;
    bool finished = false;
    int processes = 0;
    CPU cpu;
    key_t key;

    //open code file

    while(!finished) {
        if(processes < 4) {
            processes++;
            child = fork();

            if(child == 0) {
                cout << "child created\n";
                key = ftok("progfile", 65);

                msgid = msgget(key, 0666 | IPC_CREAT);

                msgsnd(msgid, &message, sizeof(message), 0)

                cpu.fetch.run(key);
            }
            
        }
        else {
            cout << "waiting \n";
            wait(NULL);
            cout << "hmm";
        }
    }
}