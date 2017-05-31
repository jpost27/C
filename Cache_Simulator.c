#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

typedef struct{
	int valid;
	int LFUcounter;
	time_t LRUcounter;
	long long tag;
	}line;


int getSetIndex(long long a, int m, int S, int b);
long long getTag(long long a, int m, int S, int b);
int hit(line** l, int s, long long tag, int rp, int E);
line** sets;

int main(void)
{
	//GET S,E,B,m,t
	int S=0,E=0,B=0,m=0,t=0,b=0,s=0;
	//#SETS
	printf("\nS = ");
	scanf("%d",&S);
	s=log(S)/log(2);
	//#LINES PER SET
	printf("\nE = ");
        scanf("%d",&E);
	//#BYTES STORED PER LINE
	printf("\nB = ");
        scanf("%d",&B);
        b=log(B)/log(2);
	//TOTAL # OF BITS
	printf("\nm = ");
        scanf("%d",&m);


	//CREATE CACHE
	sets = (line**)malloc(sizeof(line*)*E*S);
	int i;
	for (i = 0; i < S; ++i)
    	sets[i] = (line *)malloc(E * sizeof(line));
	int j,k;
    for(j = 0; j < S; j++)
    {
        for(k = 0; k < E; k++)
        {
            sets[j][k].valid = 0;
		}	
    }
	
	//GET Replacement Policy
	printf("\nReplacement Policy(LFU/LRU) = ");
	char *rpolicy = (char*) malloc(3);
	scanf("%s",rpolicy);
	//rp = 0 if LFU
	int rp = (strcmp(rpolicy,"LFU")!=0);

	//GET h,p
	int h=0,p=0;
	//HIT TIME
	printf("\nh = ");
	scanf("%d",&h);
	//MISS PENALTY
	printf("\np = ");
	scanf("%d",&p);

	//START OF CACHE SIMULATION
	printf("Input addresses, -1 to quit:\n");
	long long address;
	scanf("%lld", &address);
	int misses=0, cycles=0;

	while(address!=-1)
	{
		int w = sets[1][0].valid;
		if(hit(sets,getSetIndex(address,m,S,b),getTag(address,m,s,b),rp, E)==0){
			printf("%llx, M\n",address);//MISS
			misses++;
		}
		else
			printf("%llx, H\n",address);//HIT
		cycles++;
		scanf("%lld", &address);
	}
	if(cycles==0)
		return 0;
	int missrate = (misses*100)/cycles;
	cycles = (cycles*h)+(misses*p);
	printf("\n%d %d\n",missrate, cycles);
	return 0;
}

int getSetIndex(long long a, int m, int S, int b){
	if(S<=1)
		return 0;
	return (int)(a>>b) & (S-1);
}

long long getTag(long long a, int m, int s, int b){
	return (a & ( (1<<(m+1))-1) ) >> (s+b);
}


int hit(line** l, int s, long long tag, int rp, int E){
	int x=0,empty=-1;
	for(x=0;x<E;x++){
		if(l[s][x].valid==1){
			if(l[s][x].tag==tag){
				l[s][x].LFUcounter++;
				l[s][x].LRUcounter = time(0);
				return 1;//HIT!
			}
		}
		else{
			empty=x;
		}
	}
	//Miss
	if(empty!=-1){
		l[s][empty].valid=1;
		l[s][empty].tag=tag;
		l[s][empty].LFUcounter=0;
		l[s][empty].LRUcounter=time(0);
	}
	//NEED TO MAKE ROOM IN THE SET
	int least=l[s][0].LFUcounter,index=0;
	time_t t = time(0);
	if(rp==0){	//LFU
		for(x=0;x<E;x++){
			if(least > l[s][x].LFUcounter){
				least = l[s][x].LFUcounter;
				index=x;
			}
		}
	}
	else{		//LRU
		for(x=0;x < E;x++){
			if(difftime(t, l[s][x].LRUcounter)>0){
				t = l[s][x].LRUcounter;
				index=x;
			}
		}
	}
	l[s][index].valid=1;
	l[s][index].tag=tag;
	l[s][index].LFUcounter=0;
	l[s][index].LRUcounter=time(0);
	return 0;
}
