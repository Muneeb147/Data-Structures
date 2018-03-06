#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.cpp"
using namespace std;
void show_poly(LinkedList<string> poly)
{
	 ListItem<string> * temp=poly.getHead();
	 
	 for (int i=0;i<poly.length();i++)
	 {
	 	if (i==poly.length()-1)
	  cout << temp->value;
	 else
	  cout << temp->value << "+";
	   temp=temp->next;
	  
	  
	}
}
int main()
{
	LinkedList<string> poly1;
	LinkedList <string> poly2;
	 cout << " ....WELCOME TO OUR polynomial addition/ subtraction calculator...." << endl<< endl;
	 
	 cout << "how many terms you wanna right for first ploynomial (max:6 terms with degree 5 max)" << endl;
	 int term1;
	 cin>> term1;
	 cout << "enter every term in descending order of power one by one in the format ax^b" << endl;
	 for (int i =0;i<term1;i++)
	 {
	 	
	 	string item;
	 	cin>>item;
		poly1.insertAtTail(item);
	 }
	 
	 cout << "how many terms you wanna right for second ploynomial (max:6 terms with degree 5 max)" << endl;
	 int term2;
	 cin>> term2;
	 cout << "enter every term in descending order of power one by one in the format ax^b" << endl;
	 for (int i =0;i<term2;i++)
	 {
	 	string item;
	 	
	 	cin>> item;
	 	poly2.insertAtTail(item);
	 }
//	  show_poly(poly1);
//	  cout << endl;
//	  show_poly(poly2);
	  
	  // now addition of polynnomials
	
		ListItem<string> * temp=poly1.getHead();
		ListItem<string> * temp1= poly2.getHead();
		cout << endl;
	//	cout << ((temp->value[0]-'0') + (temp1->value[0]-'0'));	
			for (int i=0;i<poly1.length();i++)
		{
			for (int j=0;j<poly2.length();j++)
			{
				if (temp->value[3]==temp1->value[3])
				{
					int sum= ((temp->value[0]-'0') + (temp1->value[0]-'0')) ;
					LinkedList<int> SUM;
					SUM.insertAtTail(sum);
					cout << sum <<"x ^" <<temp->value[3] << "+" ; 
					 
					break;
					cout << endl<<endl;	
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
		
	
	
			  
	  
	
}
