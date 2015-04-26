/*
 * patient.h
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include<iostream>
#include<queue>
#include <string>

using namespace std;

class Patient{
public:
	Patient(string n, string s, int a);
	~Patient();

	string getName();
	string getSpec();
	int getAge();
	int getRoom();
	void setRoom(int r);

private:
	string name;
	string spec;
	int age;
	int room = -1;
};



#endif /* PATIENT_H_ */
