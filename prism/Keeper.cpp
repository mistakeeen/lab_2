#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "aeroflot.h"
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

void Keeper::add(Aeroflot* obj) {
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
    sortByDestination();
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
        throw "Заданного элемента несуществует";
    }
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    string u;
    cout << "Введите номер изменяемого параметра:\n1. Место назначения\n2. Номер рейса\n3. Тип самолета" << endl;
    cin >> u;
    if (u == "1")
    {
        string dest_;
        cout << "Введите новый пункт назначения: " << endl;
        cin.get();
        getline(cin, dest_);
        current->data->setDest(dest_);
    }
    else if (u == "2")
    {
        string num_;
        cout << "Введите новый номер рейса: " << endl;
        cin.get();
        getline(cin, num_);
        current->data->setNum(num_);
    }
    else if (u == "3")
    {
        string type_;
        cout << "Введите новый тип самолета: " << endl;
        cin.get();
        getline(cin, type_);
        current->data->setType(type_);
    }
    else
    {
        throw "Неверный номер изменяемого параметра!";
    }
}
void Keeper::sortByDestination() {
    for (Node* i = head_; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data->getDest() > j->data->getDest()) {
                // Обмен местами данных в узлах
                Aeroflot* temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void Keeper::search()
{
    int count = 0;
    Node* current = head_;
    string stype;
    cout << "Введите тип самолета: " << endl;
    cin.get();
    getline(cin, stype);
    while (current) {
        if (current->data->getType() == stype)
        {
            cout << *current->data << endl;
            count++;
        }
        current = current->next;
    }
    if (count == 0)
    {
        cout << "Рейсы, обслуживаемые данным самолетом, отсутствуют" << endl;
    }
}
void Keeper::print() { 
    Node* current = head_;
    int i = 1;
    while (current) {
        //cout << "Plane Type: " << current->data->getType() << ", Flight Number: " << current->data->getNum() << ", Destination: " << current->data->getDest() << endl;
        cout << i << ")";
        //Aeroflot *ae = current->data;
        cout << *current->data;
        i++;
        current = current->next;
    }
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
Keeper::Node::Node(Aeroflot* obj) : data(obj), prev(nullptr), next(nullptr) {}