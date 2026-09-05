#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= pivot && i < high)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

//Output:

/*
Enter number of elements: 7
Enter 7 integers: 34 12 56 23 98 76 8 

Sorted array: 8 12 23 34 56 76 98
*/


/*
Complexity Analysis:

Quick Sort follows the Divide and Conquer technique.

Best Case:
When the pivot divides the array into two nearly equal parts,
there are log n levels and O(n) work at each level.

Best Case = O(n log n)


Average Case:
On average, the pivot divides the array into reasonably sized
partitions.

Average Case = O(n log n)


Worst Case:
When the pivot is always the smallest or largest element,
the partitions become:

n, n-1, n-2, ..., 1

Total work = n + (n-1) + (n-2) + ... + 1
           = n(n+1)/2
           = O(n²)

Worst Case = O(n²)


Space Complexity:

Best Case    : O(log n)
Average Case : O(log n)
Worst Case   : O(n)
*/