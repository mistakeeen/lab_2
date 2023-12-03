#include <iostream>
#include <fstream>
#include <vector>
#include "aeroflot.h"
#include "keeper.h"
#include <string>



int main() {
    setlocale(LC_ALL, "Russian");
    string user;
    string user2;
    Keeper keeper;
        while (true)
        {
            try {
                cout << "1. Задание 1\n2. Задание 2" << endl;
                cin >> user;
                if (user == "1")
                {

                    while (true)
                    {
                        cout << "1. Добавить элемент\n2. Редактировать элемент\n3. Удалить элемент\n4. Поиск по самолету\n5. Вывод всех рейсов" << endl;
                        cin >> user2;
                        if (user2 == "1")
                        {
                            Aeroflot* ae = new Aeroflot();
                            system("cls");
                            cin >> *ae;
                            keeper.add(ae);
                            system("cls");
                        }
                        else if (user2 == "2")
                        {
                            system("cls");
                            int index;
                            string ind;
                            keeper.print();
                            cout << "Введите номер изменяемого параметра: " << endl;
                            cin.get();
                            getline(cin, ind);
                            try {
                                index = stoi(ind);
                            }
                            catch (const invalid_argument& e) {
                                cout << "Неправильно задан номер элемента" << endl;
                                break;
                            }
                            index--;
                            keeper.change(index);
                            system("cls");
                        }
                        else if (user2 == "3")
                        {
                            system("cls");
                            keeper.print();
                            if (keeper.getSize() > 0)
                            {
                                int index;
                                string ind;
                                cout << "Выберите удаляемый элемент:" << endl;
                                cin.get();
                                getline(cin, ind); 
                                try {
                                    index = stoi(ind);
                                }
                                catch (const invalid_argument& e) {
                                    cout << "Неправильно задан номер элемента" << endl;
                                    break;
                                }
                                index--;
                                keeper.remove(index);
                                system("cls");
                                cout << "Успешно удалено\n" << endl;
                            }
                        }
                        else if (user2 == "4")
                        {
                            system("cls");
                            keeper.search();
                        }
                        else if (user2 == "5")
                        {
                            system("cls");
                            keeper.print();
                        }
                        else
                            throw "Такой пункт меню отсутствует!";
                    }
                }
                else if (user == "2")
                {
                    std::ifstream inputFile("example.txt");

                    if (!inputFile.is_open()) {
                        std::cerr << "Не удалось открыть файл." << std::endl;
                        return 1;
                    }

                    // Читаем первые три предложения
                    std::vector<std::string> sentences;
                    std::string line;
                    int sentenceCount = 0;

                    while (std::getline(inputFile, line)) {
                        // Предполагаем, что предложение заканчивается точкой, вопросительным или восклицательным знаком
                        if (!line.empty() && (line.back() == '.' || line.back() == '?' || line.back() == '!')) {
                            sentences.push_back(line);
                            sentenceCount++;

                            if (sentenceCount == 3) {
                                break;
                            }
                        }
                        else {
                            // Продолжаем добавлять строки к текущему предложению
                            if (!sentences.empty()) {
                                sentences.back() += " " + line;
                            }
                        }
                    }

                    // Выводим символы в обратном порядке
                    for (const auto& sentence : sentences) {
                        std::string reversedSentence = sentence;
                        std::reverse(reversedSentence.begin(), reversedSentence.end());
                        std::cout << reversedSentence << std::endl;
                    }

                    // Закрываем файл
                    inputFile.close();
                }
                else
                    throw "Такой пункт меню отсутствует!";
            }
            catch (const char* error) {
                cout << "Error: " << error << endl;
            }
        }
    


    return 0;
}