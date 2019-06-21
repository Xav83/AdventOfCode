#include "md5_wrapper.hpp"
#include <openssl/md5.h>

std::string getMD5(std::string key)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<unsigned char*>(key.data()), key.length(), digest);

    std::string mdString(std::size(digest) * 2, 'a');
    for(size_t i = 0; i < std::size(digest); ++i)
    {
        snprintf(&mdString[i*2], 4 * sizeof(char), "%02x", static_cast<unsigned int>(digest[i]));
    }
    return mdString;
}
