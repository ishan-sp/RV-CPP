#include<iostream>
#include<cmath>
using namespace std;


class Shape {
    public:
        virtual void readDimensions() = 0;
        virtual void computeArea() = 0;
};

class Rectangle : public Shape {
    private:
        float length;
        float breadth;

    public:
        Rectangle(float l, float b) : length{l}, breadth{b} {};
        Rectangle() {};
        void readDimensions() override {
            cout << "Enter the length and breadth: ";
            cin >> length >> breadth;
        }
        void computeArea() override {
            cout << "Area is " << length*breadth << endl;
        }
};

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle(float r) : radius{r} {};
        Circle() {};
        void readDimensions() override {
            cout << "Enter the radius : ";
            cin >> radius;
        }
        void computeArea() override {
            cout << "Area is " << M_PI*pow(radius, 2) << endl;
        }
};

class Square : public Shape {
    private:
        float side; 
    public:
        Square(float s) : side{s} {};
        Square() {}
        void readDimensions() override {
            cout << "Enter the length of the side : ";
            cin >> side;
        }
        void computeArea() override {
            cout << "Area is " << pow(side,2) << endl;
        }
};
int main() {
    Circle c1;
    c1.readDimensions();
    c1.computeArea();
    Rectangle r1(3,4);
    r1.computeArea();
    Square s1;
    s1.readDimensions();
    s1.computeArea();
    return 0;
}