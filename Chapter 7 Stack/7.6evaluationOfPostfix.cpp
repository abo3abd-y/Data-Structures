#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

int evaluationOfPostfix(string input) { // here we are just getting all the numbers
    string postfix = infixToPostfix(input);
    Node *nd = nullptr;
    string temp = "";
    int number1;
    int number2;

    vector<int> numbers = {};
    std::string::size_type j = 0;
    for(std::string::size_type i = 0; i < input.length(); i++) { // this just gets the numbers as you can see here
        if(input[i] >= '0' && input[i] <= '9') {
            j = i;
            temp = "";
            while((j < input.length()) && (input[j] >= '0' && input[j] <= '9')) {
                temp += input[j++];
            }
            i = j - 1;
            numbers.push_back(stoi(temp));
        }
    }


    j = 0;

    for(std::string::size_type i= 0; i < postfix.length(); i ++) {
        if(postfix[i] >= '0' && postfix[i] <= '9') {    
            //cout << numbers[j] << endl;
            i += floor(log10(numbers[j])); // this calculates the digits on the fly here
            push(nd, '0', numbers[j++]);
        }else {
            number1 = nd -> precedence;
            number2 = nd -> next -> precedence;
            pop(nd);
            pop(nd);

            if(postfix[i] == '+') {number2 += number1;}
            else if (postfix[i] == '-') {number2-=number1;}
            else if(postfix[i] == '*') {number2*=number1;}
            else{number2/=number1;}

            push(nd, '0', number2);

        }

    }

    if(nd) {
        return nd -> precedence; // the stack will have that one number and that is it
    }
    return -1;
}




int main () {

    cout << evaluationOfPostfix("1454*357+100/4-1983") << endl;
    cout << evaluationOfPostfix("3*5+6/2-4");

    return 0;
}

// our next project is to solve simple algebraic expressions such as x + 1 = 2