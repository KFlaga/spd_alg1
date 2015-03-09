#pragma once
#include <vector>
#include "Job.h"
#include "SchrageScheduler.h"

class CarlierScheduler
{
	std::vector<Job*> jobs;
	std::vector<int> schedule; // best one
	std::vector<int> endTimes; // best ones

	int Cmax;
public:
	CarlierScheduler() { }

	void SetJobs(std::vector<Job*> jobstoset) 
	{ 
		jobs.clear();
		jobs.assign(jobstoset.begin(), jobstoset.end());
	}
	std::vector<int>& GetSchedule() { return schedule; }
	std::vector<int>& GetEndTimes() { return endTimes; }
	std::vector<Job*>& GetJobs() { return jobs; }

	int Carlier();
private:
	void startCarlier();
	void recCarlier();
};