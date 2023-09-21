#include "memory.h"

char** Memory::get_data(int address)
{
    return memory[address];
}

//TODO: set it in memory to not have gaps between fetch window
void Memory::set_data(int address, char** data)
{
    memory[address] = data;
}
