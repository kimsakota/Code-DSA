/*
﻿Nguyen Kim Linh
20233495
              ..╱ | 、 ♡
               (˚ˎ 。7      ⋆
                | 、˜〵
                じしˍ, )ノ
*/

#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

#define TVALUE string
struct Node {
    TVALUE data;
    Node* left;
    Node* right;

    Node(TVALUE value) {
        data = value;
        left = right = NULL;
    }
};

Node* createNode(TVALUE data) {
    return new Node(data);
}

bool is_tree_empty(Node* root) {
    return root == NULL;
}

void insertNode(Node*& root, TVALUE data) {
    if (is_tree_empty(root)) {
        root = createNode(data);
        return;
    }
    if (root->left == NULL)
        insertNode((root)->left, data);
    else if (is_tree_empty(root->right))
        insertNode(root->right, data);
    else
        insertNode(root->left, data);
}

/*
    Preorder - M L R
    Inorder - L M R
    Postorder - L R M
*/

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = createNode("+");

    //Tạo phần bên phải 
    Node* nhan1 = createNode("*");
    Node* a = createNode("a");
    Node* nam = createNode("5");
    nhan1->left = a;
    nhan1->right = nam;

    Node* mu1 = createNode("^");
    Node* c = createNode("c");
    Node* sau = createNode("6");
    mu1->left = c;
    mu1->right = sau;

    Node* chia1 = createNode("/");
    Node* d = createNode("d");
    chia1->left = mu1;
    chia1->right = d;

    Node* nhan2 = createNode("*");
    Node* b = createNode("b");
    nhan2->left = b;
    nhan2->right = chia1;

    Node* tru1 = createNode("-");
    tru1->left = nhan1;
    tru1->right = nhan2;

    //tạo phần bên phải 
    Node* h = createNode("h");
    Node* f = createNode("f");
    Node* tru2 = createNode("-");
    tru2->left = h;
    tru2->right = f;

    Node* mu2 = createNode("^");
    Node* e = createNode("e");
    Node* mot2 = createNode("1/2");
    mu2->left = e;
    mu2->right = mot2;

    Node* nhan3 = createNode("*");
    nhan3->left = tru2;
    nhan3->right = mu2;

    root->left = tru1;
    root->right = nhan3;
    cout << "Trung to: ";
    inorder(root);
    cout << "\nTien to: ";
    preorder(root);
    cout << "\nHau To: ";
    postorder(root);
}