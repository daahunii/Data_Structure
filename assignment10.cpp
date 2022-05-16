// 22100661 정다훈
/* HW6 palindrom Linked list version */
#include <iostream>
#include <string>
using namespace std;

class node{
public:
    char alpha;
    node *link;
};

class my_stack{
    node *top;
public:
    my_stack();
    void push(node t);
    node pop();
    bool stack_empty();
};

int main(void)
{
    string input, input2, output;
    my_stack s;
    node tmp, tmp2;

    cout << "Input a palindrome : ";
    getline(cin, input);
    for(int i=0; i<input.size(); i++){
        if(isspace(input[i]) == 0){
            tmp.alpha = input[i];
            s.push(tmp);
            input2 += input[i]; // 공백 제거
        }
    }
    for(int i=0; i<input.size(); i++){
        tmp2 = s.pop();
        output += tmp2.alpha;
    }
    if(input2.compare(output) == -1 || input2.compare(output) == 0) cout << "Yes, It\'s a palindrome." << endl;
    else cout << "No, It\'s not a palindrome." << endl;
}

my_stack::my_stack(){
    top = NULL;
}

void my_stack::push(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = top;
    top = p;
}

node my_stack::pop(){
    if(top == NULL) exit(1);
    node temp;
    node *t;
    t = top;
    temp = *top;
    top = top->link;
    delete t;
    return temp;
}

bool my_stack::stack_empty(){
    if(top == NULL) return true;
    else return false;
}
