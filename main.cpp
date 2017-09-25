#include <iostream>
#include <fstream>
#include <vector>
#include <csignal>
#include <pthread.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
using namespace std;

typedef int DATATYPE;
void signalHandler(int);
pthread_mutex_t mutex1;
int money;
struct thread_data{
    int thread_id;
    char * message;
};
typedef struct BTree
{
    struct BTree * left;
    struct BTree * right;
    DATATYPE key;
    int balance;
} BT;

BT * createTree(DATATYPE data, BT *tree)
{
    BT *node = new BT;


     //node = (BT*)malloc(sizeof(struct BTree));

    node->key=data;
    node->left= nullptr;
    node->right= nullptr;
    node->balance=0;
    tree=node;
    return tree;
}
BT * init(BT *tree,DATATYPE data)
{
    BT *node = new BT;


    //node = (BT*)malloc(sizeof(struct BTree));

    node->key=-1;
    node->left= nullptr;
    node->right= nullptr;
    node->balance=0;
    tree=node;
    return tree;
}
int addNode(DATATYPE data, BT *tree)
{
    if (!tree)
    {return 0;}

    if (tree->key==-1 && tree->left== nullptr)
    {
        BT * node;
        node = new BT;
        node->key=data;
        node->right=nullptr;
        node->left=nullptr;
        node->balance=0;
        tree->left=node;
        return 0;
    }
    if (tree->key==-1)
    {
        int balance = addNode(data,tree->left);
        tree->left->balance += balance;
        return balance;
    }
     else if(tree->right== nullptr && tree->left==nullptr)
    {
        BT * node;
        node = new BT;
        node->key=data;
        node->right=nullptr;
        node->left=nullptr;
        node->balance=0;
        if(tree->key>data)
        {


            tree->left=node;
            tree->balance += 1;
            return 1;
        } else{
            tree->right=node;
            tree->balance -= 1;
            return -1;
        }

    }
    else if(tree->right== nullptr)
    {
        if(tree->key<data)
        {
            BT * node;
            node = new BT;
            node->key=data;
            node->right= nullptr;
            node->left= nullptr;
            node->balance=0;
            tree->right=node;
            tree->balance -= 1;
            return 0;
        } else{
          int balance =  addNode(data,tree->left);
            tree->balance+=balance;
            if (balance!=0)
            {
                tree->balance += 1;
                return 1;
            }
            return 0;
        }
    }
    else if(tree->left==nullptr){
        if(tree->key>=data)
        {
            BT * node;
            node = new BT;
            node->key=data;
            node->right=nullptr;
            node->left=nullptr;
            node->balance=0;
            tree->left=node;
            tree->balance += 1;

        } else
        {
           int balance = addNode(data,tree->right);
            tree->balance += balance;
            if (balance!=0)
            {
                tree->balance += -1;
                return 0;
            }
        }
    } else{
        if(tree->key>data)
        {
           int balance = addNode(data,tree->left);
            if (balance!=0)
            {
                tree->balance += 1;
                return 1;
            }

            return 0;
        } else
        {
          int balance =  addNode(data,tree->right);
            if (balance!=0)
            {
                tree->balance += -1;
                return -1;
            }
            return 0;
        }
    }

}
vector<string> split(string name, string delim)
{
    vector<string> elems;
    int pos = 0;
    int end_index = 0;
    string temp;
    if (name.empty())
        return elems;
    while (pos >= 0)
    {
        pos = (int)name.find(" ", end_index);

        if (pos < 0)
        {

            break;

        }
        temp = name.substr(end_index, pos - end_index);
        end_index = pos + 1;
        elems.push_back(temp);
    }
    if (end_index != 0 && end_index < name.length())
    {
        elems.push_back(temp);
    }
    if (end_index==0)
    {
        elems.push_back(name);
    }
    return elems;
}
void create_tree_from_file(BT * tree)
{
    ifstream in("test.txt");
    string line;
    vector<string> name;
    while(getline(in,line))
    {
        name=split(line," ");
        while(!name.empty())
        {

           int balance =  addNode(stoi(name.back()),tree);
            tree->balance += balance;
            name.pop_back();
        }
    }
    in.close();
}

void * test_thread(void* args)
{
    struct thread_data *data;
    data = (struct thread_data *)args;
    cout<<"线程id = "<<data->thread_id<<endl;
    cout<<"消息  ："<<data->message<<endl;
    while (money>0)

    {
        pthread_mutex_lock(&mutex1);
        printf("子进程进入临界区查看money\n");
        if (money==0)
        {
            money+=200;
            printf("子线程money=%d\n",money);
        }

        pthread_mutex_unlock(&mutex1);
        sleep(1);
    }

}
void print_tree(BT * tree)
{
    if(tree)
    {
        cout<<tree->key<<endl;
    }
    if(tree->left)
    {
        print_tree(tree->left);
    }
    if(tree->right)
    {
        print_tree(tree->right);
    }
}
BT * get_insert(BT * tree)
{
    if(!tree)
    {
        return tree;
    }
}
int get_depth(BT* tree)
{
    if(!tree)
    {
        return 0;
    }
    int left=get_depth(tree->left)+1;
    int right=get_depth(tree->right)+1;
    return left>right ? left:right;
}
int main() {
    BT *tree;
    tree = init(tree,-1);
    create_tree_from_file(tree);
    cout<<get_depth(tree->left)<<endl;
    print_tree(tree->left);
    return 0;
}
