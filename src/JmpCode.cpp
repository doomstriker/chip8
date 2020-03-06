#include "JmpCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int JmpCode::execute(Cpu &) {
         switch(this->_op) {
             case JMP: {
                Chip8::getInstance()->setPC(_args);
                break;
             }
             case JPV: {
                int addr = Chip8::getInstance()->getRegister(0) + _args;
                Chip8::getInstance()->setPC(addr);
                break;
             }
         }
         return 1;
     }
     string JmpCode::disassemble() {
         ostringstream str;
         str << _label;
         switch(this->_op) {
             case JMP: {
                 str << hex << _args << endl;
                 break;
             }
             case JPV: {
                 str << "V0," << hex << _args << endl; 
                 break;
             }
         }
         

         return str.str();
     }