#include "handlers/handler_factory.h"
#include "handlers/hello_handler.h"
#include "handlers/not_found_handler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/URI.h"

using namespace charta;
using namespace Poco::Net;

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(const HTTPServerRequest& request)
{
	Poco::URI uri{ request.getURI() };

	if (uri.getPath() == "/hello" && request.getMethod() == "GET")
	{
		return new HelloHandler{ uri };
	}

	return new NotFoundHandler{};
}
