#ifndef TILE_HPP
#define TILE_HPP

#include <string>

enum Suit {
    nullsuit, man, pin, sou
};

enum NumValue {
    nullnum, one, two, three, four, five, six, seven, eight, nine
};

enum DragonValue {
    nulldragon, white, green, red
};

enum WindValue {
    nullwind, east, south, west, north
};

enum Type {
    simple, terminal, honor
};

class Tile {

private:
    std::string SuitStrings[4] =
        { "-none-", "man", "pin", "sou" };
    std::string NumValueStrings[10] = 
        { "-none-", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::string DragonValueStrings[4] =
        { "-none-", "white", "green", "red" };
    std::string WindValueStrings[5] =
        { "-none-", "east", "south", "west", "north" };
    std::string TypeStrings[3] =
        { "simple", "terminal", "honor" };
    int ID;
    Suit suit;
    Type type;
    NumValue numValue;
    DragonValue dragonValue;
    WindValue windValue;

public:
    Tile(int _ID);
    std::string toString();
};

#endif