#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    cout<<"////////////////"<<endl
        <<"/ Hello World! /"<<endl
        <<"////////////////"<<endl;
        getchar();//Oczekuje wcisniecia dowolnego klawisza, z biblioteki cstdio, podobne do getch() z biblioteki conio,
                  //jednak getchar zatrzymuje program do czasu az wcisniemy jakis przycisk :D
    cout<<"Mogloby byc cos trudniejszego :P";//Sama prawda...
        getchar();
        return 0;
}
