#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds( const char* color, int childs, float avgLifetime, float incubation );
	Birds(const Birds& b);
	//init the Birds with a given attributes
	Birds( ifstream& in_file );//init the Birds from a binary file
	virtual ~Birds();

public:
	float		GetIncubationTime() const;
	void SetIncubationTime(float incubationTime);
	//return the incubation time of the animal
	
protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	virtual void SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	float m_incubationTime;
};

#endif // ifndef