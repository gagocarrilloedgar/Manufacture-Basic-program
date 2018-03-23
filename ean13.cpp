#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
//Aquesta funció genera un nombre aleatori en [a,b]
int genera_aleatori(int a, int b){
	return rand()%(b-a+1)+a;
	}

int EAN (long long  int N)
{
if (N<100) {
return (N%10)*3 + N/10;
}
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
	
int codi_producte(){
	srand (time(NULL)); //inicialitza la semilla de la generació de nombres aleatoris
	int a, b;
	a=1000;
	b=9999;
	long long int N;
	N=(84*pow(10,8)+(3456*pow(10,3))+(genera_aleatori(a,b)*10));
	cout << "EAN=" << EAN(N) << endl;
	cout << "DC=" << DC(N) << endl;
	long long C;
	C=N*1000+(EAN(N)*10)+DC(N);
	cout << " codigo final " << C <<endl;
	
}

