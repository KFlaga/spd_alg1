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

void CarlierScheduler::findCritPath(int& a, int& b, int& c, SchrageScheduler& locSchrage)
{
	// b - max j : Cmax = C(j) + q(j)
	// a - min j : Cmax = r(j) + sum(k=j,b){p(k)} + q(b)
	// c - max a<j<b : q(j) < q(b)
	a = b = c = -1;
#define loc_job(j) jobs[locSchrage.GetSchedule()[(j)]] // praca j-ta z rozk³adu obecnego wêz³a

	int sumP, tempSumP = 0; 
	for(int j = 0; j < locSchrage.GetSchedule().size(); j++)
	{
		tempSumP += loc_job(j)->p; // wyznaczamy b, a jednoczesnie sumê p od j = 0 do j = b, potrzebn¹ do a
		if( locSchrage.GetCmax() == locSchrage.GetEndTimes()[j] +  loc_job(j)->q )
		{
			b = j;
			sumP = tempSumP;
		}
	}

	for(int j = 0; j < locSchrage.GetSchedule().size(); j++)
	{
		if( locSchrage.GetCmax() ==  loc_job(j)->r + sumP + loc_job(b)->q )
		{
			a = j;
			break;
		}
		sumP -= loc_job(j)->p;
	}

	for(int j = a; j <= b; j++)
	{
		if( loc_job(j)->q < loc_job(b)->q )
			c = j;
	}
}

/*
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
*/
