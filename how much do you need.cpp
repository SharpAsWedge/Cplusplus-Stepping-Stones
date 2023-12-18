#include <iostream>
using namespace std;

int main(){
    int bal,choice,time,day=1,year=0;
    float inte,amt,intr;

    cout<<"Do you want balance by interest(1) or interest by balance(2)?"<<endl;
    cin>>choice;
    
    cout<<"Daily(1) or yearly(2)?"<<endl;
    cin>>time;

    cout<<"What is the rate of interest?"<<endl;
    cin>>intr;
    intr/=100;

    //okay there's going to be a few ternary operators and questionable conditioning in the code below
    //But I'm assuming a 100% rational user is using this program and not the average user.
    //That is why there were no checks on whether choice is actually either 1 or 2.. or not.

    if (choice-1){
    // I wonder why I put the daily option here in this choice. It doesn't make sense much, but here it goes
    // Remember, it's a feature and not a bug ;)
        cout<<"How many "<<((time-1)?"years":"days")<<" to keep the money for?"<<endl;
        if(time-1)
            cin>>year;
        else
            cin>>day;
        
        cout<<"What is the intial balance in the account?"<<endl;
        cin>>bal;

        int nbal=bal;
        while(day>0 || year>0){
        inte=(time-1)?nbal*intr:nbal*intr/365;
        amt=nbal+inte;
        nbal=amt;
        if(day>0) day--;
        if(year>0) year--;
        }

        cout<<"The total interest after chosen time: "<<(nbal-bal)<<" and total balance after that time: "<<nbal<<endl;
    }

    else {

        cout<<"Enter the expected interest: "<<endl;
        cin>>inte;

        bal=inte/intr;
        bal*=(time-1)?1:365;

        cout<<"The needed balance is: "<<bal<<endl;
    }

    return 0;
}