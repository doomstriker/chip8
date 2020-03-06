#include "ClsCode.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
    // execute the OPCode instruction
     int ClsCode::execute(Cpu &) {
         return 1;
     }
     string ClsCode::disassemble() {
         ostringstream str;

         str << _label << endl;

         return str.str();
     }