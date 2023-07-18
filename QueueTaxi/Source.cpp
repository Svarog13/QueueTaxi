#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

class BusStop {
private:
    std::stack<int> passengers;
    int maxPassengers;
    int avgPassengerArrivalTime;
    int avgBusArrivalTime;
    bool stopType;

public:
    BusStop(int maxPass, int passengerTime, int busTime, bool isEnd) {
        maxPassengers = maxPass;
        avgPassengerArrivalTime = passengerTime;
        avgBusArrivalTime = busTime;
        stopType = isEnd;
        srand(time(0));
    }

    void addPassenger() {
        if (passengers.size() < maxPassengers) {
            passengers.push(1);
            std::cout << "Passenger added to the bus stop" << std::endl;
        }
        else {
            std::cout << "The bus stop is full, the passenger cannot enter" << std::endl;
        }
    }

    void removePassenger() {
        if (!passengers.empty()) {
            passengers.pop();
            std::cout << "Passenger left the bus stop" << std::endl;
        }
        else {
            std::cout << "There are no passengers at the bus stop" << std::endl;
        }
    }

    bool hasPassengers() {
        return !passengers.empty();
    }

    bool isEndStop() {
        return stopType;
    }

    int getAvgStayTime() {
        return avgPassengerArrivalTime * maxPassengers;
    }

    int getBusArrivalInterval() {
        return avgBusArrivalTime;
    }
};

int main() {
    int maxPassengers, passengerArrivalTime, busArrivalTime;
    bool isEndStop;
    std::cout << "Enter the maximum number of passengers at the bus stop: ";
    std::cin >> maxPassengers;
    std::cout << "Enter the average time between passenger arrivals at the bus stop: ";
    std::cin >> passengerArrivalTime;
    std::cout << "Enter the average time between bus arrivals at the bus stop: ";
    std::cin >> busArrivalTime;
    std::cout << "Enter the bus stop type (1 - end stop, 0 - not an end stop): ";
    std::cin >> isEndStop;

    BusStop busStop(maxPassengers, passengerArrivalTime, busArrivalTime, isEndStop);

    int simulationTime = 60;
    int currentTime = 0;

    while (currentTime < simulationTime) {
        if (randomInt(1, 10) <= 3) {
            busStop.addPassenger();
        }

        if (currentTime % busStop.getBusArrivalInterval() == 0) {
            if (busStop.hasPassengers()) {
                busStop.removePassenger();
            }
            else {
                std::cout << "The bus arrived at the stop, but no one got off" << std::endl;
            }
        }

        currentTime++;
    }

    std::cout << "Average stay time of a person at the bus stop: " << busStop.getAvgStayTime() << " minutes" << std::endl;

    return 0;
}