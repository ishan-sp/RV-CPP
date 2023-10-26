#include<iostream>
#include<climits>
using namespace std;
int num;
int maxnum = INT_MIN;
int minnum = INT_MAX;

int main() {
    for (int i = 1; i <= 3; i++) {
        cout << "Enter the number : ";
        cin >> num;

        if (num > maxnum) { 
            maxnum = num;
        }

        if (num < minnum) {
            minnum = num;
        }
    }
    
    cout << "Maximum number: " << maxnum << endl;
    cout << "Minimum number: " << minnum << endl;

    return 0;
}