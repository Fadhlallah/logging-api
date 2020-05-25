// logging-api.cpp : Defines the entry point for the application.
//

#include <logging-api.h>

namespace logging
{
	LogMessage::LogMessage(const severity& i_severity) :
		_severity(i_severity)
	{
		*this << "[" << _severities[(int) _severity] << " " << __FILE__ << " " << __LINE__ << "]: ";
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



