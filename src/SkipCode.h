#pragma once
#include "OpCode.h"

#define SE_LBL "SE "
#define SNE_LBL "SNE "
#define SKP_LBL "SKP "
#define SKNP_LBL "SKNP "
class SkipCode : public OpCode {
    private:

    public:
        SkipCode(OpCodeType op,uint32_t args) : OpCode(op,SE_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};