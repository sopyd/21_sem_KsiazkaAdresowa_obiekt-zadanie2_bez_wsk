#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "PlikTekstowy.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
    int idOstatniegoAdresata;
    fstream plikTekstowy;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //string nazwaPlikuZAdresatami;

    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    string nazwaPlikuZAdresatami;

    PlikZAdresatami(string nazwaPlikuZAdresatami) : nazwaPlikuZAdresatami(nazwaPlikuZAdresatami){}
    bool dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

    int pobierzIdOstatniegoAdresata();

};

#endif
