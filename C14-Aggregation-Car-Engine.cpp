// C14-Aggregation-Car-Engine.cpp 
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started!" << endl;
    }
};

class Car {
private:
    Engine* engine;                   // Aggregation: Car does not own Engine

public:
    Car(Engine* eng) : engine(eng) {} // Engine is passed in, not created

    void startCar() {
        if (engine) {
            engine->start();
            cout << "Car is running!" << endl;
        }
        else {
            cout << "No engine found!" << endl;
        }
    }
};

int main() {
    Engine myEngine;            // Engine object created independently

    Car    myCar(&myEngine);    // Aggregation: 
                                // Car receives an existing Engine
    myCar.startCar();

}
