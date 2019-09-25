// IT18350906 - I.R Aushan
// Algorithms Assignment - Y2S2.03 (Weekend)
// Bsc CyberSecurity
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>

const int maximumVal = 55; //Maximum possible value for N
const int infiniteVal = 9999; //An infinite Variable 
using namespace std;

int M,N;  // Variable Declaration
int MemoryBlockSize[maximumVal],TimeVector[maximumVal], programSize[maximumVal];
int cas = 1; 

void functionAlpha () {
	for (int i = 1; i <= M; i++) {
		scanf("%d", &MemoryBlockSize[i]); //storing the sizes of each partition
	}

	int s, t, k;
	int g,h, temp, temp2;
	int index=0;
	
	memset(TimeVector, infiniteVal, sizeof(TimeVector)); //filling the TimeVector array with infinite numbers
	for (int i = 1; i <= N; i++) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d%d", &s, &t);
			for (int j = 1; j <= M; j++){ 
            if (MemoryBlockSize[j] >= s)
				if(TimeVector[i] > t){
					TimeVector[i] = t;     //loading the programs with minimum excecution time in a given line to the TimeVector Array and their corresponding size into ProgramSize Array
					programSize[i] = s;
				}
			}
			}
		}
for(g=1;g<=N;g++)  //This loop is to sort the TimeVector Array and ProgramSize Array in the ascending order according to excecution time values
	{		
		for(h=g+1;h<=N;h++)
		{
			if(TimeVector[g]>TimeVector[h])
			{
				temp=TimeVector[g];
				temp2 =programSize[g];
				TimeVector[g]=TimeVector[h];
				programSize[g]=programSize[h];
				TimeVector[h]=temp;
				programSize[h]=temp2;
			}
		}
	}

int TimeX[M], TimeY[M];
int L[N], TimeZ[N];

for (int j = 1; j <= M; j++) TimeX[j] = TimeY[j] = 0;
for (int j = 1; j <= N; j++) L[j] = TimeZ[j] = 0;

int timetemp;

	for(int q=1; q <= N; q++){
		for(int w=1; w <= M; w++){
			if(MemoryBlockSize[w] >= programSize[q] && !L[q]){ //Compare the Memory Block size and the program size to determine whether there's sufficient space available in the memory block
				if(TimeX[w] == 0){                             // the !L[q] condition will make sure than the same program won't run multiple times and it'll store the memory region that the program excecuted on
					L[q] = w;
					TimeZ[q] = TimeX[w];
					TimeX[w] = TimeX[w] + TimeVector[q];
					TimeY[w] = TimeY[w] + TimeX[w];
				}
				else{
					timetemp = TimeX[w];
					for(int z=w; z <= M; z++){			//If the Time per memory block is not equal to 0; the program will check for the memory block that has sufficient space and lowest current excecution time
						if(timetemp >= TimeX[z]){
							index = z;
							timetemp = TimeX[z];
						}
					}
					L[q] = index;
					TimeZ[q] = TimeX[index];
					TimeX[index] = TimeX[index] + TimeVector[q];
					TimeY[index] = TimeY[index] + TimeX[index];
					}
				}
			}
		}

	double total = 0;  //Calculating the total value
	for(int x=1; x <= M; x++){
		total += TimeY[x];
	}

	double avg = 0; //calculating the average turn around time

	avg = total / N;

	//printing statements

	printf("Case %d\n", cas);
	printf("Average turnaround time is: %.2lf\n", avg);
	
	for(int h=1; h<=N; h++){
		printf("Program %d runs in region %d from %d to %d\n", h, L[h], TimeZ[h], (TimeZ[h] + TimeVector[h]) );
	}

	printf(" \n");
	cas ++;

}



int main(){
while (scanf("%d%d", &M, &N) == 2 && N != 0 && M !=0) { //The condition to check the N and M values and terminate the program if the values are 0
    functionAlpha();  //Everything happens here 
}
 return 0;
}

    


   