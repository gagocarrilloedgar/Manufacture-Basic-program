#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

const int DIM=5;
struct tProducte {
string nom;
string fabricant;
int codi;
};
int main()
{
tProducte Ps[DIM]; // Declara una taula per guardar els productes que llegirem des del fitxer
int N; // nombre de productes que acabarem llegin des del fitxer en el disc
string linia; // el fitxer el llegirem linia a linia
// Crea/obre un fitxer ifstream que es correpon amb el fitxer en el disc
// Canvieu la ruta per la del vostre programa. Si utilitzeu DevC++ simplement no poseu cap ruta!
ifstream fitxer_productes("C:/Users/edgar/Desktop/Aeros 15-16/Informática/proyecto/productes.txt");
// Recorrem el fitxer: llegim dades d'un producte i guardem a la taula de productes
if (fitxer_productes.is_open())
{
int i=0; //index de la taula de productes
while(!fitxer_productes.eof()){
// Llegim tots els camps del producte i guardem a la posició i de la taula
getline(fitxer_productes,linia,';');
Ps[i].nom=linia;
getline(fitxer_productes,linia,';');
Ps[i].fabricant=linia;
getline(fitxer_productes,linia,';');
Ps[i].codi=atoi(linia.c_str()); //s’utilitza la funció atoi de la llibreria stdlib per
//convertir un string en enter
//Passem a llegir el producte següent
i++;
}
//Hem llegit...
N = i-1; // productes
cout << "S'han llegit N=" << N <<" productes"<<endl;
fitxer_productes.close(); //tanquem el fitxer
//Comprovem que tot s'ha llegit correctament del fitxer i s'ha guardat correctament a la taula
for (int i=0; i<N; i++) {
cout << "Producte " << i << ':' << endl;
cout << "Nom producte: " << Ps[i].nom << endl;
cout << "Nom Fabricant: "<< Ps[i].fabricant << endl;
cout << "Codi producte: " << Ps[i].codi << endl;
}
}
else{
cout << "Fitxer no obert!" << endl;
}
}
