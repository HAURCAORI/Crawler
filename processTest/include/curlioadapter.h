#pragma once
#include <any>
#include <iostream>

namespace Crawler {

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

class IOAdapter {
public:
    IOAdapter();
    IOAdapter(const IOAdapter& src) = delete;
    IOAdapter(IOAdapter&& src) noexcept;
    virtual ~IOAdapter() noexcept;
    IOAdapter& operator=(const IOAdapter& rhs) = delete;
    IOAdapter& operator=(IOAdapter&& rhs) noexcept;

    template<typename E>
    void set(E data) { mdata = compatible_any(data); }

    virtual void out() const;
    
    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
protected:
    compatible_any mdata;
};

class IOAdapterConsole : public IOAdapter {
public:
    IOAdapterConsole() = default;

    virtual void out() const;
private:
    
};

}