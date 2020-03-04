#pragma once
#include "OpCode.h"

#define JMP_LBL "JP"
class JmpCode : public OpCode {
    private:

    public:
        JmpCode(uint32_t args) : OpCode(OpCodeType::JMP,JMP_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};