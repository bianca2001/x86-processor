#pragma once

class Registers {
    public:
        static int r[8];
        static int ip;
        static int flag[3];
};

int Registers::ip = 0xfff0;