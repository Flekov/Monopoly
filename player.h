#pragma once

#include "squares.h"

#include <iostream>
#include <string>

class Player
{
public:
    Player() : name("Player"), cash(0) {}
    Player(std::string nameVal, Square &start) : name(nameVal), cash(1500), current(&start) {}
    void setCurrent(Square &s) { current = &s; }
    Square *getCurrent() { return current; }
    std::string getName() { return name; }
    int getCash() { return cash; }

    void buyProperty();
    void printProperties();
    void printAvenueProperties();
    void printPlayer();
    int rollDice();
    void giveRent(Player &pb);
    void buyHouse(int propertyNum);
    bool haveProperties();

private:
    std::string name;
    int cash;
    Square *current;
    std::vector<Square *> properties;
};