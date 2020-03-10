/**
 * Name: OpCodeFactory
 * Description:  OpCodes Factory
 **/
#include "OpCodeFactory.h"
#include <cstddef>
#include <iostream>
#include "OpCode.h"
#include "JmpCode.h"
#include "ClsCode.h"
#include "LdCode.h"
#include "RndCode.h"
#include "SkipCode.h"
#include "AddCode.h"
#include "CallCode.h"
#include "OrAndCode.h"
#include "SubShiftCode.h"
#include "DrawCode.h"
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
#define OPCODE_SKIP_MSK  0xE000

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

/**
 * Function: createOpCode
 * Param: uint32_t opcode to decode
 * return OpCpode object if decoding sucess, false otherwise
 * */
OpCode* OpCodeFactory::createOpCode(uint32_t op) {
   OpCode* opCode = NULL;
   uint32_t cmd = op & OPCODE_MASK; //parse cmd group
   uint32_t addr = op & OPCODE_ADDR_MASK; //address bits

   switch(cmd) {
      case OPCODE_SYS : {
         if (op == OPCODE_CLS) {
            opCode = new ClsCode();
         }
         break;
      }
      case OPCODE_JMP : {  
         opCode = new JmpCode(OpCode::JMP,addr);
         break;
      }
      case OPCODE_CALL: {
         opCode = new CallCode(addr);
         break;
      }
      case OPCODE_SE: {
         opCode = new SkipCode(OpCode::SE,addr);
         break;
      }
      case OPCODE_SNE: {
         opCode = new SkipCode(OpCode::SNE,addr);
         break;
     }
      case OPCODE_SEXY: {
         opCode = new SkipCode(OpCode::SEXY,addr);
         break;
      }
      case OPCODE_LD: {
         opCode = new LdCode(OpCode::LD,addr);
         break;
      }
      case OPCODE_ADD: {
         opCode = new AddCode(OpCode::ADD,addr);
         break;
      }
      case OPCODE_LDE: {
         // add others
         int mask = op & 0x800F;
         switch( mask ) {
            case OPCODE_LDE: {
               opCode = new LdCode(OpCode::LDE,addr);
               break;
            }
            case OPCODE_OR: {
               opCode = new OrAndCode(OpCode::OR,addr);
               break;
           }
            case OPCODE_AND: {
               opCode = new OrAndCode(OpCode::AND,addr);
               break;
            }
            case OPCODE_XOR: {
               opCode = new OrAndCode(OpCode::XOR,addr);
               break;
            }
            case OPCODE_ADDXY: {
               opCode = new AddCode(OpCode::ADDXY,addr);
               break;
            }
            case OPCODE_SUB: {
               opCode = new SubShiftCode(OpCode::SUB,addr);
               break;
            }
            case OPCODE_SHR: {
              opCode = new SubShiftCode(OpCode::SHR,addr);
                break;
            }
            case OPCODE_SUBN: {
               opCode = new SubShiftCode(OpCode::SUBN,addr);
               break;
            }
            case OPCODE_SHL: {
               opCode = new SubShiftCode(OpCode::SHL,addr);
               break;
            }
         }
      }
      case OPCODE_SNEXY: {
         opCode = new SkipCode(OpCode::SNEXY,addr);
         break;
      }
      case OPCODE_LDI: {
         opCode = new LdCode(OpCode::LDI,addr);
         break;
      }
      case OPCODE_JPV: {
         opCode = new JmpCode(OpCode::JPV,addr);
         break;
      }
      case OPCODE_RND: {
         opCode = new RndCode(addr);
         break;
      }
      case OPCODE_DRW: {
         opCode = new DrawCode(addr);
         break;
      }
      case OPCODE_SKIP_MSK: {
         addr &=0xff ;
         switch(addr) {
            case OPCODE_SKP: {
               opCode = new SkipCode(OpCode::SKP,addr);
               break;
            }
            case OPCODE_SKNP: {
               opCode = new SkipCode(OpCode::SKNP,addr);
               break;
            }
         } 
         break;
      }
   }
   return opCode;
}



OpCode* OpCodeFactory::createOpCode(const std::string&) {
   OpCode* opCode = NULL;
   return opCode;
}
