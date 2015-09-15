
cmake_minimum_required (VERSION 3.3)

set (SOURCE_FILES FixedSizeStringBuilder.cxx)

add_library (FixedSizeStringBuilder STATIC ${SOURCE_FILES})
target_include_directories (FixedSizeStringBuilder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
