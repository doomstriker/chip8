#include "JmpCode.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
    // execute the OPCode instruction
     int JmpCode::execute(Cpu &) {
         return 1;
     }
     string JmpCode::disassemble() {
         ostringstream str;

         str << _label << " " << hex << _args;

         return str.str();
     }