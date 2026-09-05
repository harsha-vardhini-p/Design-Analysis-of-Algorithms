#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int temp[100];
    int i = low,j = mid + 1,k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid )
    {
        temp[k++] = arr[i++];
    }

    while(j <= high)
    {
        temp[k++] = arr[j++];
    }

    for(int x = low ; x <= high ; x++)
    {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array : ";

    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    cout<<"Sorted array : ";

    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//Output : 

/*
Enter the number of elements in the array : 5
Enter the elements of the array : 45 23 81 92 32
Sorted array : 23 32 45 81 92 
*/



/*
Complexity Analysis:

Merge Sort follows the Divide and Conquer technique.

The array is repeatedly divided into two halves:

n → n/2 → n/4 → n/8 → ... → 1

The number of levels is log₂(n).

At each level, all n elements are processed during
the merging operation.

Therefore,

Time Complexity = Number of levels × Work at each level
                = O(log n) × O(n)
                = O(n log n)

Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n log n)

Space Complexity: O(n)
*/