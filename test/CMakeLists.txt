
cmake_minimum_required (VERSION 3.3)

set (SOURCE_FILES main.cpp test.cpp)

set_source_files_properties (main.cpp PROPERTIES COTIRE_EXCLUDED TRUE)

include_directories (${CATCH_INCLUDE_DIR})

set (TARGET_NAME test-FixedSizeStringBuilder)

add_executable (${TARGET_NAME} ${SOURCE_FILES})
    target_link_libraries (${TARGET_NAME} PRIVATE FixedSizeStringBuilder)
    set_target_properties (${TARGET_NAME} PROPERTIES
        COTIRE_PREFIX_HEADER_INCLUDE_PATH "${CATCH_INCLUDE_DIR}"
        COTIRE_CXX_PREFIX_HEADER_INIT "common.h")
    target_compile_features (${TARGET_NAME} PRIVATE cxx_auto_type cxx_uniform_initialization)


add_test (NAME FixedSizeStringBuilderTest
          COMMAND $<TARGET_FILE:${TARGET_NAME}>)

if (COMMAND cotire)
    cotire (test-FixedSizeStringBuilder)
endif ()
