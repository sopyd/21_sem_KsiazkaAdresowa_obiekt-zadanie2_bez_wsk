#include "Adresat.h"
#include "PlikZAdresatami.h"

#include "AdresatMeneger.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMeneger.h"

void AdresatMeneger::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

}

Adresat AdresatMeneger::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata());
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
    //adresat.wczytajIdUzytkownika() = idZalogowanegoUzytkownika;

    cout << "Podaj imie: ";
    adresat.wczytajImie() = MetodyPomocnicze::wczytajLinie();
    adresat.wczytajImie() = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.wczytajImie());

    cout << "Podaj nazwisko: ";
    adresat.wczytajNazwisko() = MetodyPomocnicze::wczytajLinie();
    adresat.wczytajNazwisko() = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.wczytajNazwisko());

    cout << "Podaj numer telefonu: ";
    adresat.wczytajNumerTelefonu() = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    adresat.wczytajEmail() = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adresat.wczytajAdres() = MetodyPomocnicze::wczytajLinie();

    return adresat;
}

void AdresatMeneger::wyswietlDaneAdresata()
{
    Adresat adresat;

    cout << endl << "Id:         " << adresat.wczytajId() << endl;
    cout << "Imie:               " << adresat.wczytajImie() << endl;
    cout << "Nazwisko:           " << adresat.wczytajNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.wczytajNumerTelefonu() << endl;
    cout << "Email:              " << adresat.wczytajEmail() << endl;
    cout << "Adres:              " << adresat.wczytajAdres() << endl;
}

void AdresatMeneger::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            //wyswietlDaneAdresata(*itr);
            wyswietlDaneAdresata();
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

int AdresatMeneger::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void AdresatMeneger::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    Adresat adresat;

    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(plikZAdresatami.nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == plikZAdresatami.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = plikZAdresatami.pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = AdresatMeneger::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

/*
void AdresatMeneger::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
*/
