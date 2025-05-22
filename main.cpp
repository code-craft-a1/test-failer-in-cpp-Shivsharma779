#include "tshirts.h"
#include "misaligned.h"
#include <gtest/gtest.h>

int main(int argc, char **argv){
    
    // Tshirt size
    size(10);
    
    printColorMap();

    // tests
#if DEBUG
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
#endif
    return 0;
}