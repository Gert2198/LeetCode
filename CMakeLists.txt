cmake_minimum_required(VERSION 3.10.0)
project(LeetCode VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exec)

add_executable(LeetCode1 C++/Easy/1-TwoSumTarget.cpp)
add_executable(LeetCode13 C++/Easy/13-RomanToInteger.cpp)

add_executable(LeetCode2 C++/Medium/2-AddTwoNumbers.cpp)
add_executable(LeetCode3 C++/Medium/3-LongestSubstrWithNoRepeatingChars.cpp)

add_executable(LeetCode4 C++/Hard/4-MedianTwoSortedArrays.cpp)