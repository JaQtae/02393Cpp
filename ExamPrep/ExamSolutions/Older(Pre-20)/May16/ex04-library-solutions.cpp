#include <iostream>
#include "ex04-library.h"

using namespace std;

template <class C>
Monoid<C>::Monoid(C constant){
    this->constant = constant;
    m1 = nullptr;
    m2 = nullptr;
}

template <class C>
Monoid<C>::Monoid(Monoid<C> & m1, Monoid<C> & m2){    
    this->m1 = new Monoid<C>(m1);
    this->m2 = new Monoid<C>(m2);
}

template <class C>
Monoid<C>::Monoid(Monoid & m){
    if (m.m1 == nullptr){
        constant = m.constant;
        m1 = nullptr;
        m2 = nullptr;
        return;
    }
    m1 = new Monoid(* m.m1);
    m2 = new Monoid(* m.m2);
}

template <class C>
Monoid<C> Monoid<C>::operator*(Monoid<C> & m){
    Monoid<C> m1(* this,m);
    return m1;
}

template <class C>
C Monoid<C>::eval(C (*f)(C,C)){
    if (m1 == nullptr) return constant;
    else return f(m1->eval(f),m2->eval(f));
}

template <class C>
void Monoid<C>::print(void){
    if (m1 == nullptr) cout << constant ;
    else {
        m1->print();
        cout << " * " ;
        m2->print();
    }
}


template class Monoid<string>;
template class Monoid<unsigned int>;
