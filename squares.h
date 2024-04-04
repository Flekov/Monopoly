#pragma once

#include <iostream>
#include <string>

enum types
{
    UTILITY,
    STATION,
    BROWN,
    SKY_BLUE,
    PINK,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    BLUE,
    CHANCE,
    COMMUNITY_CHEST,
    TAX,
    GO,
    TO_JAIL,
    JAIL,
    FREE_PARKING
};

class Square
{
public:
    Square(std::string nameVal, int numberVal, int priceVal, types typeVal, std::string textVal) : name(nameVal), number(numberVal), price(priceVal), type(typeVal), text(textVal), houses(0), isBought(false) {}
    std::string getName() { return name; }
    int getPrice() { return price; }
    int getNumber() { return number; }
    std::string getOwner() { return owner; }
    int getHouses() { return houses; }
    types getType() { return type; }
    void setIsBought() { isBought = true; }
    void setOwner(std::string name) { owner = name; }
    void setHouses(int num) { houses = num; }

    bool bought();
    void printSquare();
    int rent();

private:
    std::string name;
    int number;
    int price;
    types type;
    std::string text;

    bool isBought;
    std::string owner;
    int houses;
    int priceForHouse;

    std::string printType(types type);
};
