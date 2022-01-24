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

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert((size(38) == 'S') || (size(38) == 'M')); 
    assert((size(42) == 'M') || (size(42) == 'L'));
    assert((size(0) != 'S') && (size(0) != 'M') && (size(0) != 'L'));
    assert((size(-10) != 'S') && (size(-10) != 'M') && (size(-10) != 'L'));
    std::cout << "All is well (maybe!)\n";
    return 0;
}
