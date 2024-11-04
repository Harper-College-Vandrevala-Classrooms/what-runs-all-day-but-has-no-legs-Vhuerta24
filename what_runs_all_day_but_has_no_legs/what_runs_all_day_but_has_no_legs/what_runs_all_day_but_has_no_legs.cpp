#include <iostream>
#include <ctime>  // For time()
#include <iomanip> // For std::put_time on some systems

class Timer {
private:
    time_t startTime;
    time_t endTime;
    bool running;

public:
    Timer() : running(false), startTime(0), endTime(0) {}

    void start() {
        running = true;
        startTime = std::time(nullptr); // Record the start time
    }

    void stop() {
        if (running) {
            endTime = std::time(nullptr); // Record the end time
            running = false;
        }
    }

    long elapsed() const {
        return static_cast<long>(endTime - startTime); // Return elapsed time in seconds
    }
};

// Function to print the current system time using ctime_s
void get_the_system_time() {
    time_t now = std::time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now); // Safe version of ctime
    std::cout << "System time: " << buffer; // buffer already has newline from ctime_s
}

// Function to simulate waiting for a few seconds using a busy loop
void wait_for_a_few_seconds(int seconds = 3) {
    std::cout << "Simulating a wait for " << seconds << " seconds..." << std::endl;
    time_t start = std::time(nullptr);
    while (std::time(nullptr) - start < seconds) {
        // Busy-wait loop that does nothing until 'seconds' have passed
    }
}

// Function to compare and print the elapsed time
void compare_the_times(const Timer& timer) {
    std::cout << "Elapsed time (in seconds): " << timer.elapsed() << std::endl;
}

int main() {
    Timer timer;

    std::cout << "Starting the timer..." << std::endl;
    get_the_system_time();

    timer.start();
    wait_for_a_few_seconds(3); // Simulate a 3-second wait
    timer.stop();

    get_the_system_time();
    compare_the_times(timer);

    return 0;
}
