#pragma once

namespace Crawler {
/*
struct compatible_any {
  compatible_any() {}
  template <class T>
  compatible_any(T&& t) : m_val(std::forward<T>(t)) {
    m_print_fn = [](std::ostream& os, const std::any& val) {
      os << std::any_cast<std::decay_t<T>>(val);
    };
  }

private:
  using print_fn_t = void(*)(std::ostream&, const std::any&);
  std::any m_val;
  print_fn_t m_print_fn;
  
  friend std::ostream& operator<<(std::ostream& os, const compatible_any& val) {
    val.m_print_fn(os, val.m_val);
    return os;
  }
};
*/

class IOAdapter {
public:
    IOAdapter() = default;
    IOAdapter(std::string* data) : mData(data) {}
    IOAdapter(const IOAdapter& src) = delete;
    IOAdapter(IOAdapter&& src) noexcept;
    virtual ~IOAdapter() noexcept;
    IOAdapter& operator=(const IOAdapter& rhs) = delete;
    IOAdapter& operator=(IOAdapter&& rhs) noexcept;

    virtual void out() const;
    
    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
protected:
    std::string* mData = nullptr;
};

class IOAdapterConsole : public IOAdapter {
public:
    IOAdapterConsole(std::string* data) : IOAdapter(data) {}

    virtual void out() const;
private:
    
};

}