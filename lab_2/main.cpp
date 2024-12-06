#include "Train.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "functions.h"
void menu();

int main()
{
    Train* trains = nullptr;

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

        }
    }
}



void menu() {
    cout << "1.Add a new train:" << endl;
    cout << "2.List of trains:" << endl;
    cout << "3.Find a train by number:" << endl;
    cout << "Enter command:";
}

