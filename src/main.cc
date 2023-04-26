#include <boost/program_options.hpp>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>

namespace po = boost::program_options;

int main(int argc, char** argv) {
  po::options_description desc("Allowed options");
  desc.add_options()                     //
      ("help,h", "produce help message") //
      ("option", po::value<std::string>(), "An option");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help") || vm.count("h")) {
    std::cout << desc << std::endl;
    return 0;
  }

  if (vm.count("option")) {
    std::string option_value = vm["option"].as<std::string>();
    std::string message = fmt::format("Hello, {}!", option_value);
    fmt::print(
        "+{0:-^{2}}+\n"
        "|{1: ^{2}}|\n"
        "+{0:-^{2}}+\n", "", message, 20);
  } else {
    fmt::print("Hello, World!\n");
  }

  return 0;
}
