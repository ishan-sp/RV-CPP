#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 12, 3, 8, 15, 7, 2};
    std::vector<int> lst(vec);
    std::sort(lst.begin(), lst.end());
    std::vector<int> filtered_vec;
    for (int elem : lst) {
        if (elem < 10) {
            filtered_vec.push_back(elem);
        }
    }
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
