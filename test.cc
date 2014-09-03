#include <assert.h>
#include "route.h"

using namespace route;

int main() {

  Route route;
  auto match = route.set("/foo/666/bazz");

  assert(!match.test("/foo/bar/:num/:str"));
  assert(match.test("/foo/:num/:str"));
  assert("666" == match.get("num"));
  assert("bazz" == match.get("str"));

  std::cout << "OK" << endl;
}

