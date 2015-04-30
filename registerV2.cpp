/*
 * registerV2.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: Justin
 */

#include<iostream>
#include<fstream>

#include "room.h"
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

void doctorCI();
void doctorCO();
void patientCI();
void patientCO();
void autoCheckIn(Patient p);
string specList();
vector<Room> rooms;

ofstream out;  //OUTPUT MESSAGES

int main(){

	char checkIO;
	char levelIO;

	do{
		out.open("messages.out");

		for(int x = 0;x<25;x++){
			Room temp(x);
			rooms.push_back(temp);
		}

		cout << "Wecome! Please follow our guided check-in process" << endl;
		cout << endl;
		cout << "Please type \"D\" if you are a doctor, or \"P\" if you are a patient." << endl;
		out << "Please type \"D\" if you are a doctor, or \"P\" if you are a patient." << endl;

		cin >> levelIO;
		levelIO = toupper(levelIO);

		while (levelIO != 'D' && levelIO != 'P'){
			cout << "Invalid selection. Please try again." << endl;
			cin >> levelIO;
			levelIO = toupper(levelIO);
		}

		if(levelIO == 'D'){
			cout << "Are you checking in our out? \"I\" or \"O\"" << endl;
			cin >> checkIO;
			checkIO = toupper(checkIO);

			while (checkIO != 'I' && checkIO != 'O'){
				cout << "Invalid selection. Please try again." << endl;
				cin >> checkIO;
				checkIO = toupper(checkIO);
			}

			if(checkIO == 'I'){
				doctorCI();
			} else {
				doctorCO();
			}
		} else {
			cout << "Are you checking in our out? \"I\" or \"O\"" << endl;
			cin >> checkIO;
			checkIO = toupper(checkIO);

			while (checkIO != 'I' && checkIO != 'O'){
				cout << "Invalid selection. Please try again." << endl;
				cin >> checkIO;
				checkIO = toupper(checkIO);
			}

			if(checkIO == 'I'){
				patientCI();
			} else {
				patientCO();
			}
		}
	}while(levelIO != 'Q');
	//END WHILE LOOP
	out.close();
}

void doctorCI(){
	out.open("messages.out");
	string name;
	int room;
	string spec;
	//	bool check;

	cout << "What is your name?" << endl;
	cin >> name;
	spec = specList();
	cout << "What room would you prefer? Choose 1-25" << endl;
	cin >> room;

	//	do{                     //Prevent non int types.
	//		check=false;
	//
	//	}

	while(rooms.at(room-1).hasDr()){
		cout << "Room occupied." << endl;
		cout << "Please select another room. Choose 1-25" << endl;
		cin >> room;
	}

	Doctor* doc = new Doctor(name, spec, room);

	cout << "Welcome, Dr. " << doc->getDrName() << "." << endl;
	out << "Welcome, Dr. " << doc->getDrName() << "." << endl;

	rooms.at(room-1).drArrive(*doc);   //Assigns doctor to room.
}

void doctorCO(){
	out.open("messages.out");
	string name;
	Patient *tempPat;
	int tracker;

	cout << "What is your name?" << endl;
	cin >> name;

	for(tracker=0;tracker<25;tracker++){
		if(name == rooms.at(tracker).getDoctor().getDrName())
			break;
	}

	cout << "Thank you. Your patients are being re-assigned." << endl;
	out << "Dr. " << name << " has departed. Patients are being re-assigned." << endl;
	rooms.at(tracker).drDepart();

	while(rooms.at(tracker).numWaiting() != 0){
		*tempPat = rooms.at(tracker).patDepart();
		autoCheckIn(*tempPat);
	}
}

void autoCheckIn(Patient p){
	out.open("messages.out");
	Patient pTest = Patient();
	pTest = p;
	string name;
	string spec;
	string type;
	int track;

	int docTrack;
	for(int x=0;x<25;x++){
		int count = 0;
		if(rooms.at(x).hasDr()){
			if (rooms.at(x).getDoctor().getDrSpec() == "FP"){
				docTrack = x;
			}
			type = rooms.at(x).getDoctor().getDrSpec();
			if(type == p.getSpec()){
				p.setRoom(x);
				rooms.at(x).patArrive(p);
				track = 1;
				cout << p.getName() << ", you have been assigned to Dr. " << rooms.at(x).getDoctor().getDrName() << " in room "<< rooms.at(x).roomNumber() << endl;
				out << p.getName() << ", has been relocated to Dr. " << rooms.at(x).getDoctor().getDrName() << " in room " << rooms.at(x).roomNumber() << endl;
			} else if(type != p.getSpec() && count == 24){
				p.setRoom(x);
				rooms.at(docTrack).patArrive(p);
				track = 1;
			}
		}
	}

	if(track ==0){
		int waitList = 0;

		for(int x=0;x<25;x++){
			if(rooms.at(x).hasDr()){
				if(waitList > rooms.at(x).numWaiting()){
					waitList = rooms.at(x).numWaiting();
				}
			}
		}

		cout << p.getName() << ", you have been assigned to Dr. " << rooms.at(waitList).getDoctor().getDrName() << " in room "<< rooms.at(waitList).roomNumber() << endl;
		out << p.getName() << ", has been relocated to Dr. " << rooms.at(waitList).getDoctor().getDrName() << " in room " << rooms.at(waitList).roomNumber() << endl;

		rooms.at(waitList).patArrive(p);
	}
}

void patientCI(){
	out.open("messages.out");
	string name;
	string drName;
	string spec;
	string drSpec;
	int track;
	int age;

	cout << "What is your name?" << endl;
	cin >> name;
	cout << "What is your age" << endl;
	cin >> age;

	if(age > 15){
		spec = specList();
	} else {
		spec = "PED";
	}

	Patient *pat = new Patient(name, spec, age);

	int docTrack;
	for(int x=0;x<25;x++){  //**F6 PAST HERE
		int count = 0;
		if(rooms.at(x).hasDr()){  //WORKS UP TO HERE  **F6 PAST HERE
			drName = rooms.at(x).getDoctor().getDrName();
			if (rooms.at(x).getDoctor().getDrSpec() == "FP"){
				docTrack = x;
			}
			drSpec = rooms.at(x).getDoctor().getDrSpec();
			if(drSpec == pat->getSpec()){
				pat->setRoom(x+1);
				rooms.at(x).patArrive(*pat);
				track = 1;
				cout << "Welcome, " << pat->getName() << ". You will see Dr. " << drName << " in room #" << x+1 << endl;
				out << pat->getName() << " will see Dr. " << drName << " in room #" << x+1 << endl;
			} else if(drSpec != pat->getSpec() && count == 24){
				pat->setRoom(x+1);
				rooms.at(docTrack).patArrive(*pat);
				track = 1;
			}
		}
	}

	if(track == 0){
		cout << "We are sorry, " << pat->getName() << " we do not have the required specialist on duty at this moment" << endl;
		out << "We are sorry, " << pat->getName() << " we do not have the required specialist on duty at this moment" << endl;
	}
}

void patientCO(){
	out.open("messages.out");
	string name;
	int tracker;

	cout << "Please enter your name." << endl;
	cin >> name;

	for(tracker=0;tracker<25;tracker++){
		if(name == rooms.at(tracker).getPatient().getName()){
			break;
		}

		cout << "Thank you for trusting us " << name << ". Have a wonderful day " << name << endl;
	}
}

string specList(){
	string input;
	string options[11];

	options[0]="PED";
	options[1]="FAM";
	options[2]="INT";
	options[3]="CAR";
	options[4]="SUR";
	options[5]="OBS";
	options[6]="PSY";
	options[7]="NEU";
	options[8]="ORT";
	options[9]="DET";
	options[10]="OPT";
	options[11]="ENT";


	cout << "Please enter a specialty code." << endl;
	cout << endl;
	cout << "Pediatrics\t\tPED" << endl;
	cout << "Family practice\t\tFAM" << endl;
	cout << "Internal medicine\tINT" << endl;
	cout << "Cardiology\t\tCAR" << endl;
	cout << "Surgeon\t\t\tSUR" << endl;
	cout << "Obstetrics\t\tOBS" << endl;
	cout << "Psychiatry\t\tPSY" << endl;
	cout << "Neurology\t\tNEU" << endl;
	cout << "Orthopedics\t\tORT" << endl;
	cout << "Dermatology\t\tDET" << endl;
	cout << "Ophthalmology\t\tOPT" << endl;
	cout << "Ear, Nose, and Throat\tENT" << endl;

	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::toupper);

	int track = 0;
	int x;
	while(track == 0){
		for(x = 0;x<12;x++){
			if(input == options[x]){
				track = 1;
				break;
			}
		}
		if(track == 0){
			cout << "Invalid selection. Try again." << endl;
		}
	}

	cout << options[x] << endl;
	return options[x];
}
