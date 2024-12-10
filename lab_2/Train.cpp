#include "Train.h"
#include <iostream>
#include <regex>
using namespace std;

Train::Train() { setDestination("Unknown"), setNumberTrain(0), setTimeDeparture("00:00"); };

Train::Train(string destination, int numberTrain, string timeDeparture) : destination(destination), numberTrain(numberTrain), timeDeparture(timeDeparture) {}

void Train::setDestination(string destination) { this->destination = destination; }
void Train::setTimeDeparture(string timeDeparture) { this->timeDeparture = timeDeparture; }
void Train::setNumberTrain(int numberTrain) { this->numberTrain = numberTrain; }

string Train::getDestination() { return destination; }
string Train::getTimeDeparture() { return timeDeparture; }
int Train::getNumberTrain() { return numberTrain; }


ostream& operator<<(ostream& os, const Train& train) {

        os << "Destination: " << train.destination << "\n"
        << "Number: " << train.numberTrain << "\n"
        << "Time: " << train.timeDeparture << "\n\n";

   
    return os;
}

istream& operator>>(istream& is, Train& train) {

        cout << "Enter destination: ";
        is >> ws; // ������� ������� ����� ������ ������
        getline(is, train.destination);

        cout << "Enter train number: ";
        is >> train.numberTrain;

        while (true) {
            cout << "Enter time of departure (HH:MM): ";
            is >> ws; // ������� ������� ����� ������ ������
            getline(is, train.timeDeparture);

            // ���������� ���������� ��������� ��� �������� �������
            regex timeFormat(R"(^([01]\d|2[0-3]):([0-5]\d)$)");
            if (regex_match(train.timeDeparture, timeFormat)) {
                break; // ���� ������ ����������, ������� �� �����
            }
            else {
                cout << "Invalid time format. Please enter the time in HH:MM format.\n";
            }
        }


    return is;
}


Train* Train::addTrain(Train* trains, int& count, Train& train) {
    Train* newTrains = new Train[count + 1];
    if (trains) {
        for (int i = 0; i < count; i++)
            newTrains[i] = trains[i];
    }

    newTrains[count] = train;

    delete[] trains;

    count++;

    return newTrains;

}