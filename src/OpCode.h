/**
 * Name: OpCode
 * Description: Interface to handle OpCodes 
 **/
#pragma once
#include "Cpu.h"
#include <string>

using namespace std;
class OpCode {
    public:
    enum OpCodeType {
SYS   = 0x0000,
CLS   = 0x00E0,
RET   = 0x00EE,
JMP   = 0x1000,
CALL  = 0x2000,
SE    = 0x3000,
SNE   = 0x4000,
SEXY  = 0x5000,
LD    = 0x6000,
ADD   = 0x7000,
LDE   = 0x8000,
OR    = 0x8001,
AND   = 0x8002,
XOR   = 0x8003,
ADDXY = 0x8004,
SUB   = 0x8005,
SHR   = 0x8006,
SUBN  = 0x8007,
SHL   = 0x800E,

SNEXY = 0x9000,
LDI   = 0xA000,
JPV   = 0xB000,
RND   = 0xC000,
DRW   = 0xD000,
SKP   = 0xE09E,
SKNP  = 0xE0A1,

DTLD = 0xF007,
WAIT_KP = 0xF00A,
DTSET = 0xF015,
STSND = 0xF018,
ADDI  = 0xF01E,
SPRI  = 0xF029,
BCDI  = 0xF033,
WTI   = 0xF055,
RDI   = 0xF065
    };
    protected:
    uint32_t _args;
    string _label;
    OpCodeType _op;
    OpCode(OpCodeType op, const string label, uint32_t args) : _op(op), _label(label),_args(args) {}
    public:
    // execute the OPCode instruction
     virtual int execute(Cpu &) = 0;
     virtual string disassemble() = 0;
};