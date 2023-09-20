#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fstream>
#include <string>
#include "cpu.h"
using namespace std;

ifstream fin("input.txt");

//class cpu : function fetch -> decode -> execute -> load/store(from memory)
//class memory : function load, store


//communication done through queues https://www.geeksforgeeks.org/ipc-using-message-queues/

//clock

//fetch/decode/execute/load/store parallelized

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
    
    


    key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    while(!finished) {
        if(processes < 4) {
            
            processes++;
            child = fork();
            

            if(child == 0) {
                cout << "child created\n";
                cpu.fetch.run(key);
                return 0;
            }
            else{
                mesg_buffer message;
                message.mesg_type = 1;  
                fin >> message.mesg_text;
                msgsnd(msgid, &message, sizeof(message), 0);
                cout << "message sent\n";
            }
            
        }
        else {
            cout << "waiting \n";
            wait(NULL);
            processes--;
        }
    }
}