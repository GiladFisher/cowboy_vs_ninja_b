#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Team.hpp"
using namespace std;
namespace ariel{
    Team::Team(Character* leader){
        this->team = new Character*[10];
        this->leader = leader;
        this->team[0] = leader;
    }
    // Team::Team(const Team& other){
    //     this->team = new Character*[10];
    //     this->leader = other.leader;
        
    // }
    void Team::add(Character* warrior){
        for(int i = 0; i < 10; i++){
            if(this->team[i] == nullptr){
                this->team[i] = warrior;
                return;
            }
        }

    }
    void Team::attack(Team* other){

    }
    int Team::stillAlive() const{
        return 0;
    }
    void Team::print() const{
        // first print the cowboys, then the ninjas


    }
    // Team::~Team(){
    //     delete[] this->team;
    // }
    Team2::Team2(Character* leader) : Team(leader){
    }
    int Team2::stillAlive() const{
        int alive = 0;
        for(int i = 0; i < 10; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive;
    }
    void Team2::add(Character* warrior){
        for(int i = 0; i < 10; i++){
            if(this->team[i] == nullptr){
                this->team[i] = warrior;
                return;
            }
        }
    }
    void Team2::attack(Team* other){
        for(int i = 0; i < 10; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                // this->team[i]->shoot(other->leader);// attack
            }
        }
    }
    void Team2::print() const{
        cout << "Team2:" << endl;
        for(int i = 0; i < 10; i++){
            if(this->team[i] != nullptr){
                this->team[i]->print();
            }
        }
    }


}