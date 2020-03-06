#pragma once
#include "OpCode.h"

#define CLS_LBL "CLS"
class ClsCode : public OpCode {
    private:

    public:
        ClsCode() : OpCode(OpCodeType::CLS,CLS_LBL,0) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};