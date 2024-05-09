#include "hammdynamicarray.hpp"
using namespace std;
using namespace std::hamm;

int main() {
    DynamicArray array = DynamicArray(10, true, 'c');
    array.display();

    array.push(20);
    array.display();

    array.push(false, 'h', 'b', 'q', 100);
    array.display();

    DynamicArray array2[2] = {DynamicArray(10,'z'), DynamicArray(30, 10.7)};
    for(int i = 0; i < 2; i++){
        array2[i].display();
    }

    return 0;
}
