#include "memory.h"
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;



char** Memory::get_data(int address)
{
    return memory[address];
}

//TODO: set it in memory to not have gaps between fetch window
void Memory::set_data(int address, char** data)
{
    memory[address] = data;
}

void Memory::loadInstructionsFromFile(char* filename)
{
    ifstream fin(filename);

    char * aux;
    int i = 0, j = 0;

    while(fin>>aux) {
        char *token = strtok(aux, " ");

        while(token != NULL) {
            memory[i][j] = token;
            
            if(j == 3) {
                j = 0;
                i++;
            }
            else {
                j++;
            }

            token = strtok(NULL, " ");
        }
    }

    for(int ii = 0; ii < i; ii++)
        for(int jj = 0; jj < 4; jj++)
            cout<<memory[ii][jj]<<endl;
}
