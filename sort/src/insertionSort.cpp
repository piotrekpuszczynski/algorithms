#include <insertionSort.hpp>

namespace algorithms {

    template <typename T>
    void insertion_sort(std::vector<T>& arr) {
        for (int i = 1; i < (int) arr.size(); i++) {
            T temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
    }

}

// function allows creation of template functions for arm64 architecture
void empty() {
    std::vector<int> temp;
    algorithms::insertion_sort(temp);
}
