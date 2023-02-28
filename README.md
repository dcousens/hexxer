# hexxer
A streaming hex encoding/decoding tool,  pipes `stdin` to `stdout`.

Byte-for-byte, simple, **not UTF8 aware** (if that matters).

Throws on invalid characters unless `--decode-any` is used.


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

## LICENSE [MIT](LICENSE)
