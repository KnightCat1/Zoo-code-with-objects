#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );
	Fish(const Fish& f);
	//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();

public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;
	void SetFinCount(int finCount);
	void SetGillsCount(int gillsCount);
	//return the gills count of the animal

protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	virtual void SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef