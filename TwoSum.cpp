#include <iostream>
using namespace std;

#define SIZE 100

int main()
{
    int n,T;
    int arr[SIZE];
    int hash[SIZE] = {0};

    cout<<"Enter number of elements : ";
    cin>>n;

    cout<<"Enter the elements: ";
    for(int i = 0 ; i < n ; i++ )
    {
        cin>>arr[i];
    }

    cout<<"Enter target value : ";
    cin>>T;

    for(int i = 0 ; i < n ; i++)
    {
        int x = T - arr[i];

        if(x >= 0 && hash[x] == 1)
        {
            cout<<"Yes, two elements exist: "<< x <<" + "<< arr[i] <<" = "<<T<<endl;
            return 0;
        }
        hash[arr[i]] = 1;
    }

    cout<<"No such two elements exist.";

    return 0;
}

//Output:

/*
Enter number of elements : 5   
Enter the elements: 4 9 2 8 3
Enter target value : 12
Yes, two elements exist: 4 + 8 = 12
*/