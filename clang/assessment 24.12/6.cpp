#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class AvlTreeNode {
private:

public:
    int value, height;
    AvlTreeNode * left, * right;
    AvlTreeNode(int, AvlTreeNode *, AvlTreeNode *);
//    ~AvlTreeNode();
};

int ans = 0;

class AvlTree {
private:
public:
    AvlTreeNode * root;
    AvlTree();
    ~AvlTree();
    void insert(int);
    void erase(int);
};

int getHeight(AvlTreeNode * node) {
    return (node == nullptr) ? 0 : node -> height;
}
void fixHeight(AvlTreeNode * node) {
    int h1 = getHeight(node -> left), h2 = getHeight(node -> right);
    node -> height = (h1 > h2) ? h1 + 1 : h2 + 1;
}
int bf(AvlTreeNode * node) {
    return getHeight(node -> right) - getHeight(node -> left);
}

//Node
AvlTreeNode::AvlTreeNode(int key, AvlTreeNode * l = nullptr, AvlTreeNode * r = nullptr) {
    left = l, right = r;
    value = key;
    fixHeight(this);
    return;
}
//AvlTreeNode::~AvlTreeNode() {
//    if (left != nullptr)
//        delete left;
//    if (right != nullptr)
//        delete right;
//    delete this;
//    return;
//}

//Tree
AvlTree::AvlTree() {
    root = nullptr;
    return;
}
AvlTree::~AvlTree() {
    delete root;
    return;
}

AvlTreeNode * rotateRight(AvlTreeNode * node) {
    if (node->value == 74)
        ++ans;
    AvlTreeNode * node_ = node -> left;
    node -> left = node_ -> right;
    node_ -> right = node;
    fixHeight(node);
    fixHeight(node_);
    return node_;
}

AvlTreeNode * rotateLeft(AvlTreeNode * node) {
    AvlTreeNode * node_ = node -> right;
    node -> right = node_ -> left;
    node_ -> left = node;
    fixHeight(node);
    fixHeight(node_);
    return node_;
}

AvlTreeNode * balancing(AvlTreeNode * hh) {
    fixHeight(hh);
    if (bf(hh) == 2) {
        if (bf(hh -> right) < 0)
            hh -> right = rotateRight(hh -> right);
        return  rotateLeft(hh);
    }
    if (bf(hh) == -2) {
        if (bf(hh -> left) > 0)
            hh -> left = rotateLeft(hh -> left);
        return rotateRight(hh);
    }
    return hh;
}

AvlTreeNode * findDeletor(AvlTreeNode * nowNode) {
    return (nowNode -> left == nullptr) ? nowNode : findDeletor(nowNode -> left);
}
AvlTreeNode * removeDeletor(AvlTreeNode * nowNode) {
    if (nowNode -> left == nullptr)
        return nowNode -> right;
    nowNode -> left = removeDeletor(nowNode -> left);
    return balancing(nowNode);
}

AvlTreeNode * insertion(int key, AvlTreeNode * root) {
    if (root == nullptr)
        return new AvlTreeNode(key);
    if (root -> value == key)
        return root;
    if (root ->value < key)
        root -> right = insertion(key, root -> right);
    else
        root -> left = insertion(key, root -> left);
    return balancing(root);
}

AvlTreeNode * deletion(int key, AvlTreeNode * root) {
    if (root == nullptr)
        return nullptr;
    if (root -> value < key)
        root -> right = deletion(key, root -> right);
    else if (root -> value > key)
        root -> left = deletion(key, root -> left);
    else {
        AvlTreeNode * leftNode = root -> left, * rightNode = root -> right;
        root -> left = root -> right = nullptr;
        delete root;
        if (rightNode == nullptr)
            return leftNode;
        root = findDeletor(rightNode);
        root -> right = removeDeletor(rightNode);
        root -> left = leftNode;
    }
    return balancing(root);
}
void AvlTree::insert(int key) {
    root = insertion(key, root);
    return;
}
void AvlTree::erase(int key) {
    root = deletion(key, root);
    return;
}

int main() {

    std::random_device rd;
    std::mt19937 g(rd());

    int j = 0;
    std::vector<int> v = {10, 56, 13, 21, 99, 58, 54, 74, 59, 27};
    while (1) {
        std::shuffle(v.begin(), v.end(), g);
        AvlTree t;
        for (int i:v)
            t.insert(i);
        if (ans >= 3) {
            std::cout << j << ' ' << ans << ": ";
            for (int i:v)
                std::cout <<  i << ' ';
            return 0;
        }
        ++j;

        ans = 0;
    }
}
