#include <iostream>
#include <string>

using namespace std;

// here we are representing stack as linked lists which might be easier depending on your preferences

struct Node {
    char sign;
    int precedence;
    Node *next;
};

Node *top = nullptr;

bool isEmpty (Node *topNode) {
    if(!topNode) {return true;}
    return false;
}

bool isFull () {
    Node *newNode = new Node;
    if(!newNode) {
        delete newNode;
        return true;
    }
    delete newNode;
    return false;
}

void push(Node *&topNode, char x, int y) {// as you can see here, we have edited the push function based on our new definition of node because of the problem that we have here
    Node *t = new Node;
    t -> sign = x;
    t -> precedence = y;

    if(!topNode) { // if this the first node that we are adding
       
        t -> next = nullptr;
        topNode = t;
        return;
    }
    t -> next = topNode;
    topNode = t;

}

void pop(Node *&topNode) {
    if(topNode) { // as simple as that as you can see
        Node *t = topNode;
        topNode = topNode -> next;
        delete t;
    }
}

int peek (Node *topNode, int position) {
    // the pointer is not empty and has at least one item in it
    Node *p = topNode;
    for(int i = 1; i < (position) && p;i ++) {
        p = p -> next;
    }

    if(p) {
        return p -> precedence;
    }
    return -1; // the pointer is either null or the head pointer itself is nullptr

   
}

int stackTop (Node *topNode) {
    if (topNode) {
        return topNode -> precedence;
    }
    return -1;
}





string infixToPostfix(string input) { // this function works well as you can well see here
    Node *nd = nullptr;
    string answer  = "";
    int prec = 0;

    for(std::string::size_type i = 0; i < input.length(); i ++ ) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            if(input[i] == '+' || input [i] == '-') {prec = 1;} // either + or -
            else{prec = 2;} // or * and /

            if(!nd || prec > stackTop(nd)) {push(nd, input[i], prec);} // if the top is empty or the stack top's precedence is lower then we just push as you can see here
            else { // this means that the stack is not empty and prec is not bigger than the stack's precedence
                Node *iterator = nd;
                while (iterator) {
                    if(prec > iterator -> precedence) {
                        push(nd, input[i], prec);
                        break;
                    }
                    answer += iterator -> sign;
                    iterator = iterator -> next; // we do this because we do not want a segmentation fault as you well know what it is
                    pop(nd);
                }

                if(!iterator) {push(nd, input[i], prec);}
            }
        }else {
            answer += input[i];
        }
    }

    Node *iterator = nd; // in case we had left overs, we just add those signs to the string and then return the string as the answer
    while (iterator) {
        answer += iterator -> sign;
        iterator = iterator -> next; 
        pop(nd);
    }

    return answer;

    
}




int main () {

    cout << infixToPostfix("a+b*c-d/e") << endl; // it works well as you can see here which is a good thing if you know what i mean
    cout << infixToPostfix("3*5+6/2-4") << endl;

    return 0;
}