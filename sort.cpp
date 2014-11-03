#include <iostream>
#include <string>
#include <cmath>
using namespace std;
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
bool sortowanie(int doPosortowania[1000][2],int a){
  int bufor[2]={0};
  bool test=true;
  for(int i=1;a>i;i++){
      if(doPosortowania[i-1][1]>doPosortowania[i][1]){
        bufor[0]=doPosortowania[i-1][0];
        bufor[1]=doPosortowania[i-1][1];
        doPosortowania[i-1][0]=doPosortowania[i][0];
        doPosortowania[i-1][1]=doPosortowania[i][1];
        doPosortowania[i][0]=bufor[0];
        doPosortowania[i][1]=bufor[1];
        test=false;
      }
      else if(doPosortowania[i-1][1]==doPosortowania[i][1]){
        if(doPosortowania[i-1][0]>doPosortowania[i][0]){
        bufor[0]=doPosortowania[i-1][0];
        bufor[1]=doPosortowania[i-1][1];
        doPosortowania[i-1][0]=doPosortowania[i][0];
        doPosortowania[i-1][1]=doPosortowania[i][1];
        doPosortowania[i][0]=bufor[0];
        doPosortowania[i][1]=bufor[1];
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
struct tablica{
string wyrazenie;
int suma;
};
int main(){
  int t,a=0;
  cin>>t;
  string liczby;
  int doPosortowania[1000][2]={0};
  for(int i=0;t>i;i++){
      cin>>liczby;
      doPosortowania[i][0]=stringNaInt(liczby);
      doPosortowania[i][1]=sumowanie(liczby);
      a++;
  }
  for(int i=0;t>i;i++){
    cout<<doPosortowania[i][0]<<" suma "<<doPosortowania[i][1]<<endl;
  }
  bool spr=false;
  while(!spr){
  spr=sortowanie(doPosortowania,a);
  }
  cout<<endl;
    for(int i=0;t>i;i++){
    cout<<doPosortowania[i][0]<<endl;
  }
return 0;
}
