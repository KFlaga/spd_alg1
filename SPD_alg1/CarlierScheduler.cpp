#include "CarlierScheduler.h"

int CarlierScheduler::Carlier()
{
	Cmax = 0;
	startCarlier();
	return Cmax;
}

void CarlierScheduler::startCarlier()
{

}

void CarlierScheduler::recCarlier()
{

}

/*
int Scheduler::CarlierInit()
{
	int Cmax = 0;
	int upperBound;

	Cmax = Schrage();
	upperBound = Cmax;

	Cmax = Carlier(upperBound);

	return Cmax;
}

int Scheduler::Carlier(int upperBound)
{
	vector<Job*> localSched;
	localSched.assign(schedule.begin(), schedule.end());
	int Cmax = Schrage();
	if( Cmax < upperBound )
	{
		upperBound = Cmax;
		schedule.assign(localSched.begin(), localSched.end());
	}

	int a,b,c;
	find_abc(a,b,c, localSched);
	if( c == -1 )
	{
		return Cmax;
	}
	int min_r, min_q, sum_p;
	find_rpq(min_r, min_q, sum_p, localSched, b, c);

	int rc = schedule[c]->r ;
	schedule[c]->r = max(schedule[c]->r,min_r+sum_p);
	int lowerBound = findLowerBound(localSched);
	if( lowerBound < upperBound )
		Carlier(upperBound);
	schedule[c]->r = rc;

	int qc = schedule[c]->q ;
	schedule[c]->q = max(schedule[c]->r,min_q+sum_p);
	int lowerBound = findLowerBound(localSched);
	if( lowerBound < upperBound )
		Carlier(upperBound);
	schedule[c]->q = qc;
}

void Scheduler::find_abc(int& a, int& b, int& c, vector<Job*>& sched)
{
	// add Cmax to params
	int Cmax;
	vector<Job*> C;
	a = b = c = -1;
	for( int j = 0; j < sched.size(); j++ )
	{
		
	}
}*/
