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

    keyToExecute = ftok("/workspaces/codespaces-blank/message queues/decodeToExecute", 4);
    msgIdToExecute = msgget(keyToExecute, 0666 | IPC_CREAT);
}

void Decode::run()
{
    while(1) {
        decode();
    }
}

void Decode::decode()
{
//cerr<<"Decode: Started\n";
    mesg_buffer_char_matrix message_from_fetch;

    msgrcv(msgIdFromFetch, &message_from_fetch, sizeof(message_from_fetch), 1, 0);

//cerr<<"Decode: Received message \n";

    for(int i = 0; i < 4; i++) {
//cerr<<"Decode: message_from_fetch.mesg_text[i] = "<<message_from_fetch.mesg_text[i]<<"\n";
        if(strstr(message_from_fetch.mesg_text[i], "ffff") == NULL) {
            bitset<16> bin = stoi(message_from_fetch.mesg_text[i], 0, 16);
            instructionFetch.append(bin.to_string());
        }
    }

cerr<<"Decode: in = "<<instructionFetch<<"\n";


    int opcode = stoi(instructionFetch.substr(0, 6), 0, 2);

    instructionFetch = instructionFetch.substr(6);

    //TODO: put as define in a file
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

    int src1, src2, dest, param1, param2;
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
        src1 = stoi(instructionFetch.substr(0, 5), 0, 2);
        src2 = stoi(instructionFetch.substr(5, 5), 0, 2);

        instructionFetch = instructionFetch.substr(10);

        if (src1 > 7) {
            param1 = stoi(instructionFetch.substr(0, 16), 0, 2);
            instructionFetch = instructionFetch.substr(16);
        }

        if (src2 > 7) {
cerr<< instructionFetch.substr(0, 16) <<"\n";
            param2 = stoi(instructionFetch.substr(0, 16), 0, 2);
            instructionFetch = instructionFetch.substr(16);
        }

cerr << "Decode: src1 = " << src1;
cerr << " src2 = " << src2;
cerr << " param1 = " << param1;
cerr << " param2 = " << param2 << "\n";

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
//cerr<< "Decode: jmp\n";
        src1 = stoi(instructionFetch.substr(0, 5), 0, 2);
        src2 = NULL;
        param1 = stoi(instructionFetch.substr(10, 16), 0, 2);
        param2 = NULL;

        instructionFetch = instructionFetch.substr(26);

//cerr<<"Decode: instr remained = "<< instructionFetch <<"\n";
//cerr<<"Decode: src1 = "<< src1 <<"\n";
//cerr<<"Decode: param1 = "<< param1 <<"\n";

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

    mesg_buffer_instruction message_to_execute;
    message_to_execute.mesg_type = 1;
    message_to_execute.mesg_text[0] = opcode;
    message_to_execute.mesg_text[1] = src1;
    message_to_execute.mesg_text[2] = src2;
    message_to_execute.mesg_text[3] = param1;
    message_to_execute.mesg_text[4] = param2;

    msgsnd(msgIdToExecute, &message_to_execute, sizeof(message_to_execute), 0);

    return;
}