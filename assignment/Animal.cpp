#include "Animal.h"

Animal::Animal(){
	this->m_color = strdup("GRAY");
	this->m_childCount = 0;
	this->m_avgLifetime = 0;
}//set the default color to GRAY and other params to 0

Animal::Animal(const char* color, int childs, float avgLifetime) {
	this->m_color = strdup(color);
	this->m_avgLifetime = avgLifetime;
	this->m_childCount = childs;
}//init the Animal with a given attributes

Animal::Animal(const Animal& a) {
	this->m_color = strdup(a.m_color);
	this->m_avgLifetime = a.m_avgLifetime;
	this->m_childCount = a.m_childCount;
}

Animal::Animal(ifstream& in_file) {
	this->m_color = loadCharBin(in_file, this->m_color);
	loadVarBin(in_file, this->m_avgLifetime);
	loadVarBin(in_file, this->m_childCount);
}//init the Animal from a binary file

Animal::~Animal() {
	delete m_color;
}


const char* Animal::GetColor() const { return m_color; }//return the color of the animal
int	Animal::GetChildCount() const { return m_childCount; }//return the child count of the animal
float Animal::GetLifetime() const { return m_avgLifetime; }//return the life time of the animal

void Animal::SetColor(const char* color) {
	if (m_color != nullptr)
		delete[] this->m_color;
	m_color = strdup(color);
};
void Animal::SetChildCount(int count) { m_childCount = count; };
void Animal::SetLifetime(float lifetime) { m_avgLifetime = lifetime; };


void Animal::printAdditonalInfo(ofstream& out) const{
	this->saveName(out);
	out << strlen(this->m_color) << endl;
	out << this->m_color << endl;
	out << this->m_avgLifetime << endl;
	out << this->m_childCount << endl;
}

void Animal::getAdditonalInfo(ifstream& in){
	m_color = loadChar(in, m_color);

	in >> m_avgLifetime;
	in.ignore();

	in >> m_childCount;
	in.ignore();
}

void Animal::SaveBin(ofstream& ofs) const {
	saveCharBin(ofs, this->m_color);
	saveVarBin(ofs, this->m_avgLifetime);
	saveVarBin(ofs, this->m_childCount);
}//method to save the info to a binary file
