#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class User {
private:
	int id;
	string name;
	vector<string> rented;
public:
	User() {
		id = 0;
		name = " ";
	}
	User(int idid, string namik) {
		if (idid < 0) {
			id = 0;
			throw "Id is negative!";
		}
		else {
			id = idid;
		}
		name = namik;
	}
	//setters
	void setID(int idid) {
		if (idid < 0) {
			id = 0;
			throw "Id is negative!";
		}
		else {
			id = idid;
		}
	}
	void setName(string namik) {
		name = namik;
	}
	//getters
	int getID() const{
		return id;
	}
	string getName() const {
		return name;
	}
	//vector functions
	void addRented(string cars) {
		rented.push_back(cars);
	}
	string getRented(int num) {
		return rented[num - 1];
	}
	void removeRented(int num) {
		rented.erase(rented.begin() + num - 1);
	}
	void displayRented() {
		cout << "Rented cars by user: " << endl;
		for (int i = 0; i < rented.size(); i++) {
			cout << rented[i] << endl;
		}
	}
	void display() {
		cout << "---------- User Data ---------" << endl;
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "----- Rented cars -----" << endl;
		for (int i = 0; i < rented.size(); i++) {
			cout << rented[i] << endl;
		}
	}
	~User() {};
};

