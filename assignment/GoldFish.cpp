#include "GoldFish.h"

GoldFish::GoldFish() {
	this->m_avgWeight = 0;
	this->m_avgLength = 0;
}//set the default color to GRAY and other params to 0

GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) 
	: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills) {
	this->m_avgWeight = avgW;
	this->m_avgLength = avgL;
}//init the GoldFish with a given attributes

GoldFish::GoldFish(const GoldFish& gf) : Animal(gf), MammalsFish(gf) {
	this->m_avgWeight = gf.m_avgWeight;
	this->m_avgLength = gf.m_avgLength;
}

GoldFish::GoldFish(ifstream& in_file) : Animal(in_file), MammalsFish(in_file) {
	loadVarBin(in_file, this->m_avgWeight);
	loadVarBin(in_file, this->m_avgLength);
}//init the GoldFish from a binary file

GoldFish::~GoldFish() {}


float GoldFish::GetWeight() const { return m_avgWeight; }//return the avg weight of the gold fish
float GoldFish::GetLength() const { return m_avgLength; }//return the avg length of the gold fish

void GoldFish::SetWeight(float avgWeight){m_avgWeight = avgWeight;}
void GoldFish::SetLength(float avgLength){m_avgLength = avgLength;}


void GoldFish::printAdditonalInfo(ofstream& out) const {
	MammalsFish::printAdditonalInfo(out);
	out << this->m_avgWeight << endl;
	out << this->m_avgLength << endl;
}//print additonal info

void GoldFish::getAdditonalInfo(ifstream& in) {
	MammalsFish::getAdditonalInfo(in);
	in >> m_avgWeight;
	in.ignore();

	in >> m_avgLength;
	in.ignore();
}//get additonal info

void GoldFish::SaveBin(ofstream& ofs) const {
	MammalsFish::SaveBin(ofs);
	saveVarBin(ofs, this->m_avgWeight);
	saveVarBin(ofs, this->m_avgLength);
}//method to save the info to a binary file