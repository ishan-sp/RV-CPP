#include<iostream>
#include<cmath>
using namespace std;
float a;
float b;
float c;
float root1;
float root2;
int main(){
    cout << "ax^2 + bx + c " << endl;
    cout << "Enter a : " << endl;
    cin >> a;
    cout << "Enter b : " << endl;
    cin >> b;
    cout << "Enter c : " << endl;
    cin >> c;

    root1 = (((-1)*b) + sqrt((b*b) - (4*a*c)))/(2*a);
    root2 = (((-1)*b) - sqrt((b*b) - (4*a*c)))/(2*a);

    cout << "First root : " << root1 << endl;
    cout << "Second root : " << root2 << endl;

    return 0;
}