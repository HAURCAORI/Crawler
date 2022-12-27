#include <vector>
#include <functional>

/**
 *  Modified Standard Library
 */
namespace mstd _GLIBCXX_VISIBILITY(default)
{

/**
 *  _RequireNotAllocator from /bits/alloc_traits.h
 */
  template<typename _Alloc, typename = void>
    struct __is_allocator : std::false_type { };
  template<typename _Alloc>
    struct __is_allocator<_Alloc,
      std::void_t<typename _Alloc::value_type,
	       decltype(std::declval<_Alloc&>().allocate(size_t{}))>>
    : std::true_type { };

  template<typename _Alloc>
    using _RequireAllocator
      = typename std::enable_if<__is_allocator<_Alloc>::value, _Alloc>::type;

  template<typename _Alloc>
    using _RequireNotAllocator
      = typename std::enable_if<!__is_allocator<_Alloc>::value, _Alloc>::type;

/**
 *  uses_allocator from /bits/uses_allocator.h
 */
    template<typename _Alloc, typename _Tp>
    using __is_erased_or_convertible
      = std::__or_<std::is_convertible<_Alloc, _Tp>, std::is_same<_Tp, std::__erased_type>>;

    template<typename _Tp, typename _Alloc, typename = std::void_t<>>
    struct __uses_allocator_helper
    : std::false_type { };

  template<typename _Tp, typename _Alloc>
    struct __uses_allocator_helper<_Tp, _Alloc,
				   std::void_t<typename _Tp::allocator_type>>
    : __is_erased_or_convertible<_Alloc, typename _Tp::allocator_type>::type
    { };


  template<typename _Tp, typename _Alloc>
    struct uses_allocator
    : __uses_allocator_helper<_Tp, _Alloc>::type
    { };

/**
 *  _RequireInputIter from /bits/stl_iterator_base_types.h
 */
#if __cplusplus >= 201103L
    template<typename _InIter>
    using _RequireInputIter = typename std::enable_if<std::is_convertible<typename
    std::iterator_traits<_InIter>::iterator_category,
    std::input_iterator_tag>::value>::type;
#endif

/**
 * priority queue
 */
    template <typename _Tp, typename _Sequence = std::vector<_Tp>,
              typename _Compare = std::less<typename _Sequence::value_type>>
    class priority_queue
    {

#if __cplusplus >= 201103L
                            template <typename _Alloc>
                            using _Uses = typename std::enable_if<uses_allocator<_Sequence, _Alloc>::value>::type;

#if __cplusplus >= 201703L
        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // 2566. Requirements on the first template parameter of container
        // adaptors
        static_assert(std::is_same<_Tp, typename _Sequence::value_type>::value,
                      "value_type must be the same as the underlying container");
#endif // C++17
#endif // C++11

    public:
        typedef typename _Sequence::value_type value_type;
        typedef typename _Sequence::reference reference;
        typedef typename _Sequence::const_reference const_reference;
        typedef typename _Sequence::size_type size_type;
        typedef _Sequence container_type;
        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // DR 2684. priority_queue lacking comparator typedef
        typedef _Compare value_compare;

    protected:
        //  See queue::c for notes on these names.
        _Sequence c;
        _Compare comp;

    public:
        /**
       *  @brief  Default constructor creates no elements.
       */
        template <typename _Seq = _Sequence, typename _Requires = typename std::enable_if<std::__and_<std::is_default_constructible<_Compare>,
                                                                                            std::is_default_constructible<_Seq>>::value>::type>
        priority_queue()
            : c(), comp()
        {
        }

        explicit priority_queue(const _Compare &__x, const _Sequence &__s)
            : c(__s), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        explicit priority_queue(const _Compare &__x, _Sequence &&__s = _Sequence())
            : c(std::move(__s)), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        explicit priority_queue(const _Alloc &__a)
            : c(__a), comp() {}

        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        priority_queue(const _Compare &__x, const _Alloc &__a)
            : c(__a), comp(__x) {}

        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // 2537. Constructors [...] taking allocators should call make_heap
        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        priority_queue(const _Compare &__x, const _Sequence &__c,
                       const _Alloc &__a)
            : c(__c, __a), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        priority_queue(const _Compare &__x, _Sequence &&__c, const _Alloc &__a)
            : c(std::move(__c), __a), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        priority_queue(const priority_queue &__q, const _Alloc &__a)
            : c(__q.c, __a), comp(__q.comp) {}

        template <typename _Alloc, typename _Requires = _Uses<_Alloc>>
        priority_queue(priority_queue &&__q, const _Alloc &__a)
            : c(std::move(__q.c), __a), comp(std::move(__q.comp)) {}

        /**
       *  @brief  Builds a %queue from a range.
       *  @param  __first  An input iterator.
       *  @param  __last  An input iterator.
       *  @param  __x  A comparison functor describing a strict weak ordering.
       *  @param  __s  An initial sequence with which to start.
       *
       *  Begins by copying @a __s, inserting a copy of the elements
       *  from @a [first,last) into the copy of @a __s, then ordering
       *  the copy according to @a __x.
       *
       *  For more information on function objects, see the
       *  documentation on @link functors functor base
       *  classes@endlink.
       */


        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // 3529. priority_queue(first, last) should construct c with (first, last)
        template <typename _InputIterator,
                  typename = std::_RequireInputIter<_InputIterator>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x = _Compare())
            : c(__first, __last), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // 3522. Missing requirement on InputIterator template parameter
        template <typename _InputIterator,
                  typename = std::_RequireInputIter<_InputIterator>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x, const _Sequence &__s)
            : c(__s), comp(__x)
        {
            __glibcxx_requires_valid_range(__first, __last);
            c.insert(c.end(), __first, __last);
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _InputIterator,
                  typename = std::_RequireInputIter<_InputIterator>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x, _Sequence &&__s)
            : c(std::move(__s)), comp(__x)
        {
            __glibcxx_requires_valid_range(__first, __last);
            c.insert(c.end(), __first, __last);
            std::make_heap(c.begin(), c.end(), comp);
        }

        // _GLIBCXX_RESOLVE_LIB_DEFECTS
        // 3506. Missing allocator-extended constructors for priority_queue
        template <typename _InputIterator, typename _Alloc,
                  typename = std::_RequireInputIter<_InputIterator>,
                  typename _Requires = _Uses<_Alloc>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Alloc &__alloc)
            : c(__first, __last, __alloc), comp()
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _InputIterator, typename _Alloc,
                  typename = std::_RequireInputIter<_InputIterator>,
                  typename _Requires = _Uses<_Alloc>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x, const _Alloc &__alloc)
            : c(__first, __last, __alloc), comp(__x)
        {
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _InputIterator, typename _Alloc,
                  typename = std::_RequireInputIter<_InputIterator>,
                  typename _Requires = _Uses<_Alloc>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x, const _Sequence &__s,
                       const _Alloc &__alloc)
            : c(__s, __alloc), comp(__x)
        {
            __glibcxx_requires_valid_range(__first, __last);
            c.insert(c.end(), __first, __last);
            std::make_heap(c.begin(), c.end(), comp);
        }

        template <typename _InputIterator, typename _Alloc,
                  typename _Requires = _Uses<_Alloc>>
        priority_queue(_InputIterator __first, _InputIterator __last,
                       const _Compare &__x, _Sequence &&__s,
                       const _Alloc &__alloc)
            : c(std::move(__s), __alloc), comp(__x)
        {
            __glibcxx_requires_valid_range(__first, __last);
            c.insert(c.end(), __first, __last);
            std::make_heap(c.begin(), c.end(), comp);
        }

        /**
       *  Returns true if the %queue is empty.
       */
        bool
        empty() const
        {
            return c.empty();
        }

        /**  Returns the number of elements in the %queue.  */
        size_type
        size() const
        {
            return c.size();
        }

        /**
       *  Returns a read-only (constant) reference to the data at the first
       *  element of the %queue.
       */
        const_reference
        top() const
        {
            __glibcxx_requires_nonempty();
            return c.front();
        }

        /**
       *  @brief  Add data to the %queue.
       *  @param  __x  Data to be added.
       *
       *  This is a typical %queue operation.
       *  The time complexity of the operation depends on the underlying
       *  sequence.
       */
        void
        push(const value_type &__x)
        {
            c.push_back(__x);
            std::push_heap(c.begin(), c.end(), comp);
        }

#if __cplusplus >= 201103L
        void
        push(value_type &&__x)
        {
            c.push_back(std::move(__x));
            std::push_heap(c.begin(), c.end(), comp);
        }

        template <typename... _Args>
        void
        emplace(_Args &&... __args)
        {
            c.emplace_back(std::forward<_Args>(__args)...);
            std::push_heap(c.begin(), c.end(), comp);
        }
#endif

        /**
       *  @brief  Removes first element.
       *
       *  This is a typical %queue operation.  It shrinks the %queue
       *  by one.  The time complexity of the operation depends on the
       *  underlying sequence.
       *
       *  Note that no data is returned, and if the first element's
       *  data is needed, it should be retrieved before pop() is
       *  called.
       */
        void
        pop()
        {
            __glibcxx_requires_nonempty();
            std::pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }

#if __cplusplus >= 201103L
        void
        swap(priority_queue &__pq) noexcept(std::__and_<
#if __cplusplus > 201402L || !defined(__STRICT_ANSI__) // c++1z or gnu++11
                                            std::__is_nothrow_swappable<_Sequence>,
#else
                                            std::__is_nothrow_swappable<_Tp>,
#endif
                                            std::__is_nothrow_swappable<_Compare>>::value)
        {
            using std::swap;
            swap(c, __pq.c);
            swap(comp, __pq.comp);
        }
#endif // __cplusplus >= 201103L
    };

#if __cpp_deduction_guides >= 201606
    template <typename _Compare, typename _Container,
              typename = _RequireNotAllocator<_Compare>,
              typename = _RequireNotAllocator<_Container>>
    priority_queue(_Compare, _Container)
        ->priority_queue<typename _Container::value_type, _Container, _Compare>;

    template <typename _InputIterator, typename _ValT = typename std::iterator_traits<_InputIterator>::value_type,
              typename _Compare = std::less<_ValT>,
              typename _Container = std::vector<_ValT>,
              typename = _RequireInputIter<_InputIterator>,
              typename = _RequireNotAllocator<_Compare>,
              typename = _RequireNotAllocator<_Container>>
    priority_queue(_InputIterator, _InputIterator, _Compare = _Compare(),
                   _Container = _Container())
        ->priority_queue<_ValT, _Container, _Compare>;

    template <typename _Compare, typename _Container, typename _Allocator,
              typename = _RequireNotAllocator<_Compare>,
              typename = _RequireNotAllocator<_Container>>
    priority_queue(_Compare, _Container, _Allocator)
        ->priority_queue<typename _Container::value_type, _Container, _Compare>;
#endif

    // No equality/comparison operators are provided for priority_queue.

#if __cplusplus >= 201103L
    template <typename _Tp, typename _Sequence, typename _Compare>
    inline
#if __cplusplus > 201402L || !defined(__STRICT_ANSI__) // c++1z or gnu++11
        // Constrained free swap overload, see p0185r1
        typename std::enable_if<std::__and_<std::__is_swappable<_Sequence>,
                                  std::__is_swappable<_Compare>>::value>::type
#else
        void
#endif
            swap(priority_queue<_Tp, _Sequence, _Compare> & __x,
                 priority_queue<_Tp, _Sequence, _Compare> & __y) noexcept(noexcept(__x.swap(__y)))
    {
        __x.swap(__y);
    }

    template <typename _Tp, typename _Sequence, typename _Compare,
              typename _Alloc>
    struct uses_allocator<priority_queue<_Tp, _Sequence, _Compare>, _Alloc>
        : public uses_allocator<_Sequence, _Alloc>::type
    {
    };
#endif // __cplusplus >= 201103L

    _GLIBCXX_END_NAMESPACE_VERSION
} // namespace mstd_GLIBCXX_VISIBILITY(default)