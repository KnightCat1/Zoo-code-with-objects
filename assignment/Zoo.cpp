#include "Zoo.h"
#include "Animal.h"
#include "Birds.h"
#include "Fish.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Horse.h"
#include "Mammals.h"
#include "MammalsFish.h"
#include "Mermaid.h"


Zoo::Zoo() : m_name(nullptr), m_address(nullptr), m_ticketPrice(0), m_openHours(nullptr), m_closeHours(nullptr), m_numOfAnimals(0), m_animals(nullptr) {}//default c'tor  - all to 0 or null

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close) 
	: m_name(strdup(name)), m_address(strdup(address)), m_ticketPrice(ticket), m_openHours(strdup(open)), m_closeHours(strdup(close)), m_numOfAnimals(0), m_animals(nullptr) {}//c'tor with data - init class

Zoo::Zoo(const Zoo& z) {
	this->m_name = strdup(z.m_name);
	this->m_address = strdup(z.m_address);
	this->m_ticketPrice = z.m_ticketPrice;
	this->m_openHours = strdup(z.m_openHours);
	this->m_closeHours = strdup(z.m_closeHours);
	this->m_animals = new Animal * [z.m_numOfAnimals];
	for (int i = 0; i < z.m_numOfAnimals; i++) {
		this->AddAnimal(z.m_animals[i]);
	}
	this->m_numOfAnimals = z.m_numOfAnimals;
}
Zoo::Zoo(ifstream& in_file) {
	this->m_name = Animal::loadCharBin(in_file, this->m_name);
	this->m_address = Animal::loadCharBin(in_file, this->m_address);
	Animal::loadVarBin(in_file, this->m_ticketPrice);
	this->m_openHours = Animal::loadCharBin(in_file, this->m_openHours);
	this->m_closeHours = Animal::loadCharBin(in_file, this->m_closeHours);
	Animal::loadVarBin(in_file, this->m_numOfAnimals);
	this->m_animals = new Animal * [this->m_numOfAnimals];
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		this->m_animals[i] = loadAnimalBin(in_file);
	}
}//c'tor that gets a binary file and loads the data of the zoo from the file

Animal* Zoo::loadAnimalBin(ifstream& in) {
	int size;
	in.read((char*)&size, sizeof(size));
	char* type = new char[size + 1];
	in.read(type, size + 1);
	type[size] = '\0';
	if (strcmp(type, "Horse") == 0) {
		return new Horse(in);
	}
	else if (strcmp(type, "GoldFish") == 0) {
		return new GoldFish(in);
	}
	else if (strcmp(type, "Mermaid") == 0) {
		return new Mermaid(in);
	}
	else if (strcmp(type, "Flamingo") == 0) {
		return new Flamingo(in);
	}
}
Zoo::~Zoo() {
	delete this->m_name;
	delete this->m_address;
	delete this->m_closeHours;
	delete this->m_openHours;
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		//delete this->m_animals[i];
	}
	delete[] this->m_animals;
}//d'tor


const char* Zoo::GetName() const { return m_name; }//return the name of the zoo
const char* Zoo::GetAddress() const { return m_address; }//return the address of the zoo
float Zoo::GetTicketPrice() const { return m_ticketPrice; }//return the ticket price of the zoo
const char* Zoo::GetOpenHour() const { return m_openHours; }//return the open hour of the zoo
const char* Zoo::GetCloseHour() const { return m_closeHours; }//return the close hour of the zoo
int Zoo::GetNumOfAnimals() const { return m_numOfAnimals; }//return the num of animals in the zoo
Animal** Zoo::GetAnimals() const { return m_animals; }//return the animals array of the zoo


void Zoo::AddAnimal(Animal* an) {
	int size = m_numOfAnimals + 1;
	Animal** tmp = new Animal * [m_numOfAnimals + 1]; // Create new arr

	if (m_numOfAnimals > 0){
		for (int i = 0; i < m_numOfAnimals; i++){
			DeepCopy(m_animals[i], tmp[i]); // Copy this arr of animals to the new arr
		}
	}

	DeepCopy(an, tmp[size - 1]); // Copy the new animal to the last place in the arr

	// Delete this arr
	if (m_numOfAnimals > 0){
		for (int i = 0; i < m_numOfAnimals; i++){
			delete m_animals[i];
		}
		delete[] m_animals;
	}

	m_numOfAnimals++;
	m_animals = tmp; // Copy the new arr to this arr
	//Animal** tmp = new Animal* [this->m_numOfAnimals + 1];
	//if (this->m_numOfAnimals > 0) {
	//	for (int i = 0; i < this->m_numOfAnimals; i++) {
	//		DeepCopy(this->m_animals[i], tmp[i]);
	//	}
	//}
	//if (this->m_numOfAnimals > 0) {
	//	for (int i = 0; i < this->m_numOfAnimals; i++) {
	//		delete this->m_animals[i];
	//	}
	//	delete[] this->m_animals;
	//}
	//DeepCopy(an, tmp[this->m_numOfAnimals]);
	//this->m_numOfAnimals++;
	//
	//this->m_animals = tmp;
}//creates a copy of "an" (deep copy) and adds an animal to the array


Zoo& Zoo::operator+(Animal* an){
	this->AddAnimal(an);
	//Animal** tmp = new Animal * [this->m_numOfAnimals + 1];
	//for (int i = 0; i < this->m_numOfAnimals; i++) {
	//	tmp[i] = (this->m_animals[i]);
	//}
	//tmp[this->m_numOfAnimals] = an;
	//this->m_numOfAnimals++;
	//
	//if (this->m_numOfAnimals > 0) {
	//	for (int i = 0; i < this->m_numOfAnimals; i++) {
	//		delete this->m_animals[i];
	//	}
	//	delete[] this->m_animals;
	//}
	//this->m_animals = new Animal * [this->m_numOfAnimals];
	return *this;
}//adds an animal (only pointer, no copy needed) to the class and returns this with the change

Zoo Zoo::operator+=(Animal* an) {
	this->AddAnimal(an);
	return *this;
}//adds an animal (only pointer, no copy needed) to the class and returns this with the change


Zoo Zoo::operator+(const Zoo& other) const{
	Zoo tmp;
	tmp.m_name = strdup(this->m_name);
	tmp.m_address = strdup(this->m_address);
	tmp.m_ticketPrice = this->m_ticketPrice;
	tmp.m_openHours = strdup(this->m_openHours);
	tmp.m_closeHours = strdup(this->m_closeHours);
	
	int i, j = 0;
	int size = m_numOfAnimals + other.m_numOfAnimals + 1;
	tmp.m_numOfAnimals = 0;
	tmp.m_animals = new Animal * [size];
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		tmp.AddAnimal(this->m_animals[i]);
	}
	for (int i = 0; i < other.m_numOfAnimals; i++) {
		tmp.AddAnimal(other.m_animals[i]);
	}
	tmp.m_numOfAnimals = this->m_numOfAnimals + other.m_numOfAnimals;
	return tmp;
} //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)


ofstream& operator<<(ofstream& out, const Zoo& z) {
	z.Save(out);
	return out;
}//operator to write the zoo to a text file

ifstream& operator>> (ifstream& in, Zoo& z) {
	z.Load(in);
	return in;
}//operator to read the zoo from a text file


void Zoo::Save(ofstream& ofs) const {
	ofs << strlen(this->m_name) << endl;
	ofs << this->m_name << endl;
	
	ofs << strlen(this->m_address) << endl;
	ofs << this->m_address << endl;
	
	ofs << this->m_ticketPrice << endl;
	
	ofs << strlen(this->m_openHours) << endl;
	ofs << this->m_openHours << endl;
	
	ofs << strlen(this->m_closeHours) << endl;
	ofs << this->m_closeHours << endl;
	
	ofs << this->m_numOfAnimals << endl;
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		this->m_animals[i]->printAdditonalInfo(ofs);
	}
}//method to save the info to a text file

void Zoo::Load(ifstream& ifs) {
	m_name = Animal::loadChar(ifs, m_name);
	m_address = Animal::loadChar(ifs, m_address);

	ifs >> m_ticketPrice;
	ifs.ignore();

	m_openHours = Animal::loadChar(ifs, m_openHours);
	m_closeHours = Animal::loadChar(ifs, m_closeHours);

	ifs >> m_numOfAnimals;
	ifs.ignore();
	this->m_animals = new Animal * [this->m_numOfAnimals];
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		LoadName(ifs, this->m_animals[i]);
		this->m_animals[i]->getAdditonalInfo(ifs);
	}
}//method to load the info from a text file

void Zoo::SaveBin(ofstream& ofs) const {
	Animal::saveCharBin(ofs, this->m_name);
	Animal::saveCharBin(ofs, this->m_address);
	Animal::saveVarBin(ofs, this->m_ticketPrice);
	Animal::saveCharBin(ofs, this->m_openHours);
	Animal::saveCharBin(ofs, this->m_closeHours);
	Animal::saveVarBin(ofs, this->m_numOfAnimals);
	for (int i = 0; i < this->m_numOfAnimals; i++) {
		Animal::saveCharBin(ofs, typeid(*this->m_animals[i]).name() + 1);
		this->m_animals[i]->SaveBin(ofs);
	}
}//method to save the info to a binary file


void Zoo::DeepCopy(Animal* sorce, Animal*& dest) {
	if (typeid(*sorce) == typeid(Horse)) {
		Horse* tmp = dynamic_cast<Horse*>(sorce);
		dest = new Horse(*tmp);
	}
	else if (typeid(*sorce) == typeid(Flamingo)) {
		Flamingo* tmp = dynamic_cast<Flamingo*>(sorce);
		dest = new Flamingo(*tmp);
	}
	else if (typeid(*sorce) == typeid(GoldFish)) {
		GoldFish* tmp = dynamic_cast<GoldFish*>(sorce);
		dest = new GoldFish(*tmp);
	}
	else if (typeid(*sorce) == typeid(Mermaid)) {
		Mermaid* tmp = dynamic_cast<Mermaid*>(sorce);
		dest = new Mermaid(*tmp);
	}
}

void Zoo::LoadName(ifstream& in, Animal*& a) {
	char* type = new char[9];
	in.getline(type, 9);
	if (strcmp(type, "Horse") == 0) {
		a = new Horse;
	}
	else if (strcmp(type, "GoldFish") == 0) {
		a = new GoldFish;
	}
	else if (strcmp(type, "Mermaid") == 0) {
		a = new Mermaid;
	}
	else if (strcmp(type, "Flamingo") == 0) {
		a = new Flamingo;
	}
}