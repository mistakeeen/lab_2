#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "base.h"
#include "keeper.h"

Keeper::Keeper() : head_(nullptr), tail_(nullptr) {}
Keeper::Keeper(const Keeper& other) {
    Node* current = other.head_;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

Keeper::~Keeper() {
    while (head_){
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

void Keeper::add(Base* obj) {
    Node* node = new Node(obj);
    if (!head_) {
        head_ = node;
        tail_ = node;
    }
    else {
        tail_->next = node;
        node->prev = tail_;
        tail_ = node;
    }
}

void Keeper::remove(int index) {
    if (index < 0 || index >= getSize()) {
        throw out_of_range("Index out of range");
    }
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    if (current == head_) {
        head_ = current->next;
        if (head_ != nullptr) {
            head_->prev = nullptr;
        }
    }
    else if (current == tail_) {
        tail_ = current->prev;
        tail_->next = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
}

int Keeper::getSize() const {
    Node* curr = head_;
    int i = 1;
    if (curr == nullptr) return 0;

    while (curr != tail_) {
        curr = curr->next;
        i++;
    }
    return i;
}
void Keeper::change(int index)
{

    if (index < 0 || index >= getSize()) {
        throw out_of_range("Index out of range");
    }
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data->change();
}
void Keeper::load()
{
    string buf;
    ifstream fin("data.txt");
    if (!fin.is_open()) {
        throw out_of_range("Error opening file");
    }
    string type, name, weapon_type, evil_deed, habitat, skills, desc;
    while (fin >> type) {
        if (type == "Hero") {
            getline(fin, buf);
            getline(fin, name);
            getline(fin, weapon_type);
            getline(fin, skills);

            Hero* hero = new Hero(name, weapon_type, skills);
            this->add(hero);
        }
        else if (type == "Villain") {
            getline(fin, buf);
            getline(fin, name);
            getline(fin, weapon_type);
            getline(fin, skills);
            getline(fin, habitat);
            getline(fin, evil_deed);
            Villain* vill = new Villain(name, weapon_type, skills, habitat, evil_deed);
            this->add(vill);
        }
        else if (type == "Monster") {
            getline(fin, buf);
            getline(fin, name);
            getline(fin, desc);
            Monster* monster = new Monster(name, desc);
            this->add(monster);
        }
    }
    fin.close();
}
void Keeper::save() {
    ofstream file("data.txt");
    if (!file.is_open()) {
        throw out_of_range("Error opening file");
    }
    file.close();
    Node* current = head_;
    while (current != nullptr)
    {
        current->data->save();
        current = current->next;
    }
    
}
void Keeper::print(){
    int i = 1;
    if (head_ == nullptr)
    {
        cout << "Данные отсутствуют\n" << endl;
        return;
    }
    Node* curr = head_;
    while (curr != tail_) {
        cout << i << ") ";
        curr->data->print();
        curr = curr->next;
        i++;
    }
    cout<<i<<") ";
    curr->data->print();
}
void Keeper::operator--()
{
    Node* current = head_;
    if (head_ != nullptr)
    {
        head_ = current->next;
        if (head_ != nullptr) {
            head_->prev = nullptr;
        }
        delete current;
    }
    else
    {
        cout << "Данные отсутствуют\n" << endl;
        return;
    }
}
Keeper::Node::Node(Base* obj) : data(obj), prev(nullptr), next(nullptr) {}