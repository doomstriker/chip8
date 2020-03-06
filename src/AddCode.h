#pragma once
#include "OpCode.h"

#define ADD_LBL "ADD "
class AddCode : public OpCode {
    private:

    public:
        AddCode(OpCodeType op,uint32_t args) : OpCode(op,ADD_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};