#include "OpCodeFactory.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
int main(int argc, char **argv) {

   int cmd = 0x10AF;
   string fileName = "";
   vector<uint8_t> data;

if(argc == 2 ) {
  fileName = argv[1];
} else {
  cout << "chip8Emulator <RomfileName>" <<endl;
  return -1;
}


  // open the file:
    // ifstream file(fileName, std::ios::binary);

    // file.unsetf(std::ios::skipws);

    // streampos fileSize;

    // file.seekg(0, std::ios::end);
    // //only reseve size
    // fileSize = file.tellg();
    // file.seekg(0, std::ios::beg);

    // data.reserve(fileSize);
    cout << "Reading " << fileName << endl;
    // read the data:
    // data.insert(data.begin(),
    //            istream_iterator<uint8_t>(file),
    //            istream_iterator<uint8_t>());
   
   FILE* romFile = fopen(fileName.c_str(), "r");
    uint8_t instr = 0;
    int j = 0;
   while(true)
   {
      instr = fgetc(romFile);
 cout << "j="<<++j << " " << hex << instr << "size:"<< data.size() << endl;
      if (feof(romFile))
      {
         break;
      }
      data.push_back(instr);
   }
   cout<<"Processed "<< hex << data.size()<<endl;
    for(int i = 0 ; i < data.size();)  {
      uint16_t myinstr = data[i] || (data[i+1] << 8);
      cout << i << " " << hex << myinstr << endl;
      OpCode* op = OpCodeFactory::createOpCode(instr);
      if (op != NULL ) {
        cout << op->disassemble();
      }
      i+=2; 
    }

}