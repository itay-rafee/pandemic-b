#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{

    class Player
    {


    public:
        Board& board;
        City city;
        std::set<City> cards;
        std::set<Color> meditions;
        std::string rol;
        Player(Board &b, City c, std::string r = "Player") : board(b), city(c), rol(r){};

        Player &take_card(City c);
        Player &drive(City c);
        virtual Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        virtual void fly(City c){};
        std::string role();
    };
};