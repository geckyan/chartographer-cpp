#include "chartographer_application.h"
#include "handlers/handler_factory.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Util/OptionSet.h"

using namespace charta;
using namespace Poco::Net;
using namespace Poco::Util;

void ChartographerApplication::defineOptions(OptionSet& options)
{
	ServerApplication::defineOptions(options);
	this->setUnixOptions(true);

	options.addOption(
		Option{ "folder", "f", "working folder" }
			.required(true)
			.repeatable(false)
			.argument("FOLDER")
			.callback(OptionCallback<ChartographerApplication>{ this, &ChartographerApplication::handle_working_folder })
	);
}

void ChartographerApplication::initialize(Application& app)
{
	ServerApplication::initialize(app);
	// ADVICE: Nice place to make some preparations before running the server.
}

int ChartographerApplication::main(const std::vector<std::string>& args)
{
	ServerSocket socket{ 8080 };
	HTTPServer server{ new HandlerFactory{}, socket, new HTTPServerParams{} };
	server.start();
	waitForTerminationRequest();
	server.stop();

	return ExitCode::EXIT_OK;
}

void ChartographerApplication::handle_working_folder(const std::string& name, const std::string& value)
{
	working_folder_ = value;
}

