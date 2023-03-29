
#include <iostream>
#include <string>
#include "Produkt.h"
#include "Magazyn.h"
#include "Telewizor.h"
#include "But.h"
using namespace std;
void dodaj_produkt(Magazyn& magazyn) {
    cout << "Dodawanie produktu\n";
    cout << "Wybierz typ produktu:\n";
    cout << "1. Telewizor\n";
    cout << "2. But\n";
    int wybor;
    cin >> wybor;
    if (wybor == 1) {
        string nazwa, rozdzielczosc;
        double cena;
        int ilosc, przekatna;
        cout << "Podaj nazwe: ";
        cin >> nazwa;
        cout << "Podaj cene: ";
        cin >> cena;
        cout << "Podaj ilosc: ";
        cin >> ilosc;
        cout << "Podaj przekatna w calach: ";
        cin >> przekatna;
        Produkt* telewizor = new Telewizor(nazwa, cena, ilosc, przekatna);
        magazyn.dodaj_produkt(telewizor);
    }
    else if (wybor == 2) {
        string nazwa, kolor;
        double cena;
        int ilosc, rozmiar;
        cout << "Podaj nazwe: ";
        cin >> nazwa;
        cout << "Podaj cene: ";
        cin >> cena;
        cout << "Podaj ilosc: ";
        cin >> ilosc;
        cout << "Podaj rozmiar: ";
        cin >> rozmiar;
        Produkt* buty = new But(nazwa, cena, ilosc, rozmiar);
        magazyn.dodaj_produkt(buty);
    }
}

void wyswietl_stan(Magazyn& magazyn) {
    cout << "Stan magazynu:\n";
    magazyn.wyswietl_produkty();
}

void usun_produkt(Magazyn& magazyn) {
    cout << "Usuwanie produktu\n";
    cout << "Podaj nazwe produktu do usuniecia: ";
    string nazwa;
    cin >> nazwa;
    magazyn.usun_produkt(nazwa);
}

void wyszukaj_produkt(Magazyn& magazyn) {
    cout << "Wyszukiwanie produktu\n";
    cout << "Podaj nazwe produktu \n";
    string nazwa;
    cin >> nazwa;
    Produkt* produkt = magazyn.wyszukaj_produkt(nazwa);
    if (produkt) {
        cout << produkt->info() << endl;
    }
    else {
        cout << "Nie znaleziono produktu o podanej nazwie" << endl;
    }
}
void addExampleData(Magazyn& magazyn) {
    Produkt* buty1 = new But("Jordan1", 432.23f, 12, 45);
    magazyn.dodaj_produkt(buty1);
    Produkt* buty2 = new But("Jordan3", 132.23f, 8, 45);
    magazyn.dodaj_produkt(buty2);
    Produkt* buty3 = new But("Jordan4", 232.23f, 2, 48);
    magazyn.dodaj_produkt(buty3);
    Produkt* telewizory1 = new Telewizor("Samsung1", 432.23f, 12, 35);
    magazyn.dodaj_produkt(telewizory1);
    Produkt* telewizory2 = new Telewizor("Samsung2", 1432.23f, 52, 35);
    magazyn.dodaj_produkt(telewizory2);
    Produkt* telewizory3 = new Telewizor("Samsung3", 2432.23f, 22, 35);
    magazyn.dodaj_produkt(telewizory3);
}


int main() {
    Magazyn magazyn;
    int wybor = 0;
    addExampleData(magazyn);
    while (wybor != 5) {
        cout << "----- MENU -----" << endl;
        cout << "Wybierz opcje:" << endl;
        cout << "1. Dodaj produkt" << endl;
        cout << "2. Usun produkt" << endl;
        cout << "3. Wyswietl liste produktow" << endl;
        cout << "4. Wyszukaj produkt" << endl;
        cout << "5. Wyjdz z programu" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;
        cout <<"----------------" << endl;
        switch (wybor) {
        case 1:
            dodaj_produkt(magazyn);
            break;
        case 2:
            usun_produkt(magazyn);
            break;
        case 3:
            wyswietl_stan(magazyn);
            break;
        case 4:
            wyszukaj_produkt(magazyn);
            break;
        case 5:
            cout << "Koniec programu." << endl;
            break;
        default:
            cout << "Nieznana opcja. Sprobuj ponownie." << endl;
            break;
        }
    }

    return 0;
}

