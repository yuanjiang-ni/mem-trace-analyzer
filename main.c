#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "tracer.h"

int main(void){

	double st, ss;
	uint64_t N, M;
	int i = 0;
	struct trace_t* t, *nt;
	struct trace_generator* g;



	N = 4000000;
	M = 4*1024*1024;
	st = 1.01;
	ss = 0;
	
	srand(time(NULL));

	g = create_generator(N, M, st, ss);
	
	t = create_trace(1, 0);



	for(i = 2; i <= N; i++){
		printf("%lld %lld\n", 
			t->n, t->addr);
		nt = generate_one_trace(g, t);
		free(t);
		t = nt;
	}
	printf("%lld %lld\n", 
		t->n, t->addr);

	return 1;
}

