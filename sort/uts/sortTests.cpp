#include <insertionSort.hpp>
#include <gtest/gtest.h>

TEST(sortTest, emptyVector) {
    auto vector = std::vector<int>{};
    std::vector<int> expected{};

    algorithms::insertion_sort(vector);

    EXPECT_EQ(vector, expected);
}

TEST(sortTest, sortedVector) {
    auto vector = std::vector<int>{1, 2, 3};
    std::vector<int> expected{1, 2, 3};

    algorithms::insertion_sort(vector);

    EXPECT_EQ(vector, expected);
}

TEST(sortTest, unsortedVector) {
    auto vector = std::vector<int>{3, 2, 1};
    std::vector<int> expected{1, 2, 3};

    algorithms::insertion_sort(vector);

    EXPECT_EQ(vector, expected);
}

TEST(sortTest, partlySortedVector) {
    auto vector = std::vector<int>{2, 1, 3};
    std::vector<int> expected{1, 2, 3};

    algorithms::insertion_sort(vector);

    EXPECT_EQ(vector, expected);
}
