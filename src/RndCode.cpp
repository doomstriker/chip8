#include "RndCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int RndCode::execute(Cpu &) {
         return 1;
     }
     string RndCode::disassemble() {
         ostringstream str;
         int vx = this->_args >> 8;
         int val = this->_args & 0xff;
 
         str << _label << "V" << hex << vx << ","<<val<<endl;
         //generate random number
         int reg = (rand() % 256) & val;
         
         return str.str();
     }