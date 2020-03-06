#include "AddCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int AddCode::execute(Cpu &) {
        
            //    Chip8::getInstance()->setIndex(val); 
 
         return 1;
     }
     string AddCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int val = this->_args & 0xff;
 
        str << _label ;
        switch(this->_op) {
            case ADD: {
                //ADD Vx = byte
                str << "V"<< hex << vx << "," << val << endl;
                break;
            }
            case ADDXY: {
                //ADD Vx = Vy
                val = ((val >> 4) & 0x0f);
                str << "V"<< hex << vx << ",V" << val << endl;
                break;
            }
            case ADDI: {
                //ADD I ,Vx
                val = (_args & 0xfff );
                str << "V" << hex << vx<< ",V" << val << endl;
                break;
            }
        }
         
         return str.str();
     }