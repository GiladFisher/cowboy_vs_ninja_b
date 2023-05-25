#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
using namespace std;
namespace ariel{
    Character::Character(string name, Point loc, int health): name(name), loc(loc), health(health){
        this->leader = false;
        this->inteam = false;
    }
    bool Character::isAlive() const{
        return this->health > 0;
    }
    double Character::distance(Character* other) const{
        return this->loc.distance(other->loc);
    }
    void Character::hit(int dmg){
        if(dmg < 0){
            throw std::invalid_argument("negative damage");
        }
        this->health -= dmg;        
    }   
    string Character::getName() const{
        return this->name;
    }
    Point Character::getLocation() const{
        return this->loc;
    }   
    bool Character::isLeader() const{
        return this->leader;
    }
    void Character::attack(Character* other){

    }
    void Character::setLeader(){
        this->leader = !this->leader;
    }
    string Character::print() const{
        if (!this->isAlive()){
            cout << "c" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "c";
        }
        else{
            cout << "c" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "c";
        }
    }
    bool Character::isInTeam() const{
        return this->inteam;
    }
    void Character::setInTeam(){
        this->inteam = !this->inteam;
    }
    Character::~Character(){
    }
    Cowboy::Cowboy(string name, Point loc) : Character(name, loc, 110){
        this->bullets = 6;
    }
    void Cowboy::shoot(Character* other){
        if(this == other){
            throw std::runtime_error("same");
        }
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if(this->hasboolets()){
            other->hit(10);
            this->bullets--;
        }
        
    }
    string Cowboy::print() const{
       if (!this->isAlive()){
            cout << "C" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "C" + this->name + "(" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";

        }
        else{
            cout << "C" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "C" + this->name + to_string(this->health) + "(" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
        } 

    }
    void Cowboy::attack(Character* other){
        if(!this->hasboolets()){
            this->reload();
            return;
        }
        this->shoot(other);
    }
    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }
    void Cowboy::reload(){
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        this->bullets = 6;        
    }
    YoungNinja::YoungNinja(string name, Point loc) : Character(name, loc, 100){
        this->speed = 14;
    }
    void YoungNinja::slash(Character* other){
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if(this == other){
            throw std::runtime_error("same");
        }
        if (this->distance(other) <= 1){
            other->hit(40);
        }
    }
    void YoungNinja::attack(Character* other){
        if(this == other){
            throw std::runtime_error("same");
        }
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if (this->distance(other) > 1){
            this->move(other);
            return;
        }
        this->slash(other);
    }
    void YoungNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc = this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    string YoungNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + "(" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + to_string(this->health) + "(" + to_string(this->loc.getX()) + "," + to_string(this->loc.getY()) + ")";
        }
    }
    OldNinja::OldNinja(string name, Point loc) : Character(name, loc, 150){
        this->speed = 8;
    }
    void OldNinja::slash(Character* other){
        if(this == other){
            throw std::runtime_error("same");
        }
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if (this->distance(other) <= 1){
            other->hit(40);
        }   
    }
    void OldNinja::attack(Character* other){
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if (this->distance(other) > 1){
            this->move(other);
            return;
        }
        this->slash(other);
    }
    void OldNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc = this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    string OldNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + to_string(this->health) + "(" + "," + ")" ;
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + to_string(this->health) + "(" + "," + ")" ;
        }
    }
    TrainedNinja::TrainedNinja(string name, Point loc) : Character(name, loc, 120){
        this->speed = 12;
    }
    void TrainedNinja::slash(Character* other){
        if(other == this){
            throw std::runtime_error("self harm hotline *4435");
        }
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if (this->distance(other) <= 1){
            other->hit(40);
        } 
    }
    void TrainedNinja::move(Character* other){
        if (this->distance(other) >= this->speed){
            this->loc = this->loc.moveTowards(this->loc, other->getLocation(), this->speed);
        }
        else{
            // maybe delete original point
            this->loc = Point(other->getLocation().getX(), other->getLocation().getY());
        }
    }
    void TrainedNinja::attack(Character* other){
        if(!this->isAlive()){
            throw std::runtime_error("dead");
        }
        if(!other->isAlive()){
            throw std::runtime_error("dead");
        }
        if (this->distance(other) > 1){
            this->move(other);
            return;
        }
        this->slash(other);
    }
    string TrainedNinja::print() const{
        if (!this->isAlive()){
            cout << "N" << "(" << this->name << ")" << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + "(" +  "," +  ")";
        }
        else{
            cout << "N" << this->name << this->health << "(" << this->loc.getX() << "," << this->loc.getY() << ")"<< endl;
            return "N" + this->name + to_string(this->health) + "(" + ")";

        }
    }


}