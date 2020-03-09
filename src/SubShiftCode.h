#pragma once
#include "OpCode.h"

#define SUB_LBL "SUB "
#define SUBN_LBL "SUBN "
#define SHR_LBL "SHR "
#define SHL_LBL "SHL "
class SubShiftCode : public OpCode {
    private:

    public:
        SubShiftCode(OpCodeType op,uint32_t args) : OpCode(op,"",args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};