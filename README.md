# hexxer

[![build status](https://secure.travis-ci.org/dcousens/hexxer.png)](http://travis-ci.org/dcousens/hexxer)
[![Version](https://img.shields.io/npm/v/hexxer.svg)](https://www.npmjs.org/package/hexxer)

A streaming hex encoding/decoding tool,  pipes `stdin` to `stdout`.

Byte-for-byte, simple, **not UTF8 aware** (if that matters).

Throws via `assert` on invalid characters (platform dependent, could be a SEGV).


## Examples

Decoding
``` bash
> echo "6a" | hexxer -d
j

> echo "6b" | hexxer --decode
k
```

Encoding
``` bash
> echo "j" | hexxer
6a0a

> echo -n "j" | hexxer
6a
```
