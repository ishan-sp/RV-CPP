#include <iostream>
using namespace std;

class Base {
private:
    int x;
public:
    Base(int i) : x(i) {}

    // Friend declaration for the derived class
    friend class Derived;
};

class Derived : private Base {
public:
    Derived(int i) : Base(i) {
        // Derived class can access the private member x of Base
        cout << "Derived accessing private member x: " << x << endl;
    }
};

int main() {
    Derived derivedObj(42);
    return 0;
}
