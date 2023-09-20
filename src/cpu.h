#include "fetch.h"
#include "decode.h"
#include "execute.h"

class CPU {
public:
    Fetch fetch;
   Decode decode;
   Execute execute;

};