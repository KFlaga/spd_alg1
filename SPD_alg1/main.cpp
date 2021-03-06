#include <iostream>
#include <fstream>
#include <vector>
#include "Job.h"
#include "SchrageScheduler.h"
#include "CarlierScheduler.h"

using namespace std;

void LoadData(char*);
void ShowResults();

vector<Job*> jobs;
int Cmax;
vector<Job*> schedule;

int main()
{
	LoadData("in50.txt");
	SchrageScheduler sched;
	sched.SetJobs(jobs);
	Cmax = sched.Schrage();
	ShowResults();

	cout<<"\n\nTeraz Carlier\n\n";
	CarlierScheduler carlier;
	carlier.SetJobs(jobs);
	Cmax = carlier.Carlier();
	ShowResults();

	cin>>Cmax;

	return 0;
}

void LoadData(char* file)
{
	ifstream readFile;
	readFile.open(file);

	int jobCount;
	int x3;
	readFile>>jobCount>>x3;
	jobs.resize(jobCount);

	for(int j = 0; j < jobCount; j++)
	{
		Job* job = new Job();
		job->nr = j;
		readFile>>job->r>>job->p>>job->q;
		jobs[j] = job;
	}

	readFile.close();
}

void ShowResults()
{
	cout<<Cmax;
}