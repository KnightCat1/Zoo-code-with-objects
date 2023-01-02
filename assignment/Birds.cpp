#include "Birds.h"

Birds::Birds() {
	this->m_incubationTime = 0;
}//set the default color to GRAY and other params to 0

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation) : Animal(color, childs, avgLifetime){
	this->m_incubationTime = incubation;
}//init the Birds with a given attributes

Birds::Birds(const Birds& b) : Animal(b){
	this->m_incubationTime = b.m_incubationTime;
}

Birds::Birds(ifstream& in_file) : Animal(in_file){
	loadVarBin(in_file, this->m_incubationTime);
}//init the Birds from a binary file

Birds::~Birds(){}


float Birds::GetIncubationTime() const { return m_incubationTime; }//return the incubation time of the animal

void Birds::SetIncubationTime(float incubationTime){m_incubationTime = incubationTime;}


void Birds::printAdditonalInfo(ofstream& out) const {
	Animal::printAdditonalInfo(out);
	out << this->m_incubationTime << endl;
}//print additonal info

void Birds::getAdditonalInfo(ifstream& in) {
	Animal::getAdditonalInfo(in);
	in >> m_incubationTime;
	in.ignore();
}//get additonal info

void Birds::SaveBin(ofstream& ofs) const {
	Animal::SaveBin(ofs);
	saveVarBin(ofs, this->m_incubationTime);
}//method to save the info to a binary file