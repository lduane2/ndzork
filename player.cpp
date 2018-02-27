#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player(int start_health, int start_position) {
    health = start_health;
    position = start_position;
}

Player::take(string new_item) {
    inventory.push_back(new_item);
}

Player::drop(string drop_item) {
    //remove item from inventory
    
    //add item to map's items
    
}

Player::light() {
    //depending on postion, change a variable in the map

}

Player::examine() {
    //depending on position, return a string

}

Player::move(string direction) {

}

Player::attack(){

}

Player::help() {
    //print help string
}

