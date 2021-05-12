#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include "Player.hpp"

using namespace pandemic;
using namespace std;
const int for_discover_cure = 5;

Player &Player::take_card(City c)
{
        cards.insert(c);
        return *this;
}
Player &Player::drive(City c)
{
        if (board.is_connected(city, c))
        {
                city = c;
        }
        else
        {
                throw invalid_argument("Not Neighbor City");
        }
        fly(city);
        return *this;
}
Player &Player::fly_direct(City c)
{
        if (city == c || cards.count(c) == 0)
        {
                throw invalid_argument("Not in the cards!");
        }
        city = c;
        cards.erase(c);
        fly(city);
        return *this;
}
Player &Player::fly_charter(City c)
{
        if (cards.count(city) != 0)
        {
                cards.erase(city);
                city = c;
        }
        else
        {
                throw invalid_argument("Not in the cards!");
        }
        fly(city);
        return *this;
}
Player &Player::fly_shuttle(City c)
{
        if (city != c && board.is_research_station(city) && board.is_research_station(c))
        {
                city = c;
        }
        else
        {
                throw invalid_argument("there is not research station");
        }
        fly(city);
        return *this;
}
Player &Player::build()
{
        if (board.is_research_station(city))
        {
                return *this;
        }

        if (cards.count(city) != 0)
        {
                board.build_research_station(city);
                cards.erase(city);
        }
        else{
                throw invalid_argument("No card");        
        }

        return *this;
}
Player &Player::discover_cure(Color c)
{
        if (meditions.count(c) != 0){return *this;}
        
        if (board.is_research_station(city))
        {
                int i = 0;
                for(auto &card: cards){
                        if (board.color_of(card) == c)
                        {
                                i++;
                        }
                }
                if (i < for_discover_cure)
                {
                throw invalid_argument("Not enough cards");        
                }
                i = 0;
                City t[for_discover_cure];
                for(auto &card: cards){
                        if (board.color_of(card) == c)
                        {
                                t[i] = card;
                                i++;
                        }
                        if(i == for_discover_cure){break;}
                }
                for (size_t i = 0; i < for_discover_cure; i++)
                {
                        cards.erase(t[i]);
                }
                
                board.mark_cured(c);
                meditions.insert(c);
                return *this;
        }
        throw invalid_argument("Not heve research station");        

}
Player &Player::treat(City c)
{
        if (c == city && board[c] > 0)
        {
                if (board.is_cure_discoverd(c)){board[c] = 0;}
                else{board[c]--;}
                return *this;
        }
        throw invalid_argument("illigel treat");
}
string Player::role() { return rol; }
