#include "MammalsFish.h"

MammalsFish::MammalsFish() {}//set the default color to GRAY and other params to 0

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) 
	: Mammals(color, childs, avgLifetime, preg, milk) {
	this->m_finCount = fin;
	this->m_gillsCount = gills;
} //init the MammalsFish with a given attributes

MammalsFish::MammalsFish(const MammalsFish& mf) : Mammals(mf) {
	this->m_finCount = mf.m_finCount;
	this->m_gillsCount = mf.m_gillsCount;
}

MammalsFish::MammalsFish(ifstream& in_file): Mammals(in_file) {
	loadVarBin(in_file, this->m_finCount);
	loadVarBin(in_file, this->m_gillsCount);
}//init the MammalsFish from a binary file

MammalsFish::~MammalsFish() {}


void MammalsFish::printAdditonalInfo(ofstream& out) const {
	Mammals::printAdditonalInfo(out);
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;
	//Fish::printAdditonalInfo(out);
}//print additonal info

void MammalsFish::getAdditonalInfo(ifstream& in) {
	Mammals::getAdditonalInfo(in);
	in >> m_finCount;
	in.ignore();

	in >> m_gillsCount;
	in.ignore();
	//Fish::getAdditonalInfo(in);
}//get additonal info


void MammalsFish::SaveBin(ofstream& ofs) const {
	Mammals::SaveBin(ofs);
	saveVarBin(ofs, this->m_finCount);
	saveVarBin(ofs, this->m_gillsCount);
	//Fish::SaveBin(ofs);
}//method to save the info to a binary file