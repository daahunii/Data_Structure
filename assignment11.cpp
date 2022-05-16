// 22100661 jeongdahun
/* heap structure */
#include <iostream>
#define HSIZE 100
using namespace std;

class element{
public:
    string name;
    double score; // key
    void set_data(string n, double s);
};

class my_heap{
    element h[HSIZE];
    int csize; // 현재 만들어진 원소의 개수
    
public:
    my_heap(); // 초기화
    int h_size(); // 원소의 수 리턴
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};

int main()
{
   my_heap h1;
   element temp;
   temp.set_data("Kim", 88);
   h1.insert_heap(temp);
   temp.set_data("Lee", 77);
   h1.insert_heap(temp);
   temp.set_data("Park", 98);
   h1.insert_heap(temp);
   temp.set_data("Choi", 74);
   h1.insert_heap(temp);
   temp.set_data("Ryu", 94);
   h1.insert_heap(temp);
   temp.set_data("Cho", 85);
   h1.insert_heap(temp);
   while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
   }
   return 0;
}

void element::set_data(string n, double s){
    name = n;
    score = s;
}

my_heap::my_heap(){
    csize = 0;
}

int my_heap::h_size(){
    return csize;
}

bool my_heap::heap_full(){
    if(csize >= HSIZE-1) return true;
    else return false;
}

bool my_heap::heap_empty(){
    if(csize == 0) return true;
    else return false;
}

void my_heap::insert_heap(element t){
    int k;
    csize++;
    k = csize;

    while((k != 1)&&(t.score > h[k/2].score)){ // root보다 작거나 parent의 키값보다 크면 올린다!
        h[k] = h[k/2];
        k /= 2; //위로 올림
    }
    h[k] = t; // key 값 확정
}

element my_heap::delete_heap(){
    element t;
    element temp;
    int parent, child;

    t = h[1]; // for return value
    temp = h[csize]; // 끝 원소
    csize--;
    parent = 1; child = 2; // root, root의 left child
    
    while(child <= csize){
        if((child < csize)&&(h[child].score < h[child+1].score)) child++;
        if(temp.score >= h[child].score) break;

        h[parent] = h[child];
        parent = child; // 한단계 아래로
        child *= 2;
    }
    h[parent] = temp;
    return t;
}
