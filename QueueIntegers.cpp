#include <iostream>
#include <queue>

template <typename T>
class MyQueue {
private:
    std::queue<T> elements;

public:
    void insert(T value) {
        elements.push(value);
        std::cout << "Inserted: " << value << std::endl;
    }

    void remove() {
        if (!elements.empty()) {
            std::cout << "Deleted: " << elements.front() << std::endl;
            elements.pop();
        } else {
            std::cout << "Queue is empty. Cannot delete." << std::endl;
        }
    }

    void display() {
        if (!elements.empty()) {
            std::cout << "Queue elements: ";
            std::queue<T> temp = elements;
            while (!temp.empty()) {
                std::cout << temp.front() << " ";
                temp.pop();
            }
            std::cout << std::endl;
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }
};

int main() {
    MyQueue<int> myIntQueue;

    myIntQueue.insert(10);
    myIntQueue.insert(20);
    myIntQueue.display();

    myIntQueue.remove();
    myIntQueue.display();

    myIntQueue.insert(30);
    myIntQueue.display();

    return 0;
}
