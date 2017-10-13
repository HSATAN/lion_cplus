#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "tree.h"
#include <iomanip>
#include "common.h"
#include <fstream>
#include <ctime>
using namespace std;


void new_mergearray(int a[],int first,int mid, int last, int temp[] )
{
    int k=0;
    int i=first;
    int j=mid+1;
    int m=mid;
    int n=last;
    while (i<=mid && j<=last)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }

    }
    while (i<=m)
    {
        temp[k++]=a[i++];
    }
    while (j<=last)
    {
        temp[k++]=a[j++];
    }
    for(i=0;i<k;i++)
    {
        a[first+i]=temp[i];
    }
}
void new_mergesort(int a[], int first,int last,int temp[])
{
    if(first<last)
    {
        int mid=(first+last)/2;
        new_mergesort(a,first,mid,temp);
        new_mergesort(a,mid+1,last,temp);
        new_mergearray(a,first,mid,last,temp);
    }
}
int main() {
    BT *tree;
//    tree = init(tree,-1);
//    create_tree_from_file(tree);
//    printf("%d\n",get_depth(tree->left));
//    print_tree(tree->left);
//    string a;
//    cout<<typeid(a).name()<<endl;
//    auto i="huangkaijie";
//    cout<<i<<endl;
//    cout<<typeid(i).name()<<endl;
//    string biaodashi="ab+cde+**";
//    BT * BDS=scanBiaoDaShi(biaodashi);
//    BinarySearchTree binarySearchTree;
//    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
//    string string1="ecdbfgh";
//    for (char c:string1)
//    {
//        binarySearchTree.insert(binarySearchTree.root,c);
//    }
//    print_tree_first_format(binarySearchTree.root,0);
//    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
//    test_map();
    int a[]={0,5,4,7,3,9,8,1,2,6,9,10,13};
//    for(int i=(sizeof(a)/ sizeof(int)-1)/2;i>0;i--)
//    {
//        heap_adjust(a,i,sizeof(a)/ sizeof(int)-1);
//    }
//    heap_sort(a,sizeof(a)/ sizeof(int)-1);
//
    int *p=new int[12];
    //mergesort(a,0,12,p);
    new_mergesort(a,0,12,p);
    for (int i=0;i<13;i++)
    {
        cout<<a[i]<<endl;
    }
    ifstream in;
    in.open("/Users/huangkaijie/log/log20171010");
    int i=0;
    string s;
    time_t start = time(NULL);

    while (getline(in,s))
    {
        i++;
    }
    cout<<i<<endl;
    time_t end=time(NULL);
    cout<<end-start<<endl;
    return 0;
}
