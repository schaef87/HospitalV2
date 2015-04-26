/*
 * room.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "room.h"


Room::Room(int n){
	roomNum = n;
	Doctor* doctor;
	queue<Patient> waitingRoom;
	docIn = 0;
}

Room::~Room(){
	delete this;
}

bool hasDr(){
	bool dr = false;
	if(docIn == 1){
		dr = true;
	}
	return dr;
}

void Room::drArrive(Doctor d){
	doctor = &d;
	docIn = 1;
}

void Room::drDepart(){

	docIn = 0;
}

void patArrive(Patient p){
	waitingRoom.push(p);
}

void patDepart(){
	waitingRoom.pop();
}

string Room::getDoctor(){
	return doctor.getDrName();
}

int Room::numWaiting(){
	return waitingRoom.size();
}

int Room::roomNumber(){
	return roomNum;
}
