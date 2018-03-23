#include<iostream>
using namespace std;

int main(){
int opc, opc1, opc2;

while(opc!=5){
	cout<<"Menu d'opcions"<< endl;
	cout<<"1.Gestio productes " << endl;
	cout<<"2.Cerca de productes " << endl;
	cout<<"3.Control d'estock" << endl;
	cout<<"4.Persistencia de dades" << endl;
	cout<<"5Sortir " << endl;
	cout<<"Seleccioneu una opcio " << endl;
	cin>>opc;
	switch(opc){
		case 1:
			cout<<" Esteu a Gestio de productes"<< endl;
		while(opc1!=4){
			cout<<"1.Donar d'alta un producte " << endl;
			cout<<"2.Donar de baiza un producte" << endl;
			cout<<"3.Modificar la informacio d'un producte"<< endl;
			cout<<"4.Sortit"<< endl;
			cout<<"Seleccioneu una opcio"<< endl;
			cin>>opc1;
			//switch con las tres opciones
			break;
		}
		
		case 2:
				cout<<" Esteu a Cerca de productes"<< endl;
		while(opc2!=4){
			cout<<"1.Cercar productes per codi de barres " << endl;
			cout<<"2.Cercar productes per nom" << endl;
			cout<<"3.Cercar productes per fabricant"<< endl;
			cout<<"4.Sortit"<< endl;
			cout<<"Seleccioneu una opcio"<< endl;
			cin>>opc2;
			//switch con las tres opciones
			break;
			
	}}
}}
