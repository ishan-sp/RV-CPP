#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Creating a vector of integers
    std::vector<int> vec = {5, 12, 3, 8, 15, 7, 2};

    // Copying vector contents into a list
    std::vector<int> lst(vec);

    // Sorting the contents of the list
    std::sort(lst.begin(), lst.end());

    // Copying elements less than 10 into another vector
    std::vector<int> filtered_vec;
    for (int elem : lst) {
        if (elem < 10) {
            filtered_vec.push_back(elem);
        }
    }

    // Printing the results
    std::cout << "Original Vector:";
    for (int elem : vec) {
        std::cout << " " << elem;
    }
    std::cout << "\nSorted List:";
    for (int elem : lst) {
        std::cout << " " << elem;
    }
    std::cout << "\nFiltered Vector (Elements < 10):";
    for (int elem : filtered_vec) {
        std::cout << " " << elem;
    }

    return 0;
}
