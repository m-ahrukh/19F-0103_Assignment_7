#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    Node* getRoot() {
        return this->root;
    }

    // A utility function to do inorder traversal of BST
    void inorder(Node* r) {
        if (r != NULL) {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    // A utility function to do preorer traversal of BST
    void preorder(Node* r) {
        if (r != NULL) {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    // A utility function to do postorder traversal of BST
    void postorder(Node* r) {
        if (r != NULL) {
            postorder(r->left);
            postorder(r->right);
            cout << r->data << " ";
        }
    }

    /* A utility function to insert a new node with given key in BST */
    Node* insert(Node* node, int key) {
        Node* newNode = new Node;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = key;
        if (this->root == NULL) {
            this->root = newNode;
        }
        /* If the tree is empty, return a new node */
        if (node == NULL) {
            node = newNode;
        }
        /* Otherwise, recur down the tree */
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);

        return node;
    }

    // C function to search a given key in a given BST
    bool Search(Node* node, int key) {
        static int count = 0;
        if (node != NULL) {
            // Base Cases: root is null or key is present at root
            if (node->data == key) {
                count++;
                cout << "Found in " << count << " iterations." << endl;
                return true;
            }
            // Key is greater than root's key
            if (node->data < key) {
                count++;
                return Search(node->right, key);
            }
            // Key is smaller than root's key
            count++;
            return Search(root->left, key);
        }
        cout << "Not found after " << count << " iterations." << endl;
        return false;
    }

    Node* Min(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Function to search a delete a value from tree.
    Node* Delete(Node* root, int data) {
        if (root == NULL) {
            return root;
        }
        else if (data < root->data) {
            root->left = Delete(root->left, data);
        }
        else if (data > root->data) {
            root->right = Delete(root->right, data);
        }
        else {
            // case 1: One child
            if (root->left == NULL) {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // case 2: 2 children
            else {
                Node* temp = Min(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    Node* search(Node* node, int key) {

        if (node != NULL) {
            // Base Cases: root is null or key is present at root
            if (node->data == key) {
                return node;
            }
            // Key is greater than root's key
            if (node->data < key) {
                // count++;
                return search(node->right, key);
            }
            // Key is smaller than root's key
            //count++;
            return search(root->left, key);
        }
        return node;
    }

    int depth(Node* root) {
        int Left, Right;
        if (root == NULL) {
            return 0;
        }
        else {
            Left = depth(root->left); // traversal through left sub tree.
            Right = depth(root->right); // traversal thorugh right sub tree
            if (Left > Right) {
                return (Left + 1);
            }
            return (Right + 1);
        }
    }

    int calculateLevel(Node* node, int data, int level) {
        if (node != NULL) {
            if (node->data == data)
                return level;
            int getLevel = calculateLevel(node->left, data, level + 1);
            if (getLevel != 0)
                return getLevel;

            getLevel = calculateLevel(node->right, data, level + 1);
            return getLevel;
        }
        else
            return 0;
    }

    int Level(Node* node, int data) {
        cout << "Level is ";
        return calculateLevel(node, data, 1);
    }

    int degree(Node* node,int key) {
        Node* temp;
        temp = search(node, key);
        if (temp->left == NULL && temp->right == NULL) {
            return 0;
        }
        else if (temp->left != NULL && temp->right != NULL) {
            return 2;
        }
        else if (temp->left != NULL || temp->right != NULL) {
            return 1;
        }
    }

    bool isParent(Node * node,int parent, int child) {
        Node* temp;
        temp = search(node, parent);
        if (temp->left->data == child || temp->right->data == child) {
            cout << parent << " is parent is of child " << child << endl;
            return 1;
        }
        else {
            cout << parent << " is not the parent of child " << child << endl;
            return 0;
        }
    }

    bool isChild(Node* node, int parent, int child) {
        Node* temp;
        temp = search(node, parent);
        if (temp->left->data == child || temp->right->data == child) {
            cout << child << " is the Child is of Parent " << parent << endl;
            return 1;
        }
        else {
            cout << child << " is not the Child of Prent " << parent << endl;
            return 0;
        }
    }

    bool isLeaf(Node* node, int leaf) {
        Node* temp;
        temp = search(node, leaf);
        if (temp->left == NULL && temp->right == NULL) {
            cout << leaf << " is the leaf node " << endl;
            return 1;
        }
        else {
            cout << leaf << " is not the leaf node " << endl;
            return 0;
        }
    }

    bool isNotLeaf(Node* node, int not_leaf) {
        Node* temp;
        temp = search(node, not_leaf);
        if (temp->left != NULL || temp->right != NULL) {
            cout << leaf << " is the non-leaf node " << endl;
            return 1;
        }
        else {
            cout << leaf << " is not the non-leaf node " << endl;
            return 0;
        }
    }
    int countNodes(Node* node) {
        static int count = 0;
        if (node != NULL) {
            countNodes(node->left);
            count = count + 1;
            countNodes(node->right);
        }
        return count;
    }

    int countLeafNodes(Node* node) {
        static int count = 0;
        if (node != NULL) {
            countLeafNodes(node->left);
            if (node->left == NULL && node->right == NULL) {
                count = count + 1;
            }
            countLeafNodes(node->right);
        }
        return count;
    }

    int countInternalNode(Node * node){
    static int count = 0;
    if (node != NULL) {
        countInternalNode(node->left);
        if (node->left != NULL || node->right != NULL) {
            count = count + 1;
        }
        countInternalNode(node->right);
    }
         return count;
    }

    bool isSibling(Node* node, int parent, int Left, int Right) {
        Node* temp;
        temp = search(node, parent);
        if (temp->left->data == Left && temp->right->data == Right) {
            cout << Left << " and " << Right << " are Siblings " << endl;
            return 1;
        }
        else {
            cout << Left << " and " << Right << " are not Siblings " << endl;
            return 0;
        }
    }

    bool isDescendant(Node* node, int Data) {
        if (node == NULL) {
            return 0;
        }
        if (node->data == Data) {
           
            return 1;
        }
        if (isDescendant(node->left, Data) || isDescendant(node->right, Data)) {
            cout << Data << " is descendant of " << node->data << endl;
            return true;
        }
    }

    bool isSuccessor(Node* node, int parent, int child) {
        Node* temp;
        temp = search(node, parent);
        if (temp->left->data == child || temp->right->data == child) {
            cout << child << " is the Successor of  " << parent << endl;
            return 1;
        }
        else {
            cout << child << " is not the Successor of  " << parent << endl;
            return 0;
        }
    }
    void display() {
        char ch;
        int choice, key;
        do {
            cout << "Enter 1 if you want to insert value in the tree " << endl;
            cout << "Enter 2 if you want to delete value from the tree " << endl;
            cout << "Enter 3 if you want to search any value from the tree " << endl;
            cout << "Enter 4 if you want to print the tree in in-order " << endl;
            cout << "Enter 5 if you want to print the tree in post-order " << endl;
            cout << "Enter 6 if you want to prnt the tree in pre-order " << endl;
            cout << "Enter 7 if you want to get the Depth of Tree " << endl;
            cout << "Enter 8 if you want to get Level of Node " << endl;
            cout << "Enter 9 if you want to get Degree of the Node " << endl;
            cout << "Enter 10 if you want to get the total number of nodes " << endl;
            cout << "Enter 11 if you want to check whether the given node is leaf or not " << endl;
            cout << "Enter 12 if you want to check whether the given node is non_leaf or not " << endl;
            cout << "Enter 13 if you want to check whether the given node is parent or not " << endl;
            cout << "Enter 14 if you want ot check whether the given node is child or not " << endl;
            cout << "Enter 15 if you want to know the descendants of a node " << endl;
            cout << "Enter 16 if you want to check whether the given node is successor or not of the othe given node " << endl;
            vout << "Enter 17 if you want to check the whether the nodes are siblings or not " << endl;
            cout << "Enter 18 if you want to count the leaf nodes " << endl;
            cout << "Enter 19 if you want to count the internal nodes " << endl;
            cout << "Enter your choice "; cin >> choice;
            switch (choice) {
            case 1: {
                cout << "Enter Number you want to insert "; cin >> key;
                insert(getRoot(), key);
                break;
            }
            case 2: {
                cout << "Enter Number you want to delete "; cin >> key;
                Delete(getRoot(), key);
                break;
            }
            case 3: {
                cout << "Enter Number you want to search "; cin >> key;
                if (Search(getRoot(), key)) {
                    cout << "Number found " << endl;
                }
                else {
                    cout << "Number not found " << endl;
                }
                break;
            }
            case 4: {
                cout << "In-order tree is " << endl;
                inorder(getRoot());
                cout << endl;
                break;
            }
            case 5: {
                cout << "Pre-order tree is " << endl;
                preorder(getRoot());
                cout << endl;
                break;
            }
            case 6: {
                cout << "Post-order tree is " << endl;
                postorder(getRoot());
                cout << endl;
                break;
            }
            case 7: {
                cout << "Depth is " << T.depth(T.getRoot()) << endl;
                break;
            }
            case 8: {
                cout << "Enter value of node of which you want to know the Level "; cin >> key;
                cout << T.Level(T.getRoot(), key) << endl;
                break;
            }
            case 9: {
                cout << "Enter value of node of which you want to now the degree "; cin >> key;
                cout << "Degree is " << T.degree(T.getRoot(), key) << endl;
                break;
            }
            case 10: {
                cout << "Total number of nodes are " << T.countNodes(T.getRoot()) << endl;
                break;
            }
            case 11: {
                cout << "Enter Value of node whcich you want to check whether it is leaf or not "; cin >> key;
                cout << T.isLeaf(T.getRoot(), key);
                break;
            }
            case 12: {
                cout << "Enter Value of node whcich you want to check whether it is non-leaf or not "; cin >> key;
                cout << T.isNotLeaf(T.getRoot(), key);
                break;
            }
            case 13: {
                int key1;
                cout << "Enter value of parent node "; cin >> key;
                cout << "Enter value of Child node "; cin >> key1;
                cout << T.isParent(T.getRoot(), key, key1) << endl;
                break;
            }
            case 14: {
                int key1;
                cout << "Enter value of parent node "; cin >> key;
                cout << "Enter value of Child node "; cin >> key1;
                cout << T.isChild(T.getRoot(), key, key1) << endl;
                break;
            }
            case 15: {
                cout << "Enter values of the node of which you want to know the descendants "; cin >> key;
                T.isDescendant(T.getRoot(), key);
                break;
            }
            case 16: {
                int key1;
                cout << "Enter vulue of Parent Node "; cin >> key;
                cout << "Enter value of Child Node "; cin >> key1;
                T.isSuccessor(T.getRoot(), key, key1);
                break;
            }
            case 17: {
                int key1, key2;
                cout << "Enter value of the Parent Node "; cin >> key;
                cout << "Enter value of the left Child Node "; cin >> key1;
                cout << "Enter value of the right Child Node "; cin >> key2;
                T.isSibling(T.getRoot(), key, key1, key2);
                break;
            }
            case 18: {
                cout << "Total Leaf nodes are " << T.countLeafNodes(T.getRoot()) << endl;
                break;
            }
            case 19: {
                cout << "Total Internal nodes are " << T.countInternalNode(T.getRoot()) << endl;
                break;
            }
            default: {
                cout << "Invalid Input " << endl; 
            
            }
            }
            system("pause");
            system("cls");
            cout << "Enter \'Y\' or  \'y\' if you want to continue "; cin >> ch;
        } while (ch == 'Y' || ch == 'y');
    }
};

int main() {
    Tree T;
    T.display();
    cout << endl;
    return 0;
}