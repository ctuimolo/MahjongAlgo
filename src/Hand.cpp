#include "../headers/Hand.hpp"

Hand::Hand() {
   
}

Hand::~Hand() {
    for ( Tile* tile : tiles ) {
        delete tile;
    }
}

void Hand::drawHand(std::vector<Tile*>& wall) {

    for ( int i = 0; i < 13; i++ ) {
        tiles.push_back( wall.back() );
        wall.pop_back();
    }
}

void Hand::draw(std::vector<Tile*>& wall) {
    drawnTile = wall.back();
    wall.pop_back();
}

void Hand::print() {
    for ( Tile* tile : tiles ) {
        tile->print();
        std::cout << " ";
    }
    std::cout << ":[";
    drawnTile->print();
    std::cout << "]" << std::endl;
}