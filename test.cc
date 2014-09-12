#include <assert.h>
#include "route.h"
#include <regex>

using namespace route;

#define ASSERT(message, ...) do { \
    if(!(__VA_ARGS__)) { \
      cerr << "FAIL: " << message << endl; \
    } \
    else { \
      cout << "OK: " << message << endl; \
    } \
} while(0);

int main() {

  Route route;
  auto match = route.set("/foo/666/bazz");

  ASSERT("true is false", true == false);
  ASSERT("true is true", true == true);

  int r;
  string s;


  match = route.set("/short");
  r = match.test("/short");
  ASSERT("exact match", r == true);

  match = route.set("/foo/666/bazz");

  r = match.test("/foo/:num/:str");
  ASSERT("a pattern that matches the url with two captures should contain two keys", match.keys == 2);

  s = match.get("num");
  ASSERT("the first key matches the value provided in the url", s == "666");

  s = match.get("str");
  ASSERT("the second key matches the value provided in the url", s == "bazz");

  r = match.test("/foo/:num");
  ASSERT("url match", r == false);
  ASSERT("a shorter pattern that does match the url should contain 0 keys", match.keys == 0);

  s = match.get("num");
  ASSERT("the first key from the previous match should not exist after a new call to test()", s == "");

  r = match.test("/foo/bar/:num/:str");
  ASSERT("url match", r == false);
  ASSERT("a longer pattern that doesn't match the url should contain 0 keys", match.keys == 0);

  match = route.set("/foo/a666/bazz");
  r = match.test("/foo/a:num/:str");
  ASSERT("url match", r == true);
  ASSERT("a pattern that has a prefixed capture should contain 2 keys", match.keys == 2);
}

