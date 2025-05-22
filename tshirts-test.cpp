#include <gtest/gtest.h>
#include "tshirts.h"
void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    EXPECT_EQ(size(37), 'S');
    EXPECT_EQ(size(39), 'M');
    EXPECT_EQ(size(43), 'L');
    EXPECT_EQ(size(38), 'S');
    EXPECT_EQ(size(42), 'M');
    EXPECT_EQ(size(100), 'L');
    EXPECT_EQ(size(0), 'S');
    std::cout << "All is well (maybe!)\n";
}