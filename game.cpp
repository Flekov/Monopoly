#include "squares.h"
#include "player.h"

#include <iostream>
#include <string>

const int BOARD_SIZE = 40;

Square go = {"GO", 0, 50000, GO, "text"};
Square first_brown = {"Mediterranean Avenue", 1, 60, BROWN, "text"};
Square first_com_chest = {"Community Chest", 2, 50000, COMMUNITY_CHEST, "text"};
Square second_brown = {"Baltic Avenue", 3, 60, BROWN, "text"};
Square first_tax = {"Income tax", 4, 50000, TAX, "text"};
Square first_station = {"Sofia Railroad", 5, 200, STATION, "text"};
Square first_sky = {"Oriental Avenue", 6, 100, SKY_BLUE, "text"};
Square first_chance = {"Chance", 7, 60, CHANCE, "text"};
Square second_sky = {"Vermont Avenue", 8, 100, SKY_BLUE, "text"};
Square third_sky = {"Connecticut Avenue", 9, 120, SKY_BLUE, "text"};
Square jail = {"Jail", 10, 50000, JAIL, "text"};
Square first_pink = {"St. Charles Place", 11, 140, PINK, "text"};
Square first_ut = {"Electric Company", 12, 150, UTILITY, "text"};
Square second_pink = {"States Avenue", 13, 140, PINK, "text"};
Square third_pink = {"Virginia Avenue", 14, 160, PINK, "text"};
Square second_station = {"Plovidv Railroad", 15, 200, STATION, "text"};
Square first_orange = {"St. James Place", 16, 180, ORANGE, "text"};
Square second_com_chest = {"Community Chest", 17, 50000, COMMUNITY_CHEST, "text"};
Square second_orange = {"Tennessee Avenue", 18, 180, ORANGE, "text"};
Square third_orange = {"New York Avenue", 19, 200, ORANGE, "text"};
Square free_park = {"Free Parking", 20, 50000, FREE_PARKING, "text"};
Square first_red = {"Kentucky Avenue", 21, 220, RED, "text"};
Square second_chance = {"Chance", 22, 50000, CHANCE, "text"};
Square second_red = {"Indiana Avenue", 23, 220, RED, "text"};
Square third_red = {"Illinois Avenue", 24, 240, BROWN, "text"};
Square third_station = {"Varna Railroad", 25, 200, STATION, "text"};
Square first_yellow = {"Atlantic Avenue", 26, 260, YELLOW, "text"};
Square second_yellow = {"Ventnor Avenue", 27, 260, YELLOW, "text"};
Square second_ut = {"Water Company", 28, 150, UTILITY, "text"};
Square third_yellow = {"Marvin Gardens", 29, 280, YELLOW, "text"};
Square to_jail = {"Go To Jail", 30, 50000, TO_JAIL, "text"};
Square first_green = {"Pacific Avenue", 31, 300, GREEN, "text"};
Square second_green = {"North Carolina Avenue", 32, 300, GREEN, "text"};
Square third_com_chest = {"Community Chest", 33, 50000, COMMUNITY_CHEST, "text"};
Square third_green = {"Pennsylvania Avenue", 34, 320, GREEN, "text"};
Square forth_station = {"Burgas Railroad", 35, 200, STATION, "text"};
Square third_chance = {"Chance", 36, 50000, CHANCE, "text"};
Square first_blue = {"Park Place", 37, 350, BLUE, "text"};
Square second_tax = {"Luxury Tax", 38, 50000, TAX, "text"};
Square second_blue = {"Boardwalk", 39, 400, BLUE, "text"};

Square board[BOARD_SIZE] = {
    go,
    first_brown,
    first_com_chest,
    second_brown,
    first_tax,
    first_station,
    first_sky,
    first_chance,
    second_sky,
    third_sky,
    jail,
    first_pink,
    first_ut,
    second_pink,
    third_pink,
    second_station,
    first_orange,
    second_com_chest,
    second_orange,
    third_orange,
    free_park,
    first_red,
    second_chance,
    second_red,
    third_red,
    third_station,
    first_yellow,
    second_yellow,
    second_ut,
    third_yellow,
    to_jail,
    first_green,
    second_green,
    third_com_chest,
    third_green,
    forth_station,
    third_chance,
    first_blue,
    second_tax,
    second_blue};

/*Square board[BOARD_SIZE] = {
    go,
    first_brown,
    second_brown,
};*/

int main()
{
    int numberOfPlayers;
    std::cout << "Number of players: ";
    std::cin >> numberOfPlayers;

    std::vector<Player> players;
    for (int i = 0; i < numberOfPlayers; ++i)
    {
        std::string name;
        std::cout << "Player_" << i + 1 << " name: ";
        std::cin >> name;

        Player p{name, board[0]};
        players.push_back(p);
    }

    // while (players.size() > 1)
    for (int i = 0; i < 3; ++i)
    {
        for (Player &p : players)
        {
            std::cout << p.getName() << ':' << std::endl;
            p.getCurrent()->printSquare();
            std::cout << '>';

            std::string command;
            std::cin >> command;

            while (command != "end")
            {
                if (command == "buy")
                {
                    p.buyProperty();
                    p.getCurrent()->printSquare();
                }
                else if (command == "dice")
                {
                    int dice = p.rollDice();
                    std::cout << dice << std::endl;
                    if (p.getCurrent()->getNumber() + dice < BOARD_SIZE) // dice 1
                    {
                        p.setCurrent(board[p.getCurrent()->getNumber() + dice]); // dice 1
                        p.getCurrent()->printSquare();
                    }
                    else
                    {
                        p.setCurrent(board[BOARD_SIZE - (p.getCurrent()->getNumber() + dice)]); // dice 1
                        p.getCurrent()->printSquare();
                    }

                    if (p.getCurrent()->bought() && p.getCurrent()->getOwner() != p.getName())
                    {
                        for (Player &pb : players)
                        {
                            if (p.getCurrent()->getOwner() == pb.getName())
                            {
                                p.giveRent(pb);
                                std::cout << "You lost " << p.getCurrent()->rent() << "$!\n";
                                break;
                            }
                        }
                    }
                }
                else if (command == "status")
                    p.printPlayer();
                else if (command == "house" && p.haveProperties())
                {
                    std::cout << "Where?\n";
                    p.printAvenueProperties();

                    int num;
                    std::cout << '>';
                    std::cin >> num;

                    p.buyHouse(num - 1);
                }
                else
                    std::cout << "Incorect command!\n";

                std::cout << '>';
                std::cin >> command;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

// player moje da kupuva ot dyskata propertita - gotovo
// znae se koi e ownera - gototo
// cqlata karta - gotovo
// zarche - gotovo
// kyshti - pochti gotovo
// da moje samo kogato imash vsichki ot edin cvqt
// funcionalnost na poletata // za naema - int rent() { swhitch(houses) ... } v squares
// asset money
// auction
// trade
// prodavane
// umirane
// textove