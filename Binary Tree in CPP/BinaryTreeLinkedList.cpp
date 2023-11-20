#include <iostream>
#include <iomanip>
#include <vector>

using namespace std; 

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        // Clean up the tree by deleting nodes
        destroyTree(root);
    }

    void insert(T value) {
        root = insertNode(root, value);
    }

    void remove(T value) {
        root = deleteNode(root, value);
    }

    bool search(T value) const {
        return searchNode(root, value);
    }

    void display() const {
        displayTree(root, 0);
    }

    vector<T> preOrderTraversal() const {
        vector<T> result;
        preOrderTraversal(root, result);
        return result;
    }

    vector<T> inOrderTraversal() const {
        vector<T> result;
        inOrderTraversal(root, result);
        return result;
    }

    vector<T> postOrderTraversal() const {
        vector<T> result;
        postOrderTraversal(root, result);
        return result;
    }

private:
    TreeNode<T>* insertNode(TreeNode<T>* node, T value) {
        if (node == nullptr)
            return new TreeNode<T>(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    TreeNode<T>* deleteNode(TreeNode<T>* node, T value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    TreeNode<T>* findMin(TreeNode<T>* node) const {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    bool searchNode(TreeNode<T>* node, T value) const {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;
        else if (value < node->data)
            return searchNode(node->left, value);
        else
            return searchNode(node->right, value);
    }

    void displayTree(TreeNode<T>* node, int indent) const {
        if (node == nullptr)
            return;

        if (node->right)
            displayTree(node->right, indent + 4);

        if (indent > 0)
            cout << setw(indent) << ' ';

        cout << "(" <<  node->data  << ")" << "\n";

        if (node->left)
            displayTree(node->left, indent + 4);
    }

    void destroyTree(TreeNode<T>* node) {
        if (node == nullptr)
            return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void preOrderTraversal(TreeNode<T>* node, vector<T>& result) const {
        if (node == nullptr)
            return;

        result.push_back(node->data);
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }

    void inOrderTraversal(TreeNode<T>* node, vector<T>& result) const {
        if (node == nullptr)
            return;

        inOrderTraversal(node->left, result);
        result.push_back(node->data);
        inOrderTraversal(node->right, result);
    }

    void postOrderTraversal(TreeNode<T>* node, vector<T>& result) const {
        if (node == nullptr)
            return;

        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result.push_back(node->data);
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);

    cout << "Binary Tree:" << endl;
    tree.display();

    cout << "Searching for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;
    cout << "Searching for 6: " << (tree.search(6) ? "Found" : "Not Found") << endl;

    vector<int> preOrder = tree.preOrderTraversal();
    cout << "Pre-order traversal: ";
    for (const auto& val : preOrder)
        cout << val << " ";
    cout << endl;

    vector<int> inOrder = tree.inOrderTraversal();
    cout << "In-order traversal: ";
    for (const auto& val : inOrder)
        cout << val << " ";
    cout << endl;

    vector<int> postOrder = tree.postOrderTraversal();
    cout << "Post-order traversal: ";
    for (const auto& val : postOrder)
        cout << val << " ";
    cout << endl;

    tree.remove(3);

    cout << "Binary Tree after deletion:" << endl;
    tree.display();

    return 0;
}
