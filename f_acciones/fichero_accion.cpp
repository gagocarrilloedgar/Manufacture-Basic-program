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
	
void omplir_taula(tProducte P[DIM], int N){
	for (int i=0; i< N; i++){
		cout << "Introdueix dades del producte " << i << ':' << endl;
		cout << "Nom producte: ";
		cin.ignore();
		getline(cin,P[i].nom);
		cout << "Nom Fabricant: ";
		getline(cin,P[i].fabricant);
		cout << "Codi producte: ";
		cin>> P[i].codi;}
	}

void escriure_taula(tProducte P[DIM], int N){
	cout << "----------------------------"<<endl;
	cout << "Els productes son: "<< endl;
	cout << "----------------------------"<<endl;
	for (int i=0; i< N; i++){
	cout << "Producte " << i << ':' << endl;
	cout << "Nom producte: " << P[i].nom << endl;;
	cout << "Nom Fabricant: " << P[i].fabricant << endl;
	cout << "Codi producte: " << P[i].codi << endl;
	cout << "----------------------------"<<endl;}
}

void escriure_al_fitxer(ofstream& fsortida,tProducte P[DIM], int N){
//Escrivim la informació els productes que hi ha a la taula al fitxer fsortida
	for (int i=0; i<N; i++){
		fsortida << P[i].nom<<';';//posem el caràcter ; per separar els camps del producte
	fsortida <<P[i].fabricant<<';';
	fsortida <<P[i].codi<<';';}
	
	fsortida.close(); //tanquem el fitxer
}

void llegir_del_fitxer(ifstream& fentrada,tProducte P[DIM], int& N){
	string linia; // el fitxer el llegirem linia a linia
// Recorrem el fitxer: llegim dades d'un producte i guardem a la taula de productes
	if (fentrada.is_open()){
	int i=0; //index de la taula de productes
		while(!fentrada.eof()){
// Llegim tots els camps del producte i guardem a la posició i de la taula
		getline(fentrada,linia,';');
		P[i].nom=linia;
		getline(fentrada,linia,';');
		P[i].fabricant=linia;
		getline(fentrada,linia,';');
		P[i].codi=atoi(linia.c_str());
//Passem a llegir el producte següent
		i++;
		;
//Hem llegit...
		N = i-1; // productes
		}	
	escriure_taula(P, N);
	}
	else{
	cout << "No s'ha pogut llegir del fitxer" << endl;
	}
	}

int main()
{
// Declara una taula de productes que omplirem dins el programa i desarem al fitxer
tProducte Ps[DIM];
cout << "Amb quants productes vols omplir la taula? N=";
int N; // nombre de productes de la taula
cin>>N;
omplir_taula(Ps, N);
// Crea de nou un fitxer ofstream per guardar informació dels productes
ofstream fsortida("productes.txt",ios::app);
//crida de l'acció per escriure al fitxer
escriure_al_fitxer(fsortida, Ps, N);
//Comprovem que tot s'ha escrit correctament al fitxer
//Obrim el fixer, llegim la informació dels productes i l'escrivim a la pantalla
ifstream fentrada("productes.txt");
//crida de l'acció per llegir del fitxer
llegir_del_fitxer(fentrada, Ps, N);}
