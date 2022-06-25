// 22100661 정다훈
/* binary search tree */
#include <iostream>
using namespace std;

class bst_node{
public:
    string name;
    string s_id;
    double score;
    bst_node* left, *right;
    bst_node();
    bst_node(string s1, string s2, double n);
    void set_data(string s1, string s2, double n);
};

class bst_tree{
    bst_node* root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
};
void inorder_traverse(bst_node *p);

int main()
{
    bst_node temp;
    bst_tree t1;       
    temp.set_data("21900013", "Kim", 6.5);      
    t1.insert_node(temp);     
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);
            
    cout << "\n Node List : inorder sequence \n\n";

    t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score        : " << temp.score << endl;         
    return 0;
}

bst_node::bst_node(){

}

bst_node::bst_node(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}

void bst_node::set_data(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}

bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}

void bst_tree::insert_node(bst_node t){
    bst_node* p;
    bst_node* tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(root == NULL){
        root = tmp;
        return ;
    }

    p = root;
    while(1){
        if(p->s_id == t.s_id){
            cout << "Insertion Failed : the Key" << t.s_id << "already exists." << endl;
            return;
        }

        if(p->s_id < t.s_id){
            if(p->right == NULL){
                p->right = tmp;
                return ;
            }
            else p = p->right;
        }
        else{
            if(p->left == NULL){
                p->left = tmp;
                return ;
            }
            else p = p->left;
        }
    }
}

void bst_tree::show_inorder(){
    bst_node *t;
    t = root;
    if(t == NULL) return;

    inorder_traverse(t);
}

void inorder_traverse(bst_node *p){
    if(p == NULL) return ;

    inorder_traverse(p->left);
    cout << " " << p->s_id << " : " << p->name << " : " << p->score << endl;
    inorder_traverse(p->right);
}

bst_node bst_tree::search(string tid){
    bst_node* p;
    p = root;
    if(root == NULL){
        // 해당 노드 없음 처리
        bst_node tmp;
        tmp.set_data("00000000", "None", -1);
        cout << "The key" << tid << " does not exist.\n";
        return tmp;
    }

    while(1){
        if(p->s_id == tid) return *p;

        if(p->s_id < tid){
            if(p->right == NULL){
                // 해당 노드 없음 처리
                bst_node tmp2;
                tmp2.set_data("00000000", "None", -1);
                cout << "The key" << tid << " does not exist.\n";
                return tmp2;
            }
            else p = p->right;
        }
        else{
            if(p->left == NULL){
                //해당 노드 없음 처리
                bst_node tmp3;
                tmp3.set_data("00000000", "None", -1);
                cout << "The key" << tid << " does not exist.\n";
                return tmp3;
            }
            else p = p->left;
        }
    }
}
