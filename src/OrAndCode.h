#pragma once
#include "OpCode.h"

#define AND_LBL "AND "
#define OR_LBL "OR "
#define XOR_LBL "XOR "
class OrAndCode : public OpCode {
    private:

    public:
        OrAndCode(OpCodeType op,uint32_t args) : OpCode(op,AND_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};