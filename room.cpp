/*
 * room.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#include "room.h"


Room::Room(int n){
	roomNum = n;
	doctor = 0;
	queue<Patient> waitingRoom;
	docIn = 0;
}

Room::~Room(){
	delete this;
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

void Room::patDepart(){
	waitingRoom.pop();
}

Doctor Room::getDoctor(){
	return *doctor;
}

int Room::numWaiting(){
	return waitingRoom.size();
}

int Room::roomNumber(){
	return roomNum;
}
//
//void Room::enqueue(Patient p){
//	waitingRoom.enqueue(p);
//}
