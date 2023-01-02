#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal( const char* color, int childs, float avgLifetime );
	Animal(const Animal& a);
	//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file

public:
	virtual ~Animal();

public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;
	void SetColor(const char* color);
	void SetChildCount(int count);
	void SetLifetime(float lifetime);
	//return the life time of the animal

public:
	void saveName(ofstream& out) const {
		out << typeid(*this).name() + 1 << endl;
	}
	virtual void printAdditonalInfo(ofstream& out) const;
	virtual void getAdditonalInfo(ifstream& in);
	virtual void SaveBin(ofstream& ofs) const;//method to save the info to a binary file
	
	template<class T>
	static void saveVarBin(ofstream& out, T t) { out.write((char*)&t, sizeof(t)); }
	static void saveCharBin(ofstream& out, const char* t) {
		int n = strlen(t);
		out.write((char*)&n, sizeof(n));
		out.write(t, n + 1);
	}
	template<class T>
	static void loadVarBin(ifstream& in, T t) { in.read((char*)&t, sizeof(t)); }
	static char* loadCharBin(ifstream& in, char* t) {
		int n;
		in.read((char*)&n, sizeof(n));
		t = new char[n + 1];
		in.read(t, n + 1);
		t[n] = '\0';
		return t;
	}
	static char* loadChar(ifstream& in, char* t) {
		int size;
		in >> size;
		in.ignore();
		t = new char[size + 1];
		in.getline(t, size + 1);
		return t;
	}

protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef