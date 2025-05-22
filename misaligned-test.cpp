#include "misaligned.h"
#include <iostream>
#include <iomanip>
#include <gtest/gtest.h>

void testIndexOf() {
    std::cout << "\nIndex of test\n";
    int count = 0;
    for(int major = 0; major < 5; ++major) {
        for(int minor = 0; minor < 5; ++minor) {
            ++count;
            EXPECT_EQ(indexOf(major, minor), count);
            
        }
    }
    EXPECT_EQ(count, 25);

    EXPECT_EQ(indexOf(-1, 0), -1);
    EXPECT_EQ(indexOf(0, -1), -1);
    EXPECT_EQ(indexOf(5, 0), -1);
    EXPECT_EQ(indexOf(0, 5), -1);
}


// function to test the getColorPairString function
void testGetColorPairString() {
    std::cout << "\nGet color pair string test\n";
    for(int major = 0; major < 5; ++major) {
        for(int minor = 0; minor < 5; ++minor) {
            std::ostringstream expected;
                        expected << " | " << std::left << std::setw(8) << majorColor[major]
                     << " | " << std::left << std::setw(8) << minorColor[minor];
            EXPECT_EQ(getColorPairString(major, minor), expected.str());
        }
    }
}


void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}