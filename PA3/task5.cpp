#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "openAddress.cpp"
#include "doubleHash.cpp"
#include "HashC.cpp"
# include "time.h"
using namespace std;

int main()
{ 	string name;
	vector <string> DATA;
	ifstream input;
	input.open("names.txt");
	string line;
	while (getline(input,line))
	{
		DATA.push_back(line);
	}
	cout << "enter the optimum value of parameter a :" << endl;
	int a;
	cin >>a;
	HashC rooster1(a);
	OpenAddress rooster2(a);
	DoubleHash rooster3(a);
	
	// insertion
	// time start
	startTimer();
	for (int i=0;i<DATA.size();i++)
	{
		rooster1.insert(DATA[i]);
	}
	cout << "collisions for chaining are : " << rooster1.Collisions()<<endl;
	cout << "insertion time for Chaining : " ;
	stopTimer();
	// end time
	
		// time start
		startTimer();
	for (int i=0;i<DATA.size();i++)
	{
		rooster2.insertItem(DATA[i]);
	}
	cout << "collisions for OpenAddressing are : " << rooster2.Collisions()<<endl;
  cout << "insertion time for OpenAddressing : "; 
   stopTimer();
	// end time
	
	// time start
	startTimer();
	for (int i=0;i<DATA.size();i++)
	{
		rooster3.insertItem(DATA[i]);
	}
	cout << "collisions for doublehashing are : " << rooster3.Collisions()<<endl;
	cout << "insertion time for doublehashing : " ;
	 stopTimer();
	// end time
	
	 string done="yes";
	while(done!="quit")
	{ 
		cout << "enter the name of the student you wanna search :" << endl;
		cin >> name;
		// start time
		startTimer();
				ListItem* temp = rooster1.lookup(name);
				
		cout << "searching time for  in Chaining : "; 
		 stopTimer();
		// end time
		
		// start time
		startTimer();
		string Name=rooster2.lookUp(name);
		if (Name==" ")
		cout <<"student is not in the roster" << endl;
			cout << "searching time for  in OpenAddressing : "; 
			stopTimer();
		//end time
		
		// start time
		startTimer();
		Name=rooster3.lookUp(name);
		if (Name==" ")
		cout <<"student is not in the roster" << endl;
	cout << "searching time for in doubleHashing : "; 
	stopTimer();
		//end time
		
		if (temp==NULL)
		cout << "student is not in roster " << endl;
		
	cout << "do you want to search again? (yes/quit)"<< endl;
	cin >> done;
		
	}
	 
	
	 
	
		
}
	


