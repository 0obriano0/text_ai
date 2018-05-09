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
			printf("�L�k�}���ɮ�\n");
	}else{
		printf("\n-------------------�ɮ׾ǲߤ�-------------------\n");
		while(!feof(pf)){
			double data[3];
			double answer;
			fscanf(pf,"%lf%lf%lf",&data[0],&data[1],&data[2]);
			//printf("�P�w %lf ���S���� %lf\n",data[0],data[1]);
			if(data[0]*1.35 + data[1]<= th){
				answer = 0;
			}else{
				answer = 1;
			}
			while(answer != data[2]){
				if(data[0]*1.35 + data[1] <= th){
					answer = 0;
				}else{
					answer = 1;
				}
				if(data[0]*1.35 + data[1] <= th){
					th-=0.000001;
				}else{
					th+=0.000001;
				}
				//printf("�ثe th =  %lf\n",th);
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
			printf("�L�k�}���ɮ�\n");
	}else{
		printf("\n-------------------�ɮ����Ҥ�-------------------\n");
		while(!feof(pf)){
			double data[4];
			double answer;
			fscanf(pf,"%lf%lf%lf",&data[0],&data[1],&data[2]);
			//printf("�P�w %lf ���S���� %lf\n",data[0],data[1]);
			if(data[0]*1.35 + data[1] <= th){
				data[3] = 0;
			}else{
				data[3] = 1;
			}
			fprintf(pf2,"%.6lf %.6lf %.0lf %.0lf\n",data[0],data[1],data[2],data[3]);
			if(data[2] == data[3]){
				true_num += 1;
			}else{
				false_num +=1;
				printf("�P�w %lf , %lf",data[0],data[1]);
				if(data[3])
					printf("���� ���T���Ȭ� �S��\n");
				else
					printf("�S�� ���T���Ȭ� ����\n");
			}
		}
		printf("------------------------------------------------\n");
		fclose(pf);
		//printf("th = %lf \n",th);
	}
	printf("���T   : %7d \n���~   : %7d \n���T�v : %6d%% \n",true_num,false_num,true_num*100/(true_num+false_num));
	system("pause");
	return 0;
}
