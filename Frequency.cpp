#include <iostream>
using namespace std;

#define SIZE 100

int main()
{
    int n;
    int arr[SIZE];
    int hash[SIZE] = {0};

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++;
    }

    cout << "\nFrequency of elements:\n";

    for(int i = 0; i < n; i++)
    {
        if(hash[arr[i]] != 0)
        {
            cout << arr[i] << " -> " << hash[arr[i]] << endl;

            // Set to 0 so that we don't print it again
            hash[arr[i]] = 0;
        }
    }

    return 0;
}

//Output:

/*
Enter number of elements: 5
Enter the elements: 2 3 2 7 3

Frequency of elements:
2 -> 2
3 -> 2
7 -> 1
*/