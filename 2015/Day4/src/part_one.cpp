#include <openssl/md5.h>
#include <cassert>
#include <iostream>
#include <string>

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

int main (int argc, char** argv)
{
    assert(argc == 3);

    const std::string secretKey = argv[1];
    const auto expectedResult = atoi (argv[2]);

    size_t result = 0;

    while (true)
    {
        const auto str = secretKey + std::to_string(result);
        const auto md5Result = getMD5(str);
        if(md5Result.substr(0, 5) == "00000")
        {
            break;
        }
        ++result;
    }
    if(result == expectedResult)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << result << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
