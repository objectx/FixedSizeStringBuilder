
cmake_minimum_required (VERSION 3.3)

set (SOURCE_FILES FixedSizeStringBuilder.cxx)

add_library (FixedSizeStringBuilder STATIC ${SOURCE_FILES})
    target_include_directories (FixedSizeStringBuilder PUBLIC ${PROJECT_SOURCE_DIR}/include)

if (COMMAND cotire)
    cotire (FixedSizeStringBuilder)
endif ()

