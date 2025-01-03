#include "hammasync.hpp"
#include <vector>

bool loop = true;

int main(){

    setTimeout([](){
        std::cout << "1\n";
    }, 1000);

    setTimeout([](){
        std::cout << "2\n";
    }, 1000);

    setTimeout([](){
        std::cout << "3\n";
    }, 1000);

    setTimeout([](){
        std::cout << "4\n";
    }, 1000);

    setTimeout([](){
        std::cout << "5\n";
    }, 1000);
    
    setTimeout([](){
        std::vector<int> arr = {10, 20};
        for(const auto& val: arr){
            std::cout << val << "\n";
        }
        std::cout << "\n";
    }, 1000);

    void (*interval)(const std::function<void()>&, int, bool) = setInterval;
    interval([](){
        std::cout << "oi\n";
    }, 1000, loop);

    clearInterval(interval);
    
    
    return 0;
}
