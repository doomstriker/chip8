#include "CallCode.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Chip8.h"

using namespace std;
    // execute the OPCode instruction
     int CallCode::execute(Cpu &) {
        uint8_t cpc = Chip8::getInstance()->getPC();
        //Chip8::getInstance()->getSP().push(cpc);
        //Chip8::getInstance()->setRegister(vx,vyVal);
         
         return 1;
     }

     string CallCode::disassemble() {
        ostringstream str;

        str << _label << hex << _args << endl;
         
         return str.str();
     }