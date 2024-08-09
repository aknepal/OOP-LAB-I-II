#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num3,max,min;
    cout<<"enter three numbers"<<endl;
    cin>>num1>>num2>>num3;
    max=num1;
    if(max<num2){
      max=num2;
    }
    
if(max<num3){
    max=num3;
}
    

    min=num1;
    if(min>num2){
      min=num2;
    }
    
    if(min>num3){
      min=num3;
    }
    
    cout<<"Minimum number is :"<<min<<endl;
    cout<<"maximum number is :"<<max;
    return 0;


}