//
//  ECSimTaskScheduler2.cpp
//  
//
//

#include <vector>
#include <iostream>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"

ECSimLWTFTaskScheduler::ECSimLWTFTaskScheduler(){}
ECSimTask * ECSimLWTFTaskScheduler::ChooseTaskToSchedule(const vector<ECSimTask *> &listReadyTasks) const
{
    if(listReadyTasks.size() > 0)
    {
        int max_ind = 0;
        int count = 0;
        for(auto i = listReadyTasks.begin(); i!=listReadyTasks.end(); i++, count++)
        {
            if( (*i)->GetTotWaitTime() > listReadyTasks[max_ind]->GetTotWaitTime())
            {
                max_ind = count;
            }
        }
        return listReadyTasks[max_ind];
    }
    else
    {
        return NULL;
    }

}


ECSimPriorityScheduler::ECSimPriorityScheduler(){}
ECSimTask * ECSimPriorityScheduler::ChooseTaskToSchedule(const vector<ECSimTask *> &listReadyTasks) const
{
    if(listReadyTasks.size() > 0)
    {
        int max_ind = 0;
        int count = 0;
        for(auto i = listReadyTasks.begin(); i!=listReadyTasks.end(); i++, count++)
        {
            if( (*i)->GetPriority() < listReadyTasks[max_ind]->GetPriority())
            {
                max_ind = count;
            }
        }
        return listReadyTasks[max_ind];
    }
    else
    {
        return NULL;
    }
}


ECSimRoundRobinTaskScheduler::ECSimRoundRobinTaskScheduler(){}
ECSimTask * ECSimRoundRobinTaskScheduler::ChooseTaskToSchedule(const vector<ECSimTask *> &listReadyTasks) const
{
    if(listReadyTasks.size() > 0)
    {
        int min_ind = 0;
        int count = 0;
        for(auto i = listReadyTasks.begin(); i!=listReadyTasks.end(); i++, count++)
        {
            if( (*i)->GetTotRunTime() < listReadyTasks[min_ind]->GetTotRunTime())
            {
                min_ind = count;
            }
        }
        return listReadyTasks[min_ind];
    }
    else
    {
        return NULL;
    }

}
