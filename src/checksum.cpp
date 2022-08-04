#include "checksum.hpp"
#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>
#include <fstream>
#include <iostream>

namespace shaer {
inline std::vector<unsigned char> readFile(std::string filePath) {
  std::ifstream instream(filePath, std::ios::in | std::ios::binary);
  std::vector<unsigned char> data((std::istreambuf_iterator<char>(instream)),
                                  std::istreambuf_iterator<char>());
  return data;
}

std::string getMd5(std::string filePath) {
  Poco::MD5Engine md5;
  Poco::DigestOutputStream stream(md5);
  stream << readFile(filePath).data();
  stream.close();
  return Poco::DigestEngine::digestToHex(md5.digest());
}
} // namespace shaer
