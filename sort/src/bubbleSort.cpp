#include <bubbleSort.hpp>

namespace algorithms {

    template <typename T>
    void bubble_sort(std::vector<T>& arr) {
        int n = arr.size();
        do {
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    T temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            n--;
        } while (n > 1);
    }

}

// function allows creation of template functions for arm64 architecture
void empty_bubble() {
    std::vector<int> temp;
    algorithms::bubble_sort(temp);
}
