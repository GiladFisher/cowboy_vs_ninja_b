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
    void Character::print() const{
        if (!this->isAlive()){
            cout << "c" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
        else{
            cout << "c" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
    }
    Cowboy::Cowboy(string name, Point loc) : Character(name, loc, 110){
        this->bullets = 6;
    }
    void Cowboy::shoot(Character* other){
        other->hit(10);
    }
    void Cowboy::print() const{
       if (!this->isAlive()){
            cout << "C" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
        else{
            cout << "C" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        } 
    }
    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }
    void Cowboy::reload(){
        this->bullets = 6;        
    }
    YoungNinja::YoungNinja(string name, Point loc) : Character(name, loc, 100){
        this->speed = 14;
    }
    void YoungNinja::slash(Character* other){
        if (this->distance(other) <= 1){
            other->hit(40);
        }
    }
    void YoungNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    void YoungNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
    }
    OldNinja::OldNinja(string name, Point loc) : Character(name, loc, 150){
        this->speed = 0;
    }
    void OldNinja::slash(Character* other){
        if (this->distance(other) <= 1){
            other->hit(40);
        }   
    }
    void OldNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    void OldNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
    }
    TrainedNinja::TrainedNinja(string name, Point loc) : Character(name, loc, 120){
        this->speed = 12;
    }
    void TrainedNinja::slash(Character* other){
        if (this->distance(other) <= 1){
            other->hit(40);
        } 
    }
    void TrainedNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    void TrainedNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
        }
    }


}