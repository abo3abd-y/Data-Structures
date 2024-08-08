#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

node *binary::binarySearch(node *n, int x) { // this is how is it done
    if(!n) {
        return nullptr;
    }else if(x == n -> data) {
        return n;
    }else if(x < n -> data) {
        return binarySearch(n -> left, x);
    }else{
        return binarySearch(n -> right, x);
    }
}

node *binary::loopBinarySearch(int x) { // this is the loop version as you can see here
    node *temp = root;
    while(temp) {
        if(x == temp -> data) {
            return temp;
        }else if(x < temp -> data) {
            temp = temp -> left;
        }else{
            temp = temp -> right;
        }
    }
    return nullptr;
}

void binary::insert(int x) { // this is the loop version; notice that we can create the recursive version but we won't do that to save time and space
    node *current = root;
    node *prev = nullptr;
    while(current) {
        prev = current;
        if(x > current -> data) {
            current = current -> right;
        }else if(x < current -> data) {
            current = current -> left;
        }else { // if it is equal which is not what we want
            return;
        }
    }
    
    node *newNode = new node;
    newNode -> data = x;
    newNode -> left = newNode -> right = nullptr;
    if(!root) { // if the tree is empty
        root = newNode;
    }else if(x > prev -> data) {
        prev -> right = newNode;
    }else {
        prev->left = newNode;
    }
    
}

void binary::inorder(node *n) {
    if(n) {
        inorder(n -> left);
        cout << n -> data << " ";
        inorder(n -> right);
    }
}

void binary::deleteNode(int x) {
    node *current = root;
    node *prev = nullptr;

    while(current && current->data != x) {
        prev = current;
        if(x > current -> data) {
            current = current -> right;
        }else {
            current = current -> left;
        }
    }

    if(current) {
        if(root != current) {
            if(prev -> data > current -> data) {
                prev->left = (current -> right) ? current ->right : current -> left;
                prev = current -> right;
                while(prev && prev -> left) {prev = prev -> left;}
                
                if(current -> right) {
                    
                    prev -> left = (current->left) ? current->left : prev -> left; // if node-to-be-deleted has a child then we do apply the new child, otherwise we set it to nullptr
                  
                }
                    
                
                
            }else {
                prev->right = (current -> left) ? current->left : current -> right;
                prev = current -> left;
                while(prev && prev -> right) {prev = prev -> right;}
               
                if(current -> left) {
                   
                    prev -> right = (current-> right) ? current->right : prev -> right;
                   
                }
              
                
            }
            delete current;

        }else{
            root = (current -> right) ? current -> right : current -> left;
            prev = current -> right;
            while(prev && prev -> left) {prev = prev -> left;}
            if(current->right) {
                prev -> left = (current->left) ? current->left:prev->left;
            }

            delete current;

        }
    }
}

node *binary::return_root() {return root;}

int main() {

    binary n;
    n.insert(9);
    n.insert(15);
    n.insert(5);
    n.insert(20);
    n.insert(16);
    n.insert(8);
    n.insert(12);
    n.insert(3);
    n.insert(6);

    n.inorder(n.return_root()); // as you can see, this worked perfectly which is what was expected

    cout << endl;
    n.deleteNode(5);
    n.inorder(n.return_root());

    cout << endl;
    n.deleteNode(15);
    n.inorder(n.return_root());

    cout << endl;
    n.deleteNode(6);
    n.inorder(n.return_root());

    cout << endl;
    n.deleteNode(3);
    n.inorder(n.return_root()); //as you can see, this thing works perfectly which is what i needed

    return 0;
}
