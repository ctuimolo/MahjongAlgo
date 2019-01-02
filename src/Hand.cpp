#include "../headers/Hand.hpp"
#include <algorithm>

Hand::Hand() {
   
}

Hand::~Hand() {
    for ( Tile* tile : tiles ) {
        delete tile;
    }
    for ( Meld* meld : melds ) {
        delete meld;
    }
    delete drawnTile;
}

bool Hand::compareTile(Tile*& current, Tile*& next) {
    return current->ID < next->ID;
}

void Hand::drawHand(std::vector<Tile*>& wall) {

    for ( int i = 0; i < 13; i++ ) {
        tiles.push_back( wall.back() );
        wall.pop_back();
    }
    
    std::sort(tiles.begin(), tiles.end(), compareTile);
}

void Hand::draw(std::vector<Tile*>& wall) {
    drawnTile = wall.back();
    wall.pop_back();
}

void Meld::addTile(Tile* newTile) {
    switch(size) {
        case 0 :
            first = newTile;
            break;
        case 1 :
            second = newTile;
            break;
        case 2 :
            third = newTile;
    }
    size++;
}

void Hand::findMeldTriplet(std::vector<Meld*>& melds, int indexStart) {

    Meld* meld = new Meld();
    meld->first = tiles.at(indexStart);
    
    if ( indexStart <= 11 && tiles.at(indexStart + 1)->ID == meld->first->ID) {
        meld->second = tiles.at(indexStart + 1);
        if ( indexStart <= 10 && tiles.at(indexStart + 2)->ID == meld->first->ID) {
            meld->third = tiles.at(indexStart + 2);
            melds.push_back(meld);
            if(indexStart + 3 < 13) {
                findMeldTriplet(melds, indexStart + 3);
                return;
            }
            return;
        } 
        melds.push_back(meld);
        if(indexStart + 2 < 13) {
            findMeldTriplet(melds, indexStart + 2);
            return;
        }
        return;
    } 
    melds.push_back(meld);
    if(indexStart + 1 < 13) {
        findMeldTriplet(melds, indexStart + 1);
        return;
    }
    return;
}

void Hand::parseHand() {
    
    // RECURSIVE CALL
    findMeldTriplet(melds, 0);
    
    for ( Meld* meld : melds ) {
        meld->first->print();
        if(meld->second != NULL) meld->second->print();
        if(meld->third!= NULL) meld->third->print();
        std::cout << " ";
    }

    // PROCEDURAL CALL
    /*Meld* tmpMeld = new Meld();

    for( int i = 0; i < 13; i++ ) {

        if (tmpMeld->size < 3) {
            
            if(tmpMeld->size == 0 || tmpMeld->first->ID == tiles.at(i)->ID) {
                tmpMeld->addTile(tiles.at(i));                
            } else {
                melds.push_back(tmpMeld);
                tmpMeld = new Meld();
                tmpMeld->addTile(tiles.at(i));
            }
            
        } else if (tmpMeld-> size == 3) {
            melds.push_back(tmpMeld);
            tmpMeld = new Meld();
            tmpMeld->addTile(tiles.at(i));
        }

        if (i == 12 ) {
            melds.push_back(tmpMeld);
        }
    }

    for ( Meld* meld : melds ) {
        meld->first->print();
        if(meld->second != NULL) meld->second->print();
        if(meld->third!= NULL) meld->third->print();
        std::cout << " ";
    }
    */
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