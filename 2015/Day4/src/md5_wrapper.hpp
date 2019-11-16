#pragma once

#include <array>
#include <openssl/md5.h>
#include <string>

template <size_t N>
[[nodiscard]] std::string
byteToString(const std::array<unsigned char, N>(&bytes)) {
  std::string str(std::size(bytes) * 2, 'a');
  for (size_t i = 0; i < std::size(bytes); ++i) {
    snprintf(&str[i * 2], 4 * sizeof(char), "%02x",
             static_cast<unsigned int>(bytes[i]));
  }
  return str;
}

std::array<unsigned char, MD5_DIGEST_LENGTH> getMD5(std::string key);
