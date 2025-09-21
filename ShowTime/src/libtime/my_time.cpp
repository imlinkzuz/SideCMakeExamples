#include <sample/libtime/my_time.h>
#include <fmt/core.h>
#include <chrono>
#include <fmt/chrono.h>// Required for chrono formatting

namespace sample
{

/**
 * @brief Builds a MyTime object from specified date and time components.
 * @param year Year value (e.g., 2025)
 * @param month Month value (1-12)
 * @param day Day value (1-31)
 * @param hour Hour value (0-23)
 * @param minute Minute value (0-59)
 * @param second Second value (0-59)
 * @return MyTime object representing the specified time.
 */
  MyTime buildTime(int year, int month, int day, int hour, int minute, int second)
  {
    // Create a std::tm structure
    std::tm tm; 
    tm.tm_year = year - 1900;// tm_year is years since 1900
    tm.tm_mon  = month - 1;  // tm_mon is 0-based (0 = January)
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min  = minute;
    tm.tm_sec  = second;
    tm.tm_isdst = -1;
    tm.tm_zone = nullptr;

    // Convert time_t to time_point
    return MyTime{tm};
  }

/**
 * @brief Constructs a MyTime object with the current system time.
 */
  MyTime::MyTime() : m_time { 0} { }

/**
 * @brief Constructs a MyTime object from a std::tm  value.
 * @param time The time value to initialize with.
 */
  MyTime::MyTime(const std::tm & value) : m_time { value } { }

/**
 * @brief Returns the current system time as a formatted string.
 * @return Formatted current time string.
 */
  std::string MyTime::now()
  {
    auto now = std::chrono::system_clock::now();// Get current time point

    // Format the time point
    return fmt::format("Current time: {:%Y-%m-%d %H:%M:%S}", now);
  }

/**
 * @brief Converts the stored time point to a formatted string.
 * @return Formatted time string.
 */
  std::string MyTime::toString() const
  {
    return fmt::format("{:04}-{:02}-{:02} {:02}:{:02}:{:02}",
                       m_time.tm_year + 1900, m_time.tm_mon + 1, m_time.tm_mday,
                       m_time.tm_hour, m_time.tm_min, m_time.tm_sec);
    
  }




}// namespace sample

