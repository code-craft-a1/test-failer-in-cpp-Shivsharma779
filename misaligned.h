// misaligned.h

#pragma once
#include <string>

extern const char* majorColor[];
extern const char* minorColor[];

int indexOf(int major, int minor);
std::string getColorPairString(int major, int minor);
int printColorMap();
