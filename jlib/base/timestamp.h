﻿#pragma once

#include "config.h"
//
//#include "copyable.h"
//#include <boost/operators.hpp>
//#include <stdint.h> // int64_t
//#include <string> // std::string
//#include <inttypes.h> // PRId64
//#include <stdio.h> // snprintf
//#include "time.h"

//#define _WIN32_WINNT _WIN32_WINNT_WIN7

#include "../3rdparty/date/include/date/date.h"


namespace jlib
{

using namespace date;
using Timestamp = date::sys_time<std::chrono::microseconds>;

//! now
inline Timestamp nowTimestamp() { return floor<std::chrono::microseconds>(std::chrono::system_clock::now()); }

//! (first - second) duration in micro-seconds
inline long long timeDifference(const Timestamp& first, const Timestamp& second) {
	return floor<std::chrono::microseconds>(first - second).count();
}

//! (nowTimestamp - t) duration in micro-seconds
inline long long timeDifference(const Timestamp& t) {
	return floor<std::chrono::microseconds>(nowTimestamp() - t).count();
}

//! (first - second) duration in seconds(double)
inline double timeDifferenceInS(const Timestamp& first, const Timestamp& second) {
	return static_cast<double>(floor<std::chrono::microseconds>(first - second).count()) / 1000000.0;
}

//! (nowTimestamp - t) duration in seconds(double)
inline double timeDifferenceInS(const Timestamp& t) {
	return static_cast<double>(floor<std::chrono::microseconds>(nowTimestamp() - t).count()) / 1000000.0;
}


//class ENABLE_EBO Timestamp : public jlib::copyable 
//						   , public boost::equality_comparable<Timestamp>
//						   , public boost::less_than_comparable<Timestamp>
//{
//public:
//	Timestamp()
//		: microSecondsSinceEpoch_(0)
//	{}
//
//    explicit Timestamp(int64_t microSecondsSinceEpoch)
//        : microSecondsSinceEpoch_(microSecondsSinceEpoch)
//    {}
//
//
//    void swap(Timestamp& rhs) {
//        std::swap(microSecondsSinceEpoch_, rhs.microSecondsSinceEpoch_);
//    }
//
//    std::string toString() const {
//		char buff[32] = {};
//		int64_t seconds = microSecondsSinceEpoch_ / MICRO_SECONDS_PER_SECOND;
//		int64_t microseconds = microSecondsSinceEpoch_ % MICRO_SECONDS_PER_SECOND;
//		snprintf(buff, sizeof(buff) - 1, "%" PRId64 ".%06" PRId64 "", seconds, microseconds);
//		return buff;
//    }
//
//	std::string toFormattedString(bool showMicroSeconds = true) {
//		char buf[64] = { 0 };
//		time_t seconds = static_cast<time_t>(microSecondsSinceEpoch_ / MICRO_SECONDS_PER_SECOND);
//		struct tm tm_time;
//		gmtime_r(&seconds, &tm_time);
//
//		if (showMicroSeconds) {
//			int microseconds = static_cast<int>(microSecondsSinceEpoch_ % MICRO_SECONDS_PER_SECOND);
//			snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d.%06d",
//					 tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
//					 tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec,
//					 microseconds);
//		} else {
//			snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d",
//					 tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
//					 tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
//		}
//		return buf;
//	}
//
//	bool valid() const { return microSecondsSinceEpoch_ > 0; }
//
//	int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }
//	time_t secondsSinceEpoch() const { return static_cast<time_t>(microSecondsSinceEpoch_ / MICRO_SECONDS_PER_SECOND); }
//
//
//	static Timestamp now() {
//		return Timestamp(gettimeofdayUsec());
//	}
//
//	static Timestamp invalid() { return Timestamp(); }
//
//	static Timestamp fromTime_t(time_t t) {
//		return fromTime_t(t, 0);
//	}
//
//	static Timestamp fromTime_t(time_t t, int microSeconds) {
//		return Timestamp(static_cast<int64_t>(t) * MICRO_SECONDS_PER_SECOND + microSeconds);
//	}
//
//private:
//    int64_t microSecondsSinceEpoch_ = 0;
//};
//
//static_assert(sizeof(Timestamp) == sizeof(int64_t), "Expected Timestamp to be the same size as int64_t");
//
//inline bool operator<(Timestamp lhs, Timestamp rhs) {
//	return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
//}
//
//inline bool operator==(Timestamp lhs, Timestamp rhs) {
//	return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
//}
//
///**
//* @brief Get time diff of two Timestamps, return diff in seconds
//* @param high, low
//* @return (high - low) in seconds
//*/
//inline double timeDifference(Timestamp high, Timestamp low) {
//	int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
//	return static_cast<double>(diff) / MICRO_SECONDS_PER_SECOND;
//}
//
//inline Timestamp addSeconds(Timestamp t, double seconds) {
//	int64_t delta = static_cast<int64_t>(seconds * MICRO_SECONDS_PER_SECOND);
//	return Timestamp(t.microSecondsSinceEpoch() + delta);
//}

} // namespace jlib
