#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type );
	Horse(const Horse& h);
	//init the Horse with a given attributes
	Horse( ifstream& in_file );//init the Horse from a binary file
	virtual ~Horse();

public:
	const char*		GetType() const;
	void SetType(char* type);
	//return the type of the horse

protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	void virtual SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	char*	m_type;
};

#endif // ifndef