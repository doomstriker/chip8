#include "LdCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int LdCode::execute(Cpu &) {
        int vx = this->_args >> 8;
         int val = this->_args & 0xff;
        switch(this->_op) {
            case LD: {
                Chip8::getInstance()->setRegister(vx,val);
                break;
            }
            case LDE: {
                //LD Vx = Vy
                uint8_t vy = ((val >> 4) & 0x0f);
                uint8_t vyVal = Chip8::getInstance()->getRegister(val);
                Chip8::getInstance()->setRegister(vx,vyVal);
                break;
            }
            case LDI: {
                //LD I = addr
                val = (_args & 0xfff );
                Chip8::getInstance()->setIndex(val); 
                break;
            }
            case DTLD: {
                break;
            }
            case WAIT_KP: {
                break;
            }
            case DTSET: {
                break;
            }
            case STSND: {
                break;
            }
            case SPRI: {
                break;
            }
            case BCDI: {
                break;
            }
            case WTI: {
                break;
            }
            case RDI: {
                break;
            }  
        }
         return 1;
     }
     string LdCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int val = this->_args & 0xff;
 
        str << _label ;
        switch(this->_op) {
            case LD: {
                //LD Vx = byte
                str << "V"<< hex << vx << "," << val << endl;
                break;
            }
            case LDE: {
                //LD Vx = Vy
                val = ((val >> 4) & 0x0f);
                str << " V"<< hex << vx << ",V" << val << endl;
                break;
            }
            case LDI: {
                //LD I = addr
                val = (_args & 0xfff );
                str << "I," << hex << val << endl;
                break;
            }
            case DTLD: {
                str << " V"<< hex << vx << ", DT" << endl;
                break;
            }
            case WAIT_KP: {
                str << " V"<< hex << vx << ", K" << endl;
                break;
            }
            case DTSET: {
                str << "DT, V"<< hex << vx << endl;
                break;
            }
            case STSND: {
                str << "ST, V"<< hex << vx << endl;
                break;
            }
            case SPRI: {
                str << "F,  V"<< hex << vx << endl;
                break;
            }
            case BCDI: {
                str << "B, V"<< hex << vx << endl;
                break;
            }
            case WTI: {
                str << "[I], V"<< hex << vx << ",DT" << endl;
                break;
            }
            case RDI: {
                str << " V"<< hex << vx << ", [I]" << endl;
                break;
            }  
        }
         
         return str.str();
     }