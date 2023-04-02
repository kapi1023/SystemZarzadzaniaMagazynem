#pragma once
#include <string>
using namespace std;
class Produkt {
    public:
        Produkt(const string& nazwa, float cena, int ilosc) :
            nazwa_(nazwa), cena_(cena), ilosc_(ilosc) {}

        virtual ~Produkt() {}

        virtual string info() const;

        string nazwa() const { return nazwa_; }
        float cena() const { return cena_; }
        int ilosc() const { return ilosc_; }

    protected:
        string nazwa_;
        float cena_;
        int ilosc_;
};

