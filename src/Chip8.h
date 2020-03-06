#pragma once
#include <stdint.h>
#include <stack>
#include <iostream>
#include <string.h>
#include "Cpu.h"

using namespace std;
class Chip8 : public Cpu {
    public:

    uint8_t getRegister(uint8_t reg) {
        return _registers[reg & 0xf];
    }
     void setRegister(uint8_t reg,uint8_t val) {
         if (reg > sizeof(_registers)) { //array len
             return;
         }
         _registers[reg] = val;
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
    Chip8() { memset(_registers, 0, sizeof(_registers));
    _registers[0]=1;
    cout<< "Reg:" << _registers[0] << endl;
    } //private 
};