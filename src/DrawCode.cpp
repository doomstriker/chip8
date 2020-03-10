#include "DrawCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int DrawCode::execute(Cpu &) {
        int vx = this->_args >> 8;
        int vy = ((this->_args  >> 4) & 0x0f);
        int n = this->_args & 0x01;
         return 1;
     }
     string DrawCode::disassemble() {
        ostringstream str;
        int vx = this->_args >> 8;
        int vy = ((this->_args  >> 4) & 0x0f);
        int n = this->_args & 0x0F;
 
        str << _label << "V"<< vx << ",V" << vy << "," << hex << n << endl;
         return str.str();
     }