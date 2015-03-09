#include "CarlierScheduler.h"

#define loc_job(j) jobs[locSchrage.GetSchedule()[(j)]] // praca j-ta z rozk³adu obecnego wêz³a

int CarlierScheduler::Carlier()
{
	Cmax = 0;
	globalUpperBound = 999999;

	recCarlier();

	Cmax = globalUpperBound;
	return Cmax;
}

void CarlierScheduler::recCarlier()
{
	SchrageScheduler locSchrage;
	locSchrage.SetJobs(jobs);
	int bound = locSchrage.Schrage();
	if(bound < globalUpperBound)
	{
		globalUpperBound = bound;
		schedule.assign(locSchrage.GetSchedule().begin(), locSchrage.GetSchedule().end());
	}

	int a,b,c;
	int minR, minQ, sumP;
	findCritParms(a,b,c,locSchrage,minR,sumP,minQ);
	if( c == -1 )
		return;

	int rc = loc_job(c)->r ;
	loc_job(c)->r = std::max(loc_job(c)->r,minR+sumP);
	// LB is h((c+1,b)) for now
	int lowerBound = minR + sumP + minQ;
	if( lowerBound < globalUpperBound )
		recCarlier();
	loc_job(c)->r = rc;

	int qc = loc_job(c)->q ;
	loc_job(c)->q = std::max(loc_job(c)->q,minQ+sumP);
	// LB is h((c+1,b)) for now
	//lowerBound = minR + sumP + minQ;
	if( lowerBound < globalUpperBound )
		recCarlier();
	loc_job(c)->q = qc;
}

void CarlierScheduler::findCritParms(int& a, int& b, int& c, SchrageScheduler& locSchrage, int& minr, int& sumP, int& minq)
{
	// b - max j : Cmax = C(j) + q(j)
	// a - min j : Cmax = r(j) + sum(k=j,b){p(k)} + q(b)
	// c - max a<j<b : q(j) < q(b)
	a = b = c = -1;

	int tempSumP = 0; 
	for(int j = 0; j < locSchrage.GetSchedule().size(); j++)
	{
		tempSumP += loc_job(j)->p; // wyznaczamy b, a jednoczesnie sumê p od j = 0 do j = b, potrzebn¹ do a
		if( locSchrage.GetCmax() == locSchrage.GetEndTimes()[locSchrage.GetSchedule()[j]] +  loc_job(j)->q )
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

	if( c == -1 )
		return;

	sumP = 0, minr = 99999, minq = 99999;
	for(int j = c+1; j <= b; j++)
	{
		minr = std::min(minr, loc_job(j)->r);
		minq = std::min(minq, loc_job(j)->q);
		sumP += loc_job(j)->p;
	}
}

// http://www.kierunkizamawiane.pwr.wroc.pl/materialy/smut.pdf
// strony:
// - 140
// - 143dol/144
// - 160+

// http://dominik.zelazny.staff.iiar.pwr.wroc.pl/materialy/Algorytm_Carlier.pdf
// http://mariusz.makuchowski.staff.iiar.pwr.wroc.pl/download/courses/sterowanie.procesami.dyskretnymi/lab.instrukcje/lab05.carlier/literatura/algorytm.C.%5BMBwZSZ%5D.pdf