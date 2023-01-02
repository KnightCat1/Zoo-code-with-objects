#include "Mermaid.h"

Mermaid::Mermaid() {
	this->m_firstName = nullptr;
	this->m_lastName = nullptr;
}//set the default color to GRAY and other params to 0

Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
	: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills) {
	this->m_firstName = nullptr;
	this->m_lastName = nullptr;
	SetFirstName(firstName);
	SetLastName(lastName);
}//init the Mermaid with a given attributes

Mermaid::Mermaid(const Mermaid& m) : Animal(m), MammalsFish(m) {
	this->m_firstName = strdup(m.m_firstName);
	this->m_lastName = strdup(m.m_lastName);
}

Mermaid::Mermaid(ifstream& in_file) : Animal(in_file), MammalsFish(in_file) {
	this->m_firstName = loadCharBin(in_file, this->m_firstName);
	this->m_lastName = loadCharBin(in_file, this->m_lastName);
}//init the Mermaid from a binary file{

Mermaid::~Mermaid() {
	delete m_firstName;
	delete m_lastName;
}


const char* Mermaid::GetFirstName() const { return m_firstName; }//return the first name of the mermaid
const char* Mermaid::GetLastName() const { return m_lastName; }//return the last name of the mermaid

void Mermaid::SetFirstName(const char* firstName){
	if (m_firstName != nullptr)
		delete[] m_firstName;
	m_firstName = strdup(firstName);
}
void Mermaid::SetLastName(const char* lastName){
	if (m_lastName != nullptr)
		delete[] m_lastName;
	m_lastName = strdup(lastName);
}


void  Mermaid::printAdditonalInfo(ofstream& out) const {
	MammalsFish::printAdditonalInfo(out);
	out << strlen(this->m_firstName) << endl;
	out << this->m_firstName << endl;
	out << strlen(this->m_lastName) << endl;
	out << this->m_lastName << endl;
}//print additonal info

void Mermaid::getAdditonalInfo(ifstream& in) {
	MammalsFish::getAdditonalInfo(in);
	m_firstName = loadChar(in, m_firstName);
	m_lastName = loadChar(in, m_lastName);
}//get additonal info

void Mermaid::SaveBin(ofstream& ofs) const {
	MammalsFish::SaveBin(ofs);
	saveCharBin(ofs, this->m_firstName);
	saveCharBin(ofs, this->m_lastName);
}//method to save the info to a binary file