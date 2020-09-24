#ifndef NODE_IMP_H_INCLUDED
#define NODE_IMP_H_INCLUDED
#include "node_def.h"
using namespace std;
template <class Data>
Node<Data>::Node()
{
    next_=nullptr;
    chain_=nullptr;
    prev_=nullptr;
};
template <class Data>
Node<Data>::~Node()
{

};
template <class Data>
Node<Data>* Node<Data>::getNext()
{
    return next_;
};
template <class Data>
Node<Data>* Node<Data>::getPrev()
{
    return prev_;
};
template <class Data>
Data Node<Data>::getData()
{
    return data_;
};
template <class Data>
Node<Data>* Node<Data>::getChain()
{
    return chain_;
};
template <class Data>
void Node<Data>::setNext(Node<Data>* n)
{
    next_=n;
};
template <class Data>
void Node<Data>::setPrev(Node<Data>* n)
{
    prev_=n;
};
template <class Data>
void Node<Data>::setData(Data data)
{
    data_=data;
};
template <class Data>
void Node<Data>::setChain(Node<Data>* n)
{
    chain_=n;
};
template <class Data>
void Node<Data>::setKey(int key)
{
    key_=key;
};
template <class Data>
int Node<Data>::getKey()
{
    return key_;
};
#endif // NODE_IMP_H_INCLUDED
