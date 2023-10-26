#include<iostream>
using namespace std;
int num1;
int num2;
int temp;
int main(){
    cout << "Enter the first number ";
    cin >> num1;
    cout << "Enter the second numbers ";
    cin >> num2;
    
    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "The first number after swapping is : " << num1 << endl;
    cout << "The second number after swapping is : " << num2 ;

    return 0;
}