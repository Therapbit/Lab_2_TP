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