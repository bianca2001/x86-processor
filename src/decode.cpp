#include <bitset>
#include <iostream>
#include <string>
#include <string.h>
#include "decode.h"
#include "mesgBuffer.cpp"
using namespace std;

Decode::Decode()
{
    keyFromFetch = ftok("/workspaces/codespaces-blank/message queues/fetchToDecode", 3);
    msgIdFromFetch = msgget(keyFromFetch, 0666 | IPC_CREAT);
}

void Decode::run()
{
    //TODO: detect instruction type
    //TODO: decode instruction
    //TODO: send decoded instruction to execute
cerr<<"Decode: Started\n";
    mesg_buffer_char_matrix message_from_fetch;

    msgrcv(msgIdFromFetch, &message_from_fetch, sizeof(message_from_fetch), 1, 0);

cerr<<"Decode: Received message \n";

    string in = "";
    
    if(message_from_fetch.mesg_text[0]) {
        in.append(message_from_fetch.mesg_text[0]);
    }
cerr<<"Decode: in = "<<in<<"\n";

    in.append(message_from_fetch.mesg_text[1]);

cerr<<"Decode: in = "<<in<<"\n";

    if (message_from_fetch.mesg_text[2] != "")
    {
        in.append(message_from_fetch.mesg_text[2]);
    }
    
    if (message_from_fetch.mesg_text[3] != 0)
        in.append(message_from_fetch.mesg_text[3]);

    bitset<64> binIn = stoi(in, 0, 16);

cerr<<"Decode: binIn = "<<binIn<<"\n";

    string instructionFetch = binIn.to_string();

cerr<<"Decode: instruction = "<<instructionFetch<<"\n";

    int opcode = stoi(instructionFetch.substr(0, 6));

    instructionFetch = instructionFetch.substr(6);

    const int add = 1;
    const int sub = 2;
    const int mov = 3;
    const int mul = 4;
    const int div = 5;
    const int cmp = 6;
    const int jmp = 7;
    const int je = 8;
    const int jl = 9;
    const int jg = 10;
    const int jz = 11;
    const int call = 12;
    const int ret = 13;
    const int end_sim = 14;
    const int push = 15;
    const int pop = 16;

    int src1, src2, dest;
cerr<<"Decode: opcode = "<< opcode <<"\n";
    switch (opcode)
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
    case jmp:
cerr<< "Decode: jmp\n";
        src1 = stoi(instructionFetch.substr(0, 5));
        instructionFetch = instructionFetch.substr(10);

cerr<<"Decode: instr remained = "<<instructionFetch<<"\n";
        break;
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

    return;
}