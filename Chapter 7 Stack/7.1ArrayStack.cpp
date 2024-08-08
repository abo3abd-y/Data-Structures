#include<iostream>

using namespace std;

// stack is basically a list in which the last element is the first element getting out


struct stack {
    int size;
    int top;
    int *lst; // this is a pointer to the list that we are creating which is basically a list if you know what i mean
};

void create (stack *st, int size) {
    st->size = size;
    st->lst = new int[size];
    st -> top = -1;

}

void display (stack st) {
    for(int i = st.top; i >= 0; i --) {
        cout << st.lst[i] << " ";
    }
    cout << endl;
}

void push(stack *st, int x) {
    if(st -> top == (st -> size  - 1)) {
        cout << "Stack Overflow" << endl;
    }else {
        st -> lst[++ st -> top] = x; // this just means increment then access the element at that position and then assign
    }
}

void pop (stack *st) {
    if(!(st -> top == -1)) {
        st -> lst[st -> top --] = -1; // you can print the value that is being deleted but i do not wanna do it here so 
    }
}

int peek(stack st, int position) { // as you can see, we are not really changing the values inside the stack but we are just accessing the stack
    if(st.top - position + 1 >= 0) {
        return st.lst[st.top - position + 1];
    }
    return -1;
}

int stackTop (stack st) {
    if(st.top >= 0) {
        return st.lst[st.top];
    }
    return -1;
}

bool isEmpty (stack st) {
    if(st.top == -1) {return true;} // the stack is empty as you can see here
    return false;
}

bool isFull (stack st) {
    if(st.top == (st.size - 1)) { // the stack is full as you can see here
        return true;
    }
    return false;
}

int main () {

    stack st;

    create (&st, 10);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    display(st);

    cout << stackTop(st) << endl; // works ok

    cout << isEmpty(st) << endl; // not empty as you can see

    cout << isFull(st) << endl; // not full either

    cout << peek(st, 1) << endl; // this works ok as you can see
    pop(&st);
    pop(&st);

    display(st); // the pop function works as expected fro the function and its specifications

    return 0;
}