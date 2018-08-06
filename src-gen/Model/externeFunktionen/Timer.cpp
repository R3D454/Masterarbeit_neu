
#include "Timer.h"
#include <iostream>



const double MILLI = 0.001;
const double MICRO = 0.000001;

void Timer::Update()
{
   time( &_time_of_day );
   timeinfo = localtime (&_time_of_day);

}

// long Timer::GetCurrentSeconds() const
// {
//    return _time_of_day.useconds;
// }
//
// long Timer::GetCurrentMSeconds() const
// {
//    return _time_of_day.useconds;
// }
//
// long Timer::GetCurrentUSeconds() const
// {
//    return _time_of_day.useconds;
// }
//
// double Timer::GetSeconds() const
// {
//    //return( _time_of_day.seconds + _time_of_day.mseconds*MILLI + _time_of_day.useconds*MICRO );
//    return( _time_of_day.seconds + _time_of_day.mseconds*MILLI );
//    //return( _time_of_day.seconds + _time_of_day.useconds*MICRO );
// }

time_t Timer::GetData() const
{
   return _time_of_day;

}

tm* Timer::getTime(){
return timeinfo;

}
