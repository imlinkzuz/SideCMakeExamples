#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <sample/libtime/my_time.h>

TEST_CASE("Test libTime") {
    sample::MyTime myTime = sample::buildTime(2025, 12, 31, 23, 59, 59);
    CHECK(myTime.toString() == "2025-12-31 23:59:59");
}