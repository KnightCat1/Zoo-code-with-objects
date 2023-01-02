#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills );
	MammalsFish(const MammalsFish& mf);
	//init the MammalsFish with a given attributes
	MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
	virtual ~MammalsFish();


protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	virtual void SaveBin(ofstream& ofs) const;//method to save the info to a binary file

};

#endif // ifndef