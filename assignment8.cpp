//22100661 jeongdahun
/* Finding max number in array (recursive version)*/
#include <iostream>
using namespace std;

int find_max(int arr[], int n);
int max(int x, int y);
int main(){
    int a[10] = { 24, 12, 33, 27, 41, 15, 84, 52, 16, 72 };
    int m;
    m = find_max(a, 10);
    cout << m;
    return 0;
}

int find_max(int arr[], int n){
    if(n == 1) return arr[0];
    else return max(arr[n-1], find_max(arr, n-1));
}
int max(int x, int y){
    if(x > y) return x;
    else return y;
}% 
