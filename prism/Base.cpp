#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "base.h"
using namespace std;
string check(string s)
{
    if (s == "")
    {
        return "Nothing";
    }
    else
    {
        return s;
    }
}
Hero::Hero()
{
    this->name = "Nothing";
    this->weapon_type = "Nothing";
    this->skills = "Nothing";
}
Hero::Hero(std::string name_, std::string weapon_type_, string skills_) :
    name(name_), weapon_type(weapon_type_), skills(skills_) {}
Hero::Hero(const Hero& H)
{
    this->name = H.name;
    this->weapon_type = H.weapon_type;
    this->skills = H.skills;
}
Hero::~Hero()
{
    delete this;
}
void Hero::print() {
    std::cout << "Hero: " << name << ", Weapon Type: " << weapon_type << ", Skills: "<< skills;
    std::cout << std::endl;
}

void Hero::change()
{
    int u;
    while (true)
    {
        system("cls");
        this->print();
        cout << "1 - Изменить имя\n2 - Изменить оружие\n3 - Изменить способности\n4 - Выход" << endl;
        cin >> u;
        if (u == 1)
        {
            this->setName();
        }
        else if (u == 2)
        {
            this->setWeapon();
        }
        else if (u == 3)
        {
            this->setSkills();
        }
        else if (u == 4)
        {
            break;
        }
    }
    
}

void Hero::save()
{
    ofstream file("data.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "Hero" << endl;
    file << this->getName() << endl;
    file << this->getWeapon() << endl;
    file << this->getSkills() << endl;
    file.close();
}

void Hero::setWeapon()
{
    string buf;
    getline(cin, buf);
    cout << "Введите оружие героя: ";
    getline(cin, this->weapon_type);
    this->weapon_type = check(this->weapon_type);
}

void Hero::setSkills()
{
    string buf;
    getline(cin, buf);
    cout << "Введите способности героя: ";
    getline(cin, this->skills);
    this->skills = check(this->skills);
}

string Hero::getName()
{
    return name;
}

string Hero::getWeapon()
{

    return weapon_type;
}

string Hero::getSkills()
{
    return skills;
}

void Hero::setName()
{
    string buf;
    getline(cin, buf);
    cout << "Введите имя героя: ";
    getline(cin, this->name);
    this->name = check(this->name);
}


Villain::Villain()
{
    this->name = "Nothing";
    this->weapon_type = "Nothing";
    this->skills = "Nothing";
    this->evil_deed = "Nothing";
    this->habitat = "Nothing";
}
Villain::Villain(std::string name_, std::string weapon_type_, std::string evil_deed_, std::string habitat_, string skills_) :
    name(name_), weapon_type(weapon_type_), evil_deed(evil_deed_), habitat(habitat_), skills(skills_) {}

Villain::Villain(const Villain& V)
{
    this->name = V.name;
    this->weapon_type = V.weapon_type;
    this->skills = V.skills;
    this->habitat = V.habitat;
    this->evil_deed = V.evil_deed;
}

Villain::~Villain()
{
    delete this;
}

void Villain::print(){
    std::cout << "Villain: " << name << ", Weapon Type: " << weapon_type << ", Evil Deed: " << evil_deed
        << ", Habitat: " << habitat << ", Skills: "<< skills;
    std::cout << std::endl;
}

void Villain::save()
{
    ofstream file("data.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "Villain" << endl;
    file << this->getName() << endl;
    file << this->getWeapon() << endl;
    file << this->getSkills() << endl;
    file << this->getHabitat() << endl;
    file << this->getEvil() << endl;
    file.close();
}

void Villain::change()
{
    int u;
    while (true)
    {
        system("cls");
        this->print();
        cout << "1 - Изменить имя\n2 - Изменить оружие\n3 - Изменить способности\n4 - Изменить место обитания\n5 - Изменить преступления\n6 - Назад" << endl;
        cin >> u;
        if (u == 1)
        {
            this->setName();
        }
        else if (u == 2)
        {
            this->setWeapon();
        }
        else if (u == 3)
        {
            this->setSkills();
        }
        else if (u == 4)
        {
            this->setHabitat();
        }
        else if (u == 5)
        {
            this->setEvil();
        }
        else if (u == 6)
        {
            break;
        }
    }
}

void Villain::setName()
{
    string buf;
    getline(cin, buf);
    cout << "Введите имя злодея: ";
    getline(cin, this->name);
    this->name = check(this->name);
}

void Villain::setWeapon()
{
    string buf;
    getline(cin, buf);
    cout << "Введите оружие злодея: ";
    getline(cin, this->weapon_type);
    this->weapon_type = check(this->weapon_type);
}

void Villain::setSkills()
{
    string buf;
    getline(cin, buf);
    cout << "Введите способности злодея: ";
    getline(cin, this->skills);
    this->skills = check(this->skills);
}

void Villain::setHabitat()
{
    string buf;
    getline(cin, buf);
    cout << "Введите место обитания злодея: ";
    getline(cin, this->habitat);
    this->habitat = check(this->habitat);
}

void Villain::setEvil()
{
    string buf;
    getline(cin, buf);
    cout << "Введите совершенное злодеяние: ";
    getline(cin, this->evil_deed);
    this->evil_deed = check(this->evil_deed);
}

string Villain::getName()
{
    return name;
}

string Villain::getWeapon()
{
    return weapon_type;
}

string Villain::getHabitat()
{
    return habitat;
}

string Villain::getEvil()
{
    return evil_deed;
}

string Villain::getSkills()
{
    return skills;
}



Monster::Monster()
{
    this->name = "Nothing";
    this->description = "Nothing";
}

Monster::Monster(std::string name_, std::string description_) :
    name(name_), description(description_) {}
Monster::Monster(const Monster& M)
{
    this->name = M.name;
    this->description = M.description;
}
Monster::~Monster()
{
    delete this;
}
void Monster::print(){
    std::cout << "Monster: " << name << ", Description: " << description << std::endl;
}

void Monster::change()
{
    int u;
    while (true)
    {
        system("cls");
        this->print();
        cout << "1 - Изменить имя\n2 - Изменить описание\n3 - Выход" << endl;
        cin >> u;
        if (u == 1)
        {
            this->setName();
        }
        else if (u == 2)
        {
            this->setDesc();
        }
        else if (u == 3)
        {
            break;
        }
    }
}

void Monster::save()
{
    ofstream file("data.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "Monster" << endl;
    file << this->getName() << endl;
    file << this->getDesc() << endl;
    file.close();
}

void Monster::setName()
{
    string buf;
    getline(cin, buf);
    cout << "Введите имя монстра: ";
    getline(cin, this->name);
    this->name = check(this->name);
}
void Monster::setDesc()
{
    string buf;
    getline(cin, buf);
    cout << "Введите описание монстра: ";
    getline(cin, this->description);
    this->description = check(this->description);
}
string Monster::getName()
{
    return name;
}

string Monster::getDesc()
{
    return description;
}
