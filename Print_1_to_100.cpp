//Printing 1 to 100 using two threads with the help of condition variable and unique_lock
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool odd_turn = true;  // Flag to indicate whether it is the turn of the odd thread

void print_odd() {
    for (int i = 1; i <= 100; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return odd_turn; }); // Wait until it's the turn of the odd thread
        std::cout << i << std::endl;
        odd_turn = false; // Set the flag for the even thread's turn
        cv.notify_all();  // Notify the even thread
    }
}

void print_even() {
    for (int i = 2; i <= 100; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !odd_turn; }); // Wait until it's the turn of the even thread
        std::cout << i << std::endl;
        odd_turn = true; // Set the flag for the odd thread's turn
        cv.notify_all(); // Notify the odd thread
    }
}

int main() {
    std::thread t1(print_odd);
    std::thread t2(print_even);

    t1.join();
    t2.join();

    return 0;
}
