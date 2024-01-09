#include <iostream>
#include <string.h>

using namespace std;

enum BRAND
{
    PETROM,
    OMV,
    ROMPETROL
};

class PetrolStation
{
public:
    static double PRICE_PER_LITER;

    PetrolStation(int _pumpId, string _location)
    {
        this->pumpId = _pumpId;
        this->location = _location;
    }

    PetrolStation(int _pumpId, string _location, BRAND _brand, int *_liters, int _noClients)
    {
        this->pumpId = _pumpId;
        this->location = _location;
        this->brand = _brand;

        this->liters = new int[_noClients];

        for (int i = 0; i < _noClients; i++) {
            this->liters[i] = _liters[i];
        }

        this->noClients = _noClients;
    }

    string getLocation() {
        return this->location;
    }

    void setLocation(string _location) {
        this->location = _location;
    }

    int getTotalLiters() {
        int sum = 0;
        for (int i = 0; i < this->noClients; i++) {
            sum += this->liters[i];
        }

        return sum;
    }

    int getId() {
        return this->pumpId;
    }

    void setDiesel() {
        this->isDiesel = !this->isDiesel;
    }

    int getNoClients() {
        return this->noClients;
    }

    void sellGasoline(int amount) {
        this->noClients += 1;

        int* litersCopy = new int[this->noClients];

        for (int i = 0; i < this->noClients - 1; i++) {
            litersCopy[i] = this->liters[i];
        }

        litersCopy[this->noClients - 1] = amount;

        delete[] this->liters;

        this->liters = new int[this->noClients];

        for (int i = 0; i < this -> noClients ; i++) {
            this->liters[i] = litersCopy[i];
        }
        delete[] litersCopy;
    }

    int getIncome() {
        int income = 0;

        for (int i = 0; i < this->noClients; i++) {
            income += this->liters[i] * this->PRICE_PER_LITER;
        }

        return income;
    }

    ~PetrolStation()
    {
        delete[] this->liters;
    }

private:
    int pumpId;
    string location;
    BRAND brand;
    bool isDiesel = false;
    int *liters = nullptr;
    int noClients;
};

double PetrolStation::PRICE_PER_LITER = 7.5;

int main()
{
    PetrolStation station1 = PetrolStation(23, "Bucuresti");

    cout << station1.getLocation();
    station1.setLocation("Ploiesti");
    cout << endl;
    cout << station1.getLocation();

    int liters[] = {100, 200, 300};
    PetrolStation station2(24, "Bucuresti", PETROM, liters, 3);
    cout << "\n"<<station2.getTotalLiters();
    station2.sellGasoline(500);
    cout << "\n"<<station2.getTotalLiters();
    cout << "\n"<<station2.getNoClients();

    PetrolStation::PRICE_PER_LITER = 6.5;

    cout << "\n Total revenue: " << station2.getIncome();

    return 0;
}