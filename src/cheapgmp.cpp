#include "cheapgmp.hpp"

namespace cheapgmp {

  using namespace std;

  namespace {

    /* Given a list representing a decimal number as a multiplicand,
       multiply each digit by a multiplier, leaving in its place the
       remainder modulo 10 of the result, and using result diviso 10
       as a carryover to the 10^(n+1) slot */

    void multiply(gmrep &multiplicand, ulong multiplier) {
      ulong rem = 0;
      for_each(multiplicand->rbegin(), multiplicand->rend(), [&rem, multiplier](ulong &i) { 
          ulong t = (i * multiplier) + rem ; 
          i = t % 10 ; 
          rem = t / 10; 
        });

      /* When out of list elements, drain the result diviso 10 until
         the new result is complete */
      
      while(rem > 0) {
        multiplicand->push_front(rem % 10);
        rem = rem / 10;
      }
    }

    /* Given an integer, return a std::list<int> in which each node
       represents a decimal placement, i.e the end() is the ones,
       end().prev() is the tens, etc. */
    
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

  /* Perform the operation multiple times, to produce an exponential
     result */
  
  gmrep makepower(const ulong base, const ulong power) {
    if (power == 0) {
      return makerep(base == 0 ? 0 : 1);
    }

    auto res = makerep(base);
    ulong ct = power;
    while(ct > 1) {
      multiply(res, base);
      ct--;
    }
    return res;
  }
}

