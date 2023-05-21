#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
using namespace std;
namespace ariel{
    Character::Character(string name, Point loc): name(name), loc(loc){
        this->health = 0;
    }
    bool Character::isAlive() const{
        return false;
    }
    double Character::distance(Character* other) const{
        return 0;
    }
    void Character::hit(int dmg){
        
    }   
    string Character::getName() const{
        return "";
    }
    Point Character::getLocation() const{
        return Point(0,0);
    }   
    void Character::print() const{
        
    }
    Cowboy::Cowboy(string name, Point loc) : Character(name, loc){
        this->bullets = 0;
    }
    void Cowboy::shoot(Character* other){
        
    }
    string Cowboy::print() const{
       return ""; 
    }
    bool Cowboy::hasboolets(){
        return false;
    }
    void Cowboy::reload(){
        
    }
    YoungNinja::YoungNinja(string name, Point loc) : Character(name, loc){
        this->speed = 0;
    }
    void YoungNinja::slash(Character* other){
        
    }
    void YoungNinja::move(Character* other){
        
    }
    void YoungNinja::print() const{
        
    }
    OldNinja::OldNinja(string name, Point loc) : Character(name, loc){
        this->speed = 0;
    }
    void OldNinja::slash(Character* other){
        
    }
    void OldNinja::move(Character* other){
        
    }
    void OldNinja::print() const{
        
    }
    TrainedNinja::TrainedNinja(string name, Point loc) : Character(name, loc){
        this->speed = 0;
    }
    void TrainedNinja::slash(Character* other){
        
    }
    void TrainedNinja::move(Character* other){
        
    }
    void TrainedNinja::print() const{
        
    }


}