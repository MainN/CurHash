#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <string>
#include "hash_table_imp.h"
#include <vector>
#include <complex>
#include <iterator>
using namespace std;

int main()
{
    int menu;
    string name;
    char c;
    char a;
    int size,mode,number;
    c='z';
    a= 'a';
    vector<hash_table<string>>::iterator it;
    vector<hash_table<string>> tables;
    while (true)
    {
        cout<<"1.Create new table"<<endl;
        cout<<"2.Call table with her number"<<endl;
        cout<<"3.Print list tables"<<endl;
        cout<<"4.Exit"<<endl;
        cin >> menu;
        if (menu==1)
        {
            cout<<"Enter table name"<<endl;
            cin>>name;
            cout<<"Enter number of hash function for the table"<<endl;
            cout<<"1: Cast string to integer with bytes multiplication"<<endl;
            cout<<"2: Cast string to integer with char summation"<<endl;
            cout<<"3: Cast string to integer with string translate into polynome"<<endl;
            cin>>mode;
            if ((mode<1)||(mode>3))
             {
                cout<<"Wrong number"<<endl;
                continue;
             }

            cout<<"Enter size of the table"<<endl;
            cin>>size;
            if (size<1)
             {
                cout<<"Wrong number"<<endl;
                continue;
             }
            tables.push_back(hash_table<string>(size,mode,name));
        }
        if (menu==2)
        {
            cout<<"Enter number"<<endl;
            cin >>number;

            if (number>tables.size())
            {
                cout<<"Wrong number"<<endl;
                continue;
            }
            tables[number-1].Interface();
            //system("cls");
        }
        if (menu==3)
        {
            for (it=tables.begin();it!=tables.end();++it)
            {
                cout<<(it)->getName()<<" "<<(it)->getMode()<<" "<<(it)->getSize()<<endl;
            }
        }
        if (menu==4)
            break;
    }
    return 0;
}
