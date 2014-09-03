#include "route.h"

namespace route {

Match Route::set(string u) {
  url = u;
  path_to_regex = regex(path_pattern); 
  Match m(*this);
  return m;
}

string Match::get(string key) {
  if (pairs.count(key)) {
    return pairs.at(key);
  }
  return "";
}

bool Match::test(string tmpl) {

  int pos = 0;
  
  if (route->cache.count(tmpl)) {
    path = route->cache.at(tmpl);
  }
  else {
    //
    // get all the keys from the path.
    //
    sregex_token_iterator 
      i(tmpl.begin(), tmpl.end(), route->path_to_regex),
      iend;

    while(i != iend) {
      const string key = *i++;
      path.keys.push_back(key);
    }

    //
    // create a regex from the path.
    //
    auto exp = regex_replace(
      tmpl, 
      route->path_to_regex, 
      route->capture_pattern
    );
    path.re = regex(exp);
  }

  smatch sm_values;
  regex_match (route->url, sm_values, path.re);

  for (auto i = 0; i < sm_values.size(); ++i) {
    // wouldn't need to substr if the regex was better :(
    string key = path.keys[i].substr(1, path.keys[i].length());
    pairs.insert(pair<string, string>(key, sm_values[i]));
    pos++;
  }

  return pos > 0 ? true : false;
}

} // namespace url

