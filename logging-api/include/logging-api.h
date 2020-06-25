// logging-api.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include<sstream>

// TODO: Reference additional headers your program requires here.

#define MKSTR(message) #message

#define LOG_DEBUG(message) 								   \
	logging::LogMessage(__FILE__,  __LINE__, logging::severity::DEBUG)<<#message<<"\n";

#define LOG_INFO(message)								   \
	logging::LogMessage(__FILE__,  __LINE__, logging::severity::INFO)<<#message<<"\n";

#define LOG_WARN(message)								   \
	logging::LogMessage(__FILE__,  __LINE__, logging::severity::WARNING)<<#message<<"\n";

#define LOG_ERROR(message)								   \
	logging::LogMessage(__FILE__,  __LINE__, logging::severity::ERROR).flush()<<#message<<"\n";

#define LOG_FATAL(message)								   \
	logging::LogMessage(__FILE__,  __LINE__, logging::severity::FATAL).flush()<<#message<<"\n";



namespace logging
{
enum class severity
{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	FATAL,
	maxNumber
};

static const char* severities[(int)severity::maxNumber] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
	"FATAL"
};
class LogMessage : public std::stringstream
{

private: 
	severity _severity;
public:
	
	

	LogMessage(const severity& i_severity);
	LogMessage(const char* i_file, uint32_t line,  const severity& i_severity);
	virtual ~LogMessage();

};
} // logging


