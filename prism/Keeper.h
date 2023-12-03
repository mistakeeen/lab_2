#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "aeroflot.h"
class Keeper {
public:
    Keeper();
    Keeper(const Keeper&);
    ~Keeper();
    void add(Aeroflot* obj);
    void remove(int);
    int getSize() const;
    void change(int);
    void print();
    void sortByDestination();
    void search();
    void operator --();
private:
    struct Node {
        Aeroflot* data;
        Node* prev;
        Node* next;
        Node(Aeroflot* obj);
    };
    Node* head_;
    Node* tail_;
};