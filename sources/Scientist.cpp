#include"Scientist.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;


namespace pandemic{

    Player &Scientist::discover_cure(Color c)
        {
        if (meditions.count(c) != 0){return *this;}
        
        if (board.is_research_station(city))
        {
                int i = 0;
                for(const auto &card: cards){
                        if (Board::color_of(card) == c)
                        {
                                i++;
                        }
                }
                if (i < num)
                {
                throw invalid_argument("Not enough cards");        
                }
                for (auto it = cards.begin(); it != cards.end(); i++)
                {
                        if (i == num){break;}
                        if (Board::color_of(*it) == c){it = cards.erase(it);}
                        else{++it;}
                }
                board.mark_cured(c);
                meditions.insert(c);
                return *this;
        }
        throw invalid_argument("Not heve research station");        
    }
};