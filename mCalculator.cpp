/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c; //ctor
	int Mode;
	string cmd;
	system("CLS");
	cout<<"Calclulator"<<endl<<endl;
	cout<<"Settings awal pada calculator ini adalah :"<<endl;
	cout<<"Aritmatika untuk jenis operator"<<endl;
	cout<<"Angka arab untuk jenis agka"<<endl;
	cout<<"Infiks untuk jenis ekspresi"<<endl;
	c.setMode(1);
	cout<<"Mode  yang dipilih adalah mode ekspresi"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------"<<endl;
	//loop
	while (1) {
		cout<<"Masukan command : ";
		//cin.ignore();
		char temp[256];
		cin.getline(temp,256); cout<<endl;
		char* ttemp = strdup(temp);
		cmd = ttemp;
		//cout<<cmd<<endl;
		//printf("%s", ttemp);
		//getchar();
		if (cmd.compare("Set") == 0) {
			c.setMode(2); cout<<endl;
			c.executeCommand(cmd);
			
			cout<<"Settings yang sedang digunakan : "<<endl;
			cout<<c.getOperatorType()<<endl;
			cout<<c.getNumberType()<<endl;
			cout<<c.getExpressionType()<<endl<<endl;
		}
		else {
			c.executeCommand(cmd);
		}
		//c.executeCommand(cmd);
		if (cmd.compare("Set") == 0) {
			cin.ignore();
		}
		c.setMode(1);
	}
	
	return 0;
}