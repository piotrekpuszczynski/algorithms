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
