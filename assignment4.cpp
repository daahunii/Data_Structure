// 22100661 jeongdahun
/* infix to postfix */
#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

class post_stack{
    char s[SIZE];
    int top;
public:
    post_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
    int size();
};
bool is_operand(char c){
    if(c == '(' || c == ')'|| c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '$') return false;
    else return true;
}
int get_precedence(char op){
    if(op == '$' || op == '(') return 0;
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/' || op == '%') return 2;
    return 3;
}

int main(void)
{
    string input, output; // input : a*(b+c), output : abc+*
    post_stack stack;

    cout << "Input an infix expression to convert : ";
    cin >> input;
    stack.push(EOS);
    int pre[SIZE]; // 연산자의 우선순위 저장
    for(int i=0; i<input.size(); i++){
        if(is_operand(input[i])) output += input[i];
        else{
            if(input[i] != ')'){ // 닫는 괄호 제외하고 스택에 담기
                stack.push(input[i]);
                pre[i] = get_precedence(input[i]);
            }
            if(input[i] == ')'){
                output += stack.pop();
                stack.pop(); // 여는 괄호 삭제
            }
            // if(i > 0)
            //     if(pre[i-1] > pre[i]) output += stack.pop(); //이전 우선순위보다 낮다면 pop
        }
    }
    for(int i=0; i<stack.size(); i++) output += stack.pop(); // 나머지 pop
    cout << "output is : "+ output << endl;
}

post_stack::post_stack(){
    top = 0;
}

void post_stack::push(char x){
    s[top] = x;
    top++;
}

char post_stack::pop(){
    top--;
    return s[top];
}

bool post_stack::empty(){
    return top == 0;
}

char post_stack::top_element(){
    return s[top-1];
}

int post_stack::size(){
    return top;
}
