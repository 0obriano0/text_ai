#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <windows.h>

char loading_data[] = "load.txt";
char test_data[] = "test.txt";

double th = 5;

int num = 50000;

void create_data(char *s);

int main(){
	printf("請輸入規則地震:");
	scanf("%lf",&th);
	double th2 = 5;
	printf("請輸入規則風量:");
	scanf("%lf",&th2);
	th += th2; 
	printf("請輸入數量:");
	scanf("%d",&num);
	
	create_data(loading_data);
	Sleep(1000+th2);
	create_data(test_data); 
	
	printf("th = %lf \n",th);
	system("pause");
	return 0;
}

void create_data(char *s){
	FILE *pf;
	pf = fopen(s,"w");
	if(pf == NULL){
			printf("無法開啟檔案");
			return 0;
	}else{
		printf("\n------------------檔案設定完成------------------\n");
		srand((unsigned)time(NULL));
		for(int loopnum1 = 0; loopnum1 < num;loopnum1++){
			int data1 = rand()%9+1;
			int data2 = rand()%1000;
			int data3 = rand()%1000;
			double data[3];
			data[0] = data1 + data2*0.001 + data3*0.000001;
			data1 = rand()%9+1;
			data2 = rand()%1000;
			data3 = rand()%1000;
			data[1] = data1 + data2*0.001 + data3*0.000001;
			if(data[0]*1.35+data[1]<=th){
				data[2] = 0;
			}else{
				data[2] = 1;
			}
			fprintf(pf,"%.6lf %.6lf %.6lf",data[0],data[1],data[2]);
			if(loopnum1 < num-1)
				fprintf(pf,"\n");
		}
		printf("------------------------------------------------\n");
		fclose(pf);
	}
}
