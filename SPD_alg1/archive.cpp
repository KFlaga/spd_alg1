

/*
int Scheduler::isSinkOrSource(Job* job)
{
	if( remainingSubset.size() == 0 )
		return 1;
	// first pop 'job' of remaining set
	remainingSubset.sort(HaveLesserR);
	int min_r;
	min_r = (*remainingSubset.begin())->r;

	int min_q;
	remainingSubset.sort(HaveLesserR);
	min_q = (*remainingSubset.begin())->q;

	int sum_p = 0;
	for( list<Job*>::iterator jit = remainingSubset.begin(); jit != remainingSubset.end(); jit++)
		sum_p += (*jit)->p;
	
	//if( min_r + sum_p + min_q + job->p <= curBound ) // not sink or source
	//	return 0;
	//if( min_r + sum_p + job->p + job->q > curBound ) // not source
	//	return 1;
	if( job->r + sum_p + job->p + min_q > curBound ) // is not a source
		return 0;
	else 
		return 1;
}

void Scheduler::FindBetterSchedule()
{
	remainingSubset.assign(jobs.begin(), jobs.end());

	int min_r,min_q,sum_p = 0;
	remainingSubset.sort(HaveLesserR);
	min_r = (*remainingSubset.begin())->r;

	remainingSubset.sort(HaveLesserR);
	min_q = (*remainingSubset.begin())->q;

	for( list<Job*>::iterator jit = remainingSubset.begin(); jit != remainingSubset.end(); jit++)
		sum_p += (*jit)->p;

	// first find lower bound
	int lowerBound = min_r + sum_p + min_q;

	// get some other bound - LB is usually immposible, so lets CB = (LB + schrage)/2
	// in every iteration it will get lower if found better option or higher if not
	int upperBound;
	Schrage(upperBound);
	//curBound = (lowerBound + upperBound)/2;
	curBound = lowerBound;
	int Cmax = 0;
	while(1)
	{
		int schedFreeFront = 0;
		int schedFreeBack = jobs.size() - 1;
		int notFoundBetterSched = false;
		for(int i = 0; i < jobs.size(); i++ )
		{
			Job* job;
			list<Job*>::iterator jit = remainingSubset.begin();
			list<Job*>::iterator lastjob = remainingSubset.end()--;
			bool foundSoS = false;
			while( jit != lastjob )
			{
				job = (*jit);
				jit = remainingSubset.erase(jit);
				int isSoS = isSinkOrSource(job);
				if( isSoS == 0 ) // not SoS
					remainingSubset.push_front(job);
				else if( isSoS == 1 ) // source
				{
					schedule[schedFreeFront++] = job;
					foundSoS = true;
					break;
				}
				else
				{
					schedule[schedFreeBack--] = job;
					foundSoS = true;
					break;
				}
			}
			schedule[schedFreeFront] = *lastjob;
			if( !foundSoS ) // no more does any job fullfill conds, so rise the bound and repeat
			{
				notFoundBetterSched = true;
				break;
			}
		}
		findCmax(Cmax);
		if( notFoundBetterSched )
		{
			lowerBound = curBound;
			curBound = (curBound + upperBound)/2;
			if( abs(lowerBound - curBound) <= 2 ) // between current result and optimal difference is small enough
				break;
		}
		else
		{
			upperBound = curBound;
			curBound = (curBound + lowerBound)/2;
			if( abs(upperBound - curBound) <= 2 )
				break;
		}
	}
}*/
