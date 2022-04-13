#include "wydarzenie.h"
//CIALA METOD"brak"

Wydarzenie::Wydarzenie(string n, string l="brak lokalizacji", int g=12, int mi=0, int d=1, int mies=1, int r=2022, int w=1)
{
    nazwa=n;
    lokalizacja=l;
    godzina=g;
    minuta=mi;
    dzien=d;
    miesiac=mies;
    rok=r;
    wazne=w;
}

Wydarzenie::Wydarzenie()
{
    nazwa="brak nazwy";
    lokalizacja="brak";
    godzina=12;
    minuta=0;
    dzien=1;
    miesiac=1;
    rok=2022;
    wazne=1;
}

Wydarzenie::~Wydarzenie()
{
}

void loading_bar()
{
    int ab=0;

    for(int i=0;i<26;i++)
    {
    system("CLS");
    cout<<"  ============================================"<<endl;
    cout<<"  Loading:   ";
       for(int i=0;i<ab;i++)
        {
        cout<< "#";
        }
        for(int j=0;j<29-ab;j++)
        {
            cout<<" ";
        }
    cout<<ab*4<<"%";
    cout<<endl;
    cout<<"  ============================================"<<endl;
    Sleep(30);
    ab++;
    }
    Sleep(1000);
    system("cls");
    cout << "Zanim zaczniemy sprawdzmy czy nie masz zaplanowanych na dzis jakichs wydarzen: " << endl;
    wyswietlanie_dzisiejszych_wydarzen();
    cout << endl << "Wcisnij dowolny przycisk aby kontynuowac :)" << endl;
    getch();
    system("cls");

}

void Wydarzenie::dodaj_wydarzenie()
{

    string n, l;
    int r, mies, dz, g, mi, w;
    //cin.ignore(); //
    id++; ///////////////
    id_obiektu=id; ///////////                                                                   l
    id--; /////////////////////////////////////////////////
    cout << "Aby dodac wydarzenie podaj niezbedne informacje." << endl;

    cout << "Podaj nazwe wydarzenia: " << endl;// cin.ignore();
    //cin.ignore(INT_MAX, '\n');
    cin.ignore();
    getline(cin, n);
    nazwa=n;

    cout << "Gdzie bedzie mialo miejsce?";
    getline(cin, l);
    lokalizacja=l;

    niepoprawny_rok:
    cout << endl << "Podaj rok wydarzenia: ";
    try
    {   cin >> r;
        if(cin.fail()||r<=0)
        {
            throw "Wydaje mi sie ze wpisales zly rok.";
        }
    }
    catch(char const* error)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << error << " Sprobuj jeszcze raz" << endl;
        if(error=="Wydaje mi sie ze wpisales zly rok.") goto niepoprawny_rok;

    }
    rok=r;

    niepoprawny_miesiac:
    cout << endl << "Podaj miesiac wydarzenia: ";
    cin >> mies;
    if(mies<1||mies>12||cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wydaje mi sie ze wpisales zly miesiac. Sprobuj jeszcze raz." << endl;
        goto niepoprawny_miesiac;
    }
    miesiac=mies;

    niepoprawna_data:
    cout << endl << "Podaj dzien wydarzenia: ";
    cin >> dz;
    if(dz<1||dz>31||cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wydaje mi sie, ze wpisales niepoprawny dzien. Sprobuj jeszcze raz." << endl;
        goto niepoprawna_data;
    }
    dzien=dz;

    niepoprawna_godzina:
    cout << endl << "Podaj godzine wydarzenia: ";
    cin >> g;
    if(g<0||g>23||cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wydaje mi sie, ze wpisales niepoprawna godzine. Sprobuj jeszcze raz." << endl;
        goto niepoprawna_godzina;
    }
    godzina=g;

    niepoprawna_minuta:
    cout << endl << "Podaj minute wydarzenia: ";
    cin >> mi;
    if(mi<0||mi>59||cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wydaje mi sie, ze wpisales niepoprawna minute. Sprobuj jeszcze raz." << endl;
        goto niepoprawna_minuta;
    }
    minuta=mi;

    niepoprawne_wazne:
    cout << endl << "Jak wazne jest to wydarzenie w skali od 1 do 3: ";
    cin >> w;
    if(w<1||w>3||cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Prosze, abys podal w skali od 1 do 3. Sprobuj jeszcze raz" << endl;
        goto niepoprawne_wazne;
    }
    wazne=w;
}

void Wydarzenie::wyswietl_wydarzenie()
{
    cout << endl << id_obiektu << ". " << nazwa << endl;
    cout << "Jest ono w: " << lokalizacja << endl;

    cout << "Data wydarzenia: ";
    if(dzien<10)
    {
        cout << "0";
    }
    cout << dzien << ".";
    if(miesiac<10)
    {
        cout << "0";
    }
    cout << miesiac << "." << rok << "r." << endl;

    cout << "Godzina wydarzenia: " << godzina << ":";
    if(minuta<10)
    {
        cout << "0";
    }
    cout << minuta << endl;

    cout << "Oceniles ze to wydarzenie jest dla Ciebie ";
    switch(wazne)
    {
    case 1:
        {
            cout << "malo istotne" << endl;
        }
    break;
    case 2:
        {
            cout << "srednio istotne" << endl;
        }
        break;
    case 3:
        {
            cout << "bardzo istotne" << endl;
        }
    }
}

void Wydarzenie::zapisz_wydarzenie()
{
    //int linia_aktualna;
    id++;
    ofstream plik;
    plik.open("zapis_wydarzen.txt", ios::app|ios::out);
    if(plik.good()==false)
    {
        cout << "Nie znaleziono pliku!" << endl;
        exit(0);
    }

    plik << id_obiektu << endl;
    plik << nazwa << endl;
    plik << lokalizacja << endl;
    plik << rok << endl;
    plik << miesiac << endl;
    plik << dzien << endl;
    plik << godzina << endl;
    plik << minuta << endl;
    plik << wazne << endl;

    plik.close();
}

int id_aktualnie()
{

    string linia;
    int numer=0;
    fstream plik;
    plik.open("zapis_wydarzen.txt", ios::in);
    if(plik.good()==false)
    {
        cout << "Nie znaleziono pliku!" << endl;
        exit(0);
    }

    while(getline(plik, linia))
    {
        numer++;
    }
    if(numer>=9)
    {
        Wydarzenie::id=(numer/9);
    }
    plik.close();
    return Wydarzenie::id;


}

void tworzenie_obiektow_z_pliku()
{
    int liczba_wydarzen=id_aktualnie();
    int i=0;
    int nr_linii=1;
    string linia;

    fstream plik;
    plik.open("zapis_wydarzen.txt", ios::in);
    if(plik.good()==false)
    {
        cout << "Nie znaleziono pliku!" << endl;
        exit (0);
    }

for(int i=0; i<liczba_wydarzen; i++)
{
    Wydarzenie w5;
    event.push_back(w5);
}
    while(getline(plik, linia))
    {
        switch(nr_linii)
        {
            case 1: event[i].id_obiektu=atoi(linia.c_str()); break;
            case 2: event[i].nazwa=linia; break;
            case 3: event[i].lokalizacja=linia; break;
            case 4: event[i].rok=atoi(linia.c_str()); break;
            case 5: event[i].miesiac=atoi(linia.c_str()); break;
            case 6: event[i].dzien=atoi(linia.c_str()); break;
            case 7: event[i].godzina=atoi(linia.c_str()); break;
            case 8: event[i].minuta=atoi(linia.c_str()); break;
            case 9: event[i].wazne=atoi(linia.c_str()); break;
        }
        if(nr_linii==9) {nr_linii=0; i++;}
        nr_linii++;
    }
    plik.close();
}

void wyswietlanie_wszystkich_obiektow()
{
    int abc=event.size();
    for(int i=0; i<abc; i++)
    {
        event[i].wyswietl_wydarzenie();
    }
}

void usuwanie_obiektow(int p)
{
    //int r;
    int k=0;
    event.erase(event.begin()+(p-1));
    int liczba=id_aktualnie()-1;

    ofstream plik2;
    plik2.open("zapis_wydarzen.txt", ios::trunc);
    plik2.close();

    //Wydarzenie::id=0; ////////////////////

    //r=event[p-1].get_id();
    for(int i=0; i<liczba; i++)
    {
            event[i].set_id(1+k);
            cout << endl << "Zapisuje nr" << i << endl;
            event[i].zapisz_wydarzenie();
        k++;
    }

    id_aktualnie();
}

void modyfikacja_obiektow(int p)
{
    int i=p;
    i--;

    char wybor_uzytkownika;
    cout << "Co chcialbys zmodyfikowac? " << endl;
    cout << "1. Nazwa wydarzenia" << endl;
    cout << "2. Lokalizacja" << endl;
    cout << "3. Rok" << endl;
    cout << "4. Miesiac" << endl;
    cout << "5. Dzien" << endl;
    cout << "6. Godzine" << endl;
    cout << "7. Minute" << endl;
    cout << "8. To jak wazne jest wydarzenie" << endl;
    niepoprawna_modyfikacja:
    cin >> wybor_uzytkownika;
    switch(wybor_uzytkownika)
    {
    case '1':
        {
            cout << "Podaj nowa nazwe: ";
            string nowa_nazwa;
            cin.ignore();
            getline(cin, nowa_nazwa);
            event[i].set_nazwa(nowa_nazwa);
        }
        break;
    case '2':
        {
            cout << "Podaj nowa lokalizacje: ";
            string nowa_nazwa;
            cin.ignore();
            getline(cin, nowa_nazwa);
            event[i].set_lokalizacja(nowa_nazwa);
        }
        break;
    case '3':
        {   m_niepoprawny_rok:
            cout << "Podaj nowy rok: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wydaje mi sie ze wpisales zly rok. Sprobuj jeszcze raz." << endl;
                goto m_niepoprawny_rok;
            }
            event[i].set_rok(nowe_dane);
        }
        break;
    case '4':
        {   m_niepoprawny_miesiac:
            cout << "Podaj nowy miesiac: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(nowe_dane<1||nowe_dane>12||cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wydaje mi sie ze wpisales zly miesiac. Sprobuj jeszcze raz." << endl;
                goto m_niepoprawny_miesiac;
            }
            event[i].set_miesiac(nowe_dane);
        }
        break;
    case '5':
        {   m_niepoprawna_data:
            cout << "Podaj nowy dzien: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(nowe_dane<1||nowe_dane>31||cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wydaje mi sie, ze wpisales niepoprawny dzien. Sprobuj jeszcze raz." << endl;
                goto m_niepoprawna_data;
            }
            event[i].set_dzien(nowe_dane);
        }
        break;
    case '6':
        {   m_niepoprawna_godzina:
            cout << "Podaj nowa godzine: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(nowe_dane<0||nowe_dane>23||cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wydaje mi sie, ze wpisales niepoprawna godzine. Sprobuj jeszcze raz." << endl;
                goto m_niepoprawna_godzina;
            }
            event[i].set_godzina(nowe_dane);
        }
        break;
    case '7':
        {   m_niepoprawna_minuta:
            cout << "Podaj nowa minute: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(nowe_dane<0||nowe_dane>59||cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wydaje mi sie, ze wpisales niepoprawna minute. Sprobuj jeszcze raz." << endl;
                goto m_niepoprawna_minuta;
            }
            event[i].set_minuta(nowe_dane);
        }
        break;
    case '8':
        {   m_niepoprawne_wazne:
            cout << "Okresl jak wazne jest to wydarzenie w skali 1-3: ";
            int nowe_dane;
            cin >> nowe_dane;
            if(nowe_dane<1||nowe_dane>3||cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Prosze, abys podal w skali od 1 do 3. Sprobuj jeszcze raz" << endl;
                goto m_niepoprawne_wazne;
            }
            event[i].set_wazne(nowe_dane);
        }
        break;
    default:
        {
            cout << "Wydaje mi sie, ze popelniles blad... Sprobuj jeszcze raz" << endl;
            goto niepoprawna_modyfikacja;
        }
        break;
    }
    // po switchu
    modyfikacja_obiektow2();
    cout << endl << "Udalo sie zmienic dane! Kliknij dowolny przycisk." << endl;
    system("pause");
    system("cls");


}

void modyfikacja_obiektow2()
{
    int liczba;
    liczba=id_aktualnie();
    ofstream plik2;
    plik2.open("zapis_wydarzen.txt", ios::trunc);
    plik2.close();

    for(int i=0; i<liczba; i++)
    {
        event[i].zapisz_wydarzenie();
    }
    id_aktualnie();
}

int opcje_przy_wyswietlaniu()
{
cout << endl << endl<< "1. Wstecz" << endl;
cout << "2. Modyfikuj wybrane wydarzenie" << endl;
cout << "3. Usun wybrane wydarzenie" << endl;
char zmienna;
zmienna = getch();
switch(zmienna)
{
case '1':
    {
        return 1;
    }
    break;
case '2':
    {
        cout << "Ktore wydarzenie chcialbys zmodyfikowac? (0 - wstecz) " << endl;
        int o;
        niepoprawne_o:
        cin >> o;
        if(cin.fail()||o<0||o>event.size())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Wydaje mi sie ze wpisales zla liczbe. Sprobuj jeszcze raz." << endl;
            goto niepoprawne_o;
        }

        if(o==0)
        {
            system("cls");
            return 1;
        }
        system("cls");
        cout << "Modyfikacja wydarzenia nr " << o << ":" << endl;
        event[o-1].wyswietl_wydarzenie();
        cout << endl << endl;
        modyfikacja_obiektow(o);
        return 2;
    }
case '3':
    {
        int e;
        cout << "Wpisz numer wydarzenia, ktore chcialbys usunac: (0 - wstecz)";
        niepoprawne_e:
        cin >> e;
        if(cin.fail()||e<0||e>event.size())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Wydaje mi sie ze wpisales zla liczbe. Sprobuj jeszcze raz." << endl;
            goto niepoprawne_e;
        }
        if(e==0)
        {
            return 1;
        }
        else
        {
            usuwanie_obiektow(e);
            system ("cls");
            cout << endl << "Pomyslnie usunieto wydarzenie! Kliknij dowolny przycisk, aby kontynuowac." << endl;
            system("pause");
            return 2;
        }

    }
    break;
    default:
    {
        cout << endl << "Wydaje mi sie ze wprowadziles niepoprawna liczbe. Sprobuj jeszcze raz!";
        cout << " Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        system("pause");
        system("cls");
        return 2;
    }
}
}

void wyswietlanie_dzisiejszych_wydarzen()
{
    int r=0;
    SYSTEMTIME st;
    GetSystemTime(&st);
    for(int i=0; i<id_aktualnie(); i++)
    {
        if(event[i].get_rok()==st.wYear&&event[i].get_miesiac()==st.wMonth&&event[i].get_dzien()==st.wDay)
        {
            r++;
            if(r==1) cout << "Wyswietlam dzisiejsze wydarzenia: " << endl;
            event[i].wyswietl_wydarzenie();
        }
    }
    if(r==0) cout << "Nie znaleziono zadnych wydarzen w dzisiejszym dniu." << endl;
}

void wyswietlanie_wydarzen_w_najblizszym_czasie(int plus_dni)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    int ile_miesiac_ma_dni=dzien_numer2(st.wMonth, st.wYear);                    //
    int r=0;
    int roznica_dni=0;
    roznica_dni=plus_dni+st.wDay-ile_miesiac_ma_dni;
    if((st.wDay+plus_dni)<=ile_miesiac_ma_dni)
    {//gdy nie zmienia sie miesiac
        for(int i=0; i<id_aktualnie(); i++)
        {
            if(event[i].get_dzien()<=st.wDay+plus_dni&&event[i].get_dzien()>=st.wDay)
            {
                if(st.wMonth==event[i].get_miesiac()&&st.wYear==event[i].get_rok())
                {
                    r++;
                    if(r==1) cout << "Wyswietlam wydarzenia: " << endl;
                    event[i].wyswietl_wydarzenie();
                }
            }
        }
    }

    else

    {
        if(st.wMonth!=12)
        {
            //gdy zmienia sie miesiac i miesiac!=grudnia
            for(int i=0; i<id_aktualnie(); i++)
            {
                if(event[i].get_dzien()<=ile_miesiac_ma_dni&&event[i].get_dzien()>=st.wDay&&event[i].get_miesiac()==st.wMonth&&event[i].get_rok()==st.wYear)//sprawdzanie w tym miesiacu jeszcze
                {
                    r++;
                    if(r==1) cout << "Wyswietlam wydarzenia: " << endl;
                    event[i].wyswietl_wydarzenie();
                }
                if(event[i].get_dzien()<=roznica_dni&&event[i].get_miesiac()==st.wMonth+1&&event[i].get_rok()==st.wYear)//sprawdzanie w nastepnym miesiacu
                {
                    r++;
                    if(r==1) cout << "Wyswietlam wydarzenia: " << endl;
                    event[i].wyswietl_wydarzenie();
                }
            }
        }
        else
        {
            //nowy rok i nowy miesiac
            for(int i=0; i<id_aktualnie(); i++)
            {
                if(event[i].get_dzien()<=ile_miesiac_ma_dni&&event[i].get_dzien()>=st.wDay&&event[i].get_miesiac()==st.wMonth&&event[i].get_rok()==st.wYear)//sprawdzanie w tym miesiacu jeszcze
                {
                    r++;
                    if(r==1) cout << "Wyswietlam wydarzenia: " << endl;
                    event[i].wyswietl_wydarzenie();
                }
                if(event[i].get_dzien()<=roznica_dni&&event[i].get_miesiac()==st.wMonth+1&&event[i].get_rok()==st.wYear+1)//sprawdzanie w nastepnym miesiacu i nowym roku
                {
                    r++;
                    if(r==1) cout << "Wyswietlam wydarzenia: " << endl;
                    event[i].wyswietl_wydarzenie();
                }
            }

        }
    }
}

void wyswietlanie_waznych_wydarzen()
{
    system("cls");
    int q, typ;
    int niepowodzenie;
    cout << "Jak wazne wydarzenia chcialbys wyswietlic?" << endl;
    cout << "1. Bardzo istotne" << endl;
    cout << "2. Srednio istotne" << endl;
    cout << "3. Malo istotne" << endl;
    niepoprawne_q:
    cin >> q;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wydaje mi sie ze wpisales zla liczbe. Sprobuj jeszcze raz." << endl;
        goto niepoprawne_q;
    }

    if(q==1) typ=3;
    if(q==2) typ=2;
    if(q==3) typ=1;
    for(int i=0; i<id_aktualnie(); i++)
    {
        if(event[i].get_wazne()==typ)
        {
            event[i].wyswietl_wydarzenie();
            niepowodzenie++;
        }
    }
    if(niepowodzenie==0) cout << "Nie znaleziono takich wydarzen." << endl;
}

void wyszukiwanie_wydarzen_nazwa()
{
    system("cls");
    string szukana;
    cout << "Wpisz fraze wydarzenia, ktora chcesz wyszukac: " << endl;
    //cin.ignore();
    //getline(cin, szukana);
    cin >> szukana;
    int niepowodzenie;


    for(int i=0; i<id_aktualnie(); i++)
    {
        if (event[i].get_nazwa().find(szukana) !=string::npos)
        {
            if(niepowodzenie==0) cout << "Wyswietlam wydarzenia o nazwie: " << szukana << endl;
            event[i].wyswietl_wydarzenie();
            niepowodzenie++;
        }
    }
    if(niepowodzenie==0) cout << "Nie znaleziono takich wydarzen" << endl;

}

void wyszukiwanie_wydarzen_data()
{
    system("cls");
    int r1, m1, d1;

    niepoprawne_r1:
    cout << "Wpisz rok wydarzenia, ktore chcesz wyszukac: ";
    cin >> r1;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << "Wydaje mi sie ze wpisales zly rok. Sprobuj jeszcze raz." << endl;
        goto niepoprawne_r1;
    }
    niepoprawne_m1:
    cout << "Wpisz miesiac wydarzenia, ktore chcesz wyszukac: ";
    cin >> m1;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << "Wydaje mi sie ze wpisales zly miesiac. Sprobuj jeszcze raz." << endl;
        goto niepoprawne_m1;
    }
    niepoprawne_d1:
    cout << "Wpisz dzien wydarzenia, ktore chcesz wyszukac: ";
    cin >> d1;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << "Wydaje mi sie ze wpisales zly dzien. Sprobuj jeszcze raz." << endl;
        goto niepoprawne_d1;
    }

    int niepowodzenie;
    for(int i=0; i<id_aktualnie(); i++)
    {
        if(event[i].get_rok()==r1&&event[i].get_miesiac()==m1&&event[i].get_dzien()==d1)
        {   if(niepowodzenie==0) {cout << "Wyswietlam wydarzenia w tym dniu:  " << endl;}
            event[i].wyswietl_wydarzenie();
            niepowodzenie++;
        }
    }
    if(niepowodzenie==0) cout << "Nie znaleziono takich wydarzen" << endl;
}
void wyswietlanie_chronologiczne()
{
    double ilosc_rok, ilosc_miesiac;
    int tab[id_aktualnie()];
    int sprawdzanie;
    vector <int> wyswietlone;

    for(int i=0; i<id_aktualnie(); i++)
    {
            ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
            ilosc_miesiac=0;
            for(int p=event[i].get_miesiac()-2; p>=0; p--)
            {
                ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
            }
            tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien());
    }

    sort(tab, tab+id_aktualnie());

    for(int j=0; j<id_aktualnie(); j++)
    {
            for(int i=0; i<id_aktualnie(); i++)
            {
                    for(int k=0; k<wyswietlone.size(); k++)
                    {
                        if(i==wyswietlone[k])//
                        {
                            goto heree;
                        }
                    }

                    ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
                    ilosc_miesiac=0;
                    for(int p=event[i].get_miesiac()-2; p>=0; p--)
                    {
                        ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
                    }
                    //tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); to samo ale zapisuje w sprawdzanie
                    sprawdzanie=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); //liczba dni roku+ dni w mies+ dni

                    if(tab[j]==sprawdzanie)
                    {
                        event[i].wyswietl_wydarzenie();
                        wyswietlone.push_back(i);
                    }
                    heree:
                    ;
            }
    }
}

void wyswietlanie_aktualnych_wydarzen()
{
    double ilosc_rok, ilosc_miesiac;
    int tab[id_aktualnie()];
    int sprawdzanie;
    vector <int> wyswietlone2;
    SYSTEMTIME st;
    GetSystemTime(&st);

    int godzina;
    if(st.wHour==23)
    {godzina=0;}
    else
    {godzina=++st.wHour;}

    int dzisiejsza;
            ilosc_rok=(365*(st.wYear-1)+(st.wYear/4)+366);
            ilosc_miesiac=0;
            for(int p=st.wMonth-2; p>=0; p--)
            {
                ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, st.wYear));
            }
            dzisiejsza=(ilosc_rok+ilosc_miesiac+st.wDay);




    for(int i=0; i<id_aktualnie(); i++)
    {
            ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
            ilosc_miesiac=0;
            for(int p=event[i].get_miesiac()-2; p>=0; p--)
            {
                ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
            }
            tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien());
    }

    sort(tab, tab+id_aktualnie());

    for(int j=0; j<id_aktualnie(); j++)
    {
            for(int i=0; i<id_aktualnie(); i++)
            {
                    for(int k=0; k<wyswietlone2.size(); k++)
                    {
                        if(i==wyswietlone2[k])//
                        {
                            goto heree;
                        }
                    }

                    ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
                    ilosc_miesiac=0;
                    for(int p=event[i].get_miesiac()-2; p>=0; p--)
                    {
                        ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
                    }
                    //tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); to samo ale zapisuje w sprawdzanie
                    sprawdzanie=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); //liczba dni roku+ dni w mies+ dni

                    if(tab[j]==sprawdzanie && tab[j]>=dzisiejsza)
                    {
                        event[i].wyswietl_wydarzenie();
                        wyswietlone2.push_back(i);
                    }
                    heree:
                    ;
            }
    }
}

void wyswietlanie_najblizszego_wydarzenia()
{
    double ilosc_rok, ilosc_miesiac;
    int tab[id_aktualnie()];
    int sprawdzanie;
    vector <int> wyswietlone2;
    SYSTEMTIME st;
    GetSystemTime(&st);

    int godzina;
    if(st.wHour==23)
    {godzina=0;}
    else
    {godzina=++st.wHour;}

    int dzisiejsza;
            ilosc_rok=(365*(st.wYear-1)+(st.wYear/4)+366);
            ilosc_miesiac=0;
            for(int p=st.wMonth-2; p>=0; p--)
            {
                ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, st.wYear));
            }
            dzisiejsza=(ilosc_rok+ilosc_miesiac+st.wDay);

    for(int i=0; i<id_aktualnie(); i++)
    {
            ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
            ilosc_miesiac=0;
            for(int p=event[i].get_miesiac()-2; p>=0; p--)
            {
                ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
            }
            tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien());
    }

    sort(tab, tab+id_aktualnie());

    for(int j=0; j<id_aktualnie(); j++)
    {
            for(int i=0; i<id_aktualnie(); i++)
            {
                    ilosc_rok=(365*(event[i].get_rok()-1)+(event[i].get_rok()/4)+366);
                    ilosc_miesiac=0;
                    for(int p=event[i].get_miesiac()-2; p>=0; p--)
                    {
                        ilosc_miesiac=( ilosc_miesiac+dzien_numer2(p, event[i].get_rok()));
                    }
                    //tab[i]=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); to samo ale zapisuje w sprawdzanie
                    sprawdzanie=(ilosc_rok+ilosc_miesiac+event[i].get_dzien()); //liczba dni roku+ dni w mies+ dni

                    if(tab[j]==sprawdzanie && tab[j]>=dzisiejsza)
                    {
                        event[i].wyswietl_wydarzenie();
                        j=id_aktualnie();
                    }
            }
    }
}
void wyswietlanie_aktualnej_godziny_dnia()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    string dzien_tygodnia;
    switch(st.wDayOfWeek)
    {
    case 0:
        {
            dzien_tygodnia="niedziela";
        }
        break;
    case 1:
        {
            dzien_tygodnia="poniedzialek";
        }
        break;
    case 2:
        {
            dzien_tygodnia="wtorek";
        }
        break;
    case 3:
        {
            dzien_tygodnia="sroda";
        }
        break;
    case 4:
        {
            dzien_tygodnia="czwartek";
        }
        break;
    case 5:
        {
            dzien_tygodnia="piatek";
        }
        break;
    case 6:
        {
            dzien_tygodnia="sobota";
        }
        break;
    }

    cout << "Dzis jest " << dzien_tygodnia << " (";
    if(st.wDay<10) cout << "0";
    cout << st.wDay;
    cout << ".";
    if(st.wMonth<10) cout << "0";
    cout << st.wMonth;
    cout <<  "." << st.wYear << "r.)" << endl;

    cout << "Godzina: ";
    if(st.wHour==23)
    {cout << "0:";}
    else
    {cout << st.wHour+1 << ":" ;}
    if(st.wMinute<10) cout << "0";
    cout << st.wMinute << endl;
}
// wyswietlanie roku 4 funkcje pod
int dzien_numer(int dzien, int miesiac, int rok)
{
        static int t[] = { 0, 3, 2, 5, 0, 3,5, 1, 4, 6, 2, 4 };
        rok -= miesiac < 3;
        return (rok + rok / 4- rok / 100+ rok / 400+ t[miesiac - 1] + dzien)% 7;
}

string nazwa_miesiaca(int miesiac_numer)
{
        string miesiac;
        switch (miesiac_numer)
        {
                case 0: miesiac = "Styczen";
                            break;
                case 1: miesiac = "Luty";
                            break;
                case 2: miesiac = "Marzec";
                            break;
                case 3: miesiac = "Kwiecien";
                            break;
                case 4: miesiac = "Maj";
                            break;
                case 5: miesiac = "Czerwiec";
                            break;
                case 6: miesiac = "Lipiec";
                            break;
                case 7: miesiac = "Sierpien";
                            break;
                case 8: miesiac = "Wrzesien";
                            break;
                case 9: miesiac = "Pazdziernik";
                            break;
                case 10: miesiac = "Listopad";
                            break;
                case 11: miesiac = "Grudzien";
                            break;
        }
        return miesiac;
}

int dzien_numer2(int miesiac_numer, int rok)
{
        if (miesiac_numer == 0)
                return (31);
        if (miesiac_numer == 1)
        {
                if (rok % 400 == 0 || (rok % 4 == 0 && rok % 100 != 0))
                        return (29);
                else
                        return (28);
        }
        if (miesiac_numer == 2)
                return (31);
        if (miesiac_numer == 3)
                return (30);
        if (miesiac_numer == 4)
                return (31);
        if (miesiac_numer == 5)
                return (30);
        if (miesiac_numer == 6)
                return (31);
        if (miesiac_numer == 7)
                return (31);
        if (miesiac_numer == 8)
                return (30);
        if (miesiac_numer == 9)
                return (31);
        if (miesiac_numer == 10)
                return (30);
        if (miesiac_numer == 11)
                return (31);
    //return 31;
}

void wyswietl_kalendarz()
{
        int rok;
        niepoprawny_rok_wyswietl_kalendarz:
        cout << "Podaj rok, ktory chcesz wyswietlic: ";
        cin >> rok;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Wydaje mi sie ze wpisales zly rok. Sprobuj jeszcze raz." << endl;
            goto niepoprawny_rok_wyswietl_kalendarz;
        }
        cout << endl;
        cout << "Kalendarz na rok: " << rok << endl;
        int dzien;
        int aktualny = dzien_numer(1, 1, rok);
        for (int i = 0; i < 12; i++)
        {
                dzien = dzien_numer2(i, rok);
                cout << "------------" <<nazwa_miesiaca(i)<< "------------" << endl;
                cout << "  ND   PON   WT   SR  CZW   PT  SOB" << endl;
                int k;
                for (k = 0; k < aktualny; k++)
                    {
                        cout << "     ";
                    }
                for (int j = 1; j <= dzien; j++)
                {
                        if(j<10) cout << "    " << j;
                        else
                        {
                            cout << "   " << j;
                        }
                        if (++k > 6)
                        {
                                k = 0;
                                cout << endl;
                        }
                }
                if (k) cout << endl;
                aktualny = k;
        }
        return;
}



