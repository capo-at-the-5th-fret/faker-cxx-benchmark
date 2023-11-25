cmake_minimum_required(VERSION 3.26)

project(benchmark_runner LANGUAGES CXX)

# Reference:
# https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

add_subdirectory(extern/xoshiro)
add_subdirectory(extern/faker-cxx)

include(FetchContent)

set(BENCHMARK_ENABLE_TESTING OFF)    # to suppress benchmark internal tests
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.8.3)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(benchmark_runner
    
    main.cpp

    random_number_engine_bm.cpp
    uuid_bm.cpp
)

target_include_directories(benchmark_runner PRIVATE extern/pcg-cpp/include)
target_link_libraries(benchmark_runner PRIVATE faker-cxx xoshiro::xoshiro)
target_link_libraries(benchmark_runner PRIVATE benchmark::benchmark benchmark::benchmark_main)
#target_compile_features(benchmark_runner PUBLIC cxx_std_23)
