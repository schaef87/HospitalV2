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
	Room();
	Room(int n);
	~Room();

	bool hasDr();

	void setRmNum(int r);
	void drArrive(Doctor &d);
	void drDepart();
	void patArrive(const Patient *p);
	void patShuffle(Patient p);
	Patient patDepart();

	Doctor getDoctor();
	Patient* getPatient();
	int numWaiting();
	int roomNumber();

private:
	int roomNum;
	queue<Patient> waitingRoom;
	Doctor* doctor;
	int docIn;
	Patient* patient;

};

#endif /* ROOM_H_ */
