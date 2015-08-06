#include "cheapgmp.hpp"

using namespace std;

namespace cheapgmp {
  namespace {
    void multiply(gmrep &in, ulong by) {
      gmrep res(new lmrep());
      ulong rem = 0;
      for_each(in->rbegin(), in->rend(), [&rem, by](ulong &i) { 
          ulong t = (i * by) + rem ; 
          i = t % 10 ; 
          rem = t / 10; 
        });
      
      while(rem > 0) {
        in->push_front(rem % 10);
        rem = rem / 10;
      }
    }
    
    gmrep makerep(const ulong in) {
      gmrep res(new lmrep());
      if (in == 0) {
        res->push_front(0);
        return res;
      }

      ulong rem = in;
      while(rem > 0) {
        res->push_front(rem % 10);
        rem = rem / 10;
      }
      return res;
    }
  }
  
  gmrep makepower(const ulong base, const ulong power) {
    if (power == 0) {
      return makerep(base == 0 ? 0 : 1);
    }

    gmrep res = makerep(base);
    ulong ct = power;
    while(ct > 1) {
      multiply(res, base);
      ct--;
    }
    return res;
  }
}

