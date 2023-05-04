#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int PARKING_CAPACITY = 100;
const int PARKING_RATE = 5; // $5 per hour

int main()
{
    queue<string> parkingLot;
    int totalCarsParked = 0;
    int totalParkingCharges = 0;
    string command;

    cout << "Welcome to the car parking reservation system!" << endl;

    while (true)
    {
        cout << endl;
        cout << "Please enter a command (arrive/depart/total/cost/exit): ";
        cin >> command;

        if (command == "arrive")
        {
            if (totalCarsParked >= PARKING_CAPACITY)
            {
                cout << "Sorry, the parking lot is full." << endl;
            }
            else
            {
                string carNumber;
                int arrivalTime;
                cout << "Enter the car number: ";
                cin >> carNumber;
                cout << "Enter the arrival time (in hours): ";
                cin >> arrivalTime;
                parkingLot.push(carNumber);
                totalCarsParked++;
                cout << "Car " << carNumber << " parked at " << arrivalTime << " o'clock." << endl;
            }
        }
        else if (command == "depart")
        {
            string carNumber;
            int departureTime;
            cout << "Enter the car number: ";
            cin >> carNumber;
            cout << "Enter the departure time (in hours): ";
            cin >> departureTime;
            bool found = false;
            int parkingTime = 0;
            int parkingCost = 0;
            queue<string> temp;
            while (!parkingLot.empty())
            {
                string car = parkingLot.front();
                parkingLot.pop();
                if (car == carNumber)
                {
                    found = true;
                    parkingTime = departureTime - parkingTime;
                    parkingCost = parkingTime * PARKING_RATE;
                    totalCarsParked--;
                    totalParkingCharges += parkingCost;
                    cout << "Car " << carNumber << " departed at " << departureTime << " o'clock." << endl;
                    cout << "Parking time: " << parkingTime << " hours." << endl;
                    cout << "Parking charges: $" << parkingCost << "." << endl;
                    break;
                }
                else
                {
                    temp.push(car);
                }
            }
            while (!temp.empty())
            {
                string car = temp.front();
                temp.pop();
                parkingLot.push(car);
            }
            if (!found)
            {
                cout << "Sorry, car " << carNumber << " is not parked here." << endl;
            }
        }
        else if (command == "total")
        {
            cout << "Total cars parked: " << totalCarsParked << "." << endl;
        }
        else if (command == "cost")
        {
            cout << "Total parking charges: $" << totalParkingCharges << "." << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    cout << "Thank you for using the car parking reservation system!" << endl;

    return 0;
}

