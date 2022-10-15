#include "curlthreadpool.h"

namespace Crawler {
CurlThreadPool::CurlThreadPool(size_t num_threads): num_threads_(num_threads), stop_all(false) {
  worker_threads_.reserve(num_threads_);
  for (size_t i = 0; i < num_threads_; ++i) {
    worker_threads_.emplace_back([this]() { this->WorkerThread(); });
  }
}

void CurlThreadPool::WorkerThread() {
  while (true) {
    std::unique_lock<std::mutex> lock(m_job_q_);
    cv_job_q_.wait(lock, [this]() { return !this->objs_.empty() || stop_all; });
    if (stop_all && this->objs_.empty()) {
      return;
    }

    size_t count = 0;
    while(!objs_.empty() && count < max_objs_) {
      //CurlObject obj = std::move(objs_.front());
      //objs_.pop();
      lock.unlock();
      count++;
      
      lock.lock();
    }
    

    //job();
  }
}

CurlThreadPool::~CurlThreadPool() {
  stop_all = true;
  cv_job_q_.notify_all();

  for (auto& t : worker_threads_) {
    t.join();
  }
}
}  // namespace ThreadPool