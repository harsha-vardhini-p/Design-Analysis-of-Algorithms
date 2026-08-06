//Binary Search Algorithm  
//Recursive method

#include <iostream>
using namespace std;

int binarySearch(int A[], int beg, int end, int key)
{
    if(beg>end)
    {
        return -1;
    }
    int mid = beg + (end - beg) / 2;

    if(A[mid] == key)
    {
        return mid;
    }
    else if(A[mid] < key)
    {
        return binarySearch(A, mid + 1, end, key);
    }
    else
    {
        return binarySearch(A, beg, mid - 1, key);
    }
    return -1;
}

int main()
{
    int n,key;
    
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int A[n];

    cout<<"Enter the elements of the array in sorted order: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<<"Enter the key to be searched: ";
    cin>>key;

    int position = binarySearch(A, 0, n-1, key);

    if(position == -1)
    {
        cout<<"Key not found in the array."<<endl;
    }
    else
    {
        cout<<"Key found at position: "<<position<<endl;
    }

    return 0;
}

//Output:
//Enter the number of elements in the array: 5
//Enter the elements of the array in sorted order: 1 2 3 4 5
//Enter the key to be searched: 3
//Key found at position: 2
