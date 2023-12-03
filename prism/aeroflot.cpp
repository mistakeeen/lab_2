#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "aeroflot.h"
using namespace std;

Aeroflot::Aeroflot()
{
    this->dest = "Nothing";
    this->num = "Nothing";
    this->type = "Nothing";
}
Aeroflot::Aeroflot(string dest_, string num_, string type_):
    dest(dest_), num(num_), type(type_) {}
Aeroflot::Aeroflot(const Aeroflot& A)
{
    this->dest = A.dest;
    this->num = A.num;
    this->type = A.type;
}
Aeroflot::~Aeroflot()
{
    //delete this;
}

string Aeroflot::getDest()
{
    return dest;
}

string Aeroflot::getNum()
{
    return num;
}

string Aeroflot::getType()
{
    return type;
}

void Aeroflot::setDest(string dest_)
{
    this->dest = dest_;
}

void Aeroflot::setNum(string num_)
{
    this->num = num_;
}

void Aeroflot::setType(string type_)
{
    this->type = type_;
}

void Aeroflot::print()
{
    cout << this->type << " " << this->num << " " << this->dest << endl;
}


ostream& operator<<(ostream& os, const Aeroflot& aeroflot) {
    os << "Пункт назначения: " << aeroflot.dest << ", Номер рейса: " << aeroflot.num << ", Тип самолета: " << aeroflot.type << endl;
    return os;
}
istream& operator>>(istream& is, Aeroflot &aeroflot) {
    string enter;
    cout << "Введите пункт назначения: " << endl;
    is >> enter;
    aeroflot.setDest(enter);
    cout << "Введите номер рейса: " << endl;
    is >> enter;
    aeroflot.setNum(enter);
    cout << "Введите тип самолета: " << endl;
    is >> enter;
    aeroflot.setType(enter);
    return is;
}