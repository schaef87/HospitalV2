/*
 * doctor.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "doctor.h"

Doctor::Doctor(string n, string s, int r){
	name = n;
	spec = s;
	room = r;
}

Doctor::~Doctor(){
	delete this;
}

string Doctor::getDrName(){
	return name;
}

string Doctor::getDrSpec(){
	return spec;
}

int Doctor::getDrRoom(){
	return room;
}
