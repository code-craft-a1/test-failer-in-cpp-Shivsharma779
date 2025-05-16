#include "gtest/gtest.h"

void testTshirtSize();
void testPrintColorMap();
void testWeatherReport();
void testIndexOf();
void testGetColorPairString();

TEST(TShirt, Size) {
    testTshirtSize();
}

TEST(ColorMap, Print) {
    testPrintColorMap();
}

TEST(ColorMap, Index) {
    testIndexOf();
}

TEST(ColorMap, GetColorPairString) {
    testGetColorPairString();
}

TEST(WeatherReport, Report) {
    testWeatherReport();
}
