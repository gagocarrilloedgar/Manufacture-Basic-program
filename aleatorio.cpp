#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Aquesta funció genera un nombre aleatori en [a,b]
int genera_aleatori(int a, int b)
{
return rand()%(b-a+1)+a;
}
int main ()
{
srand (time(NULL)); //inicialitza la semilla de la generació de nombres aleatoris
cout << "Introduex els extrems a i b: ";
int a, b;
cin >> a >> b;
cout << "Quants nombres aleatoris vols generar?";
int k;
cin >> k;
cout << "Els " << k << " nombres aleatoris son: " << endl;

for (int i=1; i<=k; i++) {
cout << genera_aleatori(a,b)<< ' '; // genera un nombre aleatori en [a,b]
}

}
