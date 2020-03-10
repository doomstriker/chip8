#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include "Cpu.h"

using namespace std;
class Screen {
    public:
        /**
         * Clear the screen
         **/
        void clearScreen();
        int drawSprite(uint32_t x,uint32_t y, const vector<uint8_t> &data);
};