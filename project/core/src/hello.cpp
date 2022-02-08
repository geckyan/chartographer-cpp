#include "charta/hello.h"

using namespace charta;

namespace
{
	constexpr const std::string_view HELLO_PREFIX{ "Hello, " };
}

std::string charta::make_hello(std::string_view name)
{
	std::string hello{};
	hello.reserve(HELLO_PREFIX.size() + name.size() + 1);
	hello.append(HELLO_PREFIX).append(name).append("!");
	return hello;
}
