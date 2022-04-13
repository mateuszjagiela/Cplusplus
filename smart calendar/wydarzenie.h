#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <ctime> //
#include <windows.h> //
#include <winbase.h> //
#include <conio.h>
#include <algorithm>

using namespace std;

// SPIS TRESCI

class Wydarzenie;
extern vector <Wydarzenie> event;


class Wydarzenie
{
    friend void tworzenie_obiektow_z_pliku(), usuwanie_obiektow();
private:

    string nazwa;
    string lokalizacja;
    int godzina, minuta;
    int dzien, miesiac, rok;
    int wazne;//skala od 1 do 3 jak wazne jest wydarzenie
    int id_obiektu;//numer identyfikacyjny

public:

    static int id;
    Wydarzenie(string, string, int, int, int, int, int, int);
    Wydarzenie();
    ~Wydarzenie();
    void dodaj_wydarzenie(); //user wprowadza dane
    void wyswietl_wydarzenie();//wyswietla dane o 1 obiekcie
    void zapisz_wydarzenie();//zapisuje ten obiekt w pliku

    string get_nazwa()
    {
        return nazwa;
    }
    void set_nazwa(string u)
    {
        nazwa=u;
    }
    string get_lokalizacja()
    {
        return lokalizacja;
    }
    void set_lokalizacja(string u)
    {
        lokalizacja=u;
    }
    int get_godzina()
    {
        return godzina;
    }
    void set_godzina(int u)
    {
        godzina=u;
    }
    int get_minuta()
    {
        return minuta;
    }
    void set_minuta(int u)
    {
        minuta=u;
    }
    int get_dzien()
    {
        return dzien;
    }
    void set_dzien(int u)
    {
        dzien=u;
    }
    int get_miesiac()
    {
        return miesiac;
    }
    void set_miesiac(int u)
    {
        miesiac=u;
    }
    int get_rok()
    {
        return rok;
    }
    void set_rok(int u)
    {
        rok=u;
    }
    int get_wazne()
    {
        return wazne;
    }
    void set_wazne(int u)
    {
        wazne=u;
    }
    int get_id()
    {
        return id_obiektu;
    }
    void set_id(int u)
    {
        id_obiektu=u;
    }


};
void tworzenie_obiektow_z_pliku();//przy starcie programu tworzy obiekty na podstawie zapisu w pliku
void wyswietlanie_wszystkich_obiektow();//wyswietla wszystkie wydarzenia w programie
int id_aktualnie();// sprawdza ilosc zapisanych wydarzen w pliku
void usuwanie_obiektow(int p); // usuwa podany z tablicy i pliku
void modyfikacja_obiektow(int p); // zapisuje zmiany w obiekcie
void modyfikacja_obiektow2(); // zapisuje zmiany w pliku
int opcje_przy_wyswietlaniu(); //opcja wstecz modyfikacji i usuwania
void wyswietlanie_dzisiejszych_wydarzen();
void wyswietlanie_wydarzen_w_najblizszym_czasie(int plus_dni);//MAX 4 tyg bo sie luty wywala

void wyszukiwanie_wydarzen_nazwa();
void wyszukiwanie_wydarzen_data();
void wyswietlanie_waznych_wydarzen();// 3 mozliwosci jak wazne wydarzenia ma wyswietlic
void wyswietlanie_chronologiczne(); //wszystkie wydarzenia posortowane: rok, miesiac, dzien
void wyswietlanie_aktualnych_wydarzen();// od dnia dzisiejszego dalej
void wyswietlanie_najblizszego_wydarzenia();// 1 najblizsze wydarzenie

void wyswietlanie_aktualnej_godziny_dnia();
void loading_bar(); //start programu i powiadomienie o dzisiejszych wydarzeniach

int dzien_numer(); //od jakiego dnia zaczyna sie rok
int dzien_numer2(int miesiac_numer, int rok); //zwraca liczbe dni danego miesiaca
string nazwa_miesiaca(); //zwraca nazwe miesiaca(wykorzystywana w innyh funkcjach)
void wyswietl_kalendarz();//wyswietla widok kalendarza na podany przez uzyt. rok


