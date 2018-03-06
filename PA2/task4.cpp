#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
char OP[4]={'*','/','+','-'};


bool checkopenbracket(string a,int index)
{
		if (a[index]=='(')
		return true;
		return false;
			
}
bool checkclosedbracket(string a,int index)
{
		if (a[index]==')')
		return true;
		return false;
			
}
bool checkoperator (char a)
{
	for (int i=0;i<4;i++)
	{
		if (OP[i]==a)
		{
			return true;
			break;
		}
	}
	return false;
}

class TERM
{
	public:
		char op;
		char num1;
		char num2;
		char nextop;
		char asawholeop;
		TERM ()
		{
			 asawholeop=' ';
			 nextop=' ';
			
		}
};

	

struct bst_node
{
        char value;
        //T key;
        bst_node *left;
        bst_node *right;
        bst_node *parent;

        bst_node(char val)
        {
                this->value=val;
               // this->key=key1;
                this->parent=NULL;
                this->left=NULL;
                this->right=NULL;
        }
};
class bst
{
	public:
	bst_node * root;
	
   bst ()
   {
   root=NULL;
   }
	

        void insert(TERM T)
        {
        	if (root==NULL)
        	{
        		if (T.nextop!=' ')
        		{
        			root=new bst_node (T.nextop);
        			root->parent=NULL;
        			root->left= new bst_node(T.op);
        			root->left->parent=root;
        			root->left->left=new bst_node(T.num1);
        			root->left->left->parent=root->left;
        			root->left->right=new bst_node(T.num2);
        			root->left->right->parent=root->left;
				}
				else 
				{
					root=new bst_node (T.op);
        			root->parent=NULL;
        			root->left= new bst_node(T.num1);
        			root->left->parent=root;
        			root->right=new bst_node(T.num2);
        			root->right->parent=root;
        			
				}
			}
			else if (root->right==NULL&& root->left!=NULL)
			{
				if (T.asawholeop!=' ')
				{
					if (T.nextop==' ')
					{	
						bst_node * TEMP=new bst_node (T.asawholeop);	
						bst_node* temp1=root;
						bst_node * temp=new bst_node(T.op);
						temp1->right=temp;
						temp->parent=temp1;
						temp->left=new bst_node(T.num1);
						temp->left->parent=temp;
						
						temp->right=new bst_node(T.num2);
						temp->right->parent=temp;
						TEMP->left=temp1;
						temp1->parent=TEMP;
						root=TEMP;
					}
					
				}
				else
				{
					if (T.nextop==' ')
					{
							root->right=new bst_node (T.op);
							root->right->parent=root;
							root->right->left=new bst_node (T.num1);
							root->right->left->parent=root->right;
							root->right->right=new bst_node (T.num2);
							root->right->right->parent=root->right;
					}
				}
				
			}
			
        	
		}
		    
};	

void inordertraversal (bst_node * node)
{
	if (node==NULL)
	return;
	
	inordertraversal (node->left);
	cout << node->value;
	inordertraversal (node->right);
		
}

double evaluate (bst_node * node)
{
	if (!checkoperator(node->value) )
	{
		int num=(node->value)-'0';
		return num;
	}
	else if (checkoperator(node->value))
	{
		switch (node->value)
		{
			case '+' :
				return (evaluate(node->left)+evaluate(node->right));
				break;
			case '*' :
				return (evaluate(node->left)*evaluate(node->right));
				break;
			case '/' :
				return (evaluate(node->left)/evaluate(node->right));
				break;
			case '-' :
				return (evaluate(node->left)-evaluate(node->right));
				break;
		}
	}
	
}
TERM ARRAY[10];
int size=0;

void splittingtheexpression(string exp)
{
		for (int i=0;i<exp.length();i++)
	{
	
			if (checkopenbracket(exp,i))
			{
				if (!checkopenbracket(exp,i+1))
				{
					char NUM1=exp[i+1];
					
					ARRAY[size].num1=NUM1;
					
					ARRAY[size].op=exp[i+2];
												//(4+2)*(4+1)
					char NUM2=exp[i+3];
					ARRAY[size].num2=NUM2;
					if (checkclosedbracket(exp,i+4))
					{
						if (!checkclosedbracket(exp,i+5))
						{
							if (i+5!=exp.length())
							{
							
							ARRAY[size].nextop=exp[i+5];
							size++;
							i=i+5;
							}
						}
						else
						{
							if (i+6!=exp.length())
							{
						ARRAY[size].asawholeop=exp[i+6];
				
							size++;
							i=i+6;	
							}
						}
					}
					
							
					
				}
				else
				{
					char NUM1=exp[i+2];
					      // (5+1)/(3+0)
					ARRAY[size].num1=NUM1;
					//cout << ARRAY[size].num1;
					ARRAY[size].op=exp[i+3];
					char NUM2=exp[i+4];
					ARRAY[size].num2=NUM2;
					if (checkclosedbracket(exp,i+5))
					{
						if (!checkclosedbracket(exp,i+6))
						{
							if (i+5!=exp.length())
							{
							
							ARRAY[size].nextop=exp[i+6];
							size++;
							i=i+6;
							}
						}
						else
						{
						ARRAY[size].nextop=exp[i+7];
							size++;
							i=i+7;
						}
					}	
				}

			}
	}	
}

int main ()
{
	cout << "enter yout expression :"<< endl;
	string exp;
	cin >> exp;
	splittingtheexpression(exp);
	bst TREE;		
	for (int i=0;i<=size;i++)
	TREE.insert(ARRAY[i]);
cout <<	"the answer to this expression is : "<< endl<<evaluate (TREE.root);

	

}
