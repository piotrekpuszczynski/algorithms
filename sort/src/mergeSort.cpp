#include <mergeSort.hpp>

namespace algorithms {

    template <typename T>
    void merge(std::vector<T>& arr, int begin, int mid, int end) {

        std::vector<T> left, right;

        for (int i = begin; i < mid + 1; i++)
            left.push_back(arr[i]);
        for (int i = mid + 1; i < end + 1; i++)
            right.push_back(arr[i]);

        int leftIndex = 0,
                rightIndex = 0,
                index = begin;

        while (leftIndex < (int) left.size() && rightIndex < (int) right.size()) {
            if (left[leftIndex] < right[rightIndex]) {
                arr[index] = left[leftIndex];
                leftIndex++;
            } else {
                arr[index] = right[rightIndex];
                rightIndex++;
            }
            index++;
        }

        while (leftIndex < (int) left.size()) {
            arr[index] = left[leftIndex];
            leftIndex++;
            index++;
        }

        while (rightIndex < (int) right.size()) {
            arr[index] = right[rightIndex];
            rightIndex++;
            index++;
        }
    }

    template <typename T>
    void splitMerge(std::vector<T>& arr, int begin, int end) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        splitMerge(arr, begin, mid);
        splitMerge(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }

    template <typename T>
    void merge_sort(std::vector<T>& arr) {
        splitMerge(arr, 0, arr.size() - 1);
    }

}

// function allows creation of template functions for arm64 architecture
void emptyMerge() {
    std::vector<int> temp;
    algorithms::merge_sort(temp);
}
