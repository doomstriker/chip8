/**
 * Name: OpCode
 * Description: Interface to handle OpCodes 
 **/

#include <string>

using namespace std;
class OpCode {
    public:
    // execute the OPCode instruction
     virtual int execute(Cpu &) = 0;
     virtual string disassemble() = 0;
};