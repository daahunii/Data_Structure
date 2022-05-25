//22100661 jeongdahun
/* linked list */. 
#include <iostream>
using namespace std;

class node{
public:
    string name;
    double score;
    node *link;
    void set_data(string n, double s);
};

class my_list{
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

int main(){
    my_list a;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << endl;  // 1단계 점검 (완료)

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << endl;  //2단계 점검 (완료)

    tmp = a.delete_from_head();
    cout  << tmp.name << " is deleted.\n";   // 3단계 점검 (완료)

    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);              
    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);           // 2개의 원소 추가
    cout << a.num_nodes()<< " : " << a.score_sum() << endl;
    cout << "Park\'s score : " << a.get_score("Park")<< endl;  // 4단계 점검 (완료)

    if ( a.remove_a_node("kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5단계 점검
    cout << a.num_nodes()<< " : " << a.score_sum() << endl;  // 최종 점검 (완료)
    return 0;
}

void node::set_data(string n, double s){
    name = n;
    score = s;
}

my_list::my_list(){
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = head;
    head = p;
    if(tail == NULL) tail = p; // 이전 상태가 empty이면 tail도 첫 노드로 설정
}
void my_list::add_to_tail(node t){
    node* p;
    p = new node;
    *p = t;
    p->link = NULL;
    if(tail != NULL) tail->link = p; // 이전 상태가 empty가 아니라면
    else head = p; // 이전 상태가 empty라면 head도 변경
    tail = p;
}
node my_list::delete_from_head(){
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL) tail = NULL;
    return temp;
}
int my_list::num_nodes(){
    node *t;
    int count = 0;
    for(t = head; t != NULL; t = t->link) count++;
    return count;
}
bool my_list::list_empty(){
    if(head == NULL) return true;
    else return false;
}
double my_list::score_sum(){
    node *t;
    double sum = 0;
    for(t = head; t != NULL; t = t->link) sum += t->score;
    return sum;
}
double my_list::get_score(string t_name){
    double s;
    node *t;
    for(t = head; t != NULL; t = t->link){
        if(t->name == t_name){
            s = t->score;
            break;
        }
    }
    return s;
}
int my_list::remove_a_node(string t_name){
    node *target, *prev; // name이 t_name인 노드, 타겟노드의 이전 노드
    prev = NULL;
    target = head;
    while((target!=NULL) && (target->name!=t_name)){
        prev = target;
        target = target->link;
        break;
    }
    if(target == NULL) return 0;

    if(prev) prev->link = target->link; // prev가 첫노드가 아니라면(중간노드라면)
    else head = target->link; // prev가 첫노드라면(이전 노드가 없다면) 다음 노드로 건너가라!

    if(head == NULL) tail = NULL;
    if(tail == NULL) tail = prev;

    delete target;
    return 1;
}
