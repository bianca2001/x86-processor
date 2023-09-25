#include <iostream>
#include <unistd.h>
#include "execute.h"
#include "mesgBuffer.cpp"
#include "registers.h"
using namespace std;

Execute::Execute()
{
    keyFromDecode = ftok("/workspaces/codespaces-blank/message queues/decodeToExecute", 4);
    msgIdFromDecode = msgget(keyFromDecode, 0666 | IPC_CREAT);

}



int getData(int src, int data) {
    const int r1 = 1;
    const int r2 = 2;
    const int r3 = 3;
    const int r4 = 4;
    const int r5 = 5;
    const int r6 = 6;
    const int r7 = 7;
    const int imm = 16;
    const int addr = 17;
    const int addr_r = 18;

    switch (src)
    {
    case r1:
        return Registers::r[0];
        break;
    case r2:
        return Registers::r[1];
        break;
    case r3:    
        return Registers::r[2];
        break; 
    case r4:
        return Registers::r[3];
        break;
    case r5:
        return Registers::r[4];
        break;
    case r6: 
        return Registers::r[5];
        break;
    case r7: 
        return Registers::r[6];
        break;
    case imm: 
        return data;
        break;
    case addr: 
cerr << "Execute: !!!!set access memory \n";
    break;
    case addr_r: 
cerr << "Execute: !!!!set access memory \n";
    break;
    default:
cerr << "Execute: something went wrong \n";
        break;
    }
}

void Execute::run()
{
    mesg_buffer_instruction message_from_decode;

    msgrcv(msgIdFromDecode, &message_from_decode, sizeof(message_from_decode), 1, 0);

    const int add = 1;
    const int sub = 2;
    const int mov = 3;
    const int mul = 4;
    const int div = 5;
    const int cmp = 6;
    const int jmp_command = 7;
    const int je = 8;
    const int jl = 9;
    const int jg = 10;
    const int jz = 11;
    const int call = 12;
    const int ret = 13;
    const int end_sim = 14;
    const int push = 15;
    const int pop = 16;

    switch (message_from_decode.mesg_text[0])
    {
    case add:
        /* code */
        break;
    case sub:
        /* code */
        break;
    case mov:
        /* code */
        break;
    case mul:
        /* code */
        break;
    case div:
        /* code */
        break;
    case cmp:
        /* code */
        break;
    case jmp_command:
    {
cerr << "Execute: jmp\n";
cerr << "Execute: ip = " << Registers::ip << "\n";

        int address = getData(message_from_decode.mesg_text[1], 
        message_from_decode.mesg_text[3]);
        Registers::ip = address;

cerr << "Execute: ip = " << Registers::ip << "\n";
        break;
    }
    case je:
        /* code */
        break;
    case jl:
        /* code */
        break;
    case jg:
        /* code */
        break;
    case jz:
        /* code */
        break;
    case call:
        /* code */
        break;
    case ret:
        /* code */
        break;
    case end_sim:
        /* code */
        break;
    case push:
        /* code */
        break;
    case pop:
        /* code */
        break;
    default:
        break;
    }
    
}