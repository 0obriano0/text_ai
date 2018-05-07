#include <stdio.h>
#include <stdlib.h>
#include <iostream>

char loading_data[] = "load.txt";
char test_data[] = "test.txt";

double th = 4.533;

int main(){
	FILE *pf;
	pf = fopen(loading_data,"r");
	if(pf == NULL){
			printf("無法開啟檔案\n");
	}else{
		printf("\n------------------檔案設定完成------------------\n");
		while(!feof(pf)){
			double data[2];
			double answer;
			fscanf(pf,"%lf%lf",&data[0],&data[1]);
			//printf("判定 %lf 有沒有倒 %lf\n",data[0],data[1]);
			if(data[0] <= th){
				answer = 0;
			}else{
				answer = 1;
			}
			while(answer != data[1]){
				if(data[0] <= th){
					answer = 0;
				}else{
					answer = 1;
				}
				if(data[0] <= th){
					th-=0.000001;
				}else{
					th+=0.000001;
				}
				//printf("目前 th =  %lf\n",th);
			}
		}
		printf("------------------------------------------------\n");
		fclose(pf);
		printf("th = %lf \n",th);
	}
	int true_num = 0;
	int false_num = 0;
	pf = fopen(test_data,"r");
	FILE *pf2;
	pf2 = fopen("testfinish.txt","w");
	if(pf == NULL){
			printf("無法開啟檔案\n");
	}else{
		printf("\n------------------檔案設定完成------------------\n");
		while(!feof(pf)){
			double data[3];
			double answer;
			fscanf(pf,"%lf%lf",&data[0],&data[1]);
			//printf("判定 %lf 有沒有倒 %lf\n",data[0],data[1]);
			if(data[0] <= th){
				data[2] = 0;
			}else{
				data[2] = 1;
			}
			fprintf(pf2,"%.6lf %.0lf %.0lf\n",data[0],data[1],data[2]);
			if(data[2] == data[1]){
				true_num += 1;
			}else{
				false_num +=1;
				printf("判定 %lf",data[0]);
				if(data[2])
					printf("有倒 正確的值為 沒倒\n");
				else
					printf("沒倒 正確的值為 有倒\n");
			}
		}
		printf("------------------------------------------------\n");
		fclose(pf);
		//printf("th = %lf \n",th);
	}
	printf("正確   : %7d \n錯誤   : %7d \n正確率 : %6d%% \n",true_num,false_num,true_num*100/(true_num+false_num));
	system("pause");
	return 0;
}
