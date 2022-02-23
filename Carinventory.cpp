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
Car();
};

void PrintCar(Car a);

Car::Car(){
  for(int index = 0; index < MAX_CHAR_LEN; index++){
    carName[index] = 0;
    Origin[index] = 0;
    }
    MPG = 0;
    Cylinders = 0;
    Displacement = 0;
    Horsepower = 0;
    Weight = 0;
    Acceleration = 0;
    Model = 0;
    ValidEntry = false;
  }

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
    inFile >> car.Origin;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
  //PrintCar(car);
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
ifstream carsFile("cars.txt");
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
  }while(removeIndex < 0 || removeIndex >= 500);
}

void addCar(Car cars[]){
  for(int index = 0; index < 500; index ++){
    if (cars[index].ValidEntry == false){
      cout << "Enter the name of the car you want to add:" << endl;
      cin.ignore(11,'\n');
      cin.getline(cars[index].carName,Car::MAX_CHAR_LEN);
      cars[index].MPG = readInt("Enter the car's MPG: ");
      cars[index].Cylinders = readInt("Enter the amount of cylinders: ");
      cars[index].Displacement = readInt("Enter the displacement of the engine: ");
      cars[index].Horsepower = readInt("Enter the horsepower rating: ");
      cars[index].Weight = readInt("Enter the weight of the car: ");
      cars[index].Acceleration = readDouble("Enter the 0-60 time: ");
      cin.ignore(11,'\n');
      cout << "Enter the car's origin: ";
      cin >> cars[index].Origin;
      cars[index].ValidEntry = true;
      return;
    }
    }
      cout << "The databse is full." << endl;
  }

void returnMenu(Car cars[]){
  int userInput = 0;  
  while(userInput !=5){
      cout << "Choose a number option to continue or type quit." << endl;
      cout << "1. Display the car list" << endl;
      cout << "2. Remove a car from the list" << endl;
      cout << "3. Add a car to the list" << endl;
      cout << "4. Display cars by origin" << endl;
      cout << "5. Quit" << endl;
      cin >> userInput;

    if(userInput == 1){
    printCars(cars);
    }
    if(userInput == 2){
    removeCar(cars);  
    }
    if(userInput == 3){
    addCar(cars);  
    }
    if(userInput == 4){
    printCarsByOrigin(cars);  
    }
    if(userInput == 5){
      cout << "You decided to quit.";
      break;
        }
}
  }

int main(){
Car carList[MAX_CARS];
readCarData(carList);
//printCars(carList);
returnMenu(carList);
}