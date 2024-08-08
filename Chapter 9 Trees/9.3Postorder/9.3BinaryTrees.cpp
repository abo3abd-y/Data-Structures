#include <iostream>
#include "9.3BinaryTree.h"
using namespace std;

// trees are a non-linear data structure that mainly uses linked lists to create its data structure

void queue::enqueue(treeNode *x) { // this is from the queue as you can see here
    Node *newNode = new Node;
    newNode -> data = x;
    newNode -> next = nullptr;

    
    if(!back) { // if it is empty then we do this
        front = back = newNode;
    }else {
        back -> next = newNode;
        back = back -> next;
    }
}

treeNode * queue::dequeue() { // we want it to return the treeNode because we will need to insert more nodes or not
    if(front) { // this just means if front is not a nullptr
        treeNode *placeholder = front -> data;
        back = (front == back) ? nullptr : back;
        front = (front == back) ? nullptr : front -> next;
        return placeholder; // see, we are not deleting the node as you can see here
    }
    return nullptr;
}

Node * queue::return_front() {
    return front;
}
Node * queue::return_back() {
    return back;
}



void binaryTree :: create () {
    queue q;
    cout << "Enter the root value" << endl;

    int x = 0;
    cin >> x;

    root = new treeNode;
    root -> data = x;
    root -> right = root -> left = nullptr;
    q.enqueue(root); // we pass the address of the root as the input as you can see here

    treeNode *temp = nullptr;

    while (q.return_front() && q.return_back()) {
        temp = q.dequeue();
        cout << "Enter the value that is to be added to the left of " << temp -> data << ": "<<endl;
        cin >> x;
        if(x != -1) { // for the left child
            treeNode *newNode = new treeNode;
            newNode ->data = x;
            newNode -> left = newNode -> right = nullptr;
            temp -> left = newNode; // assign the newNode to be the left child of the 
            q.enqueue(newNode);
            
        }
        cout << "Enter the value that is to be added to the right of " << temp -> data << ": "<< endl;
        cin >> x;

        if(x != -1) { // for the right child
            treeNode *newNode = new treeNode;
            newNode ->data = x;
            newNode -> left = newNode -> right = nullptr;
            temp -> right = newNode; // assign the newNode to be the left child of the 
            q.enqueue(newNode);
            
        }
    }

    
}



treeNode * binaryTree ::return_root () {
    return root;
}

void binaryTree::preorder(treeNode *binaryNode) {
    if(binaryNode) {
        cout << binaryNode -> data << " ";
        preorder(binaryNode -> left);
        preorder(binaryNode -> right); // print, then go left then right
    }
}

void binaryTree::inorder (treeNode *binaryNode) {
    if(binaryNode) {
        inorder(binaryNode -> left);
        cout << binaryNode -> data << " ";
        inorder(binaryNode -> right);
    }
}

void binaryTree ::postorder(treeNode *binaryNode) {
    if(binaryNode) {
        postorder(binaryNode -> left);
        postorder(binaryNode -> right);
        cout << binaryNode -> data << " ";
    }
}




// a binary tree is in which a node might have 0, 1, or two children 

// you can notice that when there is a binary tree with n nodes, then there are n + 1 null nodes in the tree


int main () {

    binaryTree b;
    b.create();

    b.preorder(b.return_root()); // this is supposed to print the whole tree
    cout << endl; // as you can see, this works perfectly

    b.inorder(b.return_root()); // did you see how the displays of the two functions differ (how preorder and inorder differ?)
    cout << endl;

    b.postorder(b.return_root()); // now do you see how the diplays differs with all the three different ways of displaying a binary tree
    cout << endl;

    return 0;
}