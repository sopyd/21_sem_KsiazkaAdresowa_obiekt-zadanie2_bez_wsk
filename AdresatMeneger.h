#ifndef ADRESATMENEGER_H
#define ADRESATMENEGER_H

#include <vector> // jesli tu mam wektor to nie musze go deklarowac w .cpp w funkcji dodajAdresata, to co mam zadeklarowane tutaj moge wykorzystac w funkcji bez deklaracji
                    // obiektowka na to pozwala (w podejsciu strukturalnym musia³em miec argument w funkcji, tu jest inaczej)

#include "Adresat.h"
#include "PlikZAdresatami.h"

#include "AdresatMeneger.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMeneger.h"

class AdresatMeneger
{
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMeneger(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {}; // na koncu cialo konstruktora {}

    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};

#endif
