#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Team.hpp"
using namespace std;
namespace ariel{
    Team::Team(Character* leader){
        if(leader->isLeader()){
            throw std::runtime_error("Character is already a leader");
        }
        this->team.reserve(MAX_TEAM_SIZE);
        this->leader = leader;
        leader->setLeader();
        this->team[0] = leader;
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
        if(warrior->isInTeam()){
            throw std::runtime_error("Character already in team");
        }
        for(unsigned int i = 0; i < team.size(); i++){
            if(this->team[i] == warrior){
                throw std::runtime_error("Character already in team");
            }
        }
        this->team.push_back(warrior);
        warrior->setInTeam();
    }
    void Team::attack(Team* other){
        if(other == nullptr){
            throw std::invalid_argument("Team is null");
        }
        
    }
    int Team::stillAlive() const{
        int alive = 0;
        for(unsigned int i = 0; i < team.size(); i++){
            if(this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive + 1;
    }
    void Team::print() const{
    }
    Team::~Team(){
    }
    Team2::Team2(Character* leader) : Team(leader){
        
    }
    int Team2::stillAlive() const{
        int alive = 0;
        for(unsigned int i = 0; i < team.size() ; i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive + 1;
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
        if(warrior->isInTeam()){
            throw std::runtime_error("Character already in team");
        }
        this->team.push_back(warrior);
        warrior->setInTeam();
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
    Team2::~Team2(){
        
    }
}