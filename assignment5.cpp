// 22100661 jeongdahun
/* Stack parenthesis check program */
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
bool is_operand(char c){
    if(c == '(' || c == ')'|| c == '{' || c == '}' || c == '[' || c == ']') return false;
    else return true;
}

int check_matching(string str){
    int i=0;
    char ch, prev;
    Stack ch_stack;

    while(str[i] != '\0'){
        ch = str[i++];
        if(ch == '(' || ch == '{' || ch == '[') ch_stack.push(ch);
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(ch_stack.empty()) return 2; // 스택이 비어있어서 꺼낼 수 없는 경우
            prev = ch_stack.pop();
            if((ch == ')' && prev != '(') || (ch == '}' && prev != '{') || (ch == ']' && prev != '['))
                return 3; // 여는괄호와 짝이 맞지 않는 경우
        }
    }
    if(!ch_stack.empty()) return 1; // 스택에 괄호가 남아있는 경우
    return 0; // 정상
}

int main(void)
{
    string input;
    Stack stack;

    cout << "Input an expression : ";
    cin >> input;
    int result = check_matching(input);
    if(result == 0) cout << "It's a normal expression" << endl;
    if(result == 1) cout << "Error: An extra parenthesis." << endl;
    if(result == 2 || result == 3) cout << "Error: mis-mathched parenthesis" << endl;
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
