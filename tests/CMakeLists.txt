enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_FloatingPointManager test_FloatingPointManager.cpp ../src/FloatingPointManager.cpp)
target_link_libraries(test_FloatingPointManager GTest::GTest GTest::Main)
add_test(NAME FloatingPointManagerTests COMMAND test_FloatingPointManager)
