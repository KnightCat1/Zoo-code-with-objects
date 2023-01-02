#include "Fish.h"

Fish::Fish() {
	this->m_finCount = 0;
	this->m_gillsCount = 0;
}//set the default color to GRAY and other params to 0

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime){
	this->m_finCount = fin;
	this->m_gillsCount = gills;
}//init the Fish with a given attributes

Fish::Fish(const Fish& f) : Animal(f) {
	this->m_finCount = f.m_finCount;
	this->m_gillsCount = f.m_gillsCount;
}

Fish::Fish(ifstream& in_file) :Animal(in_file){
	loadVarBin(in_file, this->m_finCount);
	loadVarBin(in_file, this->m_gillsCount);
}//init the Fish from a binary file

Fish::~Fish(){}


int Fish::GetFinCount() const { return m_finCount; }//return the fin count of the animal
int	Fish::GetGillsCount() const { return m_gillsCount; }//return the gills count of the animal

void Fish::SetFinCount(int finCount){m_finCount = finCount;}
void Fish::SetGillsCount(int gillsCount){m_gillsCount = gillsCount;}


void Fish::printAdditonalInfo(ofstream& out) const {
	Animal::printAdditonalInfo(out);
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;
}//print additonal info

void Fish::getAdditonalInfo(ifstream& in) {
	Animal::getAdditonalInfo(in);
	in >> m_finCount;
	in.ignore();
	
	in >> m_gillsCount;
	in.ignore();
}//get additonal info

void Fish::SaveBin(ofstream& ofs) const {
	Animal::SaveBin(ofs);
	saveVarBin(ofs, this->m_finCount);
	saveVarBin(ofs, this->m_gillsCount);
}//method to save the info to a binary file