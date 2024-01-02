#include <iostream>

template <typename T>
int searchKey(const T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  // Return the index if key is found
        }
    }
    return -1;  // Return -1 if key is not found
}

int main() {
    // Example with an integer array
    int intArray[] = {1, 2, 3, 4, 5};
    int intKey = 3;
    int intResult = searchKey(intArray, 5, intKey);
    std::cout << "Integer key found at index: " << intResult << std::endl;

    // Example with a character array
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    char charKey = 'c';
    int charResult = searchKey(charArray, 5, charKey);
    std::cout << "Character key found at index: " << charResult << std::endl;

    // Example with a double array
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleKey = 4.4;
    int doubleResult = searchKey(doubleArray, 5, doubleKey);
    std::cout << "Double key found at index: " << doubleResult << std::endl;

    return 0;
}
