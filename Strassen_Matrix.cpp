#include <iostream>
using namespace std;

int main()
{
    int A[2][2];
    int B[2][2];
    int C[2][2];

    cout << "Enter the elements of first 2x2 matrix:" << endl;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of second 2x2 matrix:" << endl;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> B[i][j];
        }
    }

    int a = A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];

    int e = B[0][0];
    int f = B[0][1];
    int g = B[1][0];
    int h = B[1][1];

    int M1 = (a + d) * (e + h);
    int M2 = (c + d) * e;
    int M3 = a * (f - h);
    int M4 = d * (g - e);
    int M5 = (a + b) * h;
    int M6 = (c - a) * (e + f);
    int M7 = (b - d) * (g + h);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;

    cout << "Resultant matrix:" << endl;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

/*
Strassen’s algorithm improves matrix multiplication by reducing the number of 
recursive multiplications from 8 to 7. Therefore, its time complexity is approximately 
(O(n^{2.807})), which is better than the (O(n^3)) complexity of normal matrix multiplication. 
It is mainly advantageous for large matrices.
*/

//Output:

/*
Enter the elements of first 2x2 matrix:
1 2
3 4
Enter the elements of second 2x2 matrix:
5 6
7 8
Resultant matrix:
19 22 
43 50 
*/