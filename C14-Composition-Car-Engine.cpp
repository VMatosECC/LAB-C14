// C14-Composition-Car-Engine.cpp 
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started!" << endl;
    }
};


//Here, Car owns Engine, so the engine is created and destroyed with the car.
class Car {
private:
    Engine engine;              // Composition: Car owns Engine

public:
    void startCar() {
        engine.start();
        cout << "Car is running!" << endl;
    }
};


int main() {

    Car    myCar;               // Composition: 
                                // Car creates its own Engine
    myCar.startCar();

}
