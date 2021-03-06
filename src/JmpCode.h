#pragma once
#include "OpCode.h"

#define JMP_LBL "JP "
class JmpCode : public OpCode {
    private:

    public:
        JmpCode(OpCodeType op,uint32_t args) : OpCode(op,JMP_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};