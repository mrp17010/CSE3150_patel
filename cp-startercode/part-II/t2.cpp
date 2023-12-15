#include "ECSimTask3.h"
#include "ECSimTaskScheduler3.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "****Test6\n";
    // FIFO scheduler: two simple tasks
    ECSimIntervalTask t11("t11", 1, 4);
    ECSimIntervalTask t12("t12", 7,9);
    ECSimIntervalTask t2("t2", 8, 13 );
    // create a composite
    ECSimCompositeTask t1c("t1c");
    t1c.AddSubtask(&t11);
    t1c.AddSubtask(&t12);
    // periodic with wait gap 2
    ECSimPeriodicTask t1cp(&t1c, 2);
    // ending deadline
    ECSimEndDeadlineTask t1cep(&t1cp, 18);
    
    ECSimFIFOTaskScheduler scheduler;
    // t2 is earlier!
    scheduler.AddTask(&t2);
    scheduler.AddTask(&t1cp);
    int tmSimTot = 20;
    //int tmSimRun = scheduler.Simulate(tmSimTot);

    for(int i = 0; i<=tmSimTot; i++)
    {
        cout << i <<":"<< t1cp.IsReadyToRun(i) << endl;
        if(t1cp.IsReadyToRun(i))
        {
            t1cp.Run(i, 1);
            cout << "running" <<endl;
        }
    }

    return 0;
}