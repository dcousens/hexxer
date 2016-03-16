# hexxer

[![build status](https://secure.travis-ci.org/dcousens/hexxer.png)](http://travis-ci.org/dcousens/hexxer)
[![Version](https://img.shields.io/npm/v/hexxer.svg)](https://www.npmjs.org/package/hexxer)

A streaming hex encoder/decoding tool.


## Examples

Decoding
``` bash
> echo "6a" | hexxer -d
j
```

Encoding
``` bash
> echo "j" | hexxer
6a0a

> echo -n "j" | hexxer
6a
```
