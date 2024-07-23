#include<iostream>
using namespace std;
int main()
{int no;
cout<<"Enter A Number";
cin>>no;

bool prime=true;
if(no<=1){
prime=false;

}

else{
for(int i=2;i*i<=no;i++)
{
if(no%i==0)
{
prime=false;
break;

}

}
}
if(prime)
{
cout<<"Number is Prime Number";
}
else{

cout<<"Number is Not Prime Number";


}
}
