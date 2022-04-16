// 22100661 jeongdahun
/* palindrome program (stack) */
#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

class Stack{
    char s[SIZE];
    int top;
public:
    Stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
    int size();
};


int main(void)
{
    string input, input2, output;
    Stack stack;

    cout << "Input a palindrome : ";
    getline(cin, input);
    for(int i=0; i<input.size(); i++){
        if(isspace(input[i]) == 0){
            stack.push(input[i]);
            input2 += input[i]; // 공백 제거
        }
    }
    for(int i=0; i<input.size(); i++) output += stack.pop();
    if(input2.compare(output) == -1 || input2.compare(output) == 0) cout << "Yes, It\'s a palindrome." << endl;
    else cout << "No, It\'s not a palindrome." << endl;
}

Stack::Stack(){
    top = 0;
}

void Stack::push(char x){
    s[top] = x;
    top++;
}

char Stack::pop(){
    top--;
    return s[top];
}

bool Stack::empty(){
    return top == 0;
}

char Stack::top_element(){
    return s[top-1];
}

int Stack::size(){
    return top;
}
