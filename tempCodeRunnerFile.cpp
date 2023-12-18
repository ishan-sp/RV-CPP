#include <iostream>
#include <cmath>

class Shape {
public:
    virtual void readDimensions() = 0;
    virtual void computeArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    float length;
    float breadth;

public:
    void readDimensions() override {
        std::cout << "Enter the length and breadth: ";
        std::cin >> length >> breadth;
    }

    void computeArea() const override {
        std::cout << "Area is " << length * breadth << std::endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    void readDimensions() override {
        std::cout << "Enter the radius: ";
        std::cin >> radius;
    }

    void computeArea() const override {
        std::cout << "Area is " << M_PI * std::pow(radius, 2) << std::endl;
    }
};

int main() {
    Rectangle rectangle;
    rectangle.readDimensions();
    rectangle.computeArea();

    Circle circle;
    circle.readDimensions();
    circle.computeArea();

    return 0;
}

