#include<iostream>
using namespace std;
int num1;
int num2;
int main(){
    cout << "Enter the dividend : ";
    cin >> num1;
    cout << "Enter the divisor : ";
    cin >> num2;
    cout << "The quotient of the two number is  " << num1/num2 << " and the remainder is " << num1%num2;

    return 0;
}