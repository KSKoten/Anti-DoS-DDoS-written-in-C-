#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main()
{
    const int MAX_REQUESTS_PER_SECOND = 100; // set the maximum number of requests per second
    int requestCount = 0;
    auto startTime = steady_clock::now();

    while (true) {
        // check if we've exceeded the maximum requests per second
        auto elapsed = duration_cast<milliseconds>(steady_clock::now() - startTime).count();
        if (elapsed > 1000) {
            requestCount = 0;
            startTime = steady_clock::now();
        }
        if (requestCount >= MAX_REQUESTS_PER_SECOND) {
            // limit the rate by waiting for a short period of time
            this_thread::sleep_for(milliseconds(10));
            continue;
        }

        // handle incoming request
        // ...

        // increment the request count
        requestCount++;
    }

    return 0;
}