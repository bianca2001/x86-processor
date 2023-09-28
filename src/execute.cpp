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
    const int imm = 16;
    const int addr = 17;
    const int addr_r = 18;

    if(src < 15){
        return Registers::r[src - 1];
    }

    switch (src)
    {
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

    return 0;
}

void Execute::run()
{
    while(1) {
        execute();
    }
}

void Execute::execute() {
    mesg_buffer_instruction message_from_decode;

    msgrcv(msgIdFromDecode, &message_from_decode, sizeof(message_from_decode), 1, 0);

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

    switch (message_from_decode.mesg_text[0])
    {
    case add:
    {
cerr << "Execute: add\n";
        int data = getData(message_from_decode.mesg_text[2], message_from_decode.mesg_text[4]);

        if (message_from_decode.mesg_text[1] < 9)
            {
                Registers::r[message_from_decode.mesg_text[1] - 1] += data;
            }
            if(message_from_decode.mesg_text[1] == 17) {
cerr << "Execute: !!!!set access memory \n";
            }
            if(message_from_decode.mesg_text[1] == 18) {
cerr << "Execute: !!!!set access memory \n";
            }

cerr << "Execute: registers: ";
for(int i = 0; i < 8; i++) {
    cerr << Registers::r[i] << " ";
}

// cerr << "Execute: ip = " << Registers::ip << "\n";

            Registers::setIp(Registers::getIp() + 8);


        break;
    }
    case sub:
    {
cerr << "Execute: sub\n";
        int data = getData(message_from_decode.mesg_text[2], message_from_decode.mesg_text[4]);

        if (message_from_decode.mesg_text[1] < 9)
            {
                Registers::r[message_from_decode.mesg_text[1] - 1] -= data;
            }
            if(message_from_decode.mesg_text[1] == 17) {
cerr << "Execute: !!!!set access memory \n";
            }
            if(message_from_decode.mesg_text[1] == 18) {
cerr << "Execute: !!!!set access memory \n";
            }

cerr << "Execute: registers: ";
for(int i = 0; i < 8; i++) {
    cerr << Registers::r[i] << " ";
}

// cerr << "Execute: ip = " << Registers::ip << "\n";

            Registers::setIp(Registers::getIp() + 8);


        break;
    }
    case mov:
        {
cerr << "Execute: mov\n";
            int data = getData(message_from_decode.mesg_text[2], message_from_decode.mesg_text[4]);

cerr << "Execute: data = " << data << "\n";

            if (message_from_decode.mesg_text[1] < 15)
            {
                Registers::r[message_from_decode.mesg_text[1] - 1] = data;
            }
            if(message_from_decode.mesg_text[1] == 17) {
    cerr << "Execute: !!!!set access memory \n";
            }
            if(message_from_decode.mesg_text[1] == 18) {
    cerr << "Execute: !!!!set access memory \n";
            }

cerr << "Execute: registers: ";
for(int i = 0; i < 8; i++) {
    cerr << Registers::r[i] << " ";
}

// cerr << "Execute: ip = " << Registers::ip << "\n";

            Registers::setIp(Registers::getIp() + 8);



// cerr << "Execute: ip = " << Registers::ip << "\n";

            break;
        }
    case mul:
        {
        break;}
    case div:
        {
        break;}
    case cmp:
        {
        break;}
    case jmp:
    {
cerr << "Execute: jmp\n";
//cerr << "Execute: ip = " << Registers::getIp() << "\n";

        int address = getData(message_from_decode.mesg_text[1], 
        message_from_decode.mesg_text[3]);
        Registers::setIp(address);
        // Registers::ip = address;

// cerr << "Execute: ip = " << Registers::ip << "\n";
        break;
    }
    case je:
        {/* code */
        break;}
    case jl:
        {/* code */
        break;}
    case jg:
        {/* code */
        break;}
    case jz:
        {/* code */
        break;}
    case call:
        {/* code */
        break;}
    case ret:
        {/* code */
        break;}
    case end_sim:
        {/* code */
        break;}
    case push:
        {/* code */
        break;}
    case pop:
        {/* code */
        break;}
    default:
        break;
    }
}