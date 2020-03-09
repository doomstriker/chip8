#include "OrAndCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int OrAndCode::execute(Cpu &) {
        int vx = this->_args >> 8;
        int vy = (this->_args & 0xf0) >> 4;
        int val;
        
        switch(this->_op) {
            case AND: {
                val = Chip8::getInstance()->getRegister(vx) &
                    Chip8::getInstance()->getRegister(vy);
                Chip8::getInstance()->setRegister(vx,val); 
                break;
            }
            case OR: {
                val = Chip8::getInstance()->getRegister(vx) |
                    Chip8::getInstance()->getRegister(vy);
                Chip8::getInstance()->setRegister(vx,val); 
                break;
            }
           case XOR: {
                val = Chip8::getInstance()->getRegister(vx) ^
                    Chip8::getInstance()->getRegister(vy);
                Chip8::getInstance()->setRegister(vx,val); 
                break;
            }
   
        } 
 
         return 1;
     }
     string OrAndCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int vy = (this->_args & 0xf0) >> 4;
        
        switch(this->_op) {
            case AND: {
                //AND Vx,Vy
                str << AND_LBL << "V"<< hex << vx << ",V" << vy << endl;
                break;
            }
            case OR: {
                //OR Vx,Vy
                str << OR_LBL << "V"<< hex << vx << ",V" << vy << endl;
                break;
            }
            case XOR: {
                //XOR Vx,Vy
                str << XOR_LBL << "V"<< hex << vx << ",V" << vy << endl;
                break;
            }
   
        }
         
         return str.str();
     }