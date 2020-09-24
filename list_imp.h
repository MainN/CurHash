#ifndef LIST_IMP_H_INCLUDED
#define LIST_IMP_H_INCLUDED
#include "list_def.h"
using namespace std;
template <class Data>
List<Data>::List(int size)
{
    size_=size;
    int c=1;
    first_ = new Node<Data>();
    first_->setChain(nullptr);
    first_->setNext(nullptr);

    cur_=first_;
};
template <class Data>
List<Data>::~List()
{

};
template <class Data>
Node<Data>* List<Data>::getCur()
{
    return cur_;
};
template <class Data>
Node<Data>* List<Data>::getFirst()
{
    return first_;
};
template <class Data>
int List<Data>::getSize()
{
    return size_;
};
template <class Data>
void List<Data>::AddNewNext(int key,Data value)
{
    if (first_->getData()=="")
    {
        first_->setKey(key);
        first_->setData(value);
        return;
    }
    cur_=first_;

    while ((cur_->getNext()!=nullptr)&&(cur_->getKey()!=key))
    {
        cur_=cur_->getNext();
    }
    if (cur_->getKey()!=key)
    {
        cur_->setNext(new Node<Data>());
        tmp_=cur_;
        cur_=cur_->getNext();
        cur_->setPrev(tmp_);
        cur_->setKey(key);
        cur_->setData(value);
    }
    else
    {
        while (cur_->getChain()!=nullptr)
            cur_=cur_->getChain();
        cur_->setChain(new Node<Data>());
        cur_=cur_->getChain();
        cur_->setKey(key);
        cur_->setData(value);
    }

};
template <class Data>
void List<Data>::printTable()
{
    cur_=first_;
    while (cur_!=nullptr)
    {
        tmp_=cur_;
        cout<<cur_->getKey()<<":"<<endl;
        cout<<cur_->getData()<<" ";
        while(tmp_->getChain()!=nullptr)
            {
                tmp_=tmp_->getChain();
                cout<<tmp_->getData()<<" ";


            }
        cout<<endl;
        cur_=cur_->getNext();
    }
};
template <class Data>
Node<Data>* List<Data>::Search(int key,Data value)
{
    cur_=first_;
    while (cur_!=nullptr)
    {
        tmp_=cur_;

        if (tmp_->getKey()==key)
        {
            while((tmp_->getChain()!=nullptr)||(tmp_->getData()==value))
                {
                    if (tmp_->getData()==value)
                        {

                            return tmp_;
                        }
                    tmp_=tmp_->getChain();
                }
        }
        cur_=cur_->getNext();
    }


    return nullptr;
};
template <class Data>
void List<Data>::Delete(int key,Data value)
{
    Node<Data>* tmp2;
    tmp_=Search(key,value);
    if (tmp_==nullptr)
    {
        cout<<"Element wasn't found"<<endl;
        return;
    }
    if (tmp_->getChain()!=nullptr)
    {

        tmp2=tmp_->getChain();
        tmp_->setChain(tmp2->getChain());
        tmp_->setData(tmp2->getData());
        return;
    }
    //cout<<tmp_->getPrev()->getData()<<endl;
    if (tmp_->getNext()!=nullptr)
    {
        tmp2=tmp_->getNext();
        tmp_->setNext(tmp2->getChain());
        tmp_->setData(tmp2->getData());
        tmp_->setKey(tmp2->getKey());

        return;
    }
    tmp2=tmp_->getPrev();
    tmp2->setNext(nullptr);

};
#endif // TABLE_IMP_H_INCLUDED
