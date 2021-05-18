#include "Researcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include<array>
using namespace std;
const int for_discover_cure = 5;

namespace pandemic
{
        Player &Researcher::discover_cure(Color c)
        {
                if (meditions.count(c) != 0)
                {
                        return *this;
                }

                int i = 0;
                for (const auto &card : cards)
                {
                        if (Board::color_of(card) == c)
                        {
                                i++;
                        }
                }
                if (i < for_discover_cure)
                {
                        throw invalid_argument("Not enough cards");
                }
                for (auto it = cards.begin(); it != cards.end(); i++)
                {
                        if (i == for_discover_cure){break;}
                        if (Board::color_of(*it) == c){it = cards.erase(it);}
                        else{++it;}
                }
                board.mark_cured(c);
                meditions.insert(c);
                return *this;
        }
};