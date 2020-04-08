#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double ave_online(double val,double ave,int count){
    return ((count-1)*ave + val)/count;
}

double var_online(double new_data,double ave,double ave2,double new_ave,int count){
    return ((count-1)/count*ave2+pow(new_data,2)/count) - pow(((count-1)/count*ave+new_data/count),2);
}

int main(void){

    FILE *fp;
    char *fname = "heights_male.csv";
    double data,new_data,total=0,total2=0,ave,ave2,var;
    int count=0;

    fp = fopen(fname,"r");
    if(fp==NULL){
        printf("Not open¥n");
        return -1;
    }

    //オリジナルデータ
    while(fscanf(fp,"%lf",&data) != EOF){
        total += data;
        total2 += pow(data,2);
        count++;
    }
    ave = total/count;
    ave2 = total2/count;

    double new_ave,new_var;
    //データ追加
    printf("ADD DATA: ");
    scanf("%lf",&new_data);
    count++;
    new_ave = ave_online(new_data,ave,count);
    new_var = var_online(new_data,ave,ave2,new_ave,count);
    printf("Ave: %lf\nVar: %lf\n",new_ave,new_var);
    return 0;
}


