/**
 * Name: OpCodeFactory
 * Description:  OpCodes Factory
 **/
#include "OpCodeFactory.h"
#include <cstddef>
#include <iostream>

/**
 * Technical Spec: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM 
 * 
 * */
#define OPCODE_SYS   0x0000
#define OPCODE_CLS   0x00E0
#define OPCODE_RET   0x00EE
#define OPCODE_JMP   0x1000
#define OPCODE_CALL  0x2000
#define OPCODE_SE    0x3000
#define OPCODE_SNE   0x4000
#define OPCODE_SEXY  0x5000
#define OPCODE_LD    0x6000
#define OPCODE_ADD   0x7000
#define OPCODE_LDE   0x8000
#define OPCODE_OR    0x8001
#define OPCODE_AND   0x8002
#define OPCODE_XOR   0x8003
#define OPCODE_ADDXY 0x8004
#define OPCODE_SUB   0x8005
#define OPCODE_SHR   0x8006
#define OPCODE_SUBN  0x8007
#define OPCODE_SHL   0x800E

#define OPCODE_SNEXY 0x9000
#define OPCODE_LDI   0xA000
#define OPCODE_JPV   0xB000
#define OPCODE_RND   0xC000
#define OPCODE_DRW   0xD000
#define OPCODE_SKP   0xE09E
#define OPCODE_SKNP  0xE0A1

#define OPCODE_DTLD 0xF007
#define OPCODE_WAIT_KP 0xF00A
#define OPCODE_DTSET 0xF015
#define OPCODE_STSND 0xF018
#define OPCODE_ADDI  0xF01E
#define OPCODE_SPRI  0xF029
#define OPCODE_BCDI  0xF033
#define OPCODE_WTI   0xF055
#define OPCODE_RDI   0xF065




/*
#define OPCODE_SCRL        0x00fc
#define OPCODE_SCRR       0x00fb
#define OPCODE_EXT      0x00fd
#define OPCODE_LOW       0x00fe
#define OPCODE_HIGH      0x00ff

#define OPCODE_SCRD        0x00c0
#define SCROLL_DOWN_MASK          0x00f0 
*/


#define OPCODE_MASK 0xF000
#define OPCODE_ADDR_MASK 0xFFF

OpCode* OpCodeFactory::createOpCode(uint32_t op) {
   OpCode* opCode = NULL;
   uint32_t cmd = op & OPCODE_MASK; //parse cmd group
   uint32_t addr = op & OPCODE_ADDR_MASK; //address bits

   switch(cmd) {
      case OPCODE_SYS : {
         break;
      }
      case OPCODE_JMP : {  
         cout << "JP " << hex << addr << ";" << endl; 
         break;
      }
      case OPCODE_CALL: {
         break;
      }
      case OPCODE_SE: {
         break;
      }
      case OPCODE_SNE: {
         break;
      }
      case OPCODE_SEXY: {
         break;
      }
      case OPCODE_LD: {
         break;
      }
      case OPCODE_ADD: {
         break;
      }
      case OPCODE_LDE: {
         break;
      }
      case OPCODE_SNEXY: {
         break;
      }
      case OPCODE_LDI: {
         break;
      }
      case OPCODE_JPV: {
         break;
      }
      case OPCODE_RND: {
         break;
      }
      case OPCODE_DRW: {
         break;
      }
   }
   return opCode;
}



OpCode* OpCodeFactory::createOpCode(const std::string&) {
   OpCode* opCode = NULL;
   return opCode;
}

int main () {

   int cmd = 0x10AD;
   OpCodeFactory::createOpCode(cmd);
}