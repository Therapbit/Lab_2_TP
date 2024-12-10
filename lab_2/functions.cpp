#include "Train.h"
#include <iostream>

using namespace std;

void sortTrains(Train* trains, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (trains[i].getNumberTrain() > trains[j].getNumberTrain()) {
                swap(trains[i], trains[j]);
            }
        }
    }
}

void findTrainByNumber(Train* trains, int count, int number) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (trains[i].getNumberTrain() == number) {
            cout << trains[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Train with number " << number << " didnt found" << endl;
    }
}

void editTrain(Train* trains, int count) {
    if (!trains || count == 0) {
        cout << "No trains available to edit.\n";
        return;
    }

    int trainNumber;
    cout << "Enter the number of the train to edit: ";
    cin >> trainNumber;

    // Поиск поезда по номеру
    Train* targetTrain = nullptr;
    for (int i = 0; i < count; ++i) {
        if (trains[i].getNumberTrain() == trainNumber) {
            targetTrain = &trains[i];
            break;
        }
    }

    if (!targetTrain) {
        cout << "Train with number " << trainNumber << " not found.\n";
        return;
    }

    // Меню редактирования
    int field;
    cout << "Train found:\n" << *targetTrain << endl;
    cout << "What do you want to edit?\n";
    cout << "1. Destination\n";
    cout << "2. Train Number\n";
    cout << "3. Time of Departure\n";
    cout << "Enter your choice: ";
    cin >> field;

    switch (field) {
    case 1: {
        string newDestination;
        cout << "Enter new destination: ";
        cin >> newDestination;
        targetTrain->setDestination(newDestination);
        cout << "Destination updated successfully.\n";
        break;
    }
    case 2: {
        int newNumber;
        cout << "Enter new train number: ";
        cin >> newNumber;
        targetTrain->setNumberTrain(newNumber);
        cout << "Train number updated successfully.\n";
        break;
    }
    case 3: {
        string newTime;
        cout << "Enter new time of departure (HH:MM): ";
        cin >> newTime;
        targetTrain->setTimeDeparture(newTime);
        cout << "Time of departure updated successfully.\n";
        break;
    }
    default:
        cout << "Invalid choice.\n";
        break;
    }
}