#ifndef HASH_TABLE_DEF_H_INCLUDED
#define HASH_TABLE_DEF_H_INCLUDED
#include "list_imp.h"
#include "node_imp.h"
#include "string"
using namespace std;
template <class Data>
class hash_table
{
    public:
        hash_table(int size, int param,string name);
        ~hash_table();
        void Add(Data str);
        void Search(Data value);
        void Delete(Data value);
        void getStat();
        string getName();
        int getSize();
        int getMode();
        void Interface();
    private:
        List<Data>* list_;
        int hashFunc(int param,Data str);
        int integerCastBytes(Data str);
        int integerCastSymbols(Data str);
        int integerFromPolynomial(Data str);
        int param_;
        string name_;

};

#endif // HASH_TABLE_DEF_H_INCLUDED
