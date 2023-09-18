#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
    pid_t child;
    bool finished = false;
    int processes = 0;

      

    while(!finished) {
        if(processes < 4) {
            processes++;
            child = fork();

            if(child == 0) {
                //open instruction fetch
                cout << "child created\n";
                while (1)
                {
                    if(processes == 1) return 0;
                }
                
            }
            
        }
        else {
            cout << "waiting \n";
            wait(NULL);
            cout << "hmm";
        }
    }
}