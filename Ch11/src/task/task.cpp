#include "task.h"

using hres_clock = std::chrono::high_resolution_clock;

fun::common::Task::Task(
    std::chrono::microseconds interval_micros,
    std::function<void(void)> fn) : _execute(false), _interval_micros(interval_micros), _fn(fn)
{
}

fun::common::Task::~Task()
{
  stop();
}

void fun::common::Task::start()
{
  _execute.store(true, std::memory_order_release);
  _thread = std::thread(
      [this]()
      {
        while (this->_execute.load(std::memory_order_acquire))
        {
          hres_clock::time_point start_time = hres_clock::now();
          hres_clock::time_point target_time = start_time + _interval_micros;

          // run function
          _fn();

          std::this_thread::sleep_until(target_time);
        }
      });
}

void fun::common::Task::stop()
{
  _execute.store(false, std::memory_order_release);
  if (_thread.joinable())
  {
    _thread.join();
  }
}