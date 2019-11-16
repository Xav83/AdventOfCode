#include "md5_wrapper.hpp"

std::array<unsigned char, MD5_DIGEST_LENGTH> getMD5(std::string key) {
  std::array<unsigned char, MD5_DIGEST_LENGTH> digest;
  MD5(reinterpret_cast<unsigned char *>(key.data()), key.length(),
      digest.data());
  return digest;
}
