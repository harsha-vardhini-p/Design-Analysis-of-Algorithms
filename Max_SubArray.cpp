#include <iostream>
using namespace std;

int maximum(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}

int crossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = arr[mid];

    for(int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if(sum > leftSum)
        {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = arr[mid + 1];

    for(int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if(sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maximumSubarray(int arr[], int low, int high)
{
    if(low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftSum = maximumSubarray(arr, low, mid);

    int rightSum = maximumSubarray(arr, mid + 1, high);

    int middleSum = crossingSum(arr, low, mid, high);

    return maximum(leftSum, rightSum, middleSum);
}

int main()
{
    int arr[100];
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout << "Invalid array size." << endl;
        return 0;
    }

    cout << "Enter the array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = maximumSubarray(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << answer << endl;

    return 0;
}

/*
Output:
Enter the number of elements: 9
Enter the array elements: -2 1 -3 4 -1 2 1 -5 4
Maximum subarray sum is: 6

Enter the number of elements: 5
Enter the array elements: 3 0 2 -1 6
Maximum subarray sum is: 10
*/