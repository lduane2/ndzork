#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>


class Player {
    public:
        // Actions
        void take();
        void drop();
        void light();
        string examine();
        
        void move(string direction);
        
        void attack();
        string help();
    
    private:
        int health;
        int position;
        vector<string> inventory;
    
};
#endif
