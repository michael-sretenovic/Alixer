#include "pch.h"

#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Alixer
{
	Shared<spdlog::logger> Logger::_coreLogger;

	Shared<spdlog::logger> Logger::_clientLogger;

	void Logger::Initialize(const char* appName)
	{
		spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %n [%l]: %v%$");

		_coreLogger = spdlog::stdout_color_mt("ALIXER");
		_coreLogger->set_level(spdlog::level::trace);

		_clientLogger = spdlog::stdout_color_mt(appName);
		_clientLogger->set_level(spdlog::level::trace);
	}

	Shared<spdlog::logger>& Logger::GetCoreLogger() { return _coreLogger; }

	Shared<spdlog::logger>& Logger::GetClientLogger() { return _clientLogger; }
}
