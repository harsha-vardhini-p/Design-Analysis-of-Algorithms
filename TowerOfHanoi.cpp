//Using recursive method


#include <iostream>
using namespace std;

void hanoi(int n,char source,char intermediate,char destination)
{
    if(n == 1)
    {
        cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
        return;
    }

    hanoi(n-1,source,destination,intermediate);
    
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;

    hanoi(n-1,intermediate,source,destination);

}

int main()
{
    int n;
    cout<<"Enter number of disks : ";
    cin>>n;

    hanoi(n,'A','B','C');

    return 0;
}



//OUTPUT:

/*
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/


//Towers Of Hanoi using Iterative Method

#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& a, stack<int>& b, char A, char B)
{
    if (a.empty())
    {
        a.push(b.top());
        cout << "Move disk " << b.top() << " from " << B << " to " << A << endl;
        b.pop();
    }
    else if (b.empty())
    {
        b.push(a.top());
        cout << "Move disk " << a.top() << " from " << A << " to " << B << endl;
        a.pop();
    }
    else if (a.top() < b.top())
    {
        b.push(a.top());
        cout << "Move disk " << a.top() << " from " << A << " to " << B << endl;
        a.pop();
    }
    else
    {
        a.push(b.top());
        cout << "Move disk " << b.top() << " from " << B << " to " << A << endl;
        b.pop();
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> source, auxiliary, destination;

    // Put disks in source rod
    for (int i = n; i >= 1; i--)
        source.push(i);

    char S = 'A', A = 'B', D = 'C';

    // For even number of disks, swap auxiliary and destination
    if (n % 2 == 0)
    {
        swap(A, D);
    }

    int totalMoves = (1 << n) - 1;

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, destination, S, D);

        else if (i % 3 == 2)
            moveDisk(source, auxiliary, S, A);

        else
            moveDisk(auxiliary, destination, A, D);
    }

    return 0;
}


//OUTPUT:

/*
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/