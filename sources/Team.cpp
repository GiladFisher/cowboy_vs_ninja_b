#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Team.hpp"
using namespace std;
namespace ariel{
    Team::Team(Character* leader){
        // this->team.reserve(MAX_TEAM_SIZE);

        this->leader = leader;
        leader->setLeader();
        this->team.push_back(leader);
    }
    // Team::Team(const Team& other){
    //     this->team = new Character*[10];
    //     this->leader = other.leader;
    // }
    void Team::add(Character* warrior){
        if(warrior == nullptr){
            throw std::runtime_error("Character is null");
        }
        if(this->team.size() == MAX_TEAM_SIZE){
            throw std::runtime_error("Team is full");
        }
        if(warrior->isLeader()){
            throw std::runtime_error("Character is already a leader");
        }
        for(unsigned int i = 0; i < MAX_TEAM_SIZE; i++){
            if(this->team[i] == warrior){
                throw std::runtime_error("Character already in team");
            }
        }
        this->team.push_back(warrior);
    }
    void Team::attack(Team* other){
        
    }
    int Team::stillAlive() const{
        int alive = 0;
        for(unsigned int i = 0; i < MAX_TEAM_SIZE ; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive;
    }
    void Team::print() const{
    }
    Team::~Team(){
        for(unsigned int i = 0; i < this->team.size(); i++){
            if(this->team[i] != nullptr){
                delete this->team[i];
            }
        }
        team.clear();

    }
    Team2::Team2(Character* leader) : Team(leader){
        
    }
    int Team2::stillAlive() const{
        int alive = 0;
        for(unsigned int i = 0; i < MAX_TEAM_SIZE ; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive;
    }
    void Team2::add(Character* warrior){
        if(warrior == nullptr){
            throw std::runtime_error("Character is null");
        }
        if(this->team.size() == MAX_TEAM_SIZE){
            throw std::runtime_error("Team is full");
        }
        if(warrior->isLeader()){
            throw std::runtime_error("Character is already a leader");
        }
        for(unsigned int i = 0; i < MAX_TEAM_SIZE; i++){
            if(this->team[i] == warrior){
                throw std::runtime_error("Character already in team");
            }
        }
        this->team.push_back(warrior);
    }
    void Team2::attack(Team* other){
        for(unsigned int i = 0; i < 10; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                // attack
            }
        }
    }
    void Team2::print() const{
        cout << "Team2:" << endl;
        for(unsigned int i = 0; i < 10; i++){
            if(this->team[i] != nullptr){
                this->team[i]->print();
            }
        }
    }
}