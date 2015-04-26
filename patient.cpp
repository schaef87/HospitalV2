/*
 * patient.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "patient.h"

Patient::Patient(string n, string s, int a){
	name = n;
	spec = s;
	age = a;
}

Patient::~Patient(){
	delete this;
}

string Patient::getName(){
	return name;
}

string Patient::getSpec(){
	return spec;
}

int Patient::getAge(){
	return age;
}

int Patient::getRoom(){
	return room;
}

void Patient::setRoom(int r){
	room = r;
}
