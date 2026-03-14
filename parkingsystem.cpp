#include <iostream>
using namespace std;



class ParkingSystem {
private:
    int big;
    int medium;
    int small;

public:

    
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType) {

        // Big car
        if (carType == 1) {
            if (big > 0) {
                big--;
                return true;
            }
            return false;
        }

        // Medium car
        if (carType == 2) {
            if (medium > 0) {
                medium--;
                return true;
            }
            return false;
        }

        // Small car
        if (carType == 3) {
            if (small > 0) {
                small--;
                return true;
            }
            return false;
        }

        return false;
    }
};


int main() {

    ParkingSystem parkingSystem(1,1,0);

    cout << parkingSystem.addCar(1) << endl; // true
    cout << parkingSystem.addCar(2) << endl; // true
    cout << parkingSystem.addCar(3) << endl; // false
    cout << parkingSystem.addCar(1) << endl; // false

    return 0;
}
