#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Tile.hpp"

class Hand {

private:
public:
    std::vector<Tile*> tiles;
    Tile* drawnTile = nullptr;

public:
    Hand();
    ~Hand();
    void drawHand(std::vector<Tile*>& wall);
    void draw(std::vector<Tile*>& wall);
    void print();
};

#endif