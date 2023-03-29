
#include "produkt.h"

string Produkt::info() const {
    return nazwa_ + " (" + to_string(cena_) + " zl, "
        + to_string(ilosc_) + " szt.)";
}