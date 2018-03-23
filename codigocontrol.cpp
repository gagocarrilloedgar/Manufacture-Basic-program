#include <iostream>
#include <math.h>
using namespace std;
//Funcions recursives…per una versió iterativa vegeu el llibre de problems resolts
int EAN (long int N)
{
if (N<100) {
return (N%10)*3 + N/10;
}
else {
return (N%10)*3 + (N%100)/10 + EAN(N/100);
}
}
int DC(int long N)
{
if (EAN(N)%10==0)
return 0;
else {
return (EAN(N)/10)*10+10-EAN(N);
}
}
int main () {
cout << "Introdueix un nombre enter de 12 digits: ";
long int N;
N=(480000000000+3456700000+35678);
cout << "EAN=" << EAN(N) << endl;
cout << "DC=" << DC(N) << endl;
return 0;
}

