# hexxer

[![build status](https://travis-ci.org/dcousens/hexxer.svg?branch=master)](http://travis-ci.org/dcousens/hexxer)
[![Version](https://img.shields.io/npm/v/hexxer.svg)](https://www.npmjs.org/package/hexxer)

A streaming hex encoding/decoding tool,  pipes `stdin` to `stdout`.

Byte-for-byte, simple, **not UTF8 aware** (if that matters).

Throws on invalid characters.


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
