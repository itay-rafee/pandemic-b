#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
namespace pandemic{
    Player& OperationsExpert::build(){
        if (!board.is_research_station(city)){board.build_research_station(city);}
        return *this;
    }
};