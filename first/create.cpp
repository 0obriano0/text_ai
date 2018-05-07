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

int main(){
	printf("請輸入規則th=");
	scanf("%lf",&th);
	FILE *pf;
	pf = fopen(loading_data,"w");
	if(pf == NULL){
			printf("無法開啟檔案");
			return 0;
	}else{
		printf("\n------------------檔案設定完成------------------\n");
		srand((unsigned)time(NULL));
		for(int loopnum1 = 0; loopnum1 < num;loopnum1++){
			int data1 = rand()%9+1;
			int data2 = rand()%1000;
			double data[2];
			data[0] = data1 + data2*0.001;
			if(data[0]<=th){
				data[1] = 0;
			}else{
				data[1] = 1;
			}
			fprintf(pf,"%.3lf %.3lf\n",data[0],data[1]);
		}
		printf("------------------------------------------------\n");
		fclose(pf);
	}
	Sleep(1000+th);
	
	pf = fopen(test_data,"w");
	if(pf == NULL){
			printf("無法開啟檔案");
			return 0;
	}else{
		printf("\n------------------檔案設定完成------------------\n");
		srand((unsigned)time(NULL));
		for(int loopnum1 = 0; loopnum1 < num;loopnum1++){
			int data1 = rand()%9+1;
			int data2 = rand()%1000;
			double data[2];
			data[0] = data1 + data2*0.001;
			if(data[0]<=th){
				data[1] = 0;
			}else{
				data[1] = 1;
			}
			fprintf(pf,"%.3lf %.3lf\n",data[0],data[1]);
		}
		printf("------------------------------------------------\n");
		fclose(pf);
	}
	printf("th = %lf \n",th);
	system("pause");
	return 0;
}
