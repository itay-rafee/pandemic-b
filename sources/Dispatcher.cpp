#include"Dispatcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic{
    Player& Dispatcher::fly_direct(City c){

        if (city == c)
        {
            throw invalid_argument("same city!");
 
        }
        
        if(board.is_research_station(city)){
            city = c;
            return *this;
        }
        
        if (cards.count(c) != 0)
        {
                city = c;
                cards.erase(c);
        }
        else
        {
                throw invalid_argument("Not in the cards!");
        }
        return *this;
    }
};