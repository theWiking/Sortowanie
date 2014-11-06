#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct tablica{
  string wyrazenie;
  int suma;
};
int sumowanie(string liczby){
  int wyjscie=0;
  for(int i=0;liczby.length()>i;i++)
    wyjscie+=(liczby[i]-48);
    return wyjscie;
  }
int stringNaInt(string liczby){
  int wyjscie=0;
  for(int i=0;liczby.length()>i;i++)
    wyjscie+=(liczby[i]-48)*pow(10,liczby.length()-i-1);
  return wyjscie;
}
bool sortowanie(tablica *doPosortowania,int a){
  tablica bufor;
  bool test=false;
  for(int i=1;a>i;i++){
      if(doPosortowania[i-1].suma<doPosortowania[i].suma){
          test=true;
        continue;
      }
      else if(doPosortowania[i-1].suma>doPosortowania[i].suma){
        bufor=doPosortowania[i-1];
        doPosortowania[i-1]=doPosortowania[i];
        doPosortowania[i]=bufor;
        test=false;
      }
      else if(doPosortowania[i-1].suma==doPosortowania[i].suma){
          for(int ii=1;doPosortowania[i-1].wyrazenie.length()>ii;ii++){
        if((doPosortowania[i-1].wyrazenie[ii-1]-48)>(doPosortowania[i].wyrazenie[ii-1]-48)){
        bufor=doPosortowania[i-1];
        doPosortowania[i-1]=doPosortowania[i];
        doPosortowania[i]=bufor;
        test=false;
        }
        }
      }
  }
  return test;
}
int main(){
  int t;
  bool spr=false;
  string liczby;
  cin>>t;
  tablica *struktura = new tablica[t];
  for(int i=0;t>i;i++){
      cin>>liczby;
      struktura[i].wyrazenie=liczby;
      struktura[i].suma=sumowanie(liczby);
  }
  while(!spr)
    spr=sortowanie(struktura,t);
  for(int i=0;t>i;i++)
    cout<<struktura[i].wyrazenie<<endl;
  delete[] struktura;
return 0;
}
