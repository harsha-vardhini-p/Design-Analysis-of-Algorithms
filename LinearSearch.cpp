#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int key)
{
    int position = -1;

    for(int i = 0; i < n; i++)
    {
        if(A[i] == key)
        {
            position = i;
            break;
        }
    }
    return position;
}

int main()
{
    int n,key;
    
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int A[n];

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<<"Enter the key to be searched: ";
    cin>>key;

    int position = linearSearch(A, n, key);

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

//OUTPUT:
//Enter the number of elements in the array: 5
//Enter the elements of the array: 10 20 30 40 50
//Enter the key to be searched: 30
//Key found at position: 2
