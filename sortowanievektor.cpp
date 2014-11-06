#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct tablica{
  string wyrazenie;
  int suma;
  tablica(string w,int s){
  wyrazenie=w;
  suma=s;
  }
  tablica(){
  }
};
struct bufor{
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

int main(){
  int t;
  bool spr=false;
  string liczby;
  cin>>t;
  vector <tablica> struktura;

  bufor bufor;
  for(int i=0;t>i;i++){
      cin>>liczby;
      struktura.push_back(tablica(liczby,sumowanie(liczby)));

  }
  for(int i=0;t>i;i++)
    cout<<struktura[i].wyrazenie<<endl;
  while(!spr)
    for(int i=1;t>i;i++){
      bufor.wyrazenie=struktura[i-1].wyrazenie;
      bufor.suma=struktura[i-1].suma;
      if(struktura[i-1].suma<struktura[i].suma){
          spr=true;
       // continue;
      }
      else if(struktura[i-1].suma>struktura[i].suma){
        struktura.insert(struktura.begin() + (i-1),struktura[i]);
       // struktura[i].wyrazenie=bufor.wyrazenie;
      //  struktura[i].suma=bufor.suma;
        spr=false;
      }
      else if(struktura[i-1].suma==struktura[i].suma){
          for(int ii=1;struktura[i-1].wyrazenie.length()>ii;ii++){
        if((struktura[i-1].wyrazenie[ii-1]-48)>(struktura[i].wyrazenie[ii-1]-48)){
          struktura.insert(struktura.begin() + (i-1),struktura[i]);
       //   struktura[i].wyrazenie=bufor.wyrazenie;
       //   struktura[i].suma=bufor.suma;
        spr=false;
        }
        }
      }
  }
  for(int i=0;t>i;i++)
    cout<<struktura[i].wyrazenie<<":"<<struktura[i].suma<<endl;

return 0;
}
