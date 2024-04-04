#include "squares.h"

std::string Square::printType(types type)
{
    switch (type)
    {
    case UTILITY:
        return "UTILITY";
        break;
    case STATION:
        return "STATION";
        break;
    case BROWN:
        return "BROWN";
        break;
    case SKY_BLUE:
        return "SKY BLUE";
        break;
    case PINK:
        return "PINK";
        break;
    case ORANGE:
        return "ORANGE";
        break;
    case RED:
        return "RED";
        break;
    case YELLOW:
        return "YELLOW";
        break;
    case GREEN:
        return "GREEN";
        break;
    case BLUE:
        return "BLUE";
        break;
    case CHANCE:
        return "CHANCE";
        break;
    case COMMUNITY_CHEST:
        return "COMMUNITY CHEST";
        break;
    case TAX:
        return "TAX";
        break;
    case GO:
        return "GO";
        break;
    case TO_JAIL:
        return "TO JAIL";
        break;
    case JAIL:
        return "JAIL";
        break;
    case FREE_PARKING:
        return "FREE PARKING";
        break;
    }
}

void Square::printSquare()
{
    std::string typeVal = printType(type);

    std::cout << "--------------------\n";
    switch (type)
    {
    case UTILITY:
    case STATION:
        std::cout << name << std::endl
                  << typeVal << std::endl
                  << price << std::endl;
        if (owner != "")
            std::cout << owner << std::endl;
        else
            std::cout << "No owner." << std::endl;
        break;
    case BROWN:
    case SKY_BLUE:
    case PINK:
    case ORANGE:
    case RED:
    case YELLOW:
    case GREEN:
    case BLUE:
        std::cout << name << std::endl
                  << typeVal << std::endl
                  << price << std::endl;
        if (owner != "")
        {
            std::cout << houses << " houses\n"
                      << owner << std::endl;
        }
        else
            std::cout << "No owner." << std::endl;
        break;
    case CHANCE:
    case COMMUNITY_CHEST:
    case TAX:
    case GO:
    case TO_JAIL:
    case JAIL:
    case FREE_PARKING:
        std::cout << name << std::endl;
        break;
    }
    std::cout << "--------------------\n";
}

bool Square::bought()
{
    return isBought;
}

int Square::rent()
{
    switch (houses)
    {
    case 0:
        return 14;

    case 1:
        return 70;

    case 2:
        return 200;

    case 3:
        return 550;

    case 4:
        return 750;

    case 5:
        return 950;
    }
    return 0;
};
