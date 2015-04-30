/*
 * room.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "room.h"

Room::Room(){
	roomNum = -1;
	doctor = 0;
	patient = 0;
	queue<Patient> waitingRoom;
	docIn = 0;
}

Room::Room(int n){
	roomNum = n;
	doctor = 0;
	patient = 0;
	queue<Patient> waitingRoom;
	docIn = 0;
}


Room::~Room(){
}

void Room::setRmNum(int r){
	roomNum = r;
}

bool Room::hasDr(){
	if(docIn == 1)
		return true;

	return false;
}

void Room::drArrive(Doctor d){
	doctor = &d;
	docIn = 1;
}

void Room::drDepart(){
	delete doctor;
	docIn = 0;
}

void Room::patArrive(Patient p){
	waitingRoom.push(p);
}

Patient Room::patDepart(){              //ASK JOHN!!!!!!!!!!!!!!!!!!!!!!
	Patient cured = waitingRoom.front();
	waitingRoom.pop();
	return cured;
}

Doctor Room::getDoctor(){
	return *doctor;     //RETURNING THE DE-REFERENCED DOCTOR  FAIL?
}

int Room::numWaiting(){
	return waitingRoom.size();
}

int Room::roomNumber(){
	return roomNum;
}

Patient Room::getPatient(){
	return *patient;
}
