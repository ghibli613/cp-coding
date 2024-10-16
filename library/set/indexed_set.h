#include <ext/pb_ds/assoc_container.hpp>

template<typename T>
using indexed_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
