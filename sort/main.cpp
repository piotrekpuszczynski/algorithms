#include <iostream>
#include <random>
#include "sort.cpp"

template <typename T>
void printArray(std::vector<T> arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

std::vector<int> genVector(int n) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> number(-100, 100);

    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(number(rng));
    }
    return arr;
}

typedef void (*fun) (std::vector<int>&);

int main(int argc, char** argv) {
    fun functions[] = {insertionSort, bubbleSort, mergeSort};
    auto array = genVector(10);
    for(fun f : functions) {
        auto arr = array;
        f(arr);
        printArray<int>(arr);
    }

    return 0;
}
