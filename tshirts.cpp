#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms > 0 && cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void verifyShirtSize(int size, char expectedSizeName)
{
    assert(size(size) == expectedSizeName);
}

int main() {
    verifyShirtSizet(37, 'S');
    verifyShirtSize(40, 'M');
    verifyShirtSize(43, 'L');
    verifyShirtSize(38, 'S'); 
    verifyShirtSize(42, 'M');
    verifyShirtSize(0, '\0');
    verifyShirtSize(-10, '\0');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
