// 22100661 정다훈
/* binary search tree Menu version */
#include <iostream>
using namespace std;

class bst_node{
public:
    string name;
    string birth;
    int p_num;
    bst_node* left, *right;
    bst_node();
    bst_node(string s1, string b, int n);
    void set_data(string s1, string b, int n);
};

class bst_tree{
    bst_node* root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string bd);
};
void inorder_traverse(bst_node *p);

int main()
{
    bst_node temp;
    bst_tree e;
    string name;
    string birthday;
    int phone_num;

    int menu;
    while(true){
        cout << "\n*** Select Menu ***" << endl;
        cout << "1. Insert Element"<< endl;
        cout << "2. Search Element"<< endl;
        cout << "3. Show All List" << endl;
        cout << "4. exit" << endl;
        printf("\n");
        cout << "Select Number : "; 
        cin >> menu;
        printf("\n");

        if(menu == 4) break;
        if(menu == 1){
            cout << "Enter your name : ";
            cin >> name;
            cout << "Enter your birthday : ";
            cin >> birthday;
            cout << "Enter your phone number : ";
            cin >> phone_num;
            printf("\n");

            temp.set_data(name, birthday, phone_num);
            e.insert_node(temp);
        }
        else if(menu == 2){
            string search_num;
            cout << "Enter your birthday : ";
            cin >> search_num;

            temp = e.search(search_num);
            cout << "\n--- " << search_num << "'s record ---" << endl;
            cout << "Name         : "<< temp.name << endl;
            cout << "Birthday     : "<< temp.birth << endl;
            cout << "Phone Number : " << temp.p_num << endl;
            printf("\n");
        }
        else if(menu == 3) e.show_inorder();
    }
    return 0;
}

bst_node::bst_node(){

}

bst_node::bst_node(string s1, string b, int n){
    name = s1;
    birth = b;
    p_num = n;
}

void bst_node::set_data(string s1, string b, int n){
    name = s1;
    birth = b;
    p_num = n;
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
        if(p->birth == t.birth){
            cout << "Insertion Failed : the Key" << t.birth << "already exists." << endl;
            return;
        }

        if(p->birth < t.birth){
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
    cout << " " << p->birth << " : " << p->name << " : " << p->p_num << endl;
    inorder_traverse(p->right);
}

bst_node bst_tree::search(string bd){
    bst_node* p;
    p = root;
    if(root == NULL){
        // 해당 노드 없음 처리
        bst_node tmp;
        tmp.set_data("None", 0, -1);
        cout << "The key" << bd << " does not exist.\n";
        return tmp;
    }

    while(1){
        if(p->birth == bd) return *p;

        if(p->birth < bd){
            if(p->right == NULL){
                // 해당 노드 없음 처리
                bst_node tmp2;
                tmp2.set_data("None", 0, -1);
                cout << "The key" << bd << " does not exist.\n";
                return tmp2;
            }
            else p = p->right;
        }
        else{
            if(p->left == NULL){
                //해당 노드 없음 처리
                bst_node tmp3;
                tmp3.set_data("None", 0, -1);
                cout << "The key" << bd << " does not exist.\n";
                return tmp3;
            }
            else p = p->left;
        }
    }
}
