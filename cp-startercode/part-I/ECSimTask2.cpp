//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"
#include <iostream>
ECMultiIntervalsTask::ECMultiIntervalsTask(const std::string &tid): ECSimTask(tid) {}
bool ECMultiIntervalsTask::IsReadyToRun(int tick) const
{
    //handle empty intervals vector
    //I think the loop would already handle this but better to make it explicit
    if(intervals.empty())
    {return false;}


    //iterate through intervals and check if tick is in one
    //const function, otherwise, I'd let intervals pop intervals as needed
    for(auto i = intervals.begin(); i != intervals.end(); i+=2)
    {
        int start = *i;
        int end = *(i+1);
        if(tick >= start && tick <= end)
        {
            return true;
        }
    }
    return false;
}
bool ECMultiIntervalsTask::IsFinished(int tick) const
{
    int end = intervals.back();
    return (tick > end);

}
void ECMultiIntervalsTask::AddInterval(int a, int b)
{
    intervals.push_back(a);
    intervals.push_back(b);
}

ECHardIntervalTask::ECHardIntervalTask(const std::string &tid, int tmStartin, int tmEndin): ECSimTask(tid), tmStart(tmStartin), tmEnd(tmEndin), on_time(false) {}
void ECHardIntervalTask::Run(int tick, int duration)
{
    if(tick == tmStart)
    {
        on_time = true;
    }
    ECSimTask::Run(tick, duration);
}

bool ECHardIntervalTask::IsReadyToRun(int tick) const
{
    //case 1: tick < start time -> false
    //case 2: tick > end time -> false
    //case 3: tick > start & tick < end but missed time requested -> false
    //case 4: tick > start & tick < end & starts at requested time -> true
    if(tick >= tmStart && tick <= tmEnd)
    {
        if(tick == tmStart || on_time)
        {
            return true;
        }
    }
    return false;
}
bool ECHardIntervalTask::IsFinished(int tick) const
{

    if(tick > tmEnd || (!on_time && tick > tmStart))
    {
        return true;
    }

    return false;
}

