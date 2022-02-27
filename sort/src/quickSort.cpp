#include <quickSort.hpp>

namespace algorithms {

    template <typename T>
    void swap(std::vector<T>& arr, int a, int b) {
        if (a != b) {
            T temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
    }

    int indexSelection(int begin, int end) {
        return begin + (end - begin) / 2;
    }

    template <typename T>
    int partition(std::vector<T>& arr, int begin, int end) {
        int index = indexSelection(begin, end);
        T value = arr[index];
        swap(arr, index, end);

        int cur = begin;
        for (int i = begin; i < end; i++) {
            if (arr[i] < value) {
                swap(arr, i, cur);
                cur++;
            }
        }

        swap(arr, cur, end);
        return cur;
    }

    template <typename T>
    void splitQuick(std::vector<T>& arr, int begin, int end) {
        if (begin < end) {
            int i = partition(arr, begin, end);
            splitQuick(arr, begin, i - 1);
            splitQuick(arr, i + 1, end);
        }
    }

    template <typename T>
    void quick_sort(std::vector<T>& arr) {
        splitQuick(arr, 0, arr.size() - 1);
    }

}

// function allows creation of template functions for arm64 architecture
void emptyQuick() {
    std::vector<int> temp;
    algorithms::quick_sort(temp);
}
