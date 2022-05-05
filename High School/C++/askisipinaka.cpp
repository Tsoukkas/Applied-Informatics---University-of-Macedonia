# include <iostream>
using namespace std;
int main (){
int misthos,tmisthos,katigoria;
float rate;
misthos=800;
cout<<"dose katigoria ipalilu:";
cin>>katigoria;
switch (katigoria){
case 1:
   rate=0.10;
   break;
case 2:
   rate=0.20;
   break;
case 3:
   rate=0.30;
   break;
case 4:
   rate=0.40;
   break;
default:
 cout<<"Error:";
 break;
}
tmisthos=800+(800*rate);
cout<<tmisthos;
return 0;
}
