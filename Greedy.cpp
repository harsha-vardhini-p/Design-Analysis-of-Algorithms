#include <iostream>
#include <iomanip>
using namespace std;

struct Item
{
    int profit;
    int weight;
    double ratio;
};

int main()
{
    Item items[100];
    int n;
    int capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter profit and weight of each item:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(items[j].ratio < items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double totalProfit = 0;
    int remainingCapacity = capacity;

    cout << fixed << setprecision(2);

    cout << "\nItems selected:" << endl;

    for(int i = 0; i < n; i++)
    {
        if(items[i].weight <= remainingCapacity)
        {
            totalProfit = totalProfit + items[i].profit;
            remainingCapacity =
                remainingCapacity - items[i].weight;

            cout << "Complete item with profit "
                 << items[i].profit << " and weight "
                 << items[i].weight << endl;
        }

        else
        {
            double fraction =
                (double)remainingCapacity / items[i].weight;

            totalProfit =
                totalProfit + items[i].profit * fraction;

            cout << fraction
                 << " fraction of item with profit "
                 << items[i].profit << " and weight "
                 << items[i].weight << endl;

            remainingCapacity = 0;
            break;
        }
    }

    cout << "\nMaximum profit: " << totalProfit << endl;

    return 0;
}

//Output:
/*
Enter the number of items: 6
Enter the capacity of the knapsack: 15
Enter profit and weight of each item:
Item 1: 4
2
Item 2: 3 6
Item 3: 16 8
Item 4: 14 7
Item 5: 2 5
Item 6: 8 2

Items selected:
Complete item with profit 8 and weight 2
Complete item with profit 4 and weight 2
Complete item with profit 16 and weight 8
0.43 fraction of item with profit 14 and weight 7

Maximum profit: 34.00

Enter the number of items: 3
Enter the capacity of the knapsack: 50
Enter profit and weight of each item:
Item 1: 60 10
Item 2: 100 20
Item 3: 120 30

Items selected:
Complete item with profit 60 and weight 10
Complete item with profit 100 and weight 20
0.67 fraction of item with profit 120 and weight 30

Maximum profit: 240.00
*/