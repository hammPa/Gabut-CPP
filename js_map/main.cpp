#include <iostream>
#include "jsmap.hpp"

int main(){
    
    hamm::array<int, 10> arr;
    arr.push(10);
    arr.push(30);
    arr.push(20);
    arr.push(50);
    arr.push(40);
    arr.pop();



    arr.display();
    arr.forEach([](int e){
        std::cout << e << "\n";
    });
    // arr.sort();
    // arr.display();

    arr.sort([](int a, int b){
        return a - b;
    });

    std::cout << "Sort a - b : ";
    arr.display();

    // arr.sort([](int a, int b){
    //     return b - a;
    // });

    // std::cout << "Sort b - a : ";
    // arr.display();


    hamm::array<int, 10> arr2 = arr.map([](int e){
        return e * 5;
    });

    arr2.display();

    // arr2.at(2);

    return 0;
}
