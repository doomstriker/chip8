#include "SubShiftCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int SubShiftCode::execute(Cpu &) {
        
            //    Chip8::getInstance()->setIndex(val); 
 
         return 1;
     }
     string SubShiftCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int vy = (this->_args & 0xf0) >> 4;
        int val;
 
        switch(this->_op) {
            case SUB: {
                //SUB Vx,Vy
                str << SUB_LBL << "V"<< hex << vx << ",V" << vy << endl;
                break;
            }
            case SUBN: {
                //SUBN Vx,Vy
                val = ((val >> 4) & 0x0f);
                str << SUBN_LBL "V"<< hex << vx << ",V" << vy << endl;
                break;
            }
            case SHR: {
                //SHR Vx,Vy
                str << SHR_LBL << "V" << hex << vx<< ",V" << val << endl;
                break;
            }
            case SHL: {
                //SHL Vx,Vy
                str << SHL_LBL << "V" << hex << vx<< ",V" << val << endl;
                break;
            }
        }
         
         return str.str();
     }