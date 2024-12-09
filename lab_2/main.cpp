#include "Train.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "functions.h"
#include "Text.h"

#define _CRT_SECURE_NO_WARNINGS

void menu();

int main()
{
    Train* trains = nullptr;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int command = 0;
    int count = 0;
    while (1) {
        system("cls");
        menu();
        cin >> command;
        switch (command) {
        case 1: {
            system("cls");
            Train train;
            cin >> train;
            trains = train.addTrain(trains, count, train);
            cout << "Train added successfully" << endl;
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            sortTrains(trains, count);
            if (trains) {
                for (int i = 0; i < count; i++)
                    cout << trains[i];
            }
            else {
                cout << "List of train is empty. Add new object in list." << endl;
            }
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "Enter a number of train:";
            int number;
            cin >> number;
            findTrainByNumber(trains, count, number);
            system("pause");
            break;
        }
        case 4:
            system("cls");
            cout << "Enter the name of text file:";
            string filename;
            cin >> filename;
            ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                cerr << "Error open file: " << filename << endl;
                return 1;
            }


            int targetWordCount;
            cout << "Enter the amount word in sentences:";
            cin >> targetWordCount;


            ostringstream buffer;
            buffer << inputFile.rdbuf();
            string text = buffer.str();
            inputFile.close();

            
            const char* cText = text.c_str();

            
            int sentenceCount = 0;
            char** sentences = splitIntoSentences(cText, sentenceCount);

            if (targetWordCount != 0)
                cout << "Нет предложений с таким количеством слов" << endl;
            else
                cout << "Предложения с количеством слов " << targetWordCount << ":" << endl;
            for (int i = 0; i < sentenceCount; ++i) {
                if (countWord(sentences[i]) == targetWordCount) {
                    cout << sentences[i] << endl;
                }
            }

            // Освобождение памяти
            freeSentences(sentences, sentenceCount);
            system("pause");
            break;
        }
    }
}



void menu() {
    cout << "1.Add a new train:" << endl;
    cout << "2.List of trains:" << endl;
    cout << "3.Find a train by number:" << endl;
    cout << "4.Second part of task" << endl;
    cout << "Enter command:";
}

