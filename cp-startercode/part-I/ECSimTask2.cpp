//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"

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
