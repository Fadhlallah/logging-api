#include<gtest/gtest.h>
#include<logging-api.h>
#include <sstream>
#include <string>

TEST(LOGGINGTEST, DEBUG)
{
	LOG_DEBUG("start of the test");
	std::stringstream expected;
	logging::LogMessage msg(__FILE__, __LINE__, logging::severity::DEBUG); expected << "[" << logging::severities[static_cast<int>(logging::severity::DEBUG)] << " " << __FILE__ << ":" << __LINE__
		<< "]: " << "hello" << "\n";
	msg<<"hello"<<"\n";
	ASSERT_STREQ(expected.str().c_str(), msg.str().c_str());
	LOG_DEBUG("end of the test");
}

TEST(LOGGINGTEST, INFO)
{
	LOG_INFO("start of the test");
	std::stringstream expected;
	logging::LogMessage msg(__FILE__, __LINE__, logging::severity::INFO); expected << "[" << logging::severities[static_cast<int>(logging::severity::INFO)] << " " << __FILE__ << ":" << __LINE__
		<< "]: " << "hello" << "\n";
	msg << "hello" << "\n";
	ASSERT_STREQ(expected.str().c_str(), msg.str().c_str());
	LOG_INFO("end of the test");
}

TEST(LOGGINGTEST, WARN)
{
	LOG_WARN("start of the test");
	std::stringstream expected;
	logging::LogMessage msg(__FILE__, __LINE__, logging::severity::WARNING); expected << "[" << logging::severities[static_cast<int>(logging::severity::WARNING)] << " " << __FILE__ << ":" << __LINE__
		<< "]: " << "hello" << "\n";
	msg << "hello" << "\n";
	ASSERT_STREQ(expected.str().c_str(), msg.str().c_str());
	LOG_WARN("end of the test");
}

TEST(LOGGINGTEST, ERROR)
{
	LOG_ERROR("start of the test");
	std::stringstream expected;
	logging::LogMessage msg(__FILE__, __LINE__, logging::severity::ERROR); expected << "[" << logging::severities[static_cast<int>(logging::severity::ERROR)] << " " << __FILE__ << ":" << __LINE__
		<< "]: " << "hello" << "\n";
	msg << "hello" << "\n";
	ASSERT_STREQ(expected.str().c_str(), msg.str().c_str());
	LOG_ERROR("end of the test");
}

TEST(LOGGINGTEST, FATAL)
{
	LOG_FATAL("start of the test");
	std::stringstream expected;
	logging::LogMessage msg(__FILE__, __LINE__, logging::severity::FATAL); expected << "[" << logging::severities[static_cast<int>(logging::severity::FATAL)] << " " << __FILE__ << ":" << __LINE__
		<< "]: " << "hello" << "\n";
	msg << "hello" << "\n";
	ASSERT_STREQ(expected.str().c_str(), msg.str().c_str());
	LOG_FATAL("end of the test");
}