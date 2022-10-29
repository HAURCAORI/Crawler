#include "curlthreadpool.h"
#include "curlobject.h"

#include <iostream> //입출력 테스트용

namespace Crawler {
CURLThreadPool::CURLThreadPool(size_t num_threads): num_threads_(num_threads), stop_all(false) {
  worker_threads_.reserve(num_threads_);
  for (size_t i = 0; i < num_threads_; ++i) {
    worker_threads_.emplace_back([this]() { this->WorkerThread(); });
  }
}

CURLThreadPool::~CURLThreadPool() {
  stop_all = true;
  cv_job_q_.notify_all();

  for (auto& t : worker_threads_) {
    t.join();
  }
}

void CURLThreadPool::EnqueueCURL(CURLObject&& obj) {
  {
    std::lock_guard<std::mutex> lock(m_job_q_);
    objs_.emplace(std::move(obj));
  }
  cv_job_q_.notify_one();
}

void CURLThreadPool::WorkerThread() {
  while (true) {
    CURLMultiObject curlmulti;
    std::unique_lock<std::mutex> lock(m_job_q_);
    cv_job_q_.wait(lock, [this]() { return !this->objs_.empty() || stop_all; });
    if (stop_all && this->objs_.empty()) {
      return;
    }

    size_t count = 0;
    while(!objs_.empty() && count < max_objs_) {
      curlmulti.addHandle(std::move(objs_.front()));
      objs_.pop();
      lock.unlock();
      
      //std::cout << "[" << std::hex <<  std::this_thread::get_id() << "]" << count << std::endl;

      ++count;
      lock.lock();
    }
    //std::cout << "[" << std::hex <<  std::this_thread::get_id() << "]end" << std::endl;
    lock.unlock();

    curlmulti.perform();
  }
}


}  // namespace ThreadPool