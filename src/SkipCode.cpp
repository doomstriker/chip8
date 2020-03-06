#include "SkipCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int SkipCode::execute(Cpu &) {
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
        }
         return 1;
     }
     string SkipCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int val = this->_args & 0xff;

        switch(this->_op) {
            case SE: {
                //SE Vx,byte
                str << SE_LBL << "V" << hex << vx << "," << val << endl;
                break;
            }
            case SNE: {
                //SNE Vx,byte
                 str << SNE_LBL<< "V"<< hex << vx << "," << val << endl;
                break;
            }
            case SEXY: {
                //SE Vx,Vy
                val = ((val >> 4) & 0x0f);
                str << SE_LBL<< "V"<< hex << vx << ",V" << val << endl;
                break;
            }
 
            case SNEXY: {
                //SNE Vx,Vy
                val = (_args & 0xfff );
                str << SNE_LBL<< "V"<< hex << vx << ",V" << val << endl;
                break;
            }
            case SKP: {
                str << SKP_LBL << "V" << hex << vx << endl;
                break;
            }
            case SKNP: {
                str << SKNP_LBL << "V" << hex << vx << endl;
                break;
            }
        }
         
         return str.str();
     }