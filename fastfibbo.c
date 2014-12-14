#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define FIBBONUM 1000000000


unsigned long long int fibbo(unsigned long long int num){
	unsigned long long x1 = 0;
	unsigned long long x2 = 1;
	unsigned long long x3 = 1;
//	unsigned long long int i;
//	for(i = 0; i < num; i++){
	while(num--){
		x3 = x1;
		x1 = x2;
		x2 += x3;
	}
	return x2;
}
unsigned long long int dfibbo4(unsigned long long int num){
	unsigned long long x1 = 0;
	unsigned long long x2 = 1;
	unsigned long long x3 = 1;
	unsigned long long n = (num + 3)/4;
	switch(num % 4){
		case 0:x3 = x1;x1 = x2;x2 += x3;
		case 3:x3 = x1;x1 = x2;x2 += x3;
		case 2:x3 = x1;x1 = x2;x2 += x3;
		case 1:x3 = x1;x1 = x2;x2 += x3;
	}
	while (--n){
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
	}
	return x2;
}
unsigned long long int dfibbo8(unsigned long long int num){
	unsigned long long x1 = 0;
	unsigned long long x2 = 1;
	unsigned long long x3 = 1;
	unsigned long long n = (num + 7)/8;
	switch(num % 8){
		case 0:x3 = x1;x1 = x2;x2 += x3;
		case 7:x3 = x1;x1 = x2;x2 += x3;
		case 6:x3 = x1;x1 = x2;x2 += x3;
		case 5:x3 = x1;x1 = x2;x2 += x3;
		case 4:x3 = x1;x1 = x2;x2 += x3;
		case 3:x3 = x1;x1 = x2;x2 += x3;
		case 2:x3 = x1;x1 = x2;x2 += x3;
		case 1:x3 = x1;x1 = x2;x2 += x3;
	}
	while (--n){
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
	}
	return x2;
}
unsigned long long int dfibbo16(unsigned long long int num){
	unsigned long long x1 = 0;
	unsigned long long x2 = 1;
	unsigned long long x3 = 1;
	unsigned long long n = (num + 15)/16;
	switch(num % 16){
		case 0:x3 = x1;x1 = x2;x2 += x3;
		case 15:x3 = x1;x1 = x2;x2 += x3;
		case 14:x3 = x1;x1 = x2;x2 += x3;
		case 13:x3 = x1;x1 = x2;x2 += x3;
		case 12:x3 = x1;x1 = x2;x2 += x3;
		case 11:x3 = x1;x1 = x2;x2 += x3;
		case 10:x3 = x1;x1 = x2;x2 += x3;
		case 9:x3 = x1;x1 = x2;x2 += x3;
		case 8:x3 = x1;x1 = x2;x2 += x3;
		case 7:x3 = x1;x1 = x2;x2 += x3;
		case 6:x3 = x1;x1 = x2;x2 += x3;
		case 5:x3 = x1;x1 = x2;x2 += x3;
		case 4:x3 = x1;x1 = x2;x2 += x3;
		case 3:x3 = x1;x1 = x2;x2 += x3;
		case 2:x3 = x1;x1 = x2;x2 += x3;
		case 1:x3 = x1;x1 = x2;x2 += x3;
	}
	while (--n){
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
		x3 = x1;x1 = x2;x2 += x3;
	}
	return x2;
}

int main(const int argc, const char ** argv){
	struct timespec tstart={0,0}, tend = {0,0};
	unsigned int i;
	unsigned long long int fout1 = fibbo(FIBBONUM); //to warm up processor and correctness checks
	unsigned long long int fout2;
	unsigned long long int fout3;
	unsigned long long int fout4;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i < 5;i++){
		fout1 = fibbo(FIBBONUM);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	double time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	time/= (double)i;
	printf("fibbo is %llu, time = %.5f\n", fout1, time);

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i < 5; i++){
		fout2 = dfibbo4(FIBBONUM);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	time/= (double)i;
	printf("dfibbo4 is %llu, time = %.5f\n", fout2, time);

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i < 5; i++){
		fout3 = dfibbo8(FIBBONUM);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	time/= (double)i;
	printf("dfibbo8 is %llu, time = %.5f\n", fout3, time);

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i < 5; i++){
		fout4 = dfibbo16(FIBBONUM);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	time/= (double)i;
	printf("dfibbo16 is %llu, time = %.5f\n", fout4, time);
	if(fout1 != fout2 || fout1 != fout3 || fout1 != fout4) printf("Correctness check failed! %llu vs %llu vs %llu vs %llu\n", fout1, fout2, fout3, fout4);
	return 0;
}
