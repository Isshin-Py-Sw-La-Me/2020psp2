#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(int i, double val, double ave){
    ave = ((i-1)*ave2+val)/i;
    return ave;
}

extern double var_online(int i,double val,double s,double ave){
    return ((i-1)*s+val*val)/i-pow((((i-1)*ave+val)/i),2);
}

int main(void){

    FILE *fp;
    char *fname = "heights_male.csv";
    char buf[256];

    fp = fopen(fname,"r");
    if(fp==NULL){
        printf("Not open¥n");
        return -1;
    }

    int i = 0;
    double val,ave,p,s_mean,s_variance,p_mean,p_variance,s=0,ave2=0;
    while(fgets(buf,sizeof(buf),fp) !=NULL){
        sscanf(buf,"%lf",&val);
        i++;
        ave = ave_online(i,val,ave);
        s_variance=var_online(i,val,s,ave2);
        s=((i-1)*save+val*val)/i;
        ave2=((i-1)*ave2+val)/i;
        s_mean=ave;

        p_variance=i*s_variance/(i-1);
        p_mean=s_mean;
        p=pow(p_variance/i,0.5);
    }

    printf("s_mean: %lf\n",s_mean );
    printf("s_variance:%lf\n",s_variance );
    printf("p_mean:%lf p:%lf\n", p_mean,p);
    printf("p_variance:%lf\n", p_variance);

    return 0;
}


