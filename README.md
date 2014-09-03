# SYNOPSIS
A very simple request router for C++

# EXAMPLE
This example uses the [`libuv-http`](https://github.com/hij1nx/libuv-http)
server.

```cpp
#include "http.h"
#include "route.h"

int main() {

  Router router;

  Server hs([](auto &req, auto &res) {

    auto match = router.set(req.url);

    if (match.test("/books/:id") {

      res.setStatus(200);
      res.setHeader("Content-Type", "text/plain");
      res.setHeader("Connection", "keep-alive");

      res << "You ordered #" << match.get("id") << res.end();
    }

  });

  hs.listen("0.0.0.0", 8000);
}
```

# INSTALL
```bash
clib install hij1nx/route
```

# TEST
```bash
make
```

