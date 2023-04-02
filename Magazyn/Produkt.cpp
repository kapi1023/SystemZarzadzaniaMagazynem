
#include "produkt.h"
#include <iomanip>
#include <sstream>

string Produkt::info() const {
    /*
    ostringstream ss;
    ss << fixed << setprecision(2) << cena_;
    return nazwa_ + " (" + ss.str() + " zl, "
        + to_string(ilosc_) + " szt.)";
        */
    return nazwa_ + " (" + to_string(cena_) + " zl, "
        + to_string(ilosc_) + " szt.)";
}