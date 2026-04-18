#include <iostream>
using namespace std;

int count = 0;   // counts total comparisons

struct node {
    int data;
    node *left, *right;
};

node* insert(node* root, int val) {
    if (root == NULL) {
        node* temp = new node();
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }

    count++;   // increment count instead of comp

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    int n, x;
    node* root = NULL;
    
    cout <<"BinarySearchTree_Basant_80117739"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Sorted array:\n";
    inorder(root);

    cout << "\nTotal count: " << count;

    return 0;
}
