#include "OperandConverter.h"
#include "Calculator.h"
using namespace std;

OperandConverter::OperandConverter(Calculator* calculator)
{
	this->calculator = calculator;
}

void OperandConverter::setExpression(string in)
{
	romawiExpression = in;
}

// return 1 for arithmetic expression and return 2 for logic expression
int OperandConverter::isOperator(char in)
{
	if (in == '+') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	if (in == '&') return 1;
	if (in == '|') return 1;
	if (in == '!') return 1;
	if (in == '^') return 1;
	if (in == '(') return 1;
	if (in == ')') return 1;
	return 0;
}
	
string OperandConverter::toArabicExpression()
{
	string res = "";
	string temp = "";
	string spc = " ";
	int mode = 1; // 1 : previous operator 2 : previous operand
	int flag = 1, space = 0;
	Number* num;
	if (calculator->getNumberType() == Calculator::ARABIC_NUMBER) num = new ArabicNumber();
	else if (calculator->getNumberType() == Calculator::ROMAWI_NUMBER) num = new RomanNumber();
	else if (calculator->getNumberType() == Calculator::LOGIC_NUMBER) num = new LogicNumber();
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if (isOperator(romawiExpression[i])) // arithmetic
		{
			mode = 1;
			res.append(string(1,romawiExpression[i]));
		}
		else if (romawiExpression[i] == ' ')
		{
			// previous is operator
			if (mode == 1)
			{
				res.append(spc);
				continue;
			}
			
			// previous is operand
			int xx = num->toArabicNumber();
			ostringstream convert;convert << xx;
			
			res.append(convert.str()); // append operand
			res.append(spc); // append space
			temp = "";
			/*
			if (flag == 1)
			{
				RomanNumber n(temp);
				int xx = n.toArabicNumber();
				ostringstream convert;convert << xx;
				
				res.append(convert.str()); // append operand
				res.append(spc); // append space
				temp = "";
			}else if (flag == 2)
			{
				LogicNumber n(temp);
				int xx = n.toArabicNumber();
				ostringstream convert;convert << xx;
				
				res.append(convert.str()); // append operand
				res.append(spc); // append space
				temp = "";
			}*/
		}
		else
		{
			mode = 2;
			temp.append(string(1,romawiExpression[i]));
		}
	}
	
	// reach end of line
	if (temp!="")
	{
		RomanNumber n(temp);
		int xx = n.toArabicNumber();
		ostringstream convert;convert << xx;
		
		res.append(convert.str());
	}
	
	/*
	if (flag == 1 && temp!="")
	{
		RomanNumber n(temp);
		int xx = n.toArabicNumber();
		ostringstream convert;convert << xx;
		
		res.append(convert.str());
	}
	else if (flag == 2 && temp!="")
	{
		LogicNumber n(temp);
		int xx = n.toArabicNumber();
		ostringstream convert;convert << xx;
		
		res.append(convert.str());
	}
	*/
	return res;
}
