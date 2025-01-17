#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <limits>
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
        // this->team[0] = leader;
        this->team.push_back(leader);
    }
    
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
        Character* prey = this->choosePrey(other);
        for(unsigned int i = 0; i < this->team.size(); i++){
            prey = this->choosePrey(other);
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                // if(!prey->isAlive()){
                //     prey = this->choosePrey(other);
                // }
                if(prey != nullptr){
                    this->team[i]->attack(prey);
                }
                else{ // no more prey
                    break;
                }
            }
        }
    }
    Character* Team::choosePrey(Team* other){
        Character* closest = nullptr;
        unsigned int min_dis = std::numeric_limits<int>::max();
        for(unsigned int i = 0; i < other->team.size(); i++){
            if(other->team[i] != nullptr && other->team[i]->isAlive()){
                Cowboy* cowb = dynamic_cast<Cowboy*>(other->team[i]);
                if(!cowb){ // not a cowboy
                    continue;
                }
                unsigned int dis = other->team[i]->distance(this->leader);
                if(dis < min_dis){
                    min_dis = dis;
                    closest = other->team[i];
                }
            }
        }
        for(unsigned int i = 0; i < other->team.size(); i++){
            if(other->team[i] != nullptr && other->team[i]->isAlive()){
                Cowboy* cowb = dynamic_cast<Cowboy*>(other->team[i]);
                if(cowb){ // is a cowboy
                    continue;
                }
                unsigned int dis = other->team[i]->distance(this->leader);
                if(dis < min_dis){
                    min_dis = dis;
                    closest = other->team[i];
                }
            }
        }

        return closest;
    }
    void Team::replaceLeader(){
        Character* closest = nullptr;
        unsigned int min_dis = std::numeric_limits<int>::max();
        unsigned int index = 0;
        for(unsigned int i = 0; i < this->team.size(); i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                Cowboy* cowb = dynamic_cast<Cowboy*>(this->team[i]);
                if(!cowb){ // not a cowboy
                    continue;
                }
                unsigned int dis = this->team[i]->distance(this->leader);
                if(dis < min_dis){
                    min_dis = dis;
                    closest = this->team[i];
                    index = i;
                }
            }
        }
        for(unsigned int i = 0; i < this->team.size(); i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                Cowboy* cowb = dynamic_cast<Cowboy*>(this->team[i]);
                if(cowb){ // is a cowboy
                    continue;
                }
                unsigned int dis = this->team[i]->distance(this->leader);
                if(dis < min_dis){
                    min_dis = dis;
                    closest = this->team[i];
                    index = i;
                }
            }
        }
        if(closest != nullptr){
            this->team[0] = closest;
            closest->setLeader();
            this->leader->setLeader();
            this->team[index] = this->leader;
            this->leader = closest;
        }
    }
    int Team::stillAlive() const{
        int alive = 0;
        for(unsigned int i = 0; i < team.size(); i++){
            if(this->team[i]->isAlive()){
                alive++;
            }
        }
        return alive;
    }
    void Team::print() const{
    }
    bool Team::isAlive() const{
        return this->stillAlive() > 0;
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
        if(warrior->isInTeam()){
            throw std::runtime_error("Character already in team");
        }
        this->team.push_back(warrior);
        warrior->setInTeam();
    }
    void Team2::attack(Team* other){
        if(other == nullptr){
            throw std::invalid_argument("Team is null");
        }  
        Character* prey = this->choosePrey(other);
        for(unsigned int i = 0; i < this->team.size(); i++){
            if(this->team[i] != nullptr && this->team[i]->isAlive()){
                prey = this->choosePrey(other);
                if(!prey->isAlive()){
                    prey = this->choosePrey(other);
                }
                if(prey != nullptr){
                    this->team[i]->attack(prey);
                }
                else{ // no more prey
                    break;
                }
            }
        }
    }
    Character* Team2::choosePrey(Team* other){
        Character* closest = nullptr;
        unsigned int min_dis = std::numeric_limits<int>::max();
        for(unsigned int i = 0; i < other->team.size(); i++){
            if(other->team[i] != nullptr && other->team[i]->isAlive()){
                unsigned int dis = other->team[i]->distance(this->leader);
                if(dis < min_dis){
                    min_dis = dis;
                    closest = other->team[i];
                }
            }
        }
        return closest;
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
    SmartTeam::~SmartTeam(){
        
    }
}