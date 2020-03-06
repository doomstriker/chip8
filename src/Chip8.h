#pragma once
#include <stdint.h>
#include <stack>
#include "Cpu.h"

using namespace std;
class Chip8 : public Cpu {
    public:

    uint8_t getRegister(uint8_t reg) {
        //if value > f , invalid so masking to 0
        return _registers[reg & 0xf];
    }
        void setIndex(uint16_t index) { this->_index = index;}
    //Singleton 
    static Chip8* getInstance() {
        _instance = (_instance == nullptr ? new Chip8() : _instance);
        return _instance; 
    }
    private:
        //program counter
        uint16_t _pc;
        //stack pointer
        stack<uint8_t> _sp;
        //index
        uint16_t _index;
        //registers
        uint8_t _registers[16];
        static Chip8* _instance;
    Chip8(); //private 
};