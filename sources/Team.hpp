#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include "Character.hpp"

using namespace std;
const int MAX_TEAM_SIZE = 10;
namespace ariel{
    class Team{// a team of up to 10 characters
        protected:
            // Character** team;
            // Character* leader;
        public:
            vector<Character*> team;
            Character* leader;
            Team(Character* leader);
            // Team(const Team& other);
            virtual void add(Character* warrior);
            virtual void attack(Team* other);
            virtual int stillAlive() const;
            virtual void print() const;
            void replaceLeader();
            Character* choosePrey(Team* other);
            ~Team();
    };
    class Team2 : public Team{
        private:
            // Character** team;
            // Character* leader;
        public:
            Team2(Character* leader);
            void add(Character* warrior);
            void attack(Team* other);
            int stillAlive() const;
            void print() const;
            ~Team2();
    };
    class SmartTeam : public Team{
        private:
            // Character** team;
            // Character* leader;
        public:
            SmartTeam(Character* leader);
            void add(Character* warrior);
            void attack(Team* other);
            int stillAlive() const;
            void print() const;
            // ~SmartTeam();
    };
}
    
