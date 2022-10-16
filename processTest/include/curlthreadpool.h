#pragma once
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <condition_variable>

namespace Crawler {

class CURLObject;

class CURLThreadPool {
public:
  CURLThreadPool(size_t num_threads);
  ~CURLThreadPool();
/*
  template <class... Args>
  void EnqueueJob(Args&&... args) {
    auto job = [args...](){ Load(args...); };
    {
      std::lock_guard<std::mutex> lock(m_job_q_);
      jobs_.emplace(std::move(job));
    }
    cv_job_q_.notify_one();
  }
*/

  void EnqueueCURL(CURLObject&& obj);

 private:
  size_t num_threads_;
  size_t max_objs_ = 10;
  std::vector<std::thread> worker_threads_;
  //std::queue<std::function<void()>> jobs_;

  std::queue<CURLObject> objs_;

  std::condition_variable cv_job_q_;
  std::mutex m_job_q_;

  bool stop_all;

  void WorkerThread();
};
}