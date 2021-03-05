#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::string message;
    std::ostream &out;

public:
    explicit TimerGuard(std::string_view _message = "", std::ostream &_out = std::cout)
            : out(_out) {
        message = _message;
        start = std::chrono::high_resolution_clock::now();
    }

    ~TimerGuard() {
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        out << message << ' ' << diff.count() << '\n';
    }
};
