//even address (every other word)
//address size: 16 bit
//data size: 16 bit
//number of words multiple of 16, can be read from memory in one shot: 4
//instruction 16-48 bits (1-3 words)

#ifndef MEMORY_H
#define MEMORY_H

class Memory {
    public:
        static char** get_data(int address);
        static void set_data(int address, char** data);
        static void loadInstructionsFromFile(char* filename);
    private:
        //TODO: test this, is should be an array with 65535 elements, 
        //each element being an array of 3 elements, 
        //each of those being an word of max 65535 characters
        static char*** memory;


};

char*** Memory::memory = new char**[65535]{new char*[4]{new char[65535]}};

#endif