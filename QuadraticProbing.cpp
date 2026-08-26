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
        int j = 0;

        while(table[(index + j*j) % SIZE] != -1)
        {
            j++;
        }
        if(j<SIZE)
        {
            table[(index + j * j) % SIZE] = key;

        }
        else
        {
            cout<<"Hash Table is Full!";
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
Enter the key element : 32
Enter the key element : 53
Enter the key element : 63
Enter the key element : 74
Enter the key element : 84
Enter the key element : 96
Enter the key element : 79
Enter the key element : 65
Enter the key element : 45

Hash Table : 
0 -> 45
1 -> 65
2 -> 32
3 -> 63
4 -> 84
5 -> 45
6 -> 96
7 -> 63
8 -> 84
9 -> 79

*/