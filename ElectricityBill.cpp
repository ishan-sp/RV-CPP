#include<iostream>
#include <string>
using namespace std;
string user_name;
float units;
float cost = 50.00;
int main() {
    cout << "Enter name : ";
    cin >> user_name;
    cout << "Enter the number of units consumed : ";
    cin >> units;
    if (units <= 100) {
        cost += units*1.50;
    }
    else if (units <= 200) {
        cost += units*1.80;
    }
    else {
        cost += units*2.50;
    }
    
    if (cost > 300) {
        cost += 0.15*cost;
    }

    cout << "The total cost for " << user_name << " is " << cost;
    return 0;

}