#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>
#include <string>
#include <sstream>

Tree::Tree()
{
	head = NULL;
	
}

Tree::Tree(string file)
{

	ifstream Input;
	Input.open(file.c_str());
	head=NULL;
string lines;
	while (getline(Input,lines))
	{
	    insert(lines);
	}
	Input.close();
}

Tree::~Tree()
{
}

void Tree::insert(string item)
{
	vector<char> Char;
	vector <string> STR;
	for (int i=0;i<item.size();i++)
	{
		if (item[i]!='/')
		{
			Char.push_back(item[i]);	
		}
		 if ((item[i]=='/') || i==item.size()-1 )
		{
			string path=" ";
			for (int k=0;k<Char.size();k++)
			{
				if (k==0)
			path[0]=Char[0];
			if (k!=0)
			path=path+Char[k];
			}
			Char.clear();
			STR.push_back(path);
		}
		
	}
	
	
	
	TreeItem *temp = head;
    
	if (temp == NULL)
	head = new TreeItem(STR[0]); // C:
    else
    {
        for (int i = 0; i < STR.size(); i++)
        {
            while(temp->value != STR[i])
            {
                if(temp->NextS==NULL)
                break;
                    
                else
 					temp=temp->NextS;    
	        }
            if(temp->value == STR[i])
            {
                if(temp->FChild==NULL)
                {
                     temp->FChild=new TreeItem(STR[i+1]);
                    temp->FChild->Parent=temp;
                }
					
                    
                else
                {
                   temp=temp->FChild;
                }
            }
            else if (temp->value != STR[i] && temp->NextS==NULL)
            {
                temp->NextS=new TreeItem(STR[i]);
                (temp->NextS)->Parent=temp->Parent;
            }

        }
    }
}

vector<string> Tree::Locate(string qry)
{	
	TreeItem* SEARCH = FIND(head, qry);
    vector<string> MYvec;
    if (SEARCH!=NULL)
    {
	
    while(SEARCH->Parent!= NULL)
	{
        MYvec.push_back(SEARCH->value);
        SEARCH=SEARCH->Parent;
	}
	if (SEARCH->Parent==NULL)
	MYvec.push_back(SEARCH->value);
	
    return MYvec;
	}
	
}

TreeItem* Tree::FIND(TreeItem* TEMP, string qry)
{	
	TreeItem* myTEMP =NULL;
	TreeItem * mynode;
	TreeItem* NODE;
	
	if(TEMP->value == qry)
	return TEMP;
	
	if(TEMP->FChild != NULL)
	{
		mynode=TEMP->FChild;
		myTEMP=FIND(mynode, qry);
		
	}
	if ( myTEMP!=NULL)
	return myTEMP;
	
	if(TEMP->NextS != NULL)
	{
		NODE=TEMP->NextS;
		myTEMP=FIND(NODE, qry);
	}
		return myTEMP;
	
}

string Tree::LComAc(string a, string b)
{
    string COM =head->value;
    for (int i = 0; i < Locate(a).size(); i++)
    {
        for(int j = 0; j < Locate(b).size(); j++)
        {
            if (Locate(a)[i] == Locate(b)[j])
            {
                COM = (Locate(b))[j];
                return COM;
            }
        }
    }

    return COM ;
}

TreeItem* Tree::getHead()
{
	return head;
}

int Tree::countFiles()
{
	int size;
	size = countNODES(head);
	size--;
	return size;
}

int Tree::countNODES(TreeItem *temp)
{
	int check=0;
	
	if(temp == NULL)
	return 0;
	
	if(temp->FChild == NULL)
	{
		if(temp->NextS == NULL)
		return check++;
		else
		check++; 
	}
		
	else if(temp->FChild != NULL)
	check = countNODES(temp->FChild);
		
	if(temp->NextS != NULL)
	check = check + countNODES(temp->NextS);

	return check;
}


#endif
