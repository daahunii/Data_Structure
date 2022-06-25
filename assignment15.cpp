//22100661 정다훈
/* sorting functions */
// compile command : g++ hw15_2210661_jeongdahun.cpp -std=c++11
#include <iostream>
#define S_SIZE 50
using namespace std;

class s_record{
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string n1, string n2, double s);
};

void show_thelist(s_record a[], int n);
void insertion_sort(s_record a[], int n);
void bubble_sort(s_record a[], int n);
void selection_sort(s_record a[], int n);
void quick_sort(s_record a[], int left, int right);
void heap_sort(s_record a[], int n);
void adjust(s_record a[], int troot, int size);
void merge_sort(s_record a[], int n);
void merge_pass(s_record a[], s_record b[], int n, int s);
void merge(s_record a[], s_record b[], int n1, int n2, int, int n3, int n4);

int main()
{
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8}, {"21900333", "Park", 9.2},
                            {"21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4}, {"21700248", "Cho ", 6.3},
                            {"21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9}, {"21800369", "Kang", 6.3},
                            {"21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1}, {"21700678", "Seo ", 7.9} };
    int n = 12;

    // insertion_sort(s_list, n);
    // bubble_sort(s_list, n);
    // selection_sort(s_list, n);

    // quick_sort(s_list, 0, n-1);
    // merge_sort(s_list, n);
    heap_sort(s_list, n); 

    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);

    return 0;
}

s_record::s_record(){

}

s_record::s_record(string n1, string n2, double s){
    s_id = n1;
    name = n2;
    score = s;
}

void show_thelist(s_record a[], int n){
    for(int i=0; i<n; i++){
        if(a[i].name == "") continue;
        else{
            cout << a[i].s_id << " : ";
            cout << a[i].name << " : ";
            cout << a[i].score << endl;
        }
    }
}

void insertion_sort(s_record a[], int n){
    for(int i=1; i<n; i++){
        s_record temp = a[i];
        int j = i-1;
        while((j >= 0)&&(a[j].s_id > temp.s_id)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void bubble_sort(s_record a[], int n){
    s_record temp;

    for(int i=n-1; i>=1; i--){
        for(int j=0; j<i; j++){
            if(a[j].s_id > a[j+1].s_id){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selection_sort(s_record a[], int n){
    s_record temp;
    for(int i=0; i<n; i++){
        int min_i = i; // 대상 인덱스 저장
        for(int j=i+1; j<n; j++)
            if(a[j].s_id < a[min_i].s_id) min_i = j; //대상 범위에서 가장 작은 값의 인덱스 저장
        
        temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
    }
}

void quick_sort(s_record a[], int left, int right){
    s_record pivot, temp;
    int i, j;

    if(left >= right) return;
    i = left;
    j = right+1;
    pivot = a[left];
    do{
        do{
            i++;
        }while((i <= right)&&(a[i].s_id < pivot.s_id));
        do{
            j--;
        }while(a[j].s_id > pivot.s_id);
        if(i < j) swap(a[i], a[j]);
    }while(i < j);
    swap(a[left], a[j]);
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right);
}

void heap_sort(s_record a[], int n){
    s_record b[S_SIZE], temp;

    for(int i=0; i<n; i++) b[i+1] = a[i];

    for(int i=n/2; i>0; i--) adjust(b, i, n);
    for(int i=n-1; i>0; i--){
        temp = b[1];
        b[1] = b[i+1];
        b[i+1] = temp;
        adjust(b, 1, i);
    }
    for(int i=0; i<n; i++) a[i] = b[i+1];
}

void adjust(s_record a[], int troot, int size){
    string tmpkey;
    int child;
    s_record tmp;

    tmp = a[troot];
    tmpkey = a[troot].s_id;
    child = 2*troot;

    while(child <= size){
        if((child < size)&&(a[child].s_id < a[child+1].s_id)) child++;
        if(tmpkey > a[child].s_id) break;
        else{
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = tmp;
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4){
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while((i <= n2)&&(j <= n4)){
        if(a[i].s_id <= a[j].s_id) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    if(i > n2)
        for(t = j; t <= n4; t++) b[t] = a[t];
    else
        for(t = i; t <= n2; t++) b[k+t-i] = a[t];
}

void merge_sort(s_record a[], int n){
    int s = 1;
    s_record b[S_SIZE];

    while(s < n){
        merge_pass(a, b, n-1, s);
        s *= 2;
        merge_pass(b, a, n-1, s);
        s *= 2;
    }
}

void merge_pass(s_record a[], s_record b[], int n, int s){
    int i,j;
    for(i = 0; i < (n-2*s+1); i += 2*s) merge(a, b, i, i+s-1, i+s, i+2*s-1);

    if(i+s <= n) merge(a, b, i, i+s-1, i+s, n);
    else for(j = i; j <= n; j++) b[j] = a[j];
}
