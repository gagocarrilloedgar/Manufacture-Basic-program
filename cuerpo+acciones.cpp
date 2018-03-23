#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

const int MAX=500;
const int Ms=100;

//taula per definir el temps d'alguna acció
struct ttemps{
	int dia;
	int mes;
	int any;
	int hora;
	int minut;
	int segon;
	
};


struct tPosicio{
		int planta;
		int passadis;
		int seccio;
}; 

//taula per definir tot allo relacionat amb el producte
struct tproducte{
	long long int codi;
	string nom;
	string fabricant;
	int preu;
	int unitats;
	tPosicio pMagatzem;
	ttemps ptemps;
};
//acció per guardar el temps d'alguna acció del programa
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

//Aquesta funció genera un nombre aleatori en [a,b]
int genera_aleatori(int a, int b){
	return rand()%(b-a+1)+a;
}
int EAN (long long  int N){
	if (N<100) {
	return (N%10)*3 + N/10;}
	else {
	return (N%10)*3 + (N%100)/10 + EAN(N/100);
	}
}
int DC(long long int N){
	if (EAN(N)%10==0)
	return 0;
	else {
		
	return (EAN(N)/10)*10+10-EAN(N);
	}
}
//funcio que genera el codi ean 13 del producte
long long int codi_producte(long long int C){
	srand (time(NULL)); //inicialitza la semilla de la generació de nombres aleatoris
	int a, b;
	a=1000;
	b=9999;
	long long int N;
	N=(84*pow(10,8)+(3456*pow(10,3))+(genera_aleatori(a,b)*10));
	C=(N*1000+(EAN(N)*10)+DC(N));
	return C;
	
}
//acció per llegir un procute
void llegir_producte(tproducte &p){
	long long int C;
	struct tm *info_temps;
	int dia, mes,any,hora,minuts,segons;
	cout<<"introdueix el codi(automatic):";
	cout<<codi_producte(C);
	p.codi=codi_producte(C);
	cout<<endl;
	cout<<"introduiu el nom:";
	cin>>p.nom;
	cout<<"introduiu el fabricant:"; cin>>p.fabricant;
	cout<<"introuiu el preu:"; cin>>p.preu;
	cout<<"introduiu el nombre d'unitats (stock):"; cin>>p.unitats;
	cout<<"introduiu la posicio, planta, passadis y seccio:"; cin>>p.pMagatzem.planta>>p.pMagatzem.passadis>>p.pMagatzem.seccio;
	cout<<" Data de registre del producte:"<< endl;
	temps(info_temps, dia, mes,any,hora,minuts,segons);
	p.ptemps.dia=dia;
	cout << "Dia: " << dia << endl;
	p.ptemps.mes=mes;
	cout << "Mes: " << mes << endl;
	p.ptemps.any=any;
	cout << "Any: " << any << endl;
	p.ptemps.hora=hora;
	cout << "Hora: " << hora << endl;
	p.ptemps.minut=minuts;
	cout << "Minuts: " << minuts << endl;
	p.ptemps.segon=segons;
	cout << "Segons: " << segons << endl;
}
//accio que crida a l'acció llegir_producte per a llegir un nombre n de prodcutes
void llegir_productes(tproducte p[MAX], int n){
	long long int C;
	for (int i=0;i<n;i++){
		cout<<"introduiu les dades del producte"<<i<< endl;
		llegir_producte(p[i]);
	}
}
//accio per buscar un producte amb un determinat codi de barres 
void cercar_codi_barres(tproducte p[MAX],long long int Cbarres){
	bool trobat=false;
	for (int i=0;i<MAX && !trobat ;i++){
		if(p[i].codi==Cbarres){
			cout<<" la inforamcio del producte es:"<<endl;
			cout<<"el nom es:"<<p[i].nom<<endl;
			cout<<"el nom del fabricant es :"<<p[i].fabricant<<endl;
			cout<<"el preu per del producte es:"<<p[i].preu<<endl;
			cout<<"el nombre d'unitats es:"<<p[i].unitats<<endl;
			cout<<"La posicio al magatzem es:"<<endl;
			cout<<"planta:"<<p[i].pMagatzem.planta<<","<<"passadis:"<<p[i].pMagatzem.passadis<<","<<"seccio:"<<p[i].pMagatzem.seccio<<endl;
			cout<<"l'hora de registre del producte va ser :"<< endl;
			cout << "Dia: " << p[i].ptemps.dia << endl;
			cout << "Mes: " << p[i].ptemps.mes << endl;
			cout << "Any: " << p[i].ptemps.any << endl;
			cout << "Hora: " << p[i].ptemps.hora << endl;
			cout << "Minuts: " << p[i].ptemps.minut << endl;
			cout << "Segons: " << p[i].ptemps.segon << endl;
			
		}
		else { cout<<"el codi no sha trobat "<< endl; trobat=true;}
		
			}}
//acció per  buscar un producte amb un determinat nom			
void cercar_nom(tproducte p[MAX],string pnom){
	bool trobat=false;
	int i=0;
	while (i<MAX && !trobat){
		if(p[i].nom==pnom){
			cout<<" la inforamcio del producte es:"<<endl;
			cout<<"el codi es:"<<p[i].codi<< endl;
			cout<<"el nom es:"<<p[i].nom<<endl;
			cout<<"el nom del fabricant es :"<<p[i].fabricant<<endl;
			cout<<"el preu per del producte es:"<<p[i].preu<<endl;
			cout<<"el nombre d'unitats es:"<<p[i].unitats<<endl;
			cout<<"La posicio al magatzem es:"<<endl;
			cout<<"planta:"<<p[i].pMagatzem.planta<<","<<"passadis:"<<p[i].pMagatzem.passadis<<","<<"seccio:"<<p[i].pMagatzem.seccio<<endl;
			cout<<"l'hora de registre del producte va ser :"<< endl;
			cout << "Dia: " << p[i].ptemps.dia << endl;
			cout << "Mes: " << p[i].ptemps.mes << endl;
			cout << "Any: " << p[i].ptemps.any << endl;
			cout << "Hora: " << p[i].ptemps.hora << endl;
			cout << "Minuts: " << p[i].ptemps.minut << endl;
			cout << "Segons: " << p[i].ptemps.segon << endl;
			trobat=true;
			}
			else trobat=false;
			i++;}
	if(!trobat){cout<<" el producte no sha trobat"<< endl;
	}
}
//acció per  buscar un producte amb un determinat nom de fabricant	
void cercar_fabricant(tproducte p[MAX],string pfabricant){
	bool trobat=false;
	int i=0;
	while (i<MAX && !trobat){
		if(p[i].fabricant==pfabricant){
			cout<<" la inforamcio del producte es:"<<endl;
			cout<<"el codi es:"<<p[i].codi<< endl;
			cout<<"el nom es:"<<p[i].nom<<endl;
			cout<<"el nom del fabricant es :"<<p[i].fabricant<<endl;
			cout<<"el preu per del producte es:"<<p[i].preu<<endl;
			cout<<"el nombre d'unitats es:"<<p[i].unitats<<endl;
			cout<<"La posicio al magatzem es:"<<endl;
			cout<<"planta:"<<p[i].pMagatzem.planta<<","<<"passadis:"<<p[i].pMagatzem.passadis<<","<<"seccio:"<<p[i].pMagatzem.seccio<<endl;
			cout<<"l'hora de registre del producte va ser :"<< endl;
			cout << "Dia: " << p[i].ptemps.dia << endl;
			cout << "Mes: " << p[i].ptemps.mes << endl;
			cout << "Any: " << p[i].ptemps.any << endl;
			cout << "Hora: " << p[i].ptemps.hora << endl;
			cout << "Minuts: " << p[i].ptemps.minut << endl;
			cout << "Segons: " << p[i].ptemps.segon << endl;
			trobat=true;
			}
			else trobat=false;
			i++;}
	if(!trobat){cout<<" el producte no sha trobat"<< endl;
	}
}
		
// inci del programa principal que engloba els altres subprogrames
int main(){
int opc, opc1, opc2,opc3;
tproducte p[MAX];
string resp,pnom, pfabricant;
long long int Cbarres;

//inci del primer while que engloba les opcions principal del programa
while(opc!=4){
	system("cls");
	cout<<"Menu d'opcions"<< endl;
	cout<<"1.Gestio productes " << endl;
	cout<<"2.Cerca de productes " << endl;
	cout<<"3.Control d'estock" << endl;
	cout<<"4.Sortir " << endl;
	cout<<"Seleccioneu una opcio " << endl;
	cin>>opc;
	switch(opc){
		// inici de la primera opció
		case 1:
			cout<<" Esteu a Gestio de productes"<< endl;
		while(opc1!=4){
			cout<<"1.Donar d'alta un producte " << endl;
			cout<<"2.Donar de baixa un producte" << endl;
			cout<<"3.Modificar la informacio d'un producte"<< endl;
			cout<<"4.Sortit"<< endl;
			cout<<"Seleccioneu una opcio"<< endl;
			cin>>opc1;
			system("cls");
			switch(opc1){
				case 1:
					int n;
					cout<<"Esteu a donar d'alta un producte " << endl;
					cout<<"introdueix el nombre de productes que vols donar d'alta:"; cin>>n;
					llegir_productes(p,n);
					cout<<" els productes shan donat d'alta"<< endl;
					break;
				case 2:
					cout<<" Donar de Baixa un producte"<< endl;
					break;
				case 3:
					cout<< " modificar la informacio d'un producte" << endl;
					break;
				case 4:
					default:;
			}
		}
		break;// finalització de la primera opció 
		
		case 2://inici de la segona opció
				cout<<" Esteu a Cerca de productes"<< endl;
		while(opc2!=4){
			cout<<"1.Cercar productes per codi de barres " << endl;
			cout<<"2.Cercar productes per nom" << endl;
			cout<<"3.Cercar productes per fabricant"<< endl;
			cout<<"4.Sortit"<< endl;
			cout<<"Seleccioneu una opcio"<< endl;
			cin>>opc2;
			system("cls");
			//switch con las tres opciones
			switch(opc2){
				case 1:
					cout<<"Esteu a Cercar productes per codi de barres " << endl;
					cout<<" introduiu el codi de barres"<< endl;
					cin>>Cbarres;
					cercar_codi_barres(p,Cbarres);
					while(resp!="no"){
					cout<<"voleu buscar un altre producte?"<< endl;
					cin>>resp;
					if (resp=="si"){
						cout<<"introduiu codi de barres"<<endl;
						cin>>Cbarres;
						cercar_codi_barres(p,Cbarres);
					}}
					break;
				case 2:
					cout<<"Esteu a cercar productes per nom"<< endl;
					cout<<"Introduiu el nom del producte :"<< endl;
					cin>>pnom;
					cercar_nom(p,pnom);
					while(resp!="no"){
					cout<<"voleu buscar un altre producte?"<< endl;
					cin>>resp;
					if(resp=="si"){
						cout<<"introduiu un altre nom de producte"<< endl;
						cin>>pnom;
						cercar_nom(p,pnom);
					}}
					break;
				
				case 3:
					cout<<"Esteu a cercar productes per fabricant " << endl;
					cout<<"Introduiu el nom del fabricant :"<< endl;
					cin>>pfabricant;
					cercar_fabricant(p,pfabricant);
					while(resp!="no"){
					cout<<"voleu buscar un altre producte?"<< endl;
					cin>>resp;
					if(resp=="si"){
						cout<<"introduiu un altre nom de fabricant"<< endl;
						cin>>pnom;
						cercar_fabricant(p,pfabricant);
					}}
					break;
					break;
				case 4: default:;
					
			}}break;// finalització de la segona opció 
			
			case 3://inici de la tercera opció
				cout <<" esteu a control d'estock; "<<endl;
			while(opc3!=5){
			cout<<"1.Llistat de productes amb un minim stock " << endl;
			cout<<"2.Venta d'un producte" << endl;
			cout<<"3.Comanda de productes amb un minim stock"<< endl;
			cout<<"4.Llistat de  productes de major a menor numero vendes "<< endl;
			cout<<"5.Sortir"<<endl;
			cout<<"Seleccioneu una opcio"<< endl;
			cin>>opc3;
			system("cls");
			switch(opc3){
				case 1:
					cout<<" Esteu a llistat de productes amb un minim stock " << endl;
				break;
				
				case 2:
					cout<<"Esteu a venta d'un producte" << endl;
				break;
				
				case 3:
					cout<<" Esteu a comanda de productes amb un minim stock"<< endl;
				break;
				
				case 4:
					cout<<"Esteu a llistat de  productes de major a menor numero vendes "<< endl;
				break;	
				
				case 5:
					default:;
			}
			}break;// finalització de la tercera opció 
			
			case 4:
				cout <<"El programa ha finalitzat"<< endl;
			default :;
	}
}// finalització del primer while que engloba les 3 opcions principals 
}// fi del main 
