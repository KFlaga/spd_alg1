#include "SchrageScheduler.h"
#include <algorithm>

using namespace std;

int SchrageScheduler::Schrage()
{
	// Inicjalizacja
	int t = 0;
	int Cmax = 0;
	schedule.clear();
	readySet.clear();
	endTimes.clear();
	endTimes.resize(jobs.size());
	sortedSet.assign(jobs.begin(),jobs.end());
	sortedSet.sort(HaveLesserR);

	while( !readySet.empty() || !sortedSet.empty() ) // Dopoki sa zadania do szeregowania
	{
		while( !sortedSet.empty() && (*sortedSet.begin())->r <= t ) // dodaj do zbioru gotowych zadania z r <= t
		{
			readySet.push_back((*sortedSet.begin()));
			sortedSet.pop_front();
		}
		if( readySet.empty() ) // jak w t nie ma gotowych zadan, to przesun t do pierwszego gotowego
		{
			t = (*sortedSet.begin())->r;
		}
		else
		{
			readySet.sort(HaveHigherQ);
			Job* job = (*readySet.begin()); // zadanie z najwy¿szym q 
			readySet.pop_front();			// wykonywane bedzie jako pierwsze
			schedule.push_back(job->nr);
			t = t + job->p;					// przesuwamy czas do wykonania sie tego zadania
			endTimes[job->nr] = t;			// i zapisujemy go i aktualizujemy Cmax
			Cmax = max(Cmax, t+job->q);
		}
	}

	return Cmax;
}












