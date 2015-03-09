#pragma once

struct Job
{
	int nr;
	int r;
	int p;
	int q;
};

bool HaveHigherR( Job* a, Job* b );
bool HaveHigherP( Job* a, Job* b );
bool HaveHigherQ( Job* a, Job* b );
bool HaveLesserR( Job* a, Job* b );
bool HaveLesserP( Job* a, Job* b );
bool HaveLesserQ( Job* a, Job* b );