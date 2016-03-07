/*     Librarian's Utility     */
/*Udostepniany na licencji GNU General Public Licence*/

#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;
//******************************************************
class clientclass
{
      public:
   vector <string> name;
   vector <int> age;
   vector <int> booksstored;
   vector <int> borrowedever;
   vector <int> lastborrow;
   vector <string> adress;
   vector <string> email;
   vector <int> status;

};

                void sort( vector <string> taba[], vector <int> tabq[], vector <int> tabw[], vector <int> tabe[], vector <int> tabr[], vector <string> tabt[], vector <string> taby[], vector <int> tabu[], unsigned long long size )
                     {
                                 for( int i = 0; i < size; i++ )
                                 {
                                      for( int j = 0; j < size - 1; j++ )
                                      {
                                           if(  taba[j] > taba[j + 1]  )
                                           {
                                               swap( taba[ j ], taba[ j + 1 ] );
                                               swap( tabq[ j ], tabq[ j + 1 ] );
                                               swap( tabw[ j ], tabw[ j + 1 ] );
                                               swap( tabe[ j ], tabe[ j + 1 ] );
                                               swap( tabr[ j ], tabr[ j + 1 ] );
                                               swap( tabt[ j ], tabt[ j + 1 ] );
                                               swap( taby[ j ], taby[ j + 1 ] );
                                               swap( tabu[ j ], tabu[ j + 1 ] );

                                           }
                                      }
                                 }
                     }

void drawmenu(unsigned short posopt, unsigned long long poscli, string optlist[], vector <string>& clients)
{
cout<<"|=====================|=====================|"<<endl;

int queue;
unsigned long long repeats;
if(clients.size() <= 4)
repeats = 4;
else
    repeats = clients.size();
for (queue = 1; queue <= repeats; queue++)
{


//powtorzymy to tyle razy, ile elementow ma lista klientow

cout<<"|";
if(posopt == queue)
{
    cout<<">"<<optlist[queue ];
    for(int i = 1; i <= 21-optlist[queue ].length()-1; i ++)
    {
        cout<<" ";
    }
}else{
cout<<optlist[queue ];
    for(int i = 1; i <= 21-optlist[queue ].length(); i++)
    {
        cout<<" ";
     }
}
cout<<"|";

//czesc spisu klientow
if(poscli == queue)
{
    cout<<">"<<clients[queue - 1];
    if (clients[queue - 1] != "")
    {

    for(int i = 1; i <= 21-clients[queue - 1].length()-1; i ++)
    {
        cout<<" ";
    }}
    else{cout<<"                     ";}
}else{
    if(clients[queue - 1] != "")
    {
cout<<clients[queue - 1];
    for(int i = 1; i <= 21-clients[queue - 1].length(); i++)
    {
        cout<<" ";
     }
    }
    else{cout<<"                     ";}
}
cout<<"|"<<endl;



//powtarzamy ta czesc
}

cout<<"|=====================|=====================|"<<endl<<"Wazne! Wybierajac opcje 'Dodaj Uzytkownika' nie ma znaczenia, ktory klient jest wybrany w prawej kolumnie.\nEsc-wyjscie.";
}



void dodajuzytkownika()
{
    char PL[64];
    CharToOem("ąęźćśż", PL);
    system("cls");
    cout<<"#####################"<<endl
        <<"#                   #"<<endl
        <<"# Dodaj u"<<PL[5]<<"ytkownika #"<<endl
        <<"#                   #"<<endl
        <<"#####################"<<endl;
        cout<<"Imi"<<PL[1]<<" i nazwisko:";
        string imieinazwisko;
        getline(cin, imieinazwisko);
        cout<<endl<<"";
}










//**************************************************************
void menu()
{
system("cls");//czyscimy konsole
//string clientsmenubuffer[4];//deklarujemy zmienne i tworzymy tablice
string optionsmenubuffer[4];
string optionslist[4];
optionslist[1] = "Nieoddane ksiazki";//dodajemy do listy 4 elementy,      1 element
optionslist[2] = "Dane klientow";//                                       2 element
optionslist[3] = "Dodaj uzytkownika";//                                   3 element
optionslist[4] = "Zmien status ksiazki";//                                4 element
vector <string> clients;// dynamiczna tablica ze spisem klientow biblioteki, przewaza nad zwyklymi tablicami tym, ze
//w kazdej chwili mozna zmienic jej rozmiar


fstream getdata;//zmienna przechowujaca plik
/*w zasadzie mowiac 'operacje na pliku' w C++ dzialamy na zmiennej do ktorej wczytalismy plik*/
getdata.open("daneklientow.baza", ios::in | ios::out);//otwieramy plik (wczytaj/zapisz)
if(getdata.good() == true)//*************************wczytanie pliku******************************
{//gdy wczytywanie sie powiodlo...
string dataloaded;//zmienna, do ktorej bedziemy wczytywac linijke tekstu z pliku
while(!getdata.eof())//powtarzamy, az dojdziemy do konca pliku...
{
    getline(getdata, dataloaded);//pobieramy linijke
    clients.push_back(dataloaded);//dopisz do listy klientow nastepna linijke tekstu NA KONCU
    clientclass client;
    unsigned long long namesize = client.name.size();
    sort(client.name, client.age, client.booksstored, client.borrowedever, client.lastborrow, client.adress, client.email, client.status, namesize);
    //imie = clients;
}
getdata.close();//zamykamy plik
}else//w przeciwnym razie...
{
cout<<"\n\n\n\nPrzepraszamy, wystapil blad wczytawania pliku. Upewnij sie, ze:\n -plik 'imionaklientow.baza' istnieje na dysku\n -posiadasz uprawnienia do odczytu pliku\n\nNacisnj dowolny klawiz, aby zamknac program."<<endl<<endl<<endl<<endl;
getchar();//czekaj na dowolny klawisz
/*Po wcisnieciu klawisza program konczy dzialanie*/
}




//*************************************************koniec wczytywania****************
unsigned short menuoptionsposition = 1;
unsigned long long menuclientsposition = 1;//Jak myslicie, chyba nie bedzie klientow wiecej niz 18446744073709551615 :D
bool menulevel = 0;//czy jestesmy w menu lewym czy prawym
unsigned char znak;
bool options = 0;

do
{
  system("cls");//czyscimy konsole
  drawmenu(menuoptionsposition, menuclientsposition, optionslist, clients);  //rysujemy menu, przekazujemy mu, ktore opcje sa zaznaczone
  options = 0;
  znak = getch();//z biblioteki Conio
switch (znak)
{
case 72://strzalka w gore
if(menulevel == 0)
{
        if (menuoptionsposition > 1)
    {
        menuoptionsposition = menuoptionsposition - 1;
        break;
    }
    else
    {
        menuoptionsposition = 4;
        break;
    }
}else
{
        if (menuclientsposition > 1)
    {
        menuclientsposition = menuclientsposition - 1;
        break;
    }
    else
    {
        menuclientsposition = clients.size();
        break;
    }
}



case 80://strzalka w dol
if(menulevel == 0)
{
    if (menuoptionsposition < 4)
    {
        menuoptionsposition ++;
        break;
    }
    else
    {
        menuoptionsposition = 1;
        break;
    }
}else{
    if (menuclientsposition < clients.size())
    {
        menuclientsposition ++;
        break;
    }
    else
    {
        menuclientsposition = 1;
        break;
    }
}




case 75://strzalka w lewa
    if (menulevel == 1)
    {
        menulevel = 0;
        break;
    }
    else
        break;

case 77://strzalka w prawa

    if (menulevel == 0)
    {
        menulevel = 1;
        break;
    }else
    {
    if(menulevel == 1)
        options = 1;
        break;
    }
case 27://Esc

 system("cls");
 cout<<"\n     Czy na pewno chcesz wyjsc?(t/n)"<<endl;
 char yesno;
 yesno = getch();
 if (yesno == 116)//t
 exit(1);
 else if(yesno == 110)//n
 menu();

}
        znak = 0;



}
while(!options == 1 );


switch (menuoptionsposition)
{/*
case 1:
    nieoddaneksiazki(clients[menuclientsposition]);

case 2:
    daneklientow(clients[menuclientsposition]);*/
case 3:
    dodajuzytkownika();
//case 4:
    //zmienstatusksiazki(clients[menuclientsposition]);
}



}



int main()
{
SetConsoleTitleA("Librarian's Utility");//Ustaw nazwe okna(napis na belce konsoli), windows.h
cout<<"\n\n\n\n\n\n                  WITAM!\n\n                 Librarian's Utility Version 1.0\n\n\n\n\n\nUnder GNU GPL"<<endl;
Sleep(3000);//Czekaj 3000 milisekund (biblioteka Windows)
menu();//funkcja menu budzi sie do zycia :D
return 0;
}
