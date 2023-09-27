#include <iostream>
#include <unistd.h>
#include <string.h>
#pragma once
using namespace std;

class Registers {
    public:
        //inline static int r[8] = {0};
        inline static char* r = (char*)"/workspaces/codespaces-blank/data/registers.txt";
        //inline static int ip = 0xfff0;
        inline static char* ip = (char*)"/workspaces/codespaces-blank/data/ip.txt";
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

        static int getR(int rNum) {
cerr<<"getR: rNum = "<<rNum<<"\n";
            int rValue;
            FILE *fp;
            fp = fopen(r, "r");
            int aux;
            for(int i = 0; i < rNum; i++) {
                fscanf(fp, "%x", &aux);
            }
            return aux;
        }


        //TODO: change only one register
        static void setR(int rNum, int newValue) {
cerr<<"setR: rNum = "<<rNum<<"\n";
            FILE *fp;
            fp = fopen(r, "r");
            char aux[100];
            char fileContent[1000];
            int i;

            for(i = 0; i < rNum - 1; i++) {
                fscanf(fp, "%s", &aux);
cerr<<"setR: aux = "<<aux<<"\n";
                strcat(fileContent, aux);
                strcat(fileContent, "\n");
            }

cerr<<"setR: fileContent = "<<fileContent<<"\n";

            string newValuestring = to_string(newValue);
            char* newValueChar = (char*)newValuestring.c_str();

            strcat(fileContent, newValueChar);
            strcat(fileContent, "\n");

cerr<<"setR: fileContent = "<<fileContent<<"\n";

            for(i = i + 1; i < 7; i++) {
                fscanf(fp, "%s", &aux);
                strcat(fileContent, aux);
                strcat(fileContent, "\n");
            }

cerr<<"setR: fileContent = "<<fileContent<<"\n";
            fclose(fp);

            fp = fopen(r, "w");
            fprintf(fp, "%s", fileContent);
            fclose(fp);
        }
};