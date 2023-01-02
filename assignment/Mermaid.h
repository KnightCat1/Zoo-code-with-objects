#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName );
	Mermaid(const Mermaid& m);
	//init the Mermaid with a given attributes
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	virtual ~Mermaid();

public:
	const char*		GetFirstName() const;//return the first name of the mermaid
	const char*		GetLastName() const;//return the last name of the mermaid

protected:
	void SetFirstName(const char* firstName);
	void SetLastName(const char* lastName);
	virtual void printAdditonalInfo(ofstream& out) const;//print additonal info
	virtual void getAdditonalInfo(ifstream& in);//get additonal info
	void virtual SaveBin(ofstream& ofs) const;//method to save the info to a binary file

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef