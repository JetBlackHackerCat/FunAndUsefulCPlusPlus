#ifndef COMMON_TASK
#define COMMON_TASK

#include <atomic>
#include <chrono>
#include <functional>
#include <thread>

namespace fun::common {
  class Task {
    private:
      std::atomic<bool> _execute;
      std::chrono::microseconds _interval_micros;
      std::function<void(void)> _fn;
      std::thread _thread;
    public:
      Task(std::chrono::microseconds interval_micros, std::function<void(void)> fn);
      ~Task();
      void start();
      void stop();
  };
}; // namespace fun::common

#endif /* !COMMON_TASK */