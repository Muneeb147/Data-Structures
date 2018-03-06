#include <fstream>
#include "sorts.cpp"
#include <cstdlib>

using namespace std;


// A single pair is stored in a Vector<long>
// You have to return a vector of all pairs.
int binary_search(vector <long> nums,int first,int last, long key)
{
 int index;
 if (first > last)
 index= -1;
 
 else
 {
 int mid = (first + last)/2;
 
 if (key == nums[mid])
 index = mid;
 else
 
 if (key < nums[mid])
 index = binary_search(nums,first, mid-1, key);
 else
 index = binary_search(nums, mid+1, last,key);
 }
 return index;
 }
 // end binarySearc
vector <vector<long> > smartSearch(vector<long> nums, long k)
{   
    // Write your code in this function
    int check=0;
    vector <long> singlepair;
    vector< vector<long> > allpairs;
    vector <long> sorted_vector=MergeSort(nums);
    //cout << "Sorted size :" << sorted_vector.size()<< endl;
    for (int i=0;i<sorted_vector.size();i++)
    {
    	
    	 long num1=sorted_vector[i]-k;
    	 if (num1<=0)
    	 {
		 	num1=abs(num1);
    		int index_of_num1= binary_search(sorted_vector,0,sorted_vector.size()-1,num1);
    		if (index_of_num1!=-1 && num1!=sorted_vector[i])
    		{
    			singlepair.push_back(num1);
    			singlepair.push_back(sorted_vector[i]);
    			for (int k=0;k<allpairs.size();k++)
    			{
    				if (allpairs[k][0]==num1 || allpairs[k][1]==num1)
    				{
						check=1;
						break;
					}
				}
				if (check==0)
    			allpairs.push_back(singlepair);
    			singlepair.clear();
   			}
   		}
	}
return allpairs;
}


int main()
{
    vector<long> nums;
    ifstream in("random.txt");
    long n;
    while(in >> n)
        nums.push_back(n);
        
    in.close();
//cout << "nums size :" <<nums.size()<< endl;
    long k;
    cout << "Enter the value of K: ";
    cin >> k;

    vector< vector<long> > result = smartSearch(nums, k);

    for(int i = 0; i < result.size(); i++)
        cout << result[i][0] << ", " << result[i][1] << endl;
         43

    return 0;
}
