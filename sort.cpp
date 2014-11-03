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
bool sortowanie(tablica doPosortowania[1000],int a){
  tablica bufor;
  bool test=true;
  for(int i=1;a>i;i++){
      if(doPosortowania[i-1].suma>doPosortowania[i].suma){
        bufor.wyrazenie=doPosortowania[i-1].wyrazenie;
        bufor.suma=doPosortowania[i-1].suma;
        doPosortowania[i-1].wyrazenie=doPosortowania[i].wyrazenie;
        doPosortowania[i-1].suma=doPosortowania[i].suma;
        doPosortowania[i].wyrazenie=bufor.wyrazenie;
        doPosortowania[i].suma=bufor.suma;
        test=false;
      }
      else if(doPosortowania[i-1].suma==doPosortowania[i].suma){
          for(int ii=0;doPosortowania[i-1].wyrazenie.length()>ii;ii++)
        if(doPosortowania[i-1].wyrazenie[ii]>doPosortowania[i].wyrazenie[ii]){
        bufor.wyrazenie=doPosortowania[i-1].wyrazenie;
        bufor.suma=doPosortowania[i-1].suma;
        doPosortowania[i-1].wyrazenie=doPosortowania[i].wyrazenie;
        doPosortowania[i-1].suma=doPosortowania[i].suma;
        doPosortowania[i].wyrazenie=bufor.wyrazenie;
        doPosortowania[i].suma=bufor.suma;
        test=false;
        }
      }
  }
  return test;
}/*
bool sprawdzenie(int tab[1000][2],int a){
  for(int i=1;a>i;i++)
  if(tab[i-1][1]<=tab[i][1]&&tab[i-1][0]<tab[i][0]){
    if(i==a)
      return true;
  }
  else
    if(i==a)
    return false;

}*/

int main(){
  int t,a=0;
  cin>>t;
  string liczby;
  tablica struktura[1000];
  int doPosortowania[1000][2]={0};
  for(int i=0;t>i;i++){
      cin>>liczby;
      struktura[i].wyrazenie=liczby;
      struktura[i].suma=sumowanie(liczby);
      a++;
  }
  for(int i=0;t>i;i++){
    cout<<struktura[i].wyrazenie<<" suma "<<struktura[i].suma<<endl;
  }
  bool spr=false;

  while(!spr){
  spr=sortowanie(struktura,a);
  }
  cout<<endl;
    for(int i=0;t>i;i++){
    cout<<struktura[i].wyrazenie<<endl;
  }
return 0;
}
