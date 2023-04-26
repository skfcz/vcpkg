cmake_minimum_required(VERSION 3.25)

set(VCPKG_EXAMPLE_VERSION 0.1.0)
project(vcpkg-example VERSION ${VCPKG_EXAMPLE_VERSION} LANGUAGES CXX)

# Dependencies
find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

# Set libs to link against
list(APPEND VCPKG_EXAMPLE_LIBS
     fmt::fmt
     Boost::boost
     Boost::program_options)

# Build
add_executable(${PROJECT_NAME} src/main.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE ${VCPKG_EXAMPLE_LIBS})
