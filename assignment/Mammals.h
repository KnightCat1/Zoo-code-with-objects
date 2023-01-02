#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals : virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals( const char* color, int childs, float avgLifetime, float preg, float milk );
	Mammals(const Mammals& m);
	//init the Mammals with a given attributes
	Mammals( ifstream& in_file );//init the Mammals from a binary file
	virtual ~Mammals();

	void SetPreg(float pregnancyTime);

	void SetMilk(float milkLiters);

public:
	float		GetPregnanceTime() const;//return the pregnance time of the animal
	float		GetMilk() const;//return the milk liters of the animal

protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	void virtual SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef