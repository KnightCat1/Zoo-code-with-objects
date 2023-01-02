#include "Mammals.h"

Mammals::Mammals() {
	this->m_pregnancyTime = 0;
	this->m_milkLiters = 0;
}//set the default color to GRAY and other params to 0

Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk) : Animal(color, childs, avgLifetime){
	this->m_pregnancyTime = preg;
	this->m_milkLiters = milk;
}//init the Mammals with a given attributes

Mammals::Mammals(const Mammals& m) : Animal(m) {
	this->m_pregnancyTime = m.m_pregnancyTime;
	this->m_milkLiters = m.m_milkLiters;
}

Mammals::Mammals(ifstream& in_file) :Animal(in_file){
	loadVarBin(in_file, this->m_milkLiters);
	loadVarBin(in_file, this->m_pregnancyTime);
}//init the Mammals from a binary file

Mammals::~Mammals() {}

void Mammals::SetPreg(float pregnancyTime){m_pregnancyTime = pregnancyTime;}
void Mammals::SetMilk(float milkLiters){m_milkLiters = milkLiters;}

float Mammals::GetPregnanceTime() const { return m_pregnancyTime; }//return the pregnance time of the animal
float Mammals::GetMilk() const { return m_milkLiters; }//return the milk liters of the animal


void Mammals::printAdditonalInfo(ofstream& out) const {
	Animal::printAdditonalInfo(out);
	out << this->m_pregnancyTime << endl;
	out << this->m_milkLiters << endl;
}//print additonal info

void Mammals::getAdditonalInfo(ifstream& in) {
	Animal::getAdditonalInfo(in);
	
	in >> m_pregnancyTime;
	in.ignore();
	
	in >> m_milkLiters;
	in.ignore();
}//get additonal info

void  Mammals::SaveBin(ofstream& ofs) const {
	Animal::SaveBin(ofs);
	saveVarBin(ofs, this->m_milkLiters);
	saveVarBin(ofs, this->m_pregnancyTime);
}//method to save the info to a binary file