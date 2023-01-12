#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"

class PlikTekstowy
{
    const string nazwaPliku;

public:
    fstream plikTekstowy;
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif
