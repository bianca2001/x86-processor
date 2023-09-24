#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "loadStore.h"
#pragma once

class CPU {
public:
    Fetch fetch;
   Decode decode;
   Execute execute;
    LoadStore loadStore;
};