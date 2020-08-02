#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct D{double ID;int sex;double height;};

int main(void){
	int i=-1,j=0;
	double val,id,ID;
	char fname[FILENAME_MAX],fname2[FILENAME_MAX],buf[256],buf2[256];
	FILE* fp,*fp2;
	int n_m,n_f,n_un,all;
	int sex;
	double lower,upper;
	struct D data[14];
	int n = 0;

	printf("input the filename of smaple height\n");
	fgets(fname,sizeof(fname),stdin);
	fname[strlen(fname)-1]='\0';
	printf("the file name of sample: %s\n",fname );

	printf("input the filename of sample ID\n");
	fgets(fname2,sizeof(fname2),stdin);
	fname2[strlen(fname2)-1] = '\0';
	printf("the filename of sample: %s\n",fname2 );

	fp = fopen(fname,"r");
	if(fp==NULL){
		fputs("File open error\n",stderr);
		exit(EXIT_FAILURE);
	}

	fp2 = fopen(fname2,"r");
	if(fp==NULL){
		fputs("File open error\n",stderr);
		exit(EXIT_FAILURE);
	}

	n_m=n_f=n_un=0;
	while(fgets(buf,sizeof(buf),fp) !=NULL){
		sscanf(buf,"%d,%lf",&sex,&val);
		i++;
		data[i].sex = sex;
		data[i].height = val;
		if(sex==1){
			n_m++;
		}else if(sex==2){
			n_f++;
		}else{
			n_un++;
		}
	}
	all = n_m+n_f+n_un;

	i=0;
	printf("which ID's data do you want?\n");
	scanf("%lf",&id);
	printf("---\n");

	while(fgets(buf2,sizeof(buf2),fp2) != NULL){
		sscanf(buf2,"%lf",&ID);
		i++;
		data[i].ID = ID;
	}

		for(i=1;i<=all;i++){
			if(data[i].ID == id){
				printf("ID:%.0lf\n",data[i].ID );
				printf("gender:");
				if(data[i].sex==1){
					printf("male\n");
				}else{
					printf("female\n");
				}
				printf("height:%.1lf\n",data[i].height );
				n=1;
			}
		}
		if(n==0){
			printf("No data\n");
		}
		printf("---\n");


		if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    	}

    	if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    	}

    	return 0;
}