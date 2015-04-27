/*
 * room.h
 *
 *  Created on: Apr 25, 2015
 *      Author: Justin
 */

#ifndef ROOM_H_
#define ROOM_H_

#include<iostream>
#include<queue>
#include <string>

#include "doctor.h"
#include "patient.h"

using namespace std;

class Room{
public:
	Room(int n);
	~Room();

	bool hasDr();

	void drArrive(Doctor d);
	void drDepart();
	void patArrive(Patient p);
	void patDepart();

	Doctor getDoctor();
	int numWaiting();
	int roomNumber();
	void enqueue(Patient p);

private:
	int roomNum;
	queue<Patient> waitingRoom;
	Doctor* doctor;
	int docIn;

};

#endif /* ROOM_H_ */
