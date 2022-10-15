#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <condition_variable>

namespace Crawler {

//class CurlObject;

class CurlThreadPool {
public:
  CurlThreadPool(size_t num_threads);
  ~CurlThreadPool();
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
/*
  void Enqueue(CurlObject&& obj) {
    {
      std::lock_guard<std::mutex> lock(m_job_q_);
      objs_.emplace(std::move(obj));
    }
    cv_job_q_.notify_one();
  }
*/

 private:
  size_t num_threads_;
  size_t max_objs_ = 10;
  std::vector<std::thread> worker_threads_;
  //std::queue<std::function<void()>> jobs_;

  std::queue<std::string> objs_;

  std::condition_variable cv_job_q_;
  std::mutex m_job_q_;

  bool stop_all;

  void WorkerThread();
};
}