#include <gtest/gtest.h>

#include <insertionSort.hpp>
#include <bubbleSort.hpp>
#include <mergeSort.hpp>
#include <countingSort.hpp>
#include <bucketSort.hpp>
#include <quickSort.hpp>
#include <radixSort.hpp>

typedef void (*fun) (std::vector<int>&);

class sortParameterizedTest : public ::testing::TestWithParam<fun> {
protected:
    fun f{};
};

TEST_P(sortParameterizedTest, emptyVector) {
    auto vector = std::vector<int>{};
    std::vector<int> expected{};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, oneElementVector) {
    auto vector = std::vector<int>{1};
    std::vector<int> expected{1};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, sortedNotEvenLengthVector) {
    auto vector = std::vector<int>{1, 2, 3};
    std::vector<int> expected{1, 2, 3};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, reverseSortedNotEvenLengthVector) {
    auto vector = std::vector<int>{3, 2, 1};
    std::vector<int> expected{1, 2, 3};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, unsortedNotEvenLengthVector) {
    auto vector = std::vector<int>{2, 1, 3};
    std::vector<int> expected{1, 2, 3};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, sortedEvenLengthVector) {
    auto vector = std::vector<int>{1, 2, 3, 4};
    std::vector<int> expected{1, 2, 3, 4};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, reverseSortedEvenLengthVector) {
    auto vector = std::vector<int>{4, 3, 2, 1};
    std::vector<int> expected{1, 2, 3, 4};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

TEST_P(sortParameterizedTest, unsortedEvenLengthVector) {
    auto vector = std::vector<int>{2, 4, 1, 3};
    std::vector<int> expected{1, 2, 3, 4};

    GetParam()(vector);

    EXPECT_EQ(vector, expected);
}

INSTANTIATE_TEST_SUITE_P(sortTest,
                        sortParameterizedTest,
                        ::testing::Values(
                                (fun) algorithms::insertion_sort,
                                (fun) algorithms::bubble_sort,
                                (fun) algorithms::merge_sort,
                                (fun) algorithms::counting_sort,
                                (fun) algorithms::bucket_sort,
                                (fun) algorithms::radix_sort,
                                (fun) algorithms::quick_sort
                                ));
