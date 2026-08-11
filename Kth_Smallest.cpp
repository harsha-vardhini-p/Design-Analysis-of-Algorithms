#include <iostream>
using namespace std;

int kthSmallest(int A[], int n, int k)
{
    // Bubble Sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return A[k - 1];
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter k: ";
    cin >> k;

    cout << "Kth smallest element = "
         << kthSmallest(A, n, k);

    return 0;
}

/*
Time Complexity: O(n^2)

Output:
Enter number of elements: 5
Enter elements: 7 10 4 3 20
Enter k: 4
Kth smallest element = Sorted array: 3 4 7 10 20
10
*/



//Way - 2 : Using Merge Sort

#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while(i <= mid && j <= high)
    {
        if(A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while(i <= mid)
        temp[k++] = A[i++];

    while(j <= high)
        temp[k++] = A[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        A[i] = temp[k];
}

void mergeSort(int A[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

int kthSmallest(int A[], int n, int k)
{
    // Merge Sort
    mergeSort(A, 0, n - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    // Return kth smallest element
    return A[k - 1];
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter k: ";
    cin >> k;

    cout << "Kth smallest element = "
         << kthSmallest(A, n, k);

    return 0;
}

/*
Time Complexity: O(n log n)

Output:
Enter number of elements: 5
Enter elements: 96 32 65 71 81
Enter k: 2
Kth smallest element = Sorted array: 32 65 71 81 96
65
*/