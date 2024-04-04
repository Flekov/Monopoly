#include "player.h"

void Player::buyProperty()
{
    if (cash < current->getPrice() || current->bought())
    {
        std::cout << "No!\n";
        return;
    }

    current->setIsBought();
    current->setOwner(name);
    properties.push_back(current);
    cash -= current->getPrice();
}

void Player::printProperties()
{
    for (Square *s : properties)
    {
        s->printSquare();
    }
}

void Player::printAvenueProperties()
{
    for (Square *s : properties)
    {
        if (s->getType() != UTILITY && s->getType() != STATION)
        {
            s->printSquare();
        }
    }
}

void Player::printPlayer()
{
    std::cout << "========================\n"
              << name << std::endl
              << cash << std::endl;
    printProperties();
    std::cout << "========================\n";
}

int Player::rollDice()
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

void Player::giveRent(Player &pb)
{
    cash -= current->rent();
    pb.cash += current->rent();
}

void Player::buyHouse(int propertyNum)
{
    if (propertyNum < properties.size() && propertyNum >= 0)
    {
        properties[propertyNum]->setHouses(properties[propertyNum]->getHouses() + 1);
        cash -= 100;
        std::cout << "You bought successfully!\n";
        return;
    }
    std::cout << "Invalid number!\n";
}

bool Player::haveProperties()
{
    return !(properties.empty());
}
