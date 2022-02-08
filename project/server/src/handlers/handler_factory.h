#pragma once
#include "Poco/Net/HTTPRequestHandlerFactory.h"

namespace charta
{
	class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
	{
	public:
		Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request) override;
	};
}
