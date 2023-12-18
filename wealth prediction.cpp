#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int princ,cont;
    double tim,intr,inc,amt,tot=0;

    cout<<"Enter the intial investment: "<<endl;
    cin>>princ;

    cout<<"Enter the contribution each year: "<<endl;
    cin>>cont;

    cout<<"Enter the interest rate: "<<endl;
    cin>>intr;

    cout<<"Rate of increase of pay: "<<endl;
    cin>>inc;

    cout<<"Enter the wanted amount: "<<endl;
    cin>>amt;

    // Just derived a formula straight out of Compound Interest. Since there was no loop here, not much time is wasted.
    tim=(log(amt)-log(princ))/log(1+0.01*intr);
    cout<<endl<<"The number of years taken to reach the amount with intial investment: "<<tim<<endl;
    
    /*
    This part was the initial code I used to calculate the number of years it would take to reach the wanted amount.
    But why should I put two loops in my code when the other loop is already iterating for every possible configuration.
    There is possibly a neater and less time-complex method to do it but I'll leave it at this for now.

    tim=0;
    tot=princ;
    while(tot<amt){
        tot=tot*(1+0.01*intr)+cont;
        cont*=(1+0.01*inc);
        tim++;

    }
    cout<<endl<<"The number of years taken to reach the amount with contributions too: "<<tim<<endl<<endl;
    */

   //Basic maths: calculate amount from principal for each year rather than using math functions so it can be accumulated
   //The contributions are adjusted with each year in line 49, depending on the increase in pay.
    tot=princ;
    int flag=0;
    for(tim=1;tim<=100;tim++){
        tot=tot*(1+0.01*intr)+cont;
        cont*=(1+0.01*inc);

    if(flag==0){
    if (tot>=amt){
    cout<<endl<<"The number of years taken to reach the amount with contributions too: "<<tim<<endl<<endl;
    flag=1;
    }
    }

    if (tim<10 || ((int)tim%10)==0)
            cout<<"The amount of money in "<<tim<<" years will be : "<<(int)tot<<endl;
    }

    return 0;
}