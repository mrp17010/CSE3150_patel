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

ECSimPeriodicTask :: ECSimPeriodicTask(ECSimTask *pTask, int ls): basetask(pTask), lenSleep(ls) 
{
    int start; 
    int count = 0;
    bool foundstart = false;

    while(!(basetask->IsFinished(count)))
    {
        if((basetask->IsReadyToRun(count)) && !(foundstart)){
            foundstart = true;
            start = count;
        }
        count++;
    }
    starttime = start;
    baseperiod = (count-start);
}
bool ECSimPeriodicTask:: IsReadyToRun(int tick) const
{
    int period = baseperiod + lenSleep;
    int offset = (tick-starttime)%period;
    if(offset < baseperiod)
    {
        if((tick >= starttime) && basetask->IsReadyToRun(starttime+offset))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
bool ECSimPeriodicTask:: IsFinished(int tick) const {
    return false;
}
bool ECSimPeriodicTask:: IsAborted(int tick) const {
    return false;
}
void ECSimPeriodicTask:: Run(int tick, int duration) {
    basetask->Run(tick, duration);
}
void ECSimPeriodicTask:: Wait(int tick, int duration) {
    basetask->Wait(tick, duration);
}
int ECSimPeriodicTask:: GetTotWaitTime() const {
    return basetask->GetTotWaitTime();
}
int ECSimPeriodicTask:: GetTotRunTime() const {
    return basetask->GetTotRunTime();
}


// your code here

//***********************************************************
// Task with a deadline to start: a task that must start by some time; otherwise terminate

ECSimStartDeadlineTask :: ECSimStartDeadlineTask(ECSimTask *pTask, int tmStartDeadlineIn): basetask(pTask), deadline(tmStartDeadlineIn), on_time(false) {}
bool ECSimStartDeadlineTask:: IsReadyToRun(int tick) const 
{
    if(basetask->IsReadyToRun(tick))
    {
        if(tick <= deadline || on_time)
        {
            return true;
        }
    }
    return false;
}
bool ECSimStartDeadlineTask:: IsFinished(int tick) const {
    return basetask->IsFinished(tick);
}
bool ECSimStartDeadlineTask:: IsAborted(int tick) const {
    return ((tick > deadline) && !(on_time));
}
void ECSimStartDeadlineTask:: Run(int tick, int duration) 
{
    if(tick <= deadline)
    {
        on_time = true;
    }
    basetask->Run(tick, duration);
}
void ECSimStartDeadlineTask:: Wait(int tick, int duration) {
    basetask->Wait(tick, duration);
}
int ECSimStartDeadlineTask:: GetTotWaitTime() const {
    return basetask->GetTotWaitTime();
}
int ECSimStartDeadlineTask:: GetTotRunTime() const {
    return basetask->GetTotRunTime();
}


// your code here

//***********************************************************
// Task must end by some fixed time click: this is useful e.g. when a task is periodic

ECSimEndDeadlineTask :: ECSimEndDeadlineTask(ECSimTask *pTask, int tmEndDeadlineIn): basetask(pTask), deadline(tmEndDeadlineIn) 
{}

// your code here
bool ECSimEndDeadlineTask:: IsReadyToRun(int tick) const {
    return ((basetask->IsReadyToRun(tick)) && (tick <= deadline));
}
bool ECSimEndDeadlineTask:: IsFinished(int tick) const {
    return ((basetask->IsFinished(tick)) || (tick > deadline));
}
bool ECSimEndDeadlineTask:: IsAborted(int tick) const {
    return (!(basetask->IsFinished(tick)) && (tick > deadline));
}
void ECSimEndDeadlineTask:: Run(int tick, int duration) {
    basetask->Run(tick, duration);
}
void ECSimEndDeadlineTask:: Wait(int tick, int duration) {
    basetask->Wait(tick, duration);
}
int ECSimEndDeadlineTask:: GetTotWaitTime() const {
    return basetask->GetTotWaitTime();
}
int ECSimEndDeadlineTask:: GetTotRunTime() const {
    return basetask->GetTotRunTime();
}
//***********************************************************
// Composite task: contain multiple sub-tasks
/*
ECSimCompositeTask :: ECSimCompositeTask(const std::string &tidIn) 
{
}
*/

// your code here
