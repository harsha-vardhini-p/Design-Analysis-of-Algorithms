#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int table[SIZE];

    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;

    
    for(int i = 0 ; i < SIZE ; i++)
    {
        table[i] = -1;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        int key;
        cout<<"Enter the key element : ";
        cin>>key;

        int index  = key % SIZE;

        while(table[index] != -1)
        {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    cout<<"\nHash Table : \n";

    for(int i = 0 ; i < SIZE ; i++)
    {
        cout<< i << " -> " << table[i]<<endl;
    }

    return 0;
}

//Output:

/*
Enter the number of elements : 10
Enter the key element : 12
Enter the key element : 65
Enter the key element : 83
Enter the key element : 24
Enter the key element : 74
Enter the key element : 98
Enter the key element : 45
Enter the key element : 33
Enter the key element : 62
Enter the key element : 96

Hash Table : 
0 -> 62
1 -> 96
2 -> 12
3 -> 83
4 -> 24
5 -> 65
6 -> 74
7 -> 45
8 -> 98
9 -> 33

*/