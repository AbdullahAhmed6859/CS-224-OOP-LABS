#include<iostream>
#include "Area.h"
using namespace std;

int main(){
    double ft1, ft2, in1, in2;
    cin>>ft1>>in1>>ft2>>in2;
    Area area1 = {{ft1, in1}, {ft2,in2}};

    double decimalArea = area1; // overload the double operator to convert area object into decimal value.
    cout<<"Area is: "<< decimalArea <<"sq feet"<<endl;

}