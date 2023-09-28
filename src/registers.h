#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <atomic>
#include <vector>
#include <array>
#pragma once
using namespace std;

class Registers {
    public:
        //inline static char* r = (char*)"/workspaces/codespaces-blank/data/registers.txt";
        inline static char* ip = (char*)"/workspaces/codespaces-blank/data/ip.txt";
        //inline static vector<atomic<int>> r(vector<atomic<int>>{0, 0, 0, 0, 0, 0, 0});
        //inline static array< atomic<int>, 7 > r = {};
        inline static int r[8] = {0};
        //inline static atomic<int> ip{0x500};
        inline static int flag[3] = {0};

        static int getIp() {
            int ipValue;
            FILE *fp;
            fp = fopen(ip, "r");
            fscanf(fp, "%x", &ipValue);
            fclose(fp);
            return ipValue;
        }

        static void setIp(int newIp) {
            FILE *fp;
            fp = fopen(ip, "w");
            fprintf(fp, "%x", newIp);
            fclose(fp);
        }

//         static int getR(int rNum) {
// cerr<<"getR: rNum = "<<rNum<<"\n";
//             int rValue;
//             FILE *fp;
//             fp = fopen(r, "r");
//             int aux;
//             for(int i = 0; i < rNum; i++) {
//                 fscanf(fp, "%x", &aux);
//             }
//             fclose(fp);
//             return aux;
//         }


//         //TODO: change only one register
//         static void setR(int rNum, int newValue) {

// cerr<<"setR: rNum = "<<rNum<<"\n";

//             ifstream fin(r);
//             char aux[100];
//             int i;

//             stringstream newFileContent;

//             for(i = 0; i < rNum - 1; i++) {
//                 newFileContent << aux << "\n";
//             }

//             string newValuestring = to_string(newValue);
//             char* newValueChar = (char*)newValuestring.c_str();

// cerr << "setR: newValueChar = " << newValueChar << "\n";

//             newFileContent << newValueChar;

//             for(i = i + 1; i < 7; i++) {
//                 fin >> aux;
//                 newFileContent << "\n" << aux;
//             }

//             fin.close();

//             string result = newFileContent.str();
//             ofstream fout(r);
//             fout << result;
//             fout.close();
//         }
};