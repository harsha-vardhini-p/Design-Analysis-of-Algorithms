#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c,int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct compare
{
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(Node* root, string str)
{
    if (root == nullptr)
        return;

    if(root ->left == nullptr && root->right == nullptr)
    {
        cout << root->ch << ": " << (str.empty() ? "0" : str)<< endl;
        return;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCoding(char chars[], int freq[], int size)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(chars[i], freq[i]));

    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top(); 
        minHeap.pop();
        Node *right = minHeap.top(); 
        minHeap.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    Node* root = minHeap.top();
    cout<<"Huffman Codes:\n";
    printCodes(root, " ");
}

int main()
{
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Number of characters must be positive." << endl;
        return 1;
    }

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter the characters and their frequencies:\n";

    for(int i = 0; i < n; ++i)
    {
        cin >> chars[i] >> freq[i];

        if(freq[i] <= 0)
        {
            cout << "Frequency must be positive." << endl;
            return 1;
        }
    }
    HuffmanCoding(chars.data(), freq.data(), n);

    return 0;
}

//OUTPUT

/*
Enter the number of characters: 5
Enter the characters and their frequencies:
A 89
B 43
C 64
D 34
E 21

Huffman Codes:
E: 000
D: 001
B: 01
C: 10
A: 11
*/