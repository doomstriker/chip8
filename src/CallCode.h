#pragma once
#include "OpCode.h"

#define CALL_LBL "CALL "
class CallCode : public OpCode {
    private:

    public:
        CallCode(uint32_t args) : OpCode(OpCode::CALL,CALL_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};