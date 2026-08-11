//Way - 1 : formula based approach

#include <iostream>
#include <cmath>
using namespace std;

double geometricSum(double a, double r, int n)
{
    if(r == 1)
        return a * (n + 1);

    return a * (pow(r, n) - 1) / (r - 1);
}

int main()
{
    double a, r;
    int n;

    cout << "Enter a, r and n: ";
    cin >> a >> r >> n;

    cout << "Sum = " << geometricSum(a, r, n);

    return 0;
}

/*Output:
Enter a, r and n: 2 3 4
Sum = 242
*/
//Time Complexity: O(1)


//Way - 2 :Iterative Approach

#include <iostream>
using namespace std;

double geometricSum(double a, double r, int n)
{
    double sum = 0;
    double term = a;

    for(int i = 0; i < n; i++)
    {
        sum = sum + term;
        term = term * r;
    }

    return sum;
}

int main()
{
    double a, r;
    int n;

    cout << "Enter a, r and n: ";
    cin >> a >> r >> n;

    cout << "Sum = " << geometricSum(a, r, n);

    return 0;
}
/*
Output:
Enter a, r and n: 1 4 2
Sum = 5
*/
//Time Complexity: O(n)