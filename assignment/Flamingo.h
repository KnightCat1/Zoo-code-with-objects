#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo( const char* color, int childs, float avgLifetime, float incubation, float avgHeight );
	Flamingo(const Flamingo& f);
	//init the Flamingo with a given attributes
	Flamingo( ifstream& in_file );//init the Flamingo from a binary file
	virtual ~Flamingo();

public:
	float		GetHeight() const;//return the avg height of the flamingo

protected:
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	void virtual SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	float m_avgHeight;
};

#endif // ifndef