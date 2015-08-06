#include <memory>
#include <list>
#include <algorithm>

using namespace std;

namespace cheapgmp {
  typedef list<ulong> lmrep;
  typedef unique_ptr<lmrep> gmrep;
  gmrep makepower(const ulong, const ulong);
}

