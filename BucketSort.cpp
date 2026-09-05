#include <iostream>
using namespace std;

void bucketSort(int arr[], int n)
{
    int maxValue = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    int bucket[100][100];
    int bucketCount[100] = {0};

    for(int i = 0; i < n; i++)
    {
        int index = arr[i] / 10;

        bucket[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    for(int i = 0; i <= maxValue / 10; i++)
    {
        for(int j = 1; j < bucketCount[i]; j++)
        {
            int key = bucket[i][j];
            int k = j - 1;

            while(k >= 0 && bucket[i][k] > key)
            {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    int k = 0;

    for(int i = 0; i <= maxValue / 10; i++)
    {
        for(int j = 0; j < bucketCount[i]; j++)
        {
            arr[k++] = bucket[i][j];
        }
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

    bucketSort(arr, n);

    cout << "\nSorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Output:

Enter number of elements: 7
Enter 7 integers: 34 12 56 23 98 76 8

Sorted array: 8 12 23 34 56 76 98
*/

/*
Complexity Analysis:

Bucket Sort distributes the elements into different buckets.
Each bucket is then sorted separately.

Best Case:
If the elements are distributed evenly among the buckets,
the sorting of each bucket requires less time.

Best Case = O(n + k)

Average Case:
When the elements are distributed reasonably evenly,
the average time complexity is:

Average Case = O(n + k)

Worst Case:
If all elements are placed in the same bucket, that bucket
needs to sort all n elements.

Using insertion sort for the bucket:

Worst Case = O(n²)

Therefore:

Best Case    : O(n + k)
Average Case : O(n + k)
Worst Case   : O(n²)

Space Complexity = O(n + k)

where:
n = number of elements
k = number of buckets
*/
