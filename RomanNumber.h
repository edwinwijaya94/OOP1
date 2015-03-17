#include <string>
#include <cstdlib>
#include "Number.h"
using namespace std;
#ifndef ROMANNUMBER_h
#define ROMANNUMBER_h
class RomanNumber :public Number{
	private:
	//data member
	string StrValue; 
	//fungsi antara
	int digitConvert(char); 
	
	public:
	RomanNumber();
	RomanNumber(string);
	RomanNumber(const RomanNumber&);
	~RomanNumber();
	string getStrValue(); //mengambil data member StrValue
	int toArabicNumber(); // menngubah data member ke arabic number
};
#endif
