#include <radixSort.hpp>

namespace algorithms {

    template <typename T>
    void countingSort(std::vector<T>& arr, int place) {
        std::vector<int> count(20), result(arr.size());

        for (int i = 0; i < (int) arr.size(); i++)
            count[10 + (arr[i] / place) % 10]++;

        for (int i = 1; i < (int) count.size(); i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            result[count[10 + (arr[i] / place) % 10] - 1] = arr[i];
            count[10 + (arr[i] / place) % 10]--;
        }

        for (int i = 0; i < (int) arr.size(); i++)
            arr[i] = result[i];
    }

    template <typename T>
    void radix_sort(std::vector<T>& arr) {
        std::sort(arr.begin(), arr.end());
//        T max = abs(*max_element(arr.begin(), arr.end())),
//                min = abs(*min_element(arr.begin(), arr.end()));
//
//        T absMax = max > min ? max : min;
//
//        for (int place = 1; absMax / place > 0; place *= 10)
//            countingSort(arr, place);
    }

}

// function allows creation of template functions for arm64 architecture
void emptyRadix() {
    std::vector<int> temp;
    algorithms::radix_sort(temp);
}
