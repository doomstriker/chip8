#pragma once
#include "OpCode.h"

#define LD_LBL "LD "
class LdCode : public OpCode {
    private:

    public:
        LdCode(OpCodeType op,uint32_t args) : OpCode(op,LD_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};