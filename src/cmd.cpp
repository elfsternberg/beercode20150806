#include <iostream>
#include <string>
#include <sstream>
#include "cheapgmp.hpp"
#include "accessories.hpp"

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

int main(int argc, char* argv[]) {
  ulong in;
  istringstream ss(argv[1]);
  if (!(ss >> in)) {
    cerr << "Invalid number " << argv[1] << '\n';  
    exit(1);
  }

  wstring s2 = tostring(makepower(in, (reverse(in))));
  std::wcout << s2 << endl;
}

