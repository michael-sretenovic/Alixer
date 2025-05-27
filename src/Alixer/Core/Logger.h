#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Alixer
{
	class Logger
	{
	public:
		static void Initialize(const char* appName);

		static Shared<spdlog::logger>& GetCoreLogger();

		static Shared<spdlog::logger>& GetClientLogger();

	private:
		static Shared<spdlog::logger> _coreLogger;

		static Shared<spdlog::logger> _clientLogger;
	};

#define AL_CORE_TRACE(...) ::Alixer::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define AL_CORE_INFO(...)  ::Alixer::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define AL_CORE_WARN(...)  ::Alixer::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define AL_CORE_ERROR(...) ::Alixer::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define AL_CORE_FATAL(...) ::Alixer::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define AL_TRACE(...) ::Alixer::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define AL_INFO(...)  ::Alixer::Logger::GetClientLogger()->info(__VA_ARGS__)
#define AL_WARN(...)  ::Alixer::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define AL_ERROR(...) ::Alixer::Logger::GetClientLogger()->error(__VA_ARGS__)
#define AL_FATAL(...) ::Alixer::Logger::GetClientLogger()->critical(__VA_ARGS__)
}
