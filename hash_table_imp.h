#ifndef HASH_TABLE_IMP_H_INCLUDED
#define HASH_TABLE_IMP_H_INCLUDED
#include <string>
#include "list_imp.h"
#include "hash_table_def.h"
#include "vector"
#include "bitset"
#include "limits"
#include <cstdint>
using namespace std;
template <class Data>
hash_table<Data>::hash_table(int size, int param,string name)
{
    list_ = new List<Data>(size);
    param_=param;
    name_=name;
};
template <class Data>
hash_table<Data>::~hash_table()
{
    delete list_;
};
template <class Data>
void hash_table<Data>::Add(Data str)
{
    int p;
    int res;
    res = hashFunc(param_,str);
    res = abs(res%(list_->getSize()));
    list_->AddNewNext(res,str);
};
template <class Data>
void hash_table<Data>::Search(Data value)
{
    int res;
    res=hashFunc(param_,value);
    res = abs(res%(list_->getSize()));
    if (list_->Search(res,value)==nullptr)
    {
        cout<<"Not founded"<<endl;
    }
    else
    {
        cout<<"Founded"<<endl;
    }
};
template <class Data>
void hash_table<Data>::Delete(Data value)
{
    int res;
    res=hashFunc(param_,value);
    res = abs(res%(list_->getSize()));
    list_->Delete(res,value);
};
template <class Data>
void hash_table<Data>::getStat()
{
    list_->printTable();
};
template <class Data>
int hash_table<Data>::hashFunc(int param,Data str)
{
    if (param==1)
        return integerCastBytes(str);
    if (param==2)
        return integerCastSymbols(str);
    if (param==3)
        return integerFromPolynomial(str);
};
template <class Data>
int hash_table<Data>::integerCastBytes(Data str)
{
    Data tmp;
    for (int x=0;x<str.length();x++)
    {
        tmp+=bitset<5>(str[x]).to_string();

    }
    bitset<64> tmp2(tmp);
    return tmp2.to_ullong();
};
template <class Data>
int hash_table<Data>::integerCastSymbols(Data str)
{
    int tmp=0;
    for (int x=0;x<str.length();x++)
    {
        tmp+=bitset<5>(str[x]).to_ullong();

    }
    return tmp;
};
template <class Data>
int hash_table<Data>::integerFromPolynomial(Data str)
{
    vector<string> v;
    int numberOfParts=3;
    int lenghOfParts;
    int z =33;
    unsigned long long h;
    int counter=str.length();
    unsigned long long mass[str.length()];
    string tmp2;
    for (int x=0;x<str.length();x++)
    {
        mass[x]=bitset<5>(str[x]).to_ullong();

    }
    h=mass[0];

    for (int x=1;x<str.length();x++)
    {
       h=(z*h)+mass[x];

    }

    return h;

};
template <class Data>
void hash_table<Data>::Interface()
{
    //system("cls");
    int choise;
    string value;
    while(true)
    {

        cout<<"1.Add new string"<<endl;
        cout<<"2.Search string"<<endl;
        cout<<"3.Delete string"<<endl;
        cout<<"4.Print stat"<<endl;
        cout<<"5.Exit the table interface"<<endl;
        cout<<"6.Read from file"<<endl;
        cin>>choise;
        if (choise==1)
        {
            cout<<"Enter what to add"<<endl;
            cin>>value;
            Add(value);
        }
        if (choise==2)
        {
            cout<<"Enter what to search"<<endl;
            cin>>value;
            Search(value);
        }
        if (choise==3)
        {
            cout<<"Enter what to delete"<<endl;
            cin>>value;
            Delete(value);
        }
        if (choise==4)
        {
            getStat();
        }
        if (choise==5)
        {
            break;
        }
    }
};
template <class Data>
string hash_table<Data>::getName()
{
    return name_;
};
template <class Data>
int hash_table<Data>::getSize()
{
    return list_->getSize();
};
template <class Data>
int hash_table<Data>::getMode()
{
    return param_;
};
#endif // HASH_TABLE_IMP_H_INCLUDED
