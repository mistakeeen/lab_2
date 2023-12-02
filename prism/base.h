#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Base {
public:
    virtual void print() = 0;
    virtual void change() = 0;
    virtual void save() = 0;
};


class Hero : public Base {
private:
    string name;
    string weapon_type;
    string skills;
public:
    Hero();
    Hero(std::string name_, std::string weapon_type_, string skills_);
    Hero(const Hero&);
    ~Hero();
    void print() override;
    void change() override;
    void save() override;
    void setName();
    void setWeapon();
    void setSkills();

    string getName();
    string getWeapon();
    string getSkills();
};


class Villain : public Base {
private:
    string name;
    string weapon_type;
    string evil_deed;
    string habitat;
    string skills;
public:
    Villain();
    Villain(std::string name_, std::string weapon_type_, std::string evil_deed_, std::string habitat_,string skills_);
    Villain(const Villain&);
    ~Villain();
    void print() override;
    void save() override;
    void change() override;
    void setName();
    void setWeapon();
    void setSkills();
    void setHabitat();
    void setEvil();

    string getName();
    string getWeapon();
    string getHabitat();
    string getEvil();
    string getSkills();
};


class Monster : public Base {
private:
    std::string name;
    std::string description;
public:
    Monster();
    Monster(std::string name_, std::string description_);
    Monster(const Monster&);
    ~Monster();
    void print() override;
    void change() override;
    void save() override;
    void setName();
    void setDesc();

    string getName();
    string getDesc();
};