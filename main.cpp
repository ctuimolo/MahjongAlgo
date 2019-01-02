// Start Mahjong App
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <windows.h>
#include "./headers/Tile.hpp"
#include "./headers/Hand.hpp"

int main () {

    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 15);

    std::cout << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << "=                         ";

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);

    std::cout << "C";

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 15);

    std::cout << "UTE <3 F";

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);

    std::cout << "UNNY ";

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 15);

    std::cout << "MAHJONG                        =" << std::endl;
    std::cout << "========================================================================" << std::endl;


    std::cout << std::endl;

    std::vector<Tile*> wall;

    // Build a wall array of 136, 4x each unique tile
    for( int i = 0; i < 34; i++) {
        for( int j = 0; j < 4; j++ ) {
            Tile* newTile = new Tile(i + 1);
            wall.push_back(newTile);
        }
    }

    // Chrono randomizer and shuffle wall
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(wall.begin(), wall.end(), std::default_random_engine(seed));

    /*for(Tile* tile : wall) {
        tile->print();
        std::cout << std::endl;
    }*/

    Hand* hand = new Hand();
    hand->drawHand(wall);
    hand->draw(wall);
    hand->print();

    std::cout << std::endl << "> Parse Islands : " << std::endl << std::endl;
    hand->parseHand();
    std::cout << std::endl;

    for( Tile* tile : wall ) {
        delete tile;
    }

    delete hand;

    return 0;
}