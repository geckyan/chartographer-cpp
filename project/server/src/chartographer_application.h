#pragma once
#include "Poco/Util/ServerApplication.h"
#include <filesystem>

namespace charta
{
	class ChartographerApplication final : public Poco::Util::ServerApplication
	{
	private:
		std::filesystem::path working_folder_;

		void defineOptions(Poco::Util::OptionSet& options) override;
		void initialize(Application& app) override;
		int main(const std::vector<std::string>& args) override;

		void handle_working_folder(const std::string& name, const std::string& value);
	};
}
