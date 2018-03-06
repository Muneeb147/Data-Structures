#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
	root=NULL;
}

template <class T>
AvL<T>::~AvL()
{
	delete root;
}

template <class T>
int AvL <T>:: check_balance (AvLNode<T>* node)
{
	return (nodeHeight(node->right)-nodeHeight(node->left));
}

template <class T>
AvLNode<T> * AvL<T>::find_unbalanced(AvLNode<T> *node)
{
	while (node->parent!=NULL)
	{
		if ((check_balance(node)>1)||(check_balance(node)<-1)) // right heavy hai
		{
			return node;
			break;
		}
		else
		node=node->parent;
	}
	if (node->parent==NULL)
	{
	 
		if ((check_balance(node)>1)||(check_balance(node)<-1)) 
	return node;
	else 
	return NULL;
	
	}
}

template <class T>
AvLNode<T>* AvL<T>::search(T k)
{
	AvLNode<T>*temp=root; 
	 if(root==NULL)
	 return NULL;
	 if (root->key==k)
	 return root; 
	int count=0;
   while(temp!=NULL)
   {
      if(temp->key==k)
      {
      	count=1;
	    return temp;
	    break;
	  }

      else if(k>temp->key)
         temp=temp->right;

      else if(k<temp->key)
         temp=temp->left;
   }

   if (count==0)
   return NULL;
	
}

template <class T>
void AvL<T>::replace(T ok, T nk)
{
}


template <class T>
void AvL<T>::delete_node(T k)
{
//	DEL(k);
}

template <class T>
void AvL<T>::right_rot(AvLNode<T>*n)

{
AvLNode<T> *temp = n->left;

   if(temp->right != NULL)
   {
   
    n->left = temp->right;
    temp->right->parent = n;
	}
	
	else
	n->left=NULL;

   if(n->parent == NULL)
   {
      root = temp;
      temp->parent = NULL;
   }

   else if(n->parent->left == n)
   {
   
      n->parent->left = temp;
    temp->parent=n->parent;
    }

   else
   {
   
      n->parent->right = temp;
          temp->parent=n->parent;
    }

   temp->right = n;
   n->parent = temp;


}


template <class T>
void AvL<T>::left_rot(AvLNode<T>*n)
{
AvLNode<T> *temp = n->right;

   if(temp->left != NULL)
   {
   
    n->right= temp->left;
    temp->left->parent = n;
	}
	
	else
	n->right=NULL;

   if(n->parent == NULL)
   {
      root = temp;
      temp->parent = NULL;
   }

   else if(n->parent->left == n)
   {
   
      n->parent->left = temp;
    temp->parent=n->parent;
    }

   else
   {
   
      n->parent->right = temp;
          temp->parent=n->parent;
      }

   temp->left = n;
   n->parent = temp;


}


template <class T>
AvLNode <T> * AvL<T>:: INSERT(string val, T k)
{
	if (root ==NULL)
	{
		root=new AvLNode<T>(val,k);
		root->parent=NULL;
		root->left=NULL;
		root->right=NULL;
		return root;
   	}
	else
	{
		AvLNode <T> * temp=root;
		while(1)
		{
			if (k<=temp->key)
			{
				if (temp->left!=NULL)
				temp=temp->left;
				else 
				{
				
			 	temp->left= new AvLNode <T> (val,k);
				temp->left->parent=temp;
				return temp->left;
				break;
				}
			}
			else if (k>temp->key)
			{
				if (temp->right!=NULL)
				temp=temp->right;
				else 
				{
				temp->right= new AvLNode <T> (val,k);
				temp->right->parent=temp;
				return temp->right;
				break;
				}
			}
		}
	}	
}
template <class T>
void AvL<T>::insert(string val, T k)
{
	 // the node from where we will start to traverse upwards to find the first unbalanced tree
		AvLNode<T> * Strnode=INSERT(val,k);
	 	AvLNode<T>* first_unbalanced = find_unbalanced (Strnode);
	 	if (first_unbalanced!=NULL)
	 	{
		 
	 	 if (check_balance(first_unbalanced)>1) // then it is right heavy
	 	 {
	 	 	if (nodeHeight(first_unbalanced->right->right)>nodeHeight(first_unbalanced->right->left)) // RR case
	 	 	{
	 	 		left_rot(first_unbalanced);
			}
			else if (nodeHeight(first_unbalanced->right->right)<nodeHeight(first_unbalanced->right->left)) // RL case
			{
			right_rot(first_unbalanced->right);
			left_rot(first_unbalanced);
			}
		 }
		 else if (check_balance(first_unbalanced)<-1) // then it is leftheavy
	 	{
	 		if (nodeHeight(first_unbalanced->left->right)>nodeHeight(first_unbalanced->left->left)) // LR case
	 		{
	 			left_rot(first_unbalanced->left);
	 			right_rot(first_unbalanced) ;
			}
			else if  (nodeHeight(first_unbalanced->left->right)<nodeHeight(first_unbalanced->left->left))  // LL case
				 right_rot(first_unbalanced);  
		}
	}
}
template <class T>
void AvL<T>:: DEL (T key1)
{
		AvLNode <T> *delnode =search(key1);
	if (root==NULL)
		return;
	// if on root	
	if (root->key==key1)
	{ 
		if (root->left==NULL && root->right==NULL)
	 		{
	 			delete root;
	 			root=NULL;
			}
	else if (root->left==NULL)
	{
		AvLNode <T>*temp=root;	
		root=root->right;
		delete temp;
	}
	else if (root->right==NULL)
	{
		AvLNode <T>*temp=root;	
		root=root->left;
		delete temp;
	}
	else
		{
			AvLNode<T> *temp1=root;
		AvLNode<T> *temp=find_min (root->right);
		 //we need to exchange temp and delnode
		temp1->value=temp->value;
		temp1->key=temp->key;
		DEL (temp->key);	
		}
	}
	
	// if not on root
	else if (root->key!=key1 && delnode!=NULL)
	{
	if (delnode->left==NULL && delnode->right==NULL) // when deleting a leaf
		{
			if (delnode->parent->left==delnode)
			{
				delnode->parent->left=NULL;
				AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=NULL;
AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}
		}
	
	else if(delnode->left==NULL && delnode->right!=NULL)
	{
			if (delnode->parent->left==delnode)
			{
				delnode->parent->left=delnode->right;
				delnode->right->parent=delnode->parent;
				//delnode->right=NULL;
				
				AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=delnode->right;
				delnode->right->parent=delnode->parent;
				//delnode->right=NULL;
				AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}	
	}
	else if (delnode->left!=NULL && delnode->right==NULL)
	{
		if (delnode->parent->left==delnode)
			{
				delnode->parent->left=delnode->left;
				delnode->left->parent=delnode->parent;
				//delnode->left=NULL;
				AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=delnode->left;
				delnode->left->parent=delnode->parent;
				AvLNode<T> * P=delnode->parent;				
				delete delnode;
				Balancethetree(P);
			}	
	}
	else if (delnode->left!=NULL && delnode->right!=NULL)
	{
		AvLNode<T> *temp=find_min (delnode->right);
		delnode->value=temp->value;
		delnode->key=temp->key;
		DEL(temp->key);
	}
}
}
template <class T>
void AvL<T> :: Balancethetree(AvLNode <T> * node)
{
	AvLNode<T> * temp =root;
	if (node->key<root->key)
	{
		while (temp->left!=NULL)
		{
			temp=temp->left;
		}
	}
	else
	{
		while (temp->right!=NULL)
		{
			temp=temp->right;
		}	
	}
	// now we need to traverse upward from temp
	AvLNode<T> * unbalanced;
	while (1)
	{
			unbalanced= find_unbalanced(temp);
			if (temp->parent==NULL && unbalanced==NULL )
			break;
		else	if (unbalanced!=NULL)
	 	{
		 
	 	 if (check_balance(unbalanced)>1) // then it is right heavy
	 	 {
	 	 	if (nodeHeight(unbalanced->right->right)>nodeHeight(unbalanced->right->left)) // RR case
	 	 	{
	 	 		left_rot(unbalanced);
			}
			else if (nodeHeight(unbalanced->right->right)<nodeHeight(unbalanced->right->left)) // RL case
			{
			right_rot(unbalanced->right);
			left_rot(unbalanced);
			}
		 }
		 else if (check_balance(unbalanced)<-1) // then it is leftheavy
	 	{
	 		if (nodeHeight(unbalanced->left->right)>nodeHeight(unbalanced->left->left)) // LR case
	 		{
	 			left_rot(unbalanced->left);
	 			right_rot(unbalanced) ;
			}
			else if  (nodeHeight(unbalanced->left->right)<nodeHeight(unbalanced->left->left))  // LL case
				 right_rot(unbalanced);  
		}
	}
	temp=temp->parent;
	}
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *n)
{
	int l,r;
	if (n==NULL)
    {
        return -1;
    }
	   
     l= nodeHeight(n->left);
     r = nodeHeight(n->right); 
		return max(l,r) +1;
}
template <class T>
AvLNode<T>* AvL<T>::find_min(AvLNode<T> * node)
{
	if (root==NULL)
	return NULL;
	else 
	{
		if (node->left!=NULL)
		return find_min (node->left);
		else 
		return node;
	}
}
template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
	return root;
}
#endif
