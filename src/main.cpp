#include "checksum.hpp"

#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>
namespace po = boost::program_options;

#include <fmt/core.h>

#include <iostream>
#include <iterator>
#include <string>

int main(int ac, char *av[]) {
  po::options_description desc("Usage: shaer [OPTION]... [FILE]");
  desc.add_options()("help", "Show this help message")(
      "file", po::value<std::string>(), "File to be processed");

  po::positional_options_description p;
  p.add("file", 1);

  po::variables_map vm;
  po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(),
            vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 0;
  }

  if (vm.count("file")) {
    auto file = vm["file"].as<std::string>();
    fmt::print(
        fmt::format("MD5 of file '{}' is: '{}' \n", file, shaer::getMd5(file)));
  } else {
    std::cout << "No file was specified.\n";
    return 1;
  }

  return 0;
}
