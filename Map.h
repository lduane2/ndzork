#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Map {
    public:
        
        // Pointers for map pieces
        Map* left;
        Map* right;
        Map* up;
        Map* down;
    
    private:
        string map_state;
        vector<string> map_items;
};
#endif
