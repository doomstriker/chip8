#pragma once
#include "OpCode.h"

#define RND_LBL "RND "
class RndCode : public OpCode {
    private:

    public:
        RndCode(uint32_t args) : OpCode(OpCode::RND,RND_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};