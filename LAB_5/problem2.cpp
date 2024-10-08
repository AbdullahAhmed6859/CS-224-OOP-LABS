// Don't use "using namespace std;"
#include <iostream>
using namespace std;

class TollBooth {
    unsigned int numCars;
    unsigned int money;
    
    public:
    TollBooth() {
        numCars = 0;
        money = 0;
    }
    
    void payingCar() {
        numCars += 1;
        money += 50;
    }
    
    void noPayingCar() {
        numCars += 1;
    }
    
    void display() {
        cout << "Total cars passed: " << numCars << endl << "Total toll collected: Rs. " << money;
    }
    
    unsigned int getNumCars() const {
        return numCars;
    }
    
    unsigned int getMoney() const {
        return money;
    }
    
    void setNumCars(unsigned int newNum) {
        numCars = newNum;
    }
    
    void setMoney(unsigned int newMoney) {
        money = newMoney;
    }
};


int main() {
    char input;
    TollBooth TB1;
    
    do {
        cin >> input;
        if (input == 'p') TB1.payingCar();
        else if (input == 'n')  TB1.noPayingCar();
    } while (input != 'q');
    
    TB1.display();
    return 0;
}