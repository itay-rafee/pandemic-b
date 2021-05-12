#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <map>
#include <set>
#include <iostream>

using namespace std;
static map<City, set<City>> neighbors{
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }};
static map<City, Color> city_color{
    { Algiers, Black },
    { Atlanta, Blue },
    { Baghdad, Black },
    { Bangkok, Red },
    { Beijing, Red },
    { Bogota, Yellow },
    { BuenosAires, Yellow },
    { Cairo, Black },
    { Chennai, Black },
    { Chicago, Blue },
    { Delhi, Black },
    { Essen, Blue },
    { HoChiMinhCity, Red },
    { HongKong, Red },
    { Istanbul, Black },
    { Jakarta, Red },
    { Johannesburg,Yellow },
    { Karachi, Black },
    { Khartoum, Yellow },
    { Kinshasa, Yellow },
    { Kolkata, Black },
    { Lagos, Yellow },
    { Lima, Yellow },
    {London, Blue },
    { LosAngeles, Yellow },
    { Madrid, Blue },
    { Manila, Red },
    { MexicoCity, Yellow },
    { Miami, Yellow },
    { Milan, Blue },
    { Montreal, Blue },
    { Moscow, Black },
    { Mumbai, Black },
    { NewYork,Blue },
    { Osaka, Red },
    {Paris, Blue },
    { Riyadh, Black },
    { SanFrancisco, Blue },
    { Santiago, Yellow },
    { SaoPaulo, Yellow },
    { Seoul, Red },
    { Shanghai, Red },
    { StPetersburg, Blue },
    { Sydney, Red },
    { Taipei, Red },
    { Tehran, Black },
    { Tokyo, Red },
    { Washington, Blue }};


namespace pandemic
{


    void Board::remove_cures()
    {
        medicines.clear();
    }

    int &Board::operator[](City c)
    {
        return cubesOfDiseas[c];
    }
    bool Board::is_clean()
    {
        for (auto& dis : cubesOfDiseas)
        {
            if (dis.second > 0)
            {
                return false;
            }
        }
        return true;
    }
    bool Board::is_connected(City &c1, City &c2)
    {
        if (neighbors.count(c1) != 0)
        {
            if (neighbors[c1].count(c2) != 0)
            {
                return true;
            }
        }
        return false;
    }
    void Board::build_research_station(City c)
    {
        researchStations.insert(c);
    }
    bool Board::is_research_station(City c)
    {
        return researchStations.count(c) != 0;
    }
    void Board::mark_cured(Color c)
    {
        medicines.insert(c);
    }
    bool Board::is_cure_discoverd(City c)
    {
        return medicines.count(color_of(c)) != 0;
    }
    Color Board::color_of(City c)
    {
        return city_color.at(c);
    }
    std::ostream &operator<<(std::ostream &out, Board &b)
    {
        return out;
    }

};
