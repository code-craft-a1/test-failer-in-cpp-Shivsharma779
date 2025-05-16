#include <iostream>
#include <gtest/gtest.h>
char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

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