
cmake_minimum_required (VERSION 3.3)

add_executable (test-FixedSizeStringBuilder main.cxx)
target_link_libraries (test-FixedSizeStringBuilder PRIVATE FixedSizeStringBuilder)
add_test (NAME FixedSizeStringBuilderTest
          COMMAND $<TARGET_FILE:test-FixedSizeStringBuilder>)
