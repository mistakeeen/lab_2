#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Aeroflot {
private:
	string dest;
	string num;
	string type;
public:
	Aeroflot();
	Aeroflot(string dest, string num, string type);
	Aeroflot(const Aeroflot& A);
	~Aeroflot();
	string getDest();
	string getNum();
	string getType();
	void setDest(string dest_);
	void setNum(string num_);
	void setType(string type_);
	void print();
	friend istream& operator>>(istream& is, Aeroflot &aeroflot);
	friend ostream& operator<<(ostream& os, const Aeroflot& aeroflot);
};
