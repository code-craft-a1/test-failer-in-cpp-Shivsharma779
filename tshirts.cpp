#include <iostream>
#include <assert.h>

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

    // Valid range tests
    assert(size(37) == 'S');
    assert(size(39) == 'M');
    assert(size(43) == 'L');

    // Boundary edge cases
    assert(size(38) == 'S');  // Function treats <38 as 'S', 38 is not covered -> should return '\0'
    assert(size(42) == 'M');  // Function treats >38 && <42 as 'M', 42 is not covered -> should return '\0'

    // Check unhandled case explicitly
    assert(size(100) == 'L');  // Far end test
    assert(size(0) == 'S');    // Lower limit

    std::cout << "All is well (maybe!)\n";
}