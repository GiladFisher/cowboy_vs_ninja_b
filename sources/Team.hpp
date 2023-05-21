#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"

using namespace std;

namespace ariel{
    class Team{// a team of up to 10 characters
        private:
            
        public:
            Character** team;
            Character* leader;
            Team(Character* leader);
            // Team(const Team& other);
            void add(Character* warrior);
            void attack(Team* other);
            int stillAlive() const;
            void print() const;
            // ~Team();
    };
    class Team2{
        private:
            Character** team;
            Character* leader;
        public:
            Team2(Character* leader);
            void add(Character* warrior);
            void attack(Team2* other);
            int stillAlive() const;
            void print() const;
            // ~Team2();
    };
    class SmartTeam{
        private:
            Character** team;
            Character* leader;
        public:
            SmartTeam(Character* leader);
            void add(Character* warrior);
            void attack(SmartTeam* other);
            int stillAlive() const;
            void print() const;
            // ~SmartTeam();
    };
}
    
