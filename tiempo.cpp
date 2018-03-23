#include <iostream>
#include <time.h>
using namespace std;

void temps(struct tm *info, int&dia, int& mes,int&any,int&hora,int&minuts,int&segons){
	time_t t;
	time( &t );
	info = localtime( &t );
	dia = info -> tm_mday;
	mes = info -> tm_mon;
	any = 1900 + info -> tm_year; // l'any es comença a comptar a partir del 1900
	hora = info -> tm_hour;
	minuts = info -> tm_min;
	segons = info -> tm_sec;}
	
int main ()
{struct tm *info_temps;
int dia, mes,any,hora,minuts,segons;
temps(info_temps, dia, mes,any,hora,minuts,segons);
cout<<" Data de registre del producte:"<< endl;
cout << "Dia: " << dia << endl;
cout << "Mes: " << mes << endl;
cout << "Any: " << any << endl;
cout << "Hora: " << hora << endl;
cout << "Minuts: " << minuts << endl;
cout << "Segons: " << segons << endl;
}
