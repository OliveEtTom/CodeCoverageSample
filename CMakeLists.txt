cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "-O2 -g -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_subdirectory(src bin/src)
  
add_executable(Main main.cpp bin) 
target_compile_options(Main PRIVATE -fPIC)
target_link_libraries (Main src)

get_target_property(SRC_BINARY_DIR src BINARY_DIR)
set(COVERAGE_DIR ${SRC_BINARY_DIR}/CMakeFiles/src.dir)
add_custom_target(CodeCoverage ALL ./Main 
COMMAND lcov -c -d ${COVERAGE_DIR} -o ${COVERAGE_DIR}/full.info # generating full code coverage
COMMAND lcov -r ${COVERAGE_DIR}/full.info '/usr/include/*' -o ${COVERAGE_DIR}/name.info # removing system files from coverage
COMMAND genhtml -o out ${COVERAGE_DIR}/name.info --ignore-errors source # generating html
)