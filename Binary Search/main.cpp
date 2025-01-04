#include <iostream>

using namespace std;



// First condition to do binary search on array is ARRAY SHOULD BE SORTED.

int binary_search(int low,int high,int key,int arr[])

{

int mid = 0;
     while(low<=high)
{

       mid= (low + high)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(key<arr[mid])
        {
        high = mid - 1;


        }
        else {

            low = mid +1;
            }


       }
       return -1;

}
int main()
{

    int arr[10]={21,34,42,53,64,72,73,81,82,84};

    int low=0,high=9;
    int key = 11;
    int mid=0;




   cout<< binary_search(low,high,key,arr)<<endl;


    return 0;
}
