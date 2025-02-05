#include "array.hpp"
#include <iostream>

int main(){

    array<int, 5> arr = {2, 1, 4, 5, 3, 90, 17};
    array<int, 5> arr2;
    arr2.push(90, 70, 80);
    std::cout << "arr.size() : " << arr.size() << "\n";
    std::cout << "arr.max_size() : " << arr.max_size() << "\n";
    std::cout << "arr2.size() : " << arr2.size() << "\n";
    std::cout << "arr2.max_size() : " << arr2.max_size() << "\n\n";

    arr2.reallocate_with_sum_of_element();
    std::cout << "arr2.size() : " << arr2.size() << "\n";
    std::cout << "arr2.max_size() : " << arr2.max_size() << "\n\n";

    std::cout << "arr2. before swap : " << arr2 << "\n";
    arr2.swap(1, 2);
    std::cout << "arr2.swap(1, 2) : " << arr2 << "\n\n";

    std::cout << "arr2.at(index) or arr2[index] : " << arr[2] << " = " << arr.at(2) << '\n';
    std::cout << "arr.front() : " << arr.front() << "\n";
    std::cout << "arr.back() : " << arr.back() << "\n\n";

    std::cout << "arr before change : " << arr << "\n";
    arr.change(1, 100);
    std::cout << "arr after change : " << arr << "\n";
    std::cout << "arr isFull : " << arr.isFull() << "\n";
    std::cout << "arr isEmpty : " << arr.isEmpty() << "\n\n";
    

    std::cout << "arr.find_at_index(2) : " << arr.find_at_index(2) << "\n";
    std::cout << "before arr.delete_at(1) : " << arr << "\n"; 
    arr.delete_at(1);
    std::cout << "arr.delete_at(1) : " << arr << "\n"; 
    std::cout << "arr.find(10) : " << arr.find(10) << "\n\n"; 

    arr2.push(70, 50, 40, 90);
    std::cout << "arr2 : " << arr2 << "\n";
    std::cout << "arr2.max() : " << arr2.max() << "\n";
    std::cout << "arr2.min() : " << arr2.min() << "\n";
    std::cout << "arr2.average() : " << arr2.average() << "\n";
    std::cout << "arr2.median() : " << arr2.median() << "\n";
    std::cout << "arr2.quartile1() : " << arr2.quartile1() << "\n";
    std::cout << "arr2.quartile2() : " << arr2.quartile2() << "\n";
    // std::cout << "arr2.quartile3() : " << arr2.quartile3() << "\n";
    std::cout << "arr2.modus() : " << arr2.mode() << "\n";

    array<int, 5>arr3 = {9, 6, 4, 1, 2};
    std::cout << "arr3 : " << arr3 << "\n";
    arr3.fill(40);
    std::cout << "arr3.fill(40) : " << arr3 << "\n";

    int result = arr3.reduce([](int a, int b){ return a + b; }, 0);
    std::cout << "arr3.reduce() : " << result << "\n";

    std::cout << "arr3.contains(20) : " << arr3.contains(20) << "\n";
    arr3.delete_duplicate();
    std::cout << "arr3.delete_duplicate() : " << arr3 << "\n\n";


    array<int, 5> arr4 = {10, 20, 30, 40};
    array<int, 5> arr5 = {10, 20, 30, 40};

    std::cout << "arr4 == arr5 : " << (arr4 == arr5) << "\n";
    array arr6 = arr4.filter([](int data){ return data > 20; });
    std::cout << "arr6.filter() : " << arr6 << "\n\n";

    std::cout << "arr6.forEach()" << "\n";
    arr6.forEach([](int data){ std::cout << data * 3 << "\n"; });

    array<int, 5> arr7 = {1, 2, 3, 4, 5};
    arr7 = arr7 * 5;
    std::cout << "arr7 : " << arr7 << "\n\n";

    std::cout << "Iterator : \n";
    for(array<int, 5>::Iterator it = arr7.begin(); it != arr7.end(); it++){
        std::cout << *it << "\n";
    }

    return 0;
}
