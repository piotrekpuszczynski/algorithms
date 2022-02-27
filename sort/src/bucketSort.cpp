#include <bucketSort.hpp>
#include <cmath>
#include <algorithm>

namespace algorithms {

    template <typename T>
    void bucket_sort(std::vector<T>& arr) {
        std::sort(arr.begin(), arr.end());
//        T max = *max_element(arr.begin(), arr.end()),
//        min = *min_element(arr.begin(), arr.end());
//
//        std::vector<std::vector<T>> buckets(arr.size());
//
//        for (const auto& element : arr)
//            buckets[floor((element - min) * (arr.size() - 1) / (max - min))].push_back(element);
//
//        for (const auto& bucket : buckets)
//            std::sort(bucket.begin(), bucket.end());
//
//        int i = 0;
//        for (const auto& bucket : buckets) {
//            for (const auto& element : bucket) {
//                arr[i] = element;
//                i++;
//            }
//        }
    }

}

// function allows creation of template functions for arm64 architecture
void emptyBucket() {
    std::vector<int> temp;
    algorithms::bucket_sort(temp);
}
