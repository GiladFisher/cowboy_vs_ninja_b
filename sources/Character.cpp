#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
using namespace std;
namespace ariel{
    Character::Character(string name, Point loc, int health): name(name), loc(loc), health(health){
    }
    bool Character::isAlive() const{
        return this->health > 0;
    }
    double Character::distance(Character* other) const{
        return this->loc.distance(other->loc);
    }
    void Character::hit(int dmg){
        this->health -= dmg;        
    }   
    string Character::getName() const{
        return this->name;
    }
    Point Character::getLocation() const{
        return this->loc;
    }   
    void Character::print(string kind) const{
        if (!this->isAlive()){
            cout << kind << "(" << this->name << ")" << "(" << this->loc.getX << "," << this->loc.getY << ")"<< endl;
        }
        else{
            cout << kind << this->name << this->health << "(" << this->loc.getX << "," << this->loc.getY << ")"<< endl;
        }
    }
    Cowboy::Cowboy(string name, Point loc) : Character(name, loc){
        this->bullets = 6;
    }
    void Cowboy::shoot(Character* other){
        other.hit(10);
    }
    string Cowboy::print() const{
       return ""; 
    }
    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }
    void Cowboy::reload(){
        this->bullets = 6;        
    }
    YoungNinja::YoungNinja(string name, Point loc) : Character(name, loc){
        this->speed = 14;
    }
    void YoungNinja::slash(Character* other){
        if (this->distance(other) <= 1){
            other.hit(40);
        }
    }
    void YoungNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc.moveTowards(this->loc, other.loc, this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other.loc.getX(), other.loc.getY());
        }
    }
    void YoungNinja::print() const{
        this->Character::print("N");
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