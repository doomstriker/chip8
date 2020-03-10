#pragma once
#include "OpCode.h"

#define DRW_LBL "DRW "
class DrawCode : public OpCode {
    private:

    public:
        DrawCode(uint32_t args) : OpCode(DRW,DRW_LBL,args) { }    
    // execute the OPCode instruction
     int execute(Cpu &) ;
     string disassemble();
};