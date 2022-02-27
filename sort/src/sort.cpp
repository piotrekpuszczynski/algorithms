#include <vector>
#include <algorithm>

namespace algorithms {

/* bubble sort */
    template <typename T>
    void bubbleSort(std::vector<T>& arr) {
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

/* merge sort */
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

        while (leftIndex < left.size() && rightIndex < right.size()) {
            if (left[leftIndex] < right[rightIndex]) {
                arr[index] = left[leftIndex];
                leftIndex++;
            } else {
                arr[index] = right[rightIndex];
                rightIndex++;
            }
            index++;
        }

        while (leftIndex < left.size()) {
            arr[index] = left[leftIndex];
            leftIndex++;
            index++;
        }

        while (rightIndex < right.size()) {
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
    void mergeSort(std::vector<T>& arr) {
        splitMerge(arr, 0, arr.size() - 1);
    }

/* counting sort */
    template <typename T>
    void countingSort(std::vector<T>& arr) {
        T max = *max_element(arr.begin(), arr.end()),
                min = *min_element(arr.begin(), arr.end()),
                range = max - min + 1;

        std::vector<int> count(range), result(arr.size());

        for (int i = 0; i < arr.size(); i++)
            count[arr[i] - min]++;

        for (int i = 1; i < count.size(); i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            result[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        for (int i = 0; i < arr.size(); i++)
            arr[i] = result[i];
    }

/* bucket sort */
    template <typename T>
    void bucketSort(std::vector<T>& arr) {
        T max = *max_element(arr.begin(), arr.end()),
                min = *min_element(arr.begin(), arr.end());
        std::vector<std::vector<T>> buckets(arr.size());

        for (const auto& element : arr)
            buckets[floor((element - min) * (arr.size() - 1) / (max - min))].push_back(element);

        for (const auto& bucket : buckets)
            sort(bucket.begin(), bucket.end());

        int i = 0;
        for (const auto& bucket : buckets) {
            for (const auto& element : bucket) {
                arr[i] = element;
                i++;
            }
        }
    }

/* radix sort */
    template <typename T>
    void countingSort(std::vector<T>& arr, int place) {
        std::vector<int> count(20), result(arr.size());

        for (int i = 0; i < arr.size(); i++)
            count[10 + (arr[i] / place) % 10]++;

        for (int i = 1; i < count.size(); i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            result[count[10 + (arr[i] / place) % 10] - 1] = arr[i];
            count[10 + (arr[i] / place) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++)
            arr[i] = result[i];
    }

    template <typename T>
    void radixSort(std::vector<T>& arr) {
        T max = abs(*max_element(arr.begin(), arr.end())),
                min = abs(*min_element(arr.begin(), arr.end()));

        T absMax = max > min ? max : min;

        for (int place = 1; absMax / place > 0; place *= 10)
            countingSort(arr, place);
    }

/* quick sort */
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
    void quickSort(std::vector<T>& arr) {
        splitQuick(arr, 0, arr.size() - 1);
    }
}
