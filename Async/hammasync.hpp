#define hammasync
#ifdef hammasync

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <functional>

void setTimeout(const std::function<void()>& func, int milisecond){
    std::chrono::milliseconds delay = std::chrono::milliseconds(milisecond);
    std::this_thread::sleep_for(delay);
    std::future<void> result = std::async(std::launch::async, func);
    result.get();
}

void setInterval(const std::function<void()>& func, int milisecond, bool loop = true){
    while(loop){
        std::chrono::milliseconds delay = std::chrono::milliseconds(milisecond);
        std::this_thread::sleep_for(delay);
        std::future<void> result = std::async(std::launch::async, func);
        result.get();
    }
}

void clearInterval(void (*interval)(const std::function<void()>&, int, bool)){
    bool loop = true;
    interval([](){
        std::cout << "Hello from interval!\n";
    }, 1000, loop);

    // Setelah 3 detik, hentikan interval
    std::this_thread::sleep_for(std::chrono::seconds(3));
    loop = false; // Menghentikan interval dari dalam fungsi
    std::cout << "Interval stopped from within the function!\n";
}

#endif
