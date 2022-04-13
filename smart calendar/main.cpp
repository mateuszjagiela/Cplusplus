#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <windows.h> //
#include <winbase.h> //
#include <fstream>
#include <vector>
#include <time.h> //
#include <ctime> //
#include <algorithm>

using namespace std;
#include "wydarzenie.h"

char wybor, wybor2, wybor3;
int Wydarzenie::id;
vector <Wydarzenie> event;
vector <int> wyswietlone;



/////
int dzien_numer();
int dzien_numer2();
string nazwa_miesiaca();
/////

int main()
{

    event.reserve(id_aktualnie()+1);
    tworzenie_obiektow_z_pliku();
    Wydarzenie *wskaznik;

    loading_bar();

    a:
    cout << "_________________________________" << endl << endl;
    cout << "Witaj w inteligentnym kalendarzu!" << endl;
    cout << "_________________________________" << endl << endl;
    wyswietlanie_aktualnej_godziny_dnia();
    cout << endl << endl << "Co chcialbys zrobic? Wpisz odpowiedni numer w klawiatury: " << endl;
    cout << "1. Wyswietlanie podstawowe, modyfikacja, usuwanie wydarzen." << endl;
    cout << "2. Wyswietlanie chronologiczne, najblizsze wydarzenie, aktualne wydarzenia." << endl;
    cout << "3. Wyszukiwanie wydarzen." << endl;
    cout << "4. Dodawanie nowego wydarzenia." << endl;
    cout << "5. Wyswietlanie calego roku." << endl;
    cout << "6. Wyjscie" << endl;

    b:
    wybor = getch();
    switch (wybor)
    {//wyswietlanie podstawowe modyfikacja usuwanie
    case '1':
        {
            c:
            system ("cls");
            cout << "Wybrano opcje wyswietlania, modyfikacji i usuwania. Co konkretnie chcialbys zobaczyc?" << endl << endl;
            cout << "1. Wyswietlanie waznych wydarzen." << endl; //DONE
            cout << "2. Wyswietlanie dzisiejszych wydarzen." << endl; //DONE
            cout << "3. Wyswietlanie wydarzen w najblizszych 7 dniach." << endl; //DONE
            cout << "4. Wyswietlanie wydarzen w najblizszych 4 tygodniach." << endl; //DONE
            cout << "5. Wyswietlanie wszystkich wydarzen." << endl;  //DONE
            cout << "6. Wstecz." << endl;
            int v;
            wybor2 = getch();

            switch(wybor2)
            {
                case '1':
                {   h:
                    wyswietlanie_waznych_wydarzen();
                    v = opcje_przy_wyswietlaniu();
                    if(v==1) goto c;
                    if(v==2) goto h;


                }
                break;
                case '2':
                {   i:
                    wyswietlanie_dzisiejszych_wydarzen();
                    v = opcje_przy_wyswietlaniu();
                    if(v==1) goto c;
                    if(v==2) goto i;
                }
                break;
                case '3':
                {   j:
                    wyswietlanie_wydarzen_w_najblizszym_czasie(7);
                    v = opcje_przy_wyswietlaniu();
                    if(v==1) goto c;
                    if(v==2) goto j;

                }
                break;
                case '4':
                {   k:
                    wyswietlanie_wydarzen_w_najblizszym_czasie(28);
                    v = opcje_przy_wyswietlaniu();
                    if(v==1) goto c;
                    if(v==2) goto k;
                }
                break;
                case '5':
                {
                    l:
                    wyswietlanie_wszystkich_obiektow();
                    v = opcje_przy_wyswietlaniu();
                    if(v==1) goto c;
                    if(v==2) goto l;
                }
                break;
                case '6':
                {
                    system("cls");
                    goto a;
                }
                break;
                default:
                {
                    cout << "Wydaje mi sie, ze przez przypadek wpisales zly klawisz... ";
                    cout << "Wcisnij dowolny klawisz i sprobuj jeszcze raz!" << endl;
                    system("pause");
                    goto c;
                }
                break;
            }
        }
        break;


    case '2':
        {//wyswitlanie chronologiczne
            chronologiczne:
            system("cls");
            cout << "Wybrano opcje wyswietlania chronologicznego. Co konkretnie chcialbys zobaczyc?" << endl << endl;
            cout << "1. Najblizsze wydarzenie." << endl;
            cout << "2. Aktualne wydarzenia w kolejnosci chronologicznej." << endl;
            cout << "3. Wyswietlanie wszystkich wydarzen w kolejnosci chronologicznej." << endl;
            cout << "4. Wstecz." << endl;
            char wybor_chronologiczne;
            int g;
            wybor_chronologiczne=getch();

            switch(wybor_chronologiczne)
            {
            case '1':
                {
                    system("cls");
                    wyswietlanie_najblizszego_wydarzenia();
                    cout << endl << "Wcisnij dowolny przycisk, aby kontynuowac. " << endl;
                    getch();
                    goto chronologiczne;
                }
                break;
            case '2':
                {
                    system("cls");
                    wyswietlanie_aktualnych_wydarzen();
                    cout << endl << "Wcisnij dowolny przycisk, aby kontynuowac. " << endl;
                    getch();
                    goto chronologiczne;
                }
                break;
            case '3':
                {
                    system("cls");
                    wyswietlanie_chronologiczne();
                    cout << endl << "Wcisnij dowolny przycisk, aby kontynuowac. " << endl;
                    getch();
                    goto chronologiczne;
                }
                break;
            case '4':
                {
                    system("cls");
                    goto a;
                }
                break;
            default:
                {
                    cout << "Wydaje mi sie, ze przez przypadek wpisales zly klawisz... ";
                    cout << "Wcisnij dowolny klawisz i sprobuj jeszcze raz!" << endl;
                    system("pause");
                    system("cls");
                    goto chronologiczne;
                }
                break;
            }
        }


    case '3':
        {//wyszukiwanie wydarzen
            d:
            system ("cls");
            cout << "Wybrano opcje wyszukiwania. W jaki sposob chcialbys wyszukac wydarzenie?" << endl << endl;
            cout << "1. Podajac date wydarzenia." << endl;
            cout << "2. Podajac nazwe wydarzenia." << endl;
            cout << "3. Wstecz." << endl;
            int b;
            wybor2 = getch();

            switch(wybor2)
            {
            case '1':
                {   m:
                    wyszukiwanie_wydarzen_data();
                    b=opcje_przy_wyswietlaniu();
                    if(b==1) goto d;
                    if(b==2) goto m;
                }
                break;
            case '2':
                {   n:
                    wyszukiwanie_wydarzen_nazwa();
                    b=opcje_przy_wyswietlaniu();
                    if(b==1) goto d;
                    if(b==2) goto n;
                }
                break;
            case '3':
                {
                    system("cls");
                    goto a;
                }
                break;
            default:
                {
                    cout << "Wydaje mi sie, ze przez przypadek wpisales zly klawisz... ";
                    cout << "Wcisnij dowolny klawisz i sprobuj jeszcze raz!" << endl;
                    system("pause");
                    goto d;
                }
                break;
            }

        }
        break;


     case '4':
        {//dodawanie nowego wydarzenia
            e:
            system("cls");
            //cin.ignore();
            cout << "Dodawanie nowego wydarzenia:" << endl;

            Wydarzenie w1;
            wskaznik= &w1;
            wskaznik -> dodaj_wydarzenie();
            wskaznik -> zapisz_wydarzenie();
            event.push_back(w1);
            id_aktualnie();
            system("cls");
            cout << "Zapisano wydarzenie!" << endl << endl;

            f:
            cout << "Co chcialbys teraz zrobic?" << endl;
            cout << "1. Dodaj nowe wydarzenie." << endl;
            cout << "2. Powrot do menu glownego" << endl;
            wybor3 = getch();

            switch(wybor3)
            {
                case '1':
                {
                    //cin.ignore();
                    goto e;
                }
                break;
            case '2':
                {
                    system("cls");
                    goto a;
                }
                break;
            default:
                {
                    cout << "Wydaje mi sie, ze przez przypadek wpisales zly klawisz... ";
                    cout << "Wcisnij dowolny klawisz i sprobuj jeszcze raz!" << endl;
                    system("pause");
                    system("cls");
                    goto f;
                }
                break;
            }
        }
        break;


    case '5':
        {//wyswietlanie widoku miesiecy
            g:
            system("cls");
            cout << "Wybrales wyswietlanie widoku calego roku" << endl;
            wyswietl_kalendarz();                                     //a

            cout << "1. Wstecz" << endl;
            cout << "2. Wyswietl inny rok" << endl;
            wybor3 = getch();

            switch(wybor3)
            {
            case '1':
                {
                    system ("cls");
                    goto a;
                }
                break;
            case '2':
                {
                    goto g;
                }
            default:
                {
                    cout << "Wydaje mi sie, ze sie pomyliles. Sprobuj jeszcze raz!" << endl;
                    goto g;
                }
            }
        }
        break;
    case '6':
        {//wstecz
            system("cls");
            cout << "Ok, na dzisiaj koniec do zobaczenia wkrotce!" << endl;
            return 0;

        }
        break;
    default:
        {
            cout << "Wybrano niepoprawna mozliwosc. Sprobuj ponownie wpisac" << endl;
            goto b;
        }
        break;
    }
    return 0;
}

