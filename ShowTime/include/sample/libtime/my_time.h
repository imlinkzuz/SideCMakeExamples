#ifndef LIB_SAMPLE_DATE
#define LIB_SAMPLE_DATE

#include <string>
#include <ctime>
#include "ShowTime/libTime_export.hpp"

namespace sample
{


  class MyTime
  {
   std::tm m_time;

  public:
    MyTime();
    MyTime(const std::tm & value);
    static std::string now();
    std::string   toString() const;
  };

  MyTime buildTime(int year, int month, int day, int hour, int minute, int second);


};// namespace sample

#endif//LIB_SAMPLE_DATE
