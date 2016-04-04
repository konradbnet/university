#ifndef WIELOMIAN_H
#define WIELOMIAN_H

#include <vector>
#include <iostream>

using namespace std;

class Wielomian {
    int n;
    vector<double> a;

    void set(int index, double val);

    public:
    struct proxy {
        Wielomian& parent;
        int index;
        proxy& operator=(double val);
        operator double();
        proxy(Wielomian& p, size_t index);
    };

    Wielomian(int st=0, double wsp=1.0);
    Wielomian(int st, double wsp[]);
    Wielomian(initializer_list<double> wsp);
    //Wielomian(const Wielomian& w);
    //Wielomian(Wielomian&& w);
    int stopien() {
        return this->n;
    } 
    proxy operator[](int i);
    friend ostream& operator<<(ostream& wy, const Wielomian& w);
    friend istream& operator>>(istream& we, Wielomian& w);
};

#endif