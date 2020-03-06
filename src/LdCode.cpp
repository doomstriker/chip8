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
        }
         
         return str.str();
     }