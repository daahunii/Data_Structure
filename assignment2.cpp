//22100661 jeongdahun
/* class test(weight calc program) */
#include <iostream>
using namespace std;
class weight{
    int kg, g;
    public:
        void set_weight(int w1, int w2);
        int get_weight();
};
weight add_weight(weight n1, weight n2);
bool less_than(weight n1, weight n2);

int main()
{
    weight w1, w2, w3;  // weight라는 class object 3개 생성
    w1.set_weight(3, 400);  // w1을 3kg 400 g으로
    w2.set_weight(2, 700);  // w2을 2kg 700 g으로
    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 -> w3는 6kg 100g
    cout << w3.get_weight() << "grams\n"; // w3의 값 ‘6100 grams’ 출력
    if(less_than(w1, w2)) // w1이 w2보다 작은 값인가 판단
        cout << "yes.\n";
    else cout << "no. \n";   // 작지 않으므로 ‘no’ 출력
}

void weight::set_weight(int n1, int n2){
    kg = n1;
    g = n2;
}

int weight::get_weight(){
    return(kg*1000 + g);
}

weight add_weight(weight n1, weight n2){
    weight result;
    int n3 = n1.get_weight() + n2.get_weight();
    result.set_weight(n3/1000, n3%1000);
    return result;
}

bool less_than(weight n1, weight n2){
    if(n1.get_weight() < n2.get_weight()) return true;
    else return false;
}
