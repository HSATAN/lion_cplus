//
// Created by huangkaijie on 2017/10/12.
//
#include <iostream>
#include <vector>
#include <map>
#include "common.h"
using namespace std;

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
void test_map(){
    //map操作测试
    map<int,string> person;
    person.insert(pair<int,string>(2,"xionglingut"));
    person.insert(pair<int,string>(1,"huangkaijie"));
    person.insert(pair<int,string>(3,"huangkaijie"));
    person.insert(pair<int,string>(4,"huangkaijie"));
    person.insert(pair<int,string>(5,"huangkaijie"));
    person.insert(pair<int,string>(6,"huangkaijie"));
    person.insert(pair<int,string>(7,"huangkaijie"));
    cout<<person.count(1)<<endl;
    auto it_find = person.find(1);
    if(it_find!=person.end())
    {
        cout<<"元素 1 存在"<<endl;
        person.erase(it_find);
    }
    auto it3=person.find(3);
    auto it5=person.find(6);
    person.erase(it3,it5);
    for(auto item: person)
    {
        cout<<item.first<<"  : "<<item.second<<endl;
    }
    cout<<person.size()<<endl;
    int i=5/2;
    cout<<i<<endl;
}

void mergearray(int a[], int first,int mid,int last,int temp[])
{
    int i=first;
    int j=mid+1;
    int m=mid;
    int n=last;
    int k=0;
    while(i<=m && j<=n)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        } else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=m)
    {
        temp[k++]=a[i++];
    }
    while (j<=n)
    {
        temp[k++]=a[j++];
    }

    for(i=0;i<k;i++)
    {
        a[first+i]=temp[i];
    }


}

void mergesort(int a[],int first,int last,int temp[])
{
    if(first<last)
    {
        int mid=(first+last)/2;
        mergesort(a,first,mid,temp);
        mergesort(a,mid+1,last,temp);
        mergearray(a,first,mid,last,temp);
    }

}

