/* heap exercise */
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
    void adjust(int t_root);
public:
    my_heap(); // 초기화
    my_heap(element a[], int n);
    int h_size(); // 원소의 수 리턴
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double score_average();
    int node_delete_by_name(string tname);
};

double summation(element a[], int troot, int n);
int delete_node(element a[], int troot, string tname, int n);
void heap_adjust(element a[], int troot, int size);

int main()
{
    int check = 0;
   element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85} };
   my_heap h1(a, 6);
   element temp;

   cout << "Number of nodes : " << h1.h_size() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;
   
   check = h1.node_delete_by_name("Kim");

   cout << "\n-- After the deletion operation. --\n\n";
   cout << "Number of nodes : " << h1.h_size() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;

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

my_heap::my_heap(element a[], int n){
    int i;
    for(i=1; i<=n; i++) h[i] = a[i-1];
    csize = n;
    for(i=n; i>=1; i--) adjust(i);
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

    t = h[1]; // for return value (root의 값)
    temp = h[csize]; // 끝 원소
    csize--;
    parent = 1; child = 2; // root, root의 left child
    
    while(child <= csize){
        if((child < csize)&&(h[child].score < h[child+1].score)) child++; // 오른쪽이 존재하고 오른쪽이 크면 오른쪽 선택!
        if(temp.score >= h[child].score) break;

        h[parent] = h[child];
        parent = child; // 한단계 아래로
        child *= 2;
    }
    h[parent] = temp;
    return t;
}

void my_heap::adjust(int t_root){
    double tmpkey;
    int child;
    element tmp;

    tmp = h[t_root];
    tmpkey = h[t_root].score;
    child = 2*t_root;

    while(child <= csize){
        if((child < csize)&&(h[child].score < h[child+1].score)) child++;
        if(tmpkey > h[child].score) break;
        else{
            h[child/2] = h[child];
            child *= 2;
        }
    }
    h[child/2] = tmp;
}

double my_heap::score_sum(){
    return summation(h, 1, csize);
}

double summation(element a[], int troot, int n){
    if(troot > n) return 0;
    return (a[troot].score + summation(a, 2*troot, n) + summation(a, 2*troot+1, n));
}

double my_heap::score_average(){
    if(csize == 0) return 0;
    return score_sum()/csize;
}

int my_heap::node_delete_by_name(string tname){
    if(csize == 0) return 0;
    if(delete_node(h, 1, tname, csize) == 1){
        csize--;
        return 1;
    }
    else return 0;
}

int delete_node(element a[], int troot, string tname, int n){
    int check = 0, idx;
    element tmp;
    tmp = a[troot];
    if(troot > n) return 0;
    if(tname == a[troot].name) {
		a[troot] = a[n];
		n -= 1;
		heap_adjust(a, troot, n);
		return 1;
	}
    else{
        if(delete_node(a, 2*troot, tname, n) == 1) return 1;
        return delete_node(a, 2*troot+1, tname, n);
    }
}

void heap_adjust(element a[], int troot, int size){
    double tmpkey;
    int child;
    element tmp;

    tmp = a[troot];
    tmpkey = a[troot].score;
    child = 2*troot;

    while(child <= size){
        if((child < size)&&(a[child].score < a[child+1].score)) child++;
        if(tmpkey > a[child].score) break;
        else{
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = tmp;
}
