//
//  ECSimTask3.cpp
//  
//

#include "ECSimTask3.h"
#include <iostream>
using namespace std;

//***********************************************************
// Basic task
//***********************************************************

//***********************************************************
// Interval task: a single interval.
// YW: you shouldn't need to change this class!

ECSimIntervalTask :: ECSimIntervalTask(const std::string &tidIn, int tmStartIn, int tmEndIn) : tid(tidIn), tmStart(tmStartIn), tmEnd(tmEndIn), tmTotWait(0), tmTotRun(0)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsReadyToRun(int tick) const
{
    return tick >= tmStart && tick <= tmEnd;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsFinished(int tick) const
{
    return tick > tmEnd;
}


//***********************************************************
// Consecutive task: a task that can early abort

ECSimConsecutiveTask :: ECSimConsecutiveTask(ECSimTask *pTask): basetask(pTask), started(false), interrupted(false) {}

// your code here

bool ECSimConsecutiveTask:: IsReadyToRun(int tick) const
{
    if(basetask->IsReadyToRun(tick))
    {
        if(!started || (started && !interrupted))
        {
            return true;
        }
    }
    return false;
}

bool ECSimConsecutiveTask:: IsFinished(int tick) const{
    return basetask->IsFinished(tick);
}

bool ECSimConsecutiveTask:: IsAborted(int tick) const{
    return (started && interrupted);
}

void ECSimConsecutiveTask:: Run(int tick, int duration)
{
    if(basetask->IsReadyToRun(tick) && !started)
    {
        started = true;
    }
    basetask->Run(tick, duration);

}

void ECSimConsecutiveTask:: Wait(int tick, int duration)
{
    if(started)
    {
        interrupted = true;
    }
    basetask->Wait(tick, duration);
}

int ECSimConsecutiveTask:: GetTotWaitTime() const{
    return basetask->GetTotWaitTime();
}

int ECSimConsecutiveTask:: GetTotRunTime() const{
    return basetask->GetTotRunTime();
}


//***********************************************************
// Periodic task: a task that can early abort

// ECSimPeriodicTask :: ECSimPeriodicTask(ECSimTask *pTask, int ls) 
// {
// }

// your code here

//***********************************************************
// Task with a deadline to start: a task that must start by some time; otherwise terminate

// ECSimStartDeadlineTask :: ECSimStartDeadlineTask(ECSimTask *pTask, int tmStartDeadlineIn) 
// {
// }

// your code here

//***********************************************************
// Task must end by some fixed time click: this is useful e.g. when a task is periodic

// ECSimEndDeadlineTask :: ECSimEndDeadlineTask(ECSimTask *pTask, int tmEndDeadlineIn) 
// {
// }

// your code here

//***********************************************************
// Composite task: contain multiple sub-tasks
/*
ECSimCompositeTask :: ECSimCompositeTask(const std::string &tidIn) 
{
}
*/

// your code here
