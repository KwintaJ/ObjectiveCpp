template <typename Iter>
typename sum_traits<typename std::iterator_traits<Iter>::value_type>::sum_type
sum(Iter begin, Iter end) {
    using sum_type = typename sum_traits<typename std::iterator_traits<Iter>::value_type>::sum_type;