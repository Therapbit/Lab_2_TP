#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train
{
private:
	string destination;
	int numberTrain;
	string timeDeparture;

public:

	Train();
	~Train() {};
	Train(string destination, int numberTrain, string timeDeparture);

	void setDestination(string destination);
	void setNumberTrain(int numberTrain);
	void setTimeDeparture(string timeDeparture);

	string getDestination();
	int getNumberTrain();
	string getTimeDeparture();

	friend ostream& operator<<(ostream& os, const Train& train);
	friend istream& operator>>(istream& is, Train& train);

	Train* addTrain(Train* trains, int& count, Train& train);

};

