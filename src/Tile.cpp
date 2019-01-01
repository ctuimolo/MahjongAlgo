#include "../headers/Tile.hpp"

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
    }
}