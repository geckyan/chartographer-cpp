#include "catch2/catch.hpp"
#include "charta/hello.h"

using namespace charta;

TEST_CASE("make_hello", "[hello]")
{
	CHECK(make_hello("world") == "Hello, world!");
}

