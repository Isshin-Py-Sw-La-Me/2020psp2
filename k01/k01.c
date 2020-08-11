#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double ave_online(int i, double val, double ave){
    ave = ((i-1)*ave+val)/i;
    return ave;
}

double var_online(int i,double val,double s,double ave){
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
    double val,p,s_mean,s_variance,p_mean,p_variance,save=0,ave=0,save_new,var,ave_new;
    while(fgets(buf,sizeof(buf),fp) !=NULL){
        sscanf(buf,"%lf",&val);
        i++;
        ave_new = ave_online(i, val, ave);
        var = var_online(i, val, save, ave);
        save_new = ave_online(i, val*val, save); 
        ave = ave_new;
        save = save_new;
    }

    p_variance=i*var/(i-1);
        p_mean=ave;
        p=pow(p_variance/i,0.5);

    printf("s_mean: %lf\n",ave );
    printf("s_variance:%lf\n",s_variance );
    printf("p_mean:%lf p:%lf\n", ave,p);
    printf("p_variance:%lf\n", p_variance);

    return 0;
}

// ADD DATA: 253
// Ave: 182.678889
// Var: 6321.876543
