# include <iostream>
using namespace std;
int main(){
int code , qty ;
float price,total;
cout<<"code=";
cin>> code ;
cout<<"qty";
cin>> qty ;
switch (code){
    case 1 :
    price=4;
    break;
    case 2:
price=4.50;
break;
case 3 :
price=5;
break;
case 4:
price= 2 ;
break;
case 5 :
price=1.50;
break;
total=qty*price;
cout<<total;
}
return 0;
}
