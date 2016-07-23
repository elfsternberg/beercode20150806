#include "compat.hpp"
#include <memory>
#include <list>
#include <algorithm>

namespace cheapgmp {
  typedef std::list<ulong> lmrep;
  typedef std::unique_ptr<lmrep> gmrep;
  gmrep makepower(const ulong, const ulong);
}

