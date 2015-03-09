#include "Job.h"

bool HaveHigherR( Job* a, Job* b )
{
	return a->r > b->r;
}

bool HaveHigherP( Job* a, Job* b )
{
	return a->p > b->p;
}

bool HaveHigherQ( Job* a, Job* b )
{
	return a->q > b->q;
}

bool HaveLesserQ( Job* a, Job* b )
{
	return a->q < b->q;
}

bool HaveLesserR( Job* a, Job* b )
{
	return a->r < b->r;
}

bool HaveLesserP( Job* a, Job* b )
{
	return a->p < b->p;
}