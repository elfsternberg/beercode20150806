#include "accessories.hpp"

namespace cheapgmp {

  using namespace std;

  ulong tolong(const gmrep in) {
    int pos = 1;
    ulong ret = 0;
    for_each(in->rbegin(), in->rend(), [&pos, &ret](ulong i) { 
        ret = ret + (i * pos);
        pos = pos * 10;
    });
    return ret;
  }

  wstring tostring(const gmrep in) {
    wstringstream ss;
    for_each(in->begin(), in->end(), [&ss](ulong i) { 
        ss << i;
    });
    return ss.str();
  }

}
