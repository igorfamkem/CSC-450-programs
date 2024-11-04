#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// Global variables for synchronization
std::mutex mtx;
std::condition_variable cv;
bool countUpComplete = false;

// Function for the first thread to count up to 20
void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::cout << "Counting up: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Slow down for readability
    }
    // Notify that counting up is complete
    std::unique_lock<std::mutex> lock(mtx);
    countUpComplete = true;
    cv.notify_one();
}

// Function for the second thread to count down from 20 to 0
void countDown() {
    // Wait for the first thread to complete counting up
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return countUpComplete; });

    for (int i = 20; i >= 0; --i) {
        std::cout << "Counting down: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Slow down for readability
    }
}

int main() {
    // Create two threads
    std::thread t1(countUp);
    std::thread t2(countDown);

    // Join the threads to ensure they complete before exiting main
    t1.join();
    t2.join();

    return 0;
}
