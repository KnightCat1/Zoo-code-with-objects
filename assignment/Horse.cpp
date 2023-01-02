#include "Horse.h"

Horse::Horse() : Animal(), Mammals() {
	this->m_type = nullptr;
}//set the default color to GRAY and other params to 0

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) 
	: Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk){
	this->m_type = strdup(type);
}//init the Horse with a given attributes

Horse::Horse(const Horse& h) : Animal(h), Mammals(h) {
	this->m_type = strdup(h.m_type);
}

Horse::Horse(ifstream& in_file) :Animal(in_file), Mammals(in_file) {
	this->m_type = loadCharBin(in_file, this->m_type);
}//init the Horse from a binary file

Horse::~Horse() { 
	delete m_type;
}


const char* Horse::GetType() const { return m_type; }//return the type of the horse
void Horse::SetType(char* type) {
	if (m_type != nullptr)
		delete[] m_type;
	m_type = strdup(type);
}

void Horse::printAdditonalInfo(ofstream& out) const {
	Mammals::printAdditonalInfo(out);
	out << strlen(this->m_type) << endl;
	out << this->m_type << endl;
}//print additonal info

void Horse::getAdditonalInfo(ifstream& in) {
	Mammals::getAdditonalInfo(in);
	m_type = loadChar(in, m_type);
}//get additonal info

void Horse::SaveBin(ofstream& ofs) const {
	Mammals::SaveBin(ofs);
	saveCharBin(ofs, this->m_type);
}//method to save the info to a binary file