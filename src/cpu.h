#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "loadStore.h"

class CPU {
public:
    Fetch fetch;
   Decode decode;
   Execute execute;
    LoadStore loadStore;
};