/*
 * register.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: schaeferj
 */
#include<iostream>
#include<fstream>

#include "room.h"
#include<vector>
#include<string>

using namespace std;

int main(){

	ofstream out;      //OUTPUT MESSAGES
	out.open("messages.out");


	vector<Room> rooms;
	rooms[25];

	char regType;
	string type;
	int track = 0;

	cout << "Wecome! Please follow our guided check-in process" << endl;
	cout << endl;
	cout << "Please type \"D\" if you are a doctor, or \"P\" if you are a patient." << endl;

	cin >> regType;

	while (regType != 'D' && regType != 'd' && regType != 'P'&& regType != 'p'){
		cout << "Invalid selection. Please try again." << endl;
		cin >> regType;
	}

	regType = toupper(regType);

	if(regType == 'D'){
		string name;
		int room;
		string spec;

		cout << "What is your name?" << endl;
		cin >> name;
		cout << "What is your specialty" << endl;
		cin >> spec;
		cout << "What room would you prefer? Choose 1-25" << endl;
		cin >> room;

		while(rooms.at(room).hasDr()){
			cout << "Room occupied." << endl;
			cout << "Please select another room. Choose 1-25" << endl;
			cin >> room;
		}

		Doctor* doc = new Doctor(name, spec, room);

		rooms.at(room-1).drArrive(*doc);   //Assigns doctor to room.

	} else if(regType == 'P'){
		string name;
		int age;
		string spec;

		cout << "What is your name?" << endl;
		cin >> name;
		cout << "What is your age" << endl;
		cin >> age;

		if(age > 15){
			cout << "What type of doctor would you like to see?" << endl;
			cin >> spec;
		} else {
			spec = "ped";
		}

		Patient* pat = new Patient(name, spec, age);

		for(int x=0;x<25;x++){
			if(rooms.at(x).hasDr()){
				type = rooms.at(x).getDoctor().getDrSpec();
				if(type == pat->getSpec()){
					rooms.at(x).patArrive(*pat);
					track = 1;
				}
			}
		}

		if(track == 0){
			cout << "We are sorry, we do not have the required specialits on duty at this moment" << endl;
		}
	}

} //END MAIN
