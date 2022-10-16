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
  CURLThreadPool(const CURLThreadPool& src) = delete;
  virtual ~CURLThreadPool();
  CURLThreadPool& operator=(const CURLThreadPool& rhs) = delete;

  void EnqueueCURL(CURLObject&& obj);

 private:
  size_t num_threads_;
  size_t max_objs_ = 10;
  std::vector<std::thread> worker_threads_;
  std::queue<CURLObject> objs_;

  std::condition_variable cv_job_q_;
  std::mutex m_job_q_;

  bool stop_all;

  void WorkerThread();
};
}