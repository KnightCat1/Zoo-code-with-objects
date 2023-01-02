#include "Flamingo.h"

Flamingo::Flamingo() {
	this->m_avgHeight = 0;
}//set the default color to GRAY and other params to 0

Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color, childs, avgLifetime, incubation) {
	this->m_avgHeight = avgHeight;
}//init the Flamingo with a given attributes

Flamingo::Flamingo(const Flamingo& f) : Birds(f) {
	this->m_avgHeight = f.m_avgHeight;
}

Flamingo::Flamingo(ifstream& in_file) : Birds(in_file) {
	loadVarBin(in_file, this->m_avgHeight);
}//init the Flamingo from a binary file

Flamingo::~Flamingo() {}


float Flamingo::GetHeight() const { return m_avgHeight; }//return the avg height of the flamingo


void Flamingo::printAdditonalInfo(ofstream& out) const {
	Birds::printAdditonalInfo(out);
	out << this->m_avgHeight << endl;
}//print additonal info

void Flamingo::getAdditonalInfo(ifstream& in) {
	Birds::getAdditonalInfo(in);
	in >> m_avgHeight;
	in.ignore();
}//get additonal info

void Flamingo::SaveBin(ofstream& ofs) const {
	Birds::SaveBin(ofs);
	saveVarBin(ofs, this->m_avgHeight);
}//method to save the info to a binary file