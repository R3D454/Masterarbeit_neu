#ifndef _example_timer_h_
#define _example_timer_h_

// #include <nl.h>          // for member
#include <time.h>
#include <chrono>

   /// grabs the time of day
   class Timer
   {
   public:
      void Update();

      long GetCurrentSeconds() const;
      long GetCurrentMSeconds() const;
      long GetCurrentUSeconds() const;

      // @return the time of day in seconds
      double GetSeconds() const;

      time_t GetData() const;

      tm* getTime();

   private:
      time_t _time_of_day;
      struct tm * timeinfo;

   };



#endif  // _example_timer_h_
