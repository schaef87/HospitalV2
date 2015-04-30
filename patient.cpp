/*
 * patient.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "patient.h"

Patient::Patient(){
	name = "0";
	spec = "0";
	age = 0;
}

Patient::Patient(string n, string s, int a){
	name = n;
	spec = s;
	age = a;
}

Patient::~Patient(){
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

void Patient::operator= (Patient p){
	if(this!=&p){
		name=p.name;
		spec=p.spec;
		age=p.age;
		room=p.room;
	}
}
