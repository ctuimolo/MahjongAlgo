// Start Mahjong App
#include <iostream>
#include <vector>
#include "./headers/Tile.hpp"

int main () {

    std::vector<Tile*> wall;

    // Build a wall array of 136, 4x each unique tile
    for( int i = 0; i < 34; i++) {
        for( int j = 0; j < 4; j++ ) {
            Tile* newTile = new Tile(i + 1);
            wall.push_back(newTile);
            std::cout << newTile->toString() << std::endl;
        }
    }

    for( Tile* tile : wall ) {
        delete tile;
    }

    return 0;
}