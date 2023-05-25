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
            virtual Character* choosePrey(Team* other);
            bool isAlive() const;
            virtual ~Team();
    };
    class Team2 : public Team{
        private:
            // Character** team;
            // Character* leader;
        public:
            Team2(Character* leader);
            void add(Character* warrior) override;
            void attack(Team* other) override;
            int stillAlive() const override;
            void print() const override;
            Character* choosePrey(Team* other) override;
            ~Team2() override;
    };
    class SmartTeam : public Team{
        private:
            // Character** team;
            // Character* leader;
        public:
            SmartTeam(Character* leader);
            void add(Character* warrior) override;
            void attack(Team* other) override;
            int stillAlive() const override;
            // void print() override const;
            ~SmartTeam() override;
    };
}
    
