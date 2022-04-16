// 22100661 jeongdahun
/* sorting function */
#include <iostream>
using namespace std;
void my_sort(int l[], int len);
int main()
{
    int list[10] = {23,11,15,8,17,33,7,14,19,21};
    my_sort(list, 10);   // 배열 list의 원소 10개를 sort하는 함수
    for(int i=0; i<10; i++) cout << list[i] << "\n";
    return 0;
}

void my_sort(int l[], int len){
    int temp;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(l[i] > l[j]){
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
}
