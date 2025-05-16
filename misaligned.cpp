#include <iostream>
#include <gtest/gtest.h>
#include <sstream>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int indexOf(int major, int minor) {
    if(major < 0 || major > 4 || minor < 0 || minor > 4) {
        return -1;
    }
    return major * 5 + minor;
}

std::string getColorPairString(int major, int minor) {
    std::ostringstream oss;
    oss << " | " << majorColor[major] << " | " << minorColor[major];
    return oss.str();
}

int printColorMap() {
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << indexOf(i,j) << getColorPairString(i,i) << "\n";
        }
    }
    return i * j;
}



void testIndexOf() {
    std::cout << "\nIndex of test\n";
    int count = 1;
    for(int major = 0; major < 5; ++major) {
        for(int minor = 0; minor < 5; ++minor) {
            EXPECT_EQ(indexOf(major, minor), count);
            ++count;
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
            expected << " | " << majorColor[major] << " | " << minorColor[minor];
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