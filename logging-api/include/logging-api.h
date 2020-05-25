// logging-api.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

#define LOG_DEBUG (message)								   \
	LogMessage(logging::severity::DEBUG).flush()<<message<<"\n";

#define LOG_INFO (message)								   \
	LogMessage(logging::severity::INFO).flush()<<message<<"\n";

#define LOG_WARN (message)								   \
	LogMessage(logging::severity::WARN).flush()<<message<<"\n";

#define LOG_ERROR (message)								   \
	LogMessage(logging::severity::ERROR).flush()<<message<<"\n";

#define LOG_FATAL (message)								   \
	LogMessage(logging::severity::FATAL).flush()<<message<<"\n";


#include<sstream>
namespace logging
{
typedef enum class severity
{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	FATAL,
	maxNumber
} ;

const char* _severities[(int) severity::maxNumber] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
	"FATAL"
};

class LogMessage : public std::stringstream
{
public:
	severity _severity;

	LogMessage(const severity& i_severity);
	virtual ~LogMessage();

};
} // logging


