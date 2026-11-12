
#include<iostream>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* create(char ch, Node* l=NULL, Node* r=NULL) {
    Node* n = new Node();
    n->data = ch;
    n->left = l;
    n->right = r;
    return n;
}

void generate(Node* n) {
    if(n == NULL) return;

    if(n->left == NULL && n->right == NULL) {
        cout << "LOAD R0, " << n->data << endl;
        return;
    }

    generate(n->left);
    generate(n->right);

    if(n->data == '+')
        cout << "ADD R0, R1" << endl;
    else if(n->data == '*')
        cout << "MUL R0, R1" << endl;
}

int main() {
    Node* a = create('a');
    Node* b = create('b');
    Node* c = create('c');

    Node* mul = create('*', b, c);
    Node* root = create('+', a, mul);

    cout << "Generated Machine Code:\n";
    generate(root);

    return 0;
}
