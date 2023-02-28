#include <array>
#include <cstdio>
#include <cstring>
#include <stdexcept>

#include "hexxer.hpp"

#define MAX_WRITE_OUT 4096

auto encode () {
	std::array<unsigned char, MAX_WRITE_OUT / 2> in;
	std::array<char, MAX_WRITE_OUT> out;

	while (true) {
		// read until EOF
		auto const read = fread(in.data(), 1, in.size(), stdin);
		if (read == 0) break;

		for (size_t i = 0; i < read; ++i) {
			auto const byte = in[i];
			out[i << 1] = hexxer::encodeFirst(byte);
			out[(i << 1) + 1] = hexxer::encodeSecond(byte);
		}

		if (!fwrite(out.data(), read << 1, 1, stdout)) return 1;
	}

	return 0;
}

auto decode (bool const strict = false) {
	std::array<char, MAX_WRITE_OUT * 2> in;
	std::array<unsigned char, MAX_WRITE_OUT> out;

	while (true) {
		// read until EOF
		auto const read = fread(in.data(), 1, in.size(), stdin);
		if (!read) break;

		auto const read2 = read - (read % 2);
		for (size_t i = 0; i < read2;) {
			auto const a = in[i];
			auto const b = in[i + 1];

			auto const byte = hexxer::decode(a, b);
			if (byte >= 0x100) {
				if (strict) return 3;
				if (byte == 0x101) i += 2;
				if (byte == 0x100) i += 1;
				continue;
			}

			out[i >> 1] = static_cast<unsigned char>(byte);
			i += 2;
		}

		if (!fwrite(out.data(), read2 >> 1, 1, stdout)) return 1;
	}

	return 0;
}

int main (int argc, char** argv) {
	if (argc > 1) {
		if (not (strncmp(argv[1], "-d", 2) == 0 or strncmp(argv[1], "--decode", 8) == 0)) {
			throw std::invalid_argument("unknown argument");
		}

		auto const strict = not ((strncmp(argv[1], "-da", 3) == 0) or (strncmp(argv[1], "--decode-any", 12) == 0));
		auto const error = decode(strict);
		if (error == 2) throw std::domain_error("odd number of characters");
		if (error == 3) throw std::domain_error("invalid hex character");
		return error;
	}

	return encode();
}
