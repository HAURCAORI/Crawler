#ifndef CURL_THREAD_POOL_H
#define CURL_THREAD_POOL_H

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
  void EnqueueCURL(CURLObject&& obj);

  // static local singleton
  static CURLThreadPool& getInstance() {
    static CURLThreadPool instance(5);
    return instance;
  }

 private:
  CURLThreadPool(size_t num_threads);
  CURLThreadPool(const CURLThreadPool& src) = delete;
  virtual ~CURLThreadPool();
  CURLThreadPool& operator=(const CURLThreadPool& rhs) = delete;
  
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


#endif