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
   //vector<uint8_t> data;

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
    int16_t instr = 0;
    int j = 0;
  /*  while(true)
   {
      instr = fgetc(romFile);
 cout << "j="<<++j << " " << instr << " l="<< hex<< instr <<"s:"<< data.size() << endl;
      if (feof(romFile))
      {
        fclose(romFile);
         break;
      }
      data.push_back(instr);
   } */
   std::ifstream stream(fileName, std::ios::in | std::ios::binary);
std::vector<uint8_t> data((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
for(auto i: data) {
    int value = i;
    std::cout << "data["<<++j<<"]=" << hex<<value << std::endl;
}

std::cout << "file size: " << data.size() << std::endl;
   cout<<"Processed "<< hex << data.size()<<endl;
    for(int i = 0 ; i < data.size();)  {
      uint32_t myinstr =(( data[i] <<8 )| (data[i+1] ));
      printf("%d=%0x\n",i,myinstr);
      //cout << i << " " << hex << myinstr << endl;
      OpCode* op = OpCodeFactory::createOpCode(myinstr);
      if (op != NULL ) {
        cout << op->disassemble();
      }
      i+=2; 
    }

}