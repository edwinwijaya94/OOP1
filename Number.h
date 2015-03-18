#include <string>

#ifndef NUMBER_H
#define NUMBER_H

class Number {
public:
	virtual std::string getStrValue() = 0;
	virtual long long toArabicNumber() = 0;
};
#endif
