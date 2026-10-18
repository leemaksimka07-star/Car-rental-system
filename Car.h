#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Car {
private:
	int id;
	string name;
	double price;
	bool rent;
	static int total;
public:
	Car() {
		id = 0;
		name = " ";
		price = 0;
		rent = false;
		total++;
	}
	Car(int idid, string namik, double pri, bool ren) {
		if (idid < 0) {
			id = 0;
			throw "ID is negative!";
		}
		else {
			id = idid;
		}
		name = namik;
		if (pri < 0) {
			price = 0;
			throw "Price is negative! ";
		}
		else {
			price = pri;
		}
		rent = ren;
		total++;
	}
	//rent functions
	void rentCar() {
		if (rent) {
			throw "Car is already rented!";
		}
		rent = true;
	}
	void returnCar() {
		if (!rent) {
			throw "Car is not rented!";
		}
		rent = false;
	}
	bool isRented() const{
		return rent;
	}
	//setters
	void setID(int idid) {
		if (idid < 0) {
			id = 0;
			throw "ID is negative!";
		}
		else {
			id = idid;
		}
	}
	void setName(string nam) {
		name = nam;
	}
	void setPrice(double pri) {
		if (pri < 0) {
			price = 0;
			throw "Price is negative! ";
		}
		else {
			price = pri;
		}
	}
	//getters
	int getID() const{
		return id;
	}
	string getName() const{
		return name;
	}
	double getPrice()  const{
		return price;
	}
	void displayCar() const{
		cout << "Car ID: " << id << endl;
		cout << "Car brand: " << name << endl;
		cout << "Price per day: " << price << endl;
		if (rent) {
			cout << "Status: rented" << endl;
		}
		else {
			cout << "Status: available" << endl;
		}
	}
	virtual ~Car() = 0;
	virtual double calculateCost(int days) = 0;
	virtual void display() = 0;
	static int getTotal() {
		return total;
	}
	bool operator>(const Car& other) const {
		return price > other.price;
	}
};
Car::~Car() {
	total--;
};
int Car::total = 0;
class Electric : public Car {
private:
	double battery;
public:
	Electric(int idid, string namik, double pri,bool ret, double batt): Car(idid, namik, pri, ret) {
		if (batt < 0 || batt > 100) {
			battery = 0;
		}
		else {
			battery = batt;
		}
		
	}
	~Electric() override {};
	double calculateCost(int days) override {
		return getPrice() * days;
	}
	double getBattery() {
		return battery;
	}
	void setBattery(double batt) {
		if (batt < 0 || batt > 100) {
			battery = 0;
		}
		else {
			battery = batt;
		}
	}
	void display() override{
		displayCar();
		cout << "Battery: " << battery << endl;
		cout << "-----------------------" << endl;
	}
};
class Luxury : public Car {
private: 
	double fee;
public:
	Luxury(int idid, string namik, double pri, bool ret, double fee_int) : Car(idid, namik, pri, ret){
		if (fee_int < 0) {
			fee = 0;
		}
		else {
			fee = fee_int;
		}
	}
	double getFee() const{
		return fee;
	}
	void setFee(double fee_int) {
		if (fee_int < 0) {
			fee = 0;
		}
		else {
			fee = fee_int;
		}
	}
	void display() override{
		displayCar();
		cout << "Luxury fee: " << fee << endl;
		cout << "-----------------------" << endl;

	}
	~Luxury() override {};
	double calculateCost(int days) override{
		return getPrice() * days + fee;
	}
};
class SUV:public Car {
private:
	double extra_fee;
public:
	SUV(int idid, string namik, double pri, bool ret, double extra) :Car(idid, namik, pri, ret) {
		if (extra < 0) {
			extra_fee = 0;
			throw "Extra fee shouldn't be negative!";
		}
		else {
			extra_fee = extra;
		}
	}
	double getExtra() const {
		return extra_fee;
	}
	void setExtra(double extra) {
		if (extra < 0) {
			extra_fee = 0;
			throw "Extra fee shouldn't be negative!";
		}
		else {
			extra_fee = extra;
		}
	}
	~SUV() {};
	double calculateCost(int days) override{
		return getPrice() * days + extra_fee;
	}
	void display() override {
		displayCar();
		cout << "Extra fee: " << extra_fee << endl;
		cout << "-----------------------" << endl;
	}

};
void searchCar(const vector<Car*> cars, int id) {
	bool found = false;
	cout << "-----------------------" << endl;
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i]->getID() == id) {
			cars[i]->display();
			found = true;
		}
	}
	if (found == false) {
		cout << "Car not found!" << endl;
	}
}
void searchCar(const vector<Car*> cars, string name) {
	bool found = false;
	cout << "-------------------" << endl;
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i]->getName() == name) {
			cars[i]->display();
			found = true;
		}
	}
	if (found == false) {
		cout << "Car not found!" << endl;
	}
}



