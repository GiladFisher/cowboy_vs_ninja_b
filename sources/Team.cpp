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

    }
    void Team::attack(Team* other){

    }
    int Team::stillAlive() const{
        return 0;
    }
    void Team::print() const{

    }
    // Team::~Team(){
    //     delete[] this->team;
    // }

}