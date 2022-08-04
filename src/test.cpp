#include <iostream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Shaer
#include <boost/test/unit_test.hpp>

#include "checksum.hpp"

BOOST_AUTO_TEST_CASE(ShaerTest) {
  // To simplify this example test, let's suppose we'll test 'float'.
  // Some test are stupid, but all should pass.
  auto md5 = shaer::getMd5("LICENSE");

  BOOST_CHECK_EQUAL(md5, "2aef344f96bdcf12b7f4c02600b5b92d");
}
