#include <iostream>
#include "cheapgmp.hpp"

using namespace cheapgmp;
using namespace std;

ulong reverse(ulong in) {
  ulong rev = 0;
  for(; in != 0; ) {
    rev = (rev * 10) + (in % 10);
    in = in / 10;
  }
  return rev;
}

bool process() {
  ulong in;
  ulong rev;
  cout << "Enter your value: ";
  cin >> in;
  
  if (in == 0) {
    return false;
  }

  rev = reverse(in);
  cout << in << "^" << rev << " = ";

  gmrep ret = makepower(in, rev);
  for_each(ret->begin(), ret->end(), [](ulong i) { cout << i; });
  cout << endl;
  return true;
}


int main(int argc, char* argv[]) {
  while(true) {
    if (process() == false) {
      break;
    }
  }
}

