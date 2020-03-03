/**
 * Name: OpCodeFactory
 * Description:  OpCodes Factory
 **/
#include "Cpu.h"
#include "OpCode.h"
#include <string>

using namespace std;
class OpCodeFactory {
    public:
   static OpCode* createOpCode(unsigned int);
   static OpCode* createOpCode(const string &);
};