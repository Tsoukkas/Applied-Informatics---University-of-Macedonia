# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
int main(){
   int N;
   float Riza;
   cout<<"N=";
   cin>>N;
   if(N>=0) {
   Riza= sqrt(N);
   cout<<"Riza="<<fixed<<setprecision(2)<<Riza;
   }
   else
   cout<<"Error";
return 0;
}
