#ifndef NODE_DEF_H_INCLUDED
#define NODE_DEF_H_INCLUDED
using namespace std;
template <class Data>
class Node
{
    public:
        Node();
        ~Node();
        Node<Data>* getPrev();
        Node<Data>* getNext();
        Node<Data>* getChain();
        void setNext(Node<Data>* n);
        void setPrev(Node<Data>* n);
        void setChain(Node<Data>* n);
        void setData(Data data);
        Data getData();
        void setKey(int key);
        int getKey();
    private:
    Node<Data>* next_;
    Node<Data>* prev_;
    Node<Data>* chain_;
    Data data_;
    int pos_;
    int key_;

};


#endif // NODE_DEF_H_INCLUDED
