#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#pragma once
using namespace std;
namespace ariel{
    class Character{
        protected:
            Point loc;
            string name;
            int health;
            bool leader;
            bool inteam;
        public:
            bool isInTeam() const;
            void setInTeam();
            bool isLeader() const;
            void setLeader();
            Character(string name, Point loc, int health);
            bool isAlive() const;
            double distance(Character* other) const;
            void hit(int dmg);
            string getName() const;
            Point getLocation() const;
            virtual void print() const;
            virtual void attack(Character* other) ;
            ~Character();
    };
    class Cowboy : public Character{
        private:
            int bullets;
        public:
            Cowboy(string name, Point loc);
            void shoot(Character* other); // 10 damage
            void print() const override;
            bool hasboolets();
            void reload(); // 6 bullets
            void attack(Character* other) override;
    };
    class YoungNinja : public Character{
        private:
            int speed;
        public:
            YoungNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const override;
            void attack(Character* other) override;
    };
    class OldNinja : public Character{
        private:
            int speed;
        public:
            OldNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const override;
            void attack(Character* other) override;
    };
    class TrainedNinja : public Character{
        private:
            int speed;
        public:
            TrainedNinja(string name, Point loc);
            void slash(Character* other); // 40 damage
            void move(Character* other); // move towards other
            void print() const override;
            void attack(Character* other) override;
    };
}