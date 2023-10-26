#include<iostream>
using namespace std;
int num;
int main(){
    cout << "Enter the number ";
    cin >> num;
    if (num%2 == 0) {
        cout << "The number is even";
    }
    else {
        cout << "The number is odd";
    }

    return 0;
}