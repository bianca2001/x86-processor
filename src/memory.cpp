#include "memory.h"
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;


char* Memory::get_data(int address)
{
cerr<<"Memory: Returning data "<< memory[address] <<" at address "<<address<<'\n';
    return memory[address];
}

void Memory::set_data(int address, char data[])
{
    strcpy(memory[address], data);
}

void Memory::loadInstructionsFromFile(char* filename)
{
    ifstream fin(filename);

    string line;

    int address = 0;

    while (fin>>line)
    {
        if(line[0] == '#') {
            address = stoi(line.substr(1), 0, 16);
        }
        else {
            char* data = new char[65535];
            
            strcpy(data, line.c_str());
            
            memory[address] = strcat(data, "\0");

            address += 2;
        
        }
    }
    
    fin.close();
}

void Memory::initialize()
{
    char *aux = new char[65535];
    for(int i = 0; i < 65535; i++) {
        memory[i] = (char*)"ffff\0";
    }
}
