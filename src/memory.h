//even address (every other word)
//address size: 16 bit
//data size: 16 bit
//number of words multiple of 16 bit, can be read from memory in one shot: 4
//instruction 16-48 bits (1-3 words)

#pragma once

class Memory {
    public:
        static char* get_data(int address);
        static void set_data(int address, char data[]);
        static void loadInstructionsFromFile(char* filename);
        static void initialize();
        inline static char** memory = new char*[65535]{new char[65535]};
};