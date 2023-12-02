#include <iostream>
#include <fstream>
#include <vector>
#include "base.h"
#include "keeper.h"



int main() {
    setlocale(LC_ALL, "Russian");
    int user = 0;
    int user2 = 0;
    Keeper keeper;
    try {
        while (true)
        {
           
            cout << "Меню программы:\n1 - Отобразить данные\n2 - Добавить элемент\n3 - Удалить первый элемент\n4 - Удалить элемент\n5 - Изменить элемент\n6 - Сохранение в файл\n7 - Загрузка из файла\n8 - Выход" << endl;;
            cin >> user;
            if (user == 1)
            {
                system("cls");
                keeper.print();
            }
            else if (user == 2)
            {
                while (true)
                {
                    system("cls");
                    cout << "1 - Добавить героя\n2 - Добавить злодея\n3 - Добавить монстра\n4 - Выход" << endl;
                    cin >> user2;
                    if (user2 == 1)
                    {
                        Hero* new_hero = new Hero();
                        new_hero->setName();
                        new_hero->setWeapon();
                        new_hero->setSkills();
                        keeper.add(new_hero);
                    }
                    else if (user2 == 2)
                    {
                        Villain* new_villain = new Villain();
                        new_villain->setName();
                        new_villain->setWeapon();
                        new_villain->setSkills();
                        new_villain->setHabitat();
                        new_villain->setEvil();
                        keeper.add(new_villain);
                    }
                    else if (user2 == 3)
                    {
                        Monster* new_monster = new Monster();
                        new_monster->setName();
                        new_monster->setDesc();
                        keeper.add(new_monster);
                    }
                    else if (user2 == 4)
                    {
                        system("cls");
                        break;
                        
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                }
                
            }
            else if (user == 3)
            {
                system("cls");
                if (keeper.getSize() > 0)
                {
                    cout << "Первый элемент успешно удален\n" << endl;
                }
                --keeper;
                
            }
            else if (user == 4)
            {
                system("cls");
                keeper.print();
                if (keeper.getSize() > 0)
                {
                    int index;
                    cout << "Выберите удаляемый элемент:" << endl;
                    cin >> index;
                    index--;
                    keeper.remove(index);
                    system("cls");
                    cout << "Успешно удалено\n" << endl;
                }
                
            }
            else if (user == 5)
            {
                system("cls");
                keeper.print();
                if (keeper.getSize() > 0)
                {
                    int index;
                    cout << "Выберите элемент для изменения:" << endl;
                    cin >> index;
                    index--;
                    keeper.change(index);
                    system("cls");
                    cout << "Успешно изменено\n" << endl;
                }
            }
            else if (user == 6)
            {
                keeper.save();
                system("cls");
                cout << "Успешно сохранено\n" << endl;
            }
            else if (user == 7)
            {
                keeper.load();
                system("cls");
                cout << "Успешно загружено\n" << endl;
            }
            else if (user == 8)
            {
                break;
            }
            else {
                throw out_of_range("Wrong input");
            }
        }
    }
    catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }


    return 0;
}