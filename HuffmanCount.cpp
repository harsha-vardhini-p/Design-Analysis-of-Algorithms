#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) const {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << '\n';
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    char letters[] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't', 'u'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < 9; i++)
        pq.push(new Node(letters[i], freq[i]));

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();

        pq.push(new Node('\0', l->freq + r->freq, l, r));
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

//OUTPUT:
/*
Huffman Codes:
e : 000
s : 001
t : 01
c : 100
d : 10100
u : 10101
m : 1011
o : 110
a : 111


*/