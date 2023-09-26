#include <mutex>
#pragma once

class Registers {
    public:
        inline static int r[8] = {0};
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
};