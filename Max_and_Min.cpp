#include <iostream>
using namespace std;

void findMaxMin(int arr[],int low,int high,int &max,int &min)
{
    if(low == high)
    {
        max = arr[low];
        min = arr[low];
        return;
    }

    else if(low == high - 1)
    {
        if(arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
        return;
    }
    else
    {
        int mid = low + (high - low) / 2;

        int leftMax, leftMin, rightMax, rightMin;
        

        findMaxMin(arr,low,mid,leftMax,leftMin);

        findMaxMin(arr,mid + 1,high,rightMax,rightMin);

        if(leftMax > rightMax)
            max = leftMax;
        else
            max = rightMax;

        if(leftMin < rightMin)
            min = leftMin;
        else
            min = rightMin;
    }
}

int main()
{
    int arr[100];
    int n;

    cout <<"Enter the number of elements in the array: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout <<"Invalid number of elements. Please enter a number between 1 and 100." << endl;
        return 1;
    }

    cout <<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maximum, minimum;

    findMaxMin(arr,0,n-1,maximum,minimum);

    cout <<"Maximum element in the array is: " << maximum << endl;
    cout <<"Minimum element in the array is: " << minimum << endl;

    return 0;
}

/*
Time Complexity for Traditional Approach: O(n)
Time Complexity for Divide and Conquer Approach: O(n)

Comparisons:
2n - 2 comparisons in the traditional approach.
In the divide and conquer approach, the number of comparisons is approximately 3n/2 - 2 comparisons.

Divide and conquer requires 10 comparisons, while the traditional method requires 14 comparisons.


The divide-and-conquer strategy finds the maximum and minimum using fewer comparisons than the traditional approach. 
Both methods have (O(n)) time complexity, but divide and conquer reduces the number of comparisons from (2n-2) to approximately ((3n/2)-2).

However, divide and conquer requires (O(log n)) extra stack space because it uses recursion. The traditional method 
requires only (O(1)) extra space. Therefore, divide and conquer is better in terms of comparisons and parallel processing, 
while the traditional approach is better in terms of memory usage.

*/

//Output:

/*
Enter the number of elements in the array: 2
Enter the elements of the array: 11 11
Maximum element in the array is: 11
Minimum element in the array is: 11


Enter the number of elements in the array: 5
Enter the elements of the array: 21 41 81 12 98
Maximum element in the array is: 98
Minimum element in the array is: 12

*/