// 22100661 jeongdahun
/* stack */
#include <iostream>
#define SIZE 10
using namespace std;

class mystack{
private:
    int s[SIZE];
    int top;
public:
    void init();
    void push(int e);
    int pop();
    bool stack_full();
    bool stack_empty();
};

int main()
{
    mystack  s1;
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;
    s1.init();
    for(i = 0; i < 5; i++ )
        if(list[i] > 100) s1.push(list[i]);
    
    while(!s1.stack_empty()){
        x = s1.pop();
        cout << x << endl;
    }
    return 0;
}

void mystack::init(){
    top = 0;
}
void mystack::push(int e){
    s[top] = e;
    top++;
}
int mystack::pop(){
    top--;
    return s[top];
}
bool mystack::stack_full(){
    if(top >= SIZE) return true;
    else return false;
}
bool mystack::stack_empty(){
    if(top == 0) return true;
    else return false;
}
