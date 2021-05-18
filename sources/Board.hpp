#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic {

    class Board {
        private:
        std::map<City, int> cubesOfDiseas;
        std::set<City> researchStations;
        std::set<Color> medicines;

        public:
            Board() {}

            void remove_cures();
            int& operator[](City c);
            bool is_clean();
            static bool is_connected(City& c1, City& c2);
            void build_research_station(City c);
            bool is_research_station(City c);
            void mark_cured(Color c);
            bool is_cure_discoverd(City c);
            static Color color_of(City c);
            friend std::ostream& operator<<(std::ostream& out, Board& b);
    };



}