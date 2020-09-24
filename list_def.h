#ifndef LIST_DEF_H_INCLUDED
#define LIST_DEF_H_INCLUDED
#include "node_imp.h"
#include<string>
using namespace std;
template <class Data>
class List
{
    public:
        List(int size);
        ~List();
        Node<Data>* getCur();
        Node<Data>* getFirst();
        int getSize();
        void AddNewNext(int key,Data value);
        void printTable();
        Node<Data>* Search(int key,Data value);
        void Delete(int key,Data value);
    private:
    Node<Data>* cur_;
    Node<Data>* tmp_;
    Node<Data>* first_;
    int size_;


};
#endif // TABLE_DEF_H_INCLUDED
