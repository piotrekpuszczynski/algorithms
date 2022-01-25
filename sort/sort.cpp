/* insertion sort */
template <typename T>
void insertionSort(std::vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

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
void split(std::vector<T>& arr, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    split(arr, begin, mid);
    split(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

template <typename T>
void mergeSort(std::vector<T>& arr) {
    split(arr, 0, arr.size() - 1);
}

/* counting sort */
template <typename T>
void countingSort(std::vector<T>& arr) {
    T max = *max_element(arr.begin(), arr.end()),
      min = *min_element(arr.begin(), arr.end()),
      range = max - min + 1;

    std::vector<long long> count(range), result(arr.size());

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

    for (auto& element : arr)
        buckets[floor((element - min) * (arr.size() - 1) / (max - min))].push_back(element);

    for (auto& bucket : buckets)
        sort(bucket.begin(), bucket.end());

    int i = 0;
    for (auto& bucket : buckets) {
        for (auto& element : bucket) {
            arr[i] = element;
            i++;
        }
    }
}

/* radix sort */
template <typename T>
void countingSort(std::vector<T>& arr, int place) {
    std::vector<long long> count(21), result(arr.size());

    for (int i = 0; i < arr.size(); i++)
        count[10 + (arr[i] / place % 10)]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        result[count[10 + (arr[i] / place % 10)] - 1] = arr[i];
        count[10 + (arr[i] / place % 10)]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = result[i];
}

template <typename T>
void radixSort(std::vector<T>& arr) {
    T max = *max_element(arr.begin(), arr.end());

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, place);
}
