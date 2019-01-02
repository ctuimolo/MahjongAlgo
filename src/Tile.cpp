#include "../headers/Tile.hpp"
#include <windows.h>
#include <iostream>

Tile::Tile(int _ID) {
    // it's a man
    if(_ID >= 1 && _ID <= 9) {
        ID = _ID;
        suit = man;
        numValue = NumValue(_ID);
        dragonValue = DragonValue::nulldragon;
        windValue = WindValue::nullwind;
    // it's a pin
    } else if(_ID >= 10 && _ID <= 18) {
        ID = _ID;
        suit = pin;
        numValue = NumValue(_ID - 9 );
        dragonValue = DragonValue::nulldragon;
        windValue = WindValue::nullwind;
    // it's a sou
    } else if(_ID >= 19 && _ID <= 27) {
        ID = _ID;
        suit = sou;
        numValue = NumValue(_ID - 18);
        dragonValue = DragonValue::nulldragon;
        windValue = WindValue::nullwind;
    // it's a dragon
    } else if (_ID >= 28 && _ID <= 30) {
        ID = _ID;
        suit = Suit::nullsuit;
        numValue = NumValue::nullnum;
        dragonValue = DragonValue(_ID - 27);
        windValue = WindValue::nullwind;
    // it's a wind
    } else if (_ID >= 31 && _ID <= 34) {
        ID = _ID;
        suit = Suit::nullsuit;
        numValue = NumValue::nullnum;
        dragonValue = DragonValue::nulldragon;
        windValue = WindValue(_ID - 30);
    }
}

std::string Tile::toString() {
    // it's a man, sou, or pin
    if(ID >= 1 && ID <= 27) {
        return NumValueStrings[numValue] + " " + SuitStrings[suit];
    // it's a dragon
    } else if (ID >= 28 && ID <= 30) {
        return DragonValueStrings[dragonValue] + " dragon";
    // it's a wind
    } else if (ID >= 31 && ID <= 34) {
        return WindValueStrings[windValue] + " wind";
    } else {
        return "invalid tile ID";
    }
}

void Tile::print() {
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 1);
    
    // Little Print
    // it's a man
    if(ID >= 1 && ID <= 9) {
        SetConsoleTextAttribute(console, 4 + 15*16);
        std::cout << " " << ID << "M ";
    // it's a pin
    } else if(ID >= 10 && ID <= 18) {
        SetConsoleTextAttribute(console, 1 + 15*16);
        std::cout << " " << ID - 9 << "P ";
    // it's a sou
    } else if(ID >= 19 && ID <= 27) {
        SetConsoleTextAttribute(console, 2 + 15*16);
        std::cout << " " << ID - 18 << "S ";
    // it's a white dragon
    } else if (ID == 28) {
        SetConsoleTextAttribute(console, 7 + 15*16);
        std::cout << " WD ";
    // it's a green dragon
    } else if (ID == 29) {
        SetConsoleTextAttribute(console, 2 + 15*16);
        std::cout << " GD ";
    // it's a red dragon
    } else if (ID == 30) {
        SetConsoleTextAttribute(console, 4 + 15*16);
        std::cout << " RD ";
    // it's a wind
    } else if (ID >= 31 && ID <= 34) {
        SetConsoleTextAttribute(console, 1 + 15*16);
        if(ID == 31) {
            std::cout << " E";
        } else if (ID == 32) {
            std::cout << " S";
        } else if (ID == 33) {
            std::cout << " W";
        } else if (ID == 34) {
            std::cout << " N";
        }
        std::cout << "W ";
    }

    // Big Print
    /*// it's a man
    if(ID >= 1 && ID <= 9) {
        SetConsoleTextAttribute(console, 4);
        std::cout << NumValueStrings[numValue] + " " + SuitStrings[suit];
    // it's a pin
    } else if(ID >= 10 && ID <= 18) {
        SetConsoleTextAttribute(console, 3);
        std::cout << NumValueStrings[numValue] + " " + SuitStrings[suit];
    // it's a sou
    } else if(ID >= 19 && ID <= 27) {
        SetConsoleTextAttribute(console, 10);
        std::cout << NumValueStrings[numValue] + " " + SuitStrings[suit];
    // it's a white dragon
    } else if (ID == 28) {
        SetConsoleTextAttribute(console, 15);
        std::cout << DragonValueStrings[dragonValue] + " dragon";
    // it's a green dragon
    } else if (ID == 29) {
        SetConsoleTextAttribute(console, 2);
        std::cout << DragonValueStrings[dragonValue] + " dragon";
    // it's a red dragon
    } else if (ID == 30) {
        SetConsoleTextAttribute(console, 5);
        std::cout << DragonValueStrings[dragonValue] + " dragon";
    // it's a wind
    } else if (ID >= 31 && ID <= 34) {
        SetConsoleTextAttribute(console, 1);
        std::cout << WindValueStrings[windValue] + " wind";
    }*/

    SetConsoleTextAttribute(console, 15);
}