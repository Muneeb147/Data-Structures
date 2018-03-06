#include <iostream>
#include "bst.cpp"
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//#include <time.h>
using namespace std;
int main()
{
	
	string file;
	cout << "Please enter a file name: ";
	cin>>file;
	
	ifstream IN;
	bst<int>TREE1;
	//AvL<int>TREE2;
	vector<string>vec;
	vector <string> ROLLNUM;
	vector <string> NAME;	
	IN.open(file.c_str());
	string line;
	
	if(IN.fail())
	{
		cout << "File not found, exiting!!"<<endl;
	}
	else 
	{
		
		while(getline(IN,line,'~'))
		{
			vec.push_back(line);
		}
		//
		for (int i=0; i<vec.size(); i++)
      {
          if(i%2==0)
            NAME.push_back(vec[i]);
          else
            ROLLNUM.push_back(vec[i]);

      }
      
		cout << "File loaded successfully."<<endl;;
		//
		vector <int> rollnumber;
       for (int i=0; i<ROLLNUM.size(); i++)
       {
           int num = atoi(ROLLNUM[i].c_str());
           rollnumber.push_back(num);
       }
       for (int i=0; i<NAME.size(); i++)

    {
        TREE1.insert(NAME[i],rollnumber[i]);
    }

		
		cout << "Please choose the Data Structure:"<<endl;
		cout <<"1. BST"<<endl<<"2. AVL"<<endl;
		int dec;
		cin>>dec;
		int done =1;
		if(dec== 1)
		{
			while(done == 1)
			{
				cout <<"\n- Press 1 to Insert another key/value Pair" <<endl;
				cout <<"- Press 2 to search for a value using its key" <<endl;
				cout <<"- Press 3 to delete a key/value pair"<<endl;
				cout <<"- Press 4 to update the key of an existing value"<<endl;
				cout <<"- Press 5 to see the current height of the Tree"<<endl;
					int choice;
				cin >> choice;
				if (choice == 1)
				{
					string value; int KEY;
					cout << "Please enter a key along with it's value."<<endl;
					cout << "Key: "; 
					cin>>KEY;
					cout << "Value: "; cin>>value; 	
					//
					TREE1.insert(value,KEY);
					//
				}
				else if(choice == 2)
				{
					int KEY;
					bst_node<int> *search;
					cout << "Please enter a key to search."<<endl;
					cout << "Key: "; cin>>KEY;
					//
					search = TREE1.search(KEY);
					if (search == NULL)
						cout << "Key, value not found!"<<endl;
					else 
						cout <<"the value is:"<<search->value<<endl;	
					//	
				}
				else if(choice == 3)
				{
					int KEY;
					cout << "Please enter a key to delete the key/value pair."<<endl;
					cout << "Key: "; 
					cin>>KEY;
					//
					TREE1.delete_node(KEY);
					cout << "Keysuccessfully deleted."<<endl;
					//
				}
				else if(choice == 4)
				{
					int oldkey1,newkey2;
					cout << "Please enter the old and new keys to update"<<endl;
					cout <<"Old Key: "; 
					cin>>oldkey1;
					cout <<"New Key is: "; 
					cin>>newkey2;
					//
					TREE1.replace(oldkey1,newkey2);
					//
				}
				else if(choice == 5)
				{
					int height;
					height = TREE1.height(TREE1.getroot());
					//
					cout << "The current height of the tree is: "<<height<<endl;
					//
				}
				cout << " do you want to quit?" << endl;
				cin >> done;
				
			}	
		}
	
	}
	//return 0;
}
