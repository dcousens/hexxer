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
		const auto read = fread(in.data(), 1, in.size(), stdin);
		if (read == 0) break;

		for (size_t i = 0; i < read; ++i) {
			const auto byte = in[i];
			out[i << 1] = hexxer::encodeFirst(byte);
			out[(i << 1) + 1] = hexxer::encodeSecond(byte);
		}

		if (!fwrite(out.data(), read * 2, 1, stdout)) return 1;
	}

	return 0;
}

auto decode () {
	std::array<char, MAX_WRITE_OUT * 2> in;
	std::array<unsigned char, MAX_WRITE_OUT> out;

	while (true) {
		// read until EOF
		const auto read = fread(in.data(), 1, in.size(), stdin);
		if (!read) break;
		if (read % 2 != 0) throw std::domain_error("Odd number of characters");

		for (size_t i = 0; i < read; i += 2) {
			const auto a = in[i];
			const auto b = in[i + 1];

			const auto byte = hexxer::decode(a, b);
			if (byte > 0xff) throw std::domain_error("Invalid hex character");

			out[i >> 1] = static_cast<unsigned char>(byte);
		}

		if (!fwrite(out.data(), read, 1, stdout)) return 1;
	}

	return 0;
}

int main (int argc, char** argv) {
	if (argc > 1) {
		if (strncmp(argv[1], "-d", 2) != 0 && strncmp(argv[1], "--decode", 8) != 0) {
			throw std::invalid_argument("Unknown argument");
		}

		return decode();
	}

	return encode();
}
