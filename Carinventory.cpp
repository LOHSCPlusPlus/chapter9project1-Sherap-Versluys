#include <iostream>
#include <fstream>
using namespace std;

struct Car{
enum {MAX_CHAR_LEN=100};
char carName[MAX_CHAR_LEN];
double MPG;
int Cylinders;
double Displacement;
double Horsepower;
double Weight;
double Acceleration;
int Model;
char Origin[MAX_CHAR_LEN];
bool ValidEntry;
};

const int MAX_CARS=500;
Car readCars(ifstream &inFile){
    Car car; 
    inFile.get(car.carName, Car::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile >> car.ValidEntry;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
    return car;
}
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

double readDouble(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

int readCarData(Car cars[]){
ifstream carsFile("cars");
    int numCars = 0;
    while(carsFile.peek() != EOF && numCars < MAX_CARS) {
        cars[numCars] = readCars(carsFile);
        numCars++;
    }
    return numCars;
}

void PrintCar(Car a){
  cout << a.carName << ";" << a.MPG << ";" << a.Cylinders << ";" << a.Displacement << ";" << a.Horsepower << ";" << a.Weight << ";" << a.Acceleration << ";" << a.Model << ";" << a.Origin << endl;
}

void printCars(Car cars[]){
  for(int index = 0; index < 500; index++){
    if (cars[index].ValidEntry == true){
      cout << "Index " << index << ": ";
        PrintCar(cars[index]);
      cout << endl;
    }
  }
}

void printCarsByOrigin(Car cars[]){
  string userOrigin;
  cout << "Enter an origin(US, Europe, Japan)" << endl;
  cin >> userOrigin;
  for(int index = 0; index < 500; index++){
    if (cars[index].ValidEntry == true && cars[index].Origin == userOrigin){
      cout << "Index " << index << ": ";
        PrintCar(cars[index]);
      cout << endl;
    }
  }
}

void removeCar(Car cars[]){
  int removeIndex;
  do{
  removeIndex = readInt("Enter an index to remove: ");
  cars[removeIndex].ValidEntry = false;
  }while(removeIndex > 0 || removeIndex <= 500);
}

void addCar(Car cars[]){
  for(int index = 0; index < 500; index ++){
    if (cars[index].ValidEntry == false){
      cout << "Enter the details of the car you want to add:" << endl;
      cin.ignore(11,'\n');
      cin.getline(cars[index].carName, MAX_CARS);
      cars[index].MPG = readInt("Enter the car's MPG: ");
      cars[index].Cylinders = readInt("Enter the amount of cylinders: ");
      cars[index].Displacement = readInt("Enter the displacement of the engine: ");
      cars[index].Horsepower = readInt("Enter the horsepower rating: ");
      cars[index].Weight = readInt("Enter the weight of the car: ");
      cars[index].Acceleration = readDouble("Enter the 0-60 time: ");
      cout << "Enter the car's origin: ";
      cin >> cars[index].Origin;
    }
    else{
      cout << "The databse is full.";
      break;
    }
  }
}

void returnMenu(){
  cout << 
}

int main(){
Car cars[MAX_CARS];
printCars(cars);
printCarsByOrigin(cars);
removeCar(cars);
addCar(cars);

}