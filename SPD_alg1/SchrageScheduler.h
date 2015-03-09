#pragma once
#include <vector>
#include <list>
#include <queue>
#include "Job.h"

class SchrageScheduler
{
	std::vector<Job*> jobs;
	std::vector<int> schedule; // aka PI
	std::vector<int> endTimes; // aka C

	std::list<Job*> sortedSet; // aka N
	std::list<Job*> readySet; // aka G
	int Cmax;
public:
	SchrageScheduler(void) { }

	int Schrage();
	void SetJobs(std::vector<Job*> jobstoset) 
	{ 
		jobs.clear();
		jobs.assign(jobstoset.begin(), jobstoset.end());
	}
	std::vector<int>& GetSchedule() { return schedule; }
	std::vector<int>& GetEndTimes() { return endTimes; }
	std::vector<Job*>& GetJobs() { return jobs; }
	int GetCmax() { return Cmax; }
private:

};

