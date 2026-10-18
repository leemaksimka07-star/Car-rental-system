#include "User.h"
#include "Car.h"
using namespace std;
int main() {
	//add car variables
	int type, idCar;
	string name;
	double price, extra;
	//user variables
	int exit, id;
	string login;
	vector<Car*>cars;
	cars.push_back(new Electric(101, "Tesla", 120, false, 95));
	cars.push_back(new Luxury(102, "BMW", 200, false,50));
	cars.push_back(new SUV(103, "Toyota", 150, false, 30));
	cars.push_back(new Electric(104, "Nissan", 100, false, 80));
	cars.push_back(new Luxury(105, "Mercedes", 250, false, 70));
	//search cars variables
	int idi, cho;
	string na;
	//statistics variables
	int available;
	int rented;
	//rent cars variables
	int carid, days;
	bool found;
	double cost;
	//retrun car variables
	int returnId;
	//load variables
	int loadid;
	string line;
	ofstream fout;
	ifstream fin;
	//best car
	Car* best;
	cout << "Enter name: ";
	cin >> login;
	cout << "Enter ID: ";
	cin >> id;
	while (id < 0) {
		cout << "Error: ID should be non negative!" << endl;
		cout << "Enter ID: ";
		cin >> id;
	}
	User u1(id, login);
	do {
		cout << "========= CAR RENTAL SYSTEM =========" << endl;
		cout << "|1.RENT CAR" << endl;
		cout << "|2.RETURN CAR" << endl;
		cout << "|3.SHOW AVAILABLE CARS" << endl;
		cout << "|4.SEARCH CAR" << endl;
		cout << "|5.SHOW RENTAL HISTORY" << endl;
		cout << "|6.SHOW MOST EXPENSIVE CAR" << endl;
		cout << "=====================================" << endl;
		cout << "|7.ADMIN MENU" << endl;
		cout << "|0.EXIT" << endl;
		cout << "=====================================" << endl;
		cout << "Enter the option: ";
		cin >> exit;
		try {
			switch (exit) {
			case 1:
				//-----------------RENT CAR------------------------------
				cout << "Enter car ID: ";
				cin >> carid;
				cout << "Enter days: ";
				cin >> days;
				found = false;
				for (int k = 0; k < cars.size(); k++) {
					if (cars[k]->getID() == carid) {
						cars[k]->rentCar();
						cost = cars[k]->calculateCost(days);
						cout << "Total cost: " << "$ " << cost << endl;
						u1.addRented(cars[k]->getName());
						found = true;
					}
				}
				if (found == false) {
					throw "Car not found!";
				}
				break;
			case 2:
				//-----------------RETURN CAR---------------------------
				u1.displayRented();
				cout << "Enter car ID: ";
				cin >> returnId;
				found = false;
				for (int k = 0; k < cars.size(); k++) {
					if (cars[k]->getID() == returnId) {
						cars[k]->returnCar();
						found = true;
						cout << "Returned!" << endl;
					}
				}
				if (found == false) {
					throw "Car not found!";
				}
				break;
			case 3:
				//-----------------SHOW AVAILABLE CARS-------------------
				cout << "------- CAR DATA -------" << endl;
				for (int k = 0; k < cars.size(); k++) {
					if (!cars[k]->isRented()) {
						cars[k]->display();
					}
				}
				break;
			case 4:
				//-----------------SEARCH CAR----------------------------
				cout << "Choice the search option:" << endl;
				cout << "1.ID" << endl;
				cout << "2.Brand" << endl;
				cout << "Enter(1 or 2): ";
				cin >> cho;
				if (cho == 1) {
					cout << "Enter ID: ";
					cin >> idi;
					searchCar(cars, idi);
				}
				else if (cho == 2) {
					cout << "Enter brand/name: ";
					cin >> na;
					searchCar(cars, na);
				}
				else {
					throw "Invalid option!";
				}
				break;
			case 5:
				//-----------------SHOW RENTAL HISTORY-------------------
				cout << "---------RENTAL HISTORY-----------" << endl;
				u1.display();
				break;
			case 6:
				//---------------SHOW BEST CAR--------------------------
				if (cars.size() == 0) {
					cout << "No cars available!" << endl;
					break;
				}
				best = cars[0];
				for (int k = 0; k < cars.size(); k++) {
					if (*cars[k] > *best) {
						best = cars[k];
					}
				}
				cout << "------MOST EXPENSIVE CAR--------" << endl;
				best->display();
				break;
			case 7:
				//-----------------ADMIN MENU----------------------------
				int menu;
				do {
					cout << "========= CAR RENTAL SYSTEM (ADMIN) =========" << endl;
					cout << "|1.ADD CAR" << endl;
					cout << "|2.SHOW ALL CARS" << endl;
					cout << "|3.SHOW STATISTICS" << endl;
					cout << "|4.SAVE DATA" << endl;
					cout << "|5.LOAD DATA" << endl;
					cout << "|0.BACK" << endl;
					cout << "=====================================" << endl;
					cout << "Enter the option: ";
					cin >> menu;
						switch (menu) {
						case 1:
							//-----------------ADD CAR------------------------------
							cout << "Enter type: " << endl << "1.Electric" << endl << "2.Luxury" << endl << "3.SUV" << endl;
							cout << "Choice: ";
							cin >> type;
							while (type < 1 || type > 3) {
								cout << "Error: Enter valid choice! " << endl;
								cout << "Enter type: " << endl << "1.Electric" << endl << "2.Luxury" << endl << "3.SUV" << endl;
								cout << "Choice: ";
								cin >> type;
							}
							cout << "Enter ID: ";
							cin >> idCar;
							while (idCar < 0) {
								cout << "Error: ID should be non negative!" << endl;
								cout << "Enter ID: ";
								cin >> idCar;
							}
							cout << "Enter car brand: ";
							cin >> name;
							cout << "Enter the price per day: ";
							cin >> price;
							if (type == 1) {
								cout << "Battery: ";
								cin >> extra;
								cars.push_back(new Electric(idCar, name, price, false, extra));
							}
							else if (type == 2) {
								cout << "Luxury fee: ";
								cin >> extra;
								cars.push_back(new Luxury(idCar, name, price, false, extra));
							}
							else if (type == 3) {
								cout << "SUV extra fee: ";
								cin >> extra;
								cars.push_back(new SUV(idCar, name, price, false, extra));
							}
							cout << "Car added!" << endl;
							break;
						case 2:
							//-----------------SHOW ALL CARS----------------------------
							for (int k = 0; k < cars.size(); k++) {
								cars[k]->display();
							}
							break;
						case 3:
							//-----------------SHOW STATISTICS-------------------
							available = 0;
							rented = 0;
							for (int k = 0; k < cars.size(); k++) {
								if (cars[k]->isRented()) {
									rented++;
								}
								else {
									available++;
								}
							}
							cout << "------- STATISTICS -------" << endl;
							cout << "|Total cars: " << Car::getTotal() << endl;
							cout << "|Avaiable cars: " << available << endl;
							cout << "|Rented cars: " << rented << endl;
							cout << "----------------------------" << endl;
							break;
						case 4:
							//-----------------SAVE DATA----------------------------
							fout.open("cars.txt");
							if (!fout) {
								throw "File cannot be opened!";
							}
							for (int k = 0; k < cars.size(); k++) {
								fout << cars[k]->getID() << endl;
								fout << cars[k]->getName() << endl;
								fout << cars[k]->getPrice() << endl;
							}
							fout.close();
							cout << "Saved!" << endl;
							break;
						case 5:
							//-----------------LOAD DATA-------------------
							fin.open("cars.txt");
							if (!fin) {
								throw "File cannot be opened!";
							}
							while (!fin.eof()) {
								for (int t = 0; t < 3; t++) {
									fin >> line;
									if (fin.eof() == 1) {
										break;
									}
									else {
										cout << line << "\t";
									}
								}
								cout << endl;
							}
							fin.close();
							cout << "Loaded!" << endl;
							break;
						case 0:
							cout << "Admin session ended!" << endl;
							break;
						default:
							cout << "Invalid option!" << endl;
					}
				} while (menu != 0);
				break;
			case 0:
				//-----------------EXIT-------------------------
				cout << "Programm ended!" << endl;
				break;
			default:
				cout << "Invalid option!" << endl;
			}
		}
		catch (const char* msg) {
			cout << "Error: " << msg << endl;
		}
	} while (exit != 0);
	for (int i = 0; i < cars.size(); i++) {
		delete cars[i];
	}
	cout << "Memory cleaned successfully! " << endl;
	return 0;
}