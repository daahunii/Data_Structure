// 22100661 jeongdahun
#include <iostream>
#define Q_SIZE 10
using namespace std;

class element{
public:
    string s_title;
    int npages;
    int price;
    void set_data(string bn, int p, int pr);
};

class my_queue{
    element q[Q_SIZE];
    int front, rear;
public:
    my_queue();
    void insert_q(element x);
    element delete_q();
    bool full();
    bool empty();
};

int main(){
    my_queue a;
    element tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while(!a.empty()){
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
    return 0;
}

my_queue::my_queue(){
    front = 0;
    rear = 0;
}

void my_queue::insert_q(element x){
    if(!full()){
        q[rear] = x;
        rear = (rear+1) % Q_SIZE;
    }
}

bool my_queue::full(){
    if((rear+1)%Q_SIZE == front) return true;
    else return false;
}

bool my_queue::empty(){
    if(rear == front) return true;
    else return false;
}

void element::set_data(string bn, int p, int pr){
    s_title = bn;
    npages = p;
    price = pr;
}

element my_queue::delete_q(){
    element tmp;
    if(!empty()){
        tmp = q[front];
        front = (front+1) % Q_SIZE;
        return tmp;
    }
    else return tmp;
}
