#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include "time.h"
using namespace std;
template <class T>
void bst<T>:: Del (bst_node<T> * temp)
{
		if (temp->left==NULL && temp->right==NULL) // when deleting a leaf
		{
			if (temp->parent->left==temp)
			{
				temp->parent->left=NULL;
				delete temp;
			}
			else if (temp->parent->right==temp)
			{
				temp->parent->right=NULL;
				delete temp;
			}
		}
			else if(temp->left==NULL && temp->right!=NULL)
	{
			if (temp->parent->left==temp)
			{
				temp->parent->left=temp->right;
				temp->right->parent=temp->parent;
				//delnode->right=NULL;
				delete temp;
			}
			else if (temp->parent->right==temp)
			{
				temp->parent->right=temp->right;
				temp->right->parent=temp->parent;
				//delnode->right=NULL;
				delete temp;
			}	
	}
}
template <class T>
bst<T>::bst()
{
	root=NULL;
}

template <class T>
void bst<T>::insert(string val,T key1)
{
	if (root ==NULL)
	{
	
	root=new bst_node<T>(val,key1);
	root->parent=NULL;
	root->left=NULL;
	root->right==NULL;
   }
	
	else
	{
		bst_node <T> * temp=root;
		while(1)
		{
			if (key1<=temp->key)
			{
				if (temp->left!=NULL)
				temp=temp->left;
				else 
				{
				
				temp->left= new bst_node <T> (val,key1);
				temp->left->parent=temp;
				break;
				}
			}
			else if (key1>temp->key)
			{
				if (temp->right!=NULL)
				temp=temp->right;
				else 
				{
				
				temp->right= new bst_node <T> (val,key1);
				temp->right->parent=temp;
				break;
				}
			}
			
			
		}
	}
	
}
template <class T>
bst_node<T>* bst<T>::search(T key1)
{
	 bst_node<T>*temp=root; 
	 if(root==NULL)
	 return NULL;
	 if (root->key==key1)
	 return root; 
	int count=0;
   while(temp!=NULL)
   {
      if(temp->key==key1)
      {
      	count=1;
	    return temp;
	    break;
	  }

      else if(key1>temp->key)
         temp=temp->right;

      else if(key1<temp->key)
         temp=temp->left;
   }

   if (count==0)
   return NULL;

}

template <class T>
void bst<T>::delete_node(T key1)
{
		bst_node <T> *delnode =search(key1);
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
		bst_node <T>*temp=root;	
		root=root->right;
		delete temp;
	}
	else if (root->right==NULL)
	{
		bst_node <T>*temp=root;	
		root=root->left;
		delete temp;
	}
	else
		{
			bst_node<T> *temp1=root;
		bst_node<T> *temp=find_min (root->right);
		 //we need to exchange temp and delnode
		temp1->value=temp->value;
		temp1->key=temp->key;
		Del (temp);	
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
				delete delnode;
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=NULL;
				delete delnode;
			}
		}
	
	else if(delnode->left==NULL && delnode->right!=NULL)
	{
			if (delnode->parent->left==delnode)
			{
				delnode->parent->left=delnode->right;
				delnode->right->parent=delnode->parent;
				//delnode->right=NULL;
				delete delnode;
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=delnode->right;
				delnode->right->parent=delnode->parent;
				//delnode->right=NULL;
				delete delnode;
			}	
	}
	else if (delnode->left!=NULL && delnode->right==NULL)
	{
		if (delnode->parent->left==delnode)
			{
				delnode->parent->left=delnode->left;
				delnode->left->parent=delnode->parent;
				//delnode->left=NULL;
				delete delnode;
			}
			else if (delnode->parent->right==delnode)
			{
				delnode->parent->right=delnode->left;
				delnode->left->parent=delnode->parent;
				delete delnode;
			}	
	}
	else if (delnode->left!=NULL && delnode->right!=NULL)
	{
		bst_node<T> *temp=find_min (delnode->right);
		delnode->value=temp->value;
		delnode->key=temp->key;
		Del(temp);
	}
}
}

template <class T>
int bst<T>::height( bst_node<T> *temp)
{
	int l,r;
	if (temp==NULL)
    {
        return -1;
    }
    
     l= height(temp->left);
     r = height(temp->right); 
		return max(l,r) +1;
		
	
}

template<class T>
void bst<T>::replace(T old_key,T new_key)
{
	
		bst_node<T>* t=search (old_key);
			delete_node(old_key);		
		insert(t->value,new_key);
	
	 
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
	return root;
}
template <class T>
bst_node<T>* bst<T>::find_min(bst_node<T> * node)
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
#endif
