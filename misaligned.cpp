#include <iostream>
#include <sstream>
#include <iomanip>


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int indexOf(int major, int minor) {
    if(major < 0 || major > 4 || minor < 0 || minor > 4) {
        return -1;
    }
    return major * 5 + minor + 1;
}

std::string getColorPairString(int major, int minor) {
    std::ostringstream oss;
    oss << " | " << std::left << std::setw(8) << majorColor[major] << " | " << std::left << std::setw(8) << minorColor[minor];
    return oss.str();
}

int printColorMap() {
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout <<  std::setw(2) << indexOf(i,j) << getColorPairString(i,j) << "\n";
        }
    }
    return i * j;
}


