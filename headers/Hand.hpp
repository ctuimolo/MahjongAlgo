#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Tile.hpp"

enum MeldType {
    pair, triplet, sequence
};

enum MissingTile {
    sameID, leftID, middleID, rightID 
};

struct Island {

public:
    int size = 0;
    Tile* first;
    Tile* second = NULL;
    MeldType type;
    MissingTile missingTile;
};

struct Meld {
public:
    int size = 0;
    Tile* first;
    Tile* second = NULL;
    Tile* third = NULL;
    MeldType type;
    void addTile(Tile*);
    bool complete = false;
};

class Hand {

private:
    std::vector<Tile*> tiles;
    std::vector< std::vector< Meld* > > allMelds;
    std::vector<Meld*> melds;
    std::vector<Island*> islands;
    Tile* drawnTile = NULL;
    static bool compareTile(Tile*&, Tile*&);
    void findMeldTriplet(std::vector<Meld*>&, int);
    void findMeldSequence(std::vector<Meld*>&, int);

public:
    Hand();
    ~Hand();
    void drawHand(std::vector<Tile*>& wall);
    void draw(std::vector<Tile*>& wall);
    void parseHand();
    void print();
};

#endif