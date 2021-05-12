#include "GeneSplicer.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
const int for_discover_cure = 5;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color c)
    {
        if (meditions.count(c) != 0)
        {
            return *this;
        }

        if (!board.is_research_station(city))
        {
            throw invalid_argument("Not research station");
        }

        int i = 0;
        for (const auto &card : cards)
        {
            i++;
        }
        if (i < for_discover_cure)
        {
            throw invalid_argument("Not enough cards");
        }
        i = 0;
        City t[for_discover_cure];
        for (auto &card : cards)
        {
            t[i] = card;
            i++;
            if (i == for_discover_cure)
            {
                break;
            }
        }
        for (size_t i = 0; i < for_discover_cure; i++)
        {
            cards.erase(t[i]);
        }
        board.mark_cured(c);
        meditions.insert(c);
        return *this;
    }
};