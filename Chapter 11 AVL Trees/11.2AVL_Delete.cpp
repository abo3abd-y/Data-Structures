#include <iostream>

using namespace std;

struct Node {
    Node *left;
    int data;
    int height; // this calculates the height of the tree
    Node *right;
};

Node *root = nullptr;

int nodeHeight(Node *p) {
    int left = (p && p -> left) ? p -> left -> height : 0;
    int right = (p && p -> right) ? p -> right -> height : 0;

    return (left > right) ? left + 1 : right + 1;
}

int balanceFactor (Node *p) { // this calculates the balance factor as you can see here
    int left = (p && p -> left) ? p -> left -> height : 0; // copied from the above function as you can see here
    int right = (p && p -> right) ? p -> right -> height : 0;
    return left - right;
}

Node * llRotation(Node *p) {
    Node *temp = p -> left -> right; // write it down so you won't forget
    Node *leftChild = p -> left;
    leftChild -> right = p;
    p -> left = temp; // thats about it

    p -> height = nodeHeight(p); // do not forget to change their heights because their nodes shifted and had differnet children as you can see here
    leftChild -> height = nodeHeight(leftChild);

    if(root == p) {
        root = leftChild;
    }

    return leftChild;

}

Node * lrRotation(Node *p) {
    Node *plr = p -> left -> right;
    Node *right = plr -> right;
    Node *left = plr -> left;

    plr -> right = p;
    plr -> left = p-> left;

    p->left = right;
    plr -> left -> right = left; // as you can see we made the necessary changes which is what was needed

    // all of their heights will be changed because their children changed

    plr -> left -> height = nodeHeight(plr -> left);
    p -> height = nodeHeight(p);
    plr -> height = nodeHeight(plr);

    if(p == root) { // do not forget to change the root if p was equal to root
        root = plr;
    }

    return plr;


}

Node * rrRotation(Node *p) {
    Node *pr = p -> right;
    Node *prl = p -> left;
    pr -> left = p;
    p -> right = prl;

    pr -> height = nodeHeight(pr);
    p -> height = nodeHeight(p);

    if(p == root) {
        root = pr;
    }

    return pr;

    
}

Node * rlRotation(Node *p) {
    Node *prl = p -> right -> left;
    Node *right = prl -> right;
    Node *left = prl -> left;
    Node *pr = p -> right;

    prl -> right = p -> right;
    prl -> left = p;

    p-> right = left;
    pr -> left = right;

    // do not forget to modify the heights as you can see here
    prl -> height = nodeHeight(prl);
    p -> height = nodeHeight(p);
    pr -> height = nodeHeight(pr);

    if(p == root) {
        root = prl;
    }

    

}

Node * insert(int x, Node *p) { // as you can see here, we are using the recursive version to insert a node in the binary tree
    Node *t = nullptr;

    if(!p) {
        t = new Node;
        t -> data = x;
        t -> height = 1; // we are starting the heighrt at 1 which is different than what we learned in the videos
        t -> left = t -> right = nullptr;
        return t;
    }
    
    if(x < p -> data) {
        p -> left = insert(x, p -> left);
    }else if(x > p -> data) {
        p -> right = insert (x, p -> right);
    }

    p -> height = nodeHeight(p); // we calculate the height of every node that is being affected by the addition of this node

    // now we check if we have to do any sort of rotations as you can see here 

    if((balanceFactor(p) == 2) && balanceFactor(p->left) == 1) {return llRotation(p);} // here call the function for LL rotation because p->left is indeed 1 which means that there is a node to p's left's child
    else if((balanceFactor(p) == 2) && balanceFactor(p->left) == -1) {return lrRotation(p);}
    else if ((balanceFactor(p) == -2) && balanceFactor(p->right) == -1) {return rrRotation(p);}
    else if((balanceFactor(p) == -2) && balanceFactor(p->right) == 1) {return rlRotation(p);}
    return p;
    
}

int main () {

    // root = insert(10, root);
    // insert(5, root);
    // insert(2, root);

    root = insert(50, root);
    insert(10, root);
    insert(20, root);

    cout << root -> data << endl; // ll works perfectly as you can see here
    
    return 0;
}

// we wiill compelte deletion later on but not right now