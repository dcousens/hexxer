#include <cstdio>
#include <cstring>
#include <stdexcept>

#include "hexxer.h"

int main (int argc, char** argv) {
	char hbuf[2] = {};
	unsigned char bbuf[1] = {};

	// decode?
	if (argc > 1) {
		if (strncmp(argv[1], "-d", 2) != 0 && strncmp(argv[1], "--decode", 8) != 0) {
			throw std::invalid_argument("Unknown argument");
		}

		while (true) {
			const auto read = fread(hbuf, sizeof(hbuf), 1, stdin);

			// EOF?
			if (read == 0) break;
			if (!hex_decode(bbuf, hbuf, 2)) throw std::domain_error("Invalid hex character");

			fwrite(bbuf, sizeof(bbuf), 1, stdout);
		}

	// encode
	} else {
		while (true) {
			const auto read = fread(bbuf, sizeof(bbuf), 1, stdin);

			// EOF?
			if (read == 0) break;
			if (!hex_encode(hbuf, bbuf, 1)) return 1;

			fwrite(hbuf, sizeof(hbuf), 1, stdout);
		}
	}

	return 0;
}
