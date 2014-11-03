#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int sumowanie(string liczby){
  int wyjscie=0;
  for(int i=0;liczby.length()>i;i++)
    wyjscie+=liczby[i];
    return wyjscie;
  }
int stringNaInt(string liczby){
  int wyjscie=0;
  for(int i=0;liczby.length()>i;i++)
    wyjscie+=liczby[i]*pow(10,liczby.length()-i);
  return wyjscie;
}
int main(){
  int t;
  cin>>t;
  string liczby;
  int doPosortowania[1000][2];
  for(int i=0;t>i;i++){
      cin>>liczby;
      cout<<liczby[0]*10+liczby[1]<<endl;
      doPosortowania[i][0]=stringNaInt(liczby);
      doPosortowania[i][1]=sumowanie(liczby);
  }
  for(int i=0;t>i;i++){
    cout<<doPosortowania[i][0]<<" suma "<<doPosortowania[i][1]<<endl;
  }
return 0;
}
