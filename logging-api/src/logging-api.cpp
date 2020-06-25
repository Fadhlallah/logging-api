// logging-api.cpp : Defines the entry point for the application.
//

#include <logging-api.h>

namespace logging
{
	LogMessage::LogMessage(const severity& i_severity) :
		_severity(i_severity)
	{
		*this << "[" << severities[static_cast<int>(_severity)] << " " << __FILE__ << ":" << __LINE__ << "]: ";
	}

	LogMessage::LogMessage(const char * file, uint32_t line, const severity& i_severity) :
		_severity(i_severity)
	{
		*this << "[" << severities[static_cast<int>(_severity)] << " " << file << ":" << line << "]: ";
	}

	LogMessage::~LogMessage()
	{
		switch (_severity)
		{
		case severity::DEBUG:
		case severity::INFO:
			fprintf(stdout, str().c_str());
			break;
		case severity::WARNING:
		case severity::ERROR:
		case severity::FATAL:
			fprintf(stderr, str().c_str());
			break;
		default:
			;
		}
	}
}



