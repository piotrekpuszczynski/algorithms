#include <countingSort.hpp>

namespace algorithms {

    template <typename T>
    void counting_sort(std::vector<T>& arr) {
        if (arr.size() == 0) return;
        T max = *max_element(arr.begin(), arr.end()),
        min = *min_element(arr.begin(), arr.end()),
        range = max - min + 1;

        std::vector<int> count(range), result(arr.size());

        for (int i = 0; i < (int) arr.size(); i++)
            count[arr[i] - min]++;

        for (int i = 1; i < (int) count.size(); i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            result[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        for (int i = 0; i < (int) arr.size(); i++)
            arr[i] = result[i];
    }

}

// function allows creation of template functions for arm64 architecture
void emptyCounting() {
    std::vector<int> temp;
    algorithms::counting_sort(temp);
}