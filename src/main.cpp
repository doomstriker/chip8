#include "OpCodeFactory.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
int main2(int argc, char **argv) {

   int cmd = 0x10AF;
   string fileName = "";
   //vector<uint8_t> data;

if(argc == 2 ) {
  fileName = argv[1];
} else {
  cout << "chip8Emulator <RomfileName>" <<endl;
  return -1;
}


  // open the file:
   
    cout << "Reading " << fileName << endl;
  
   FILE* romFile = fopen(fileName.c_str(), "r");
    int16_t instr = 0;
    int j = 0;
  
   std::ifstream stream(fileName, std::ios::in | std::ios::binary);
std::vector<uint8_t> data((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
// for(auto i: data) {
//     int value = i;
//    // std::cout << "data["<<++j<<"]=" << hex<<value << std::endl;
// }

std::cout << "file size: " << data.size() << std::endl;
   cout<<"Processed "<< hex << data.size()<<endl;
   
    for(int i = 0 ; i < data.size();)  {
      uint32_t myinstr =(( data[i] <<8 )| (data[i+1] ));
   //   printf("%d=%0x\n",i,myinstr);
      //cout << i << " " << hex << myinstr << endl;
      OpCode* op = OpCodeFactory::createOpCode(myinstr);
      if (op != NULL ) {
        cout << hex << (0x200 + i ) << "    "<< op->disassemble();
      }
      i+=2; 
    }
    

}