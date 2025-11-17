// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

#define REPEAT 5
static int *copy_array(const int *src, size_t n){int *dst=malloc(n*sizeof(int));memcpy(dst,src,n*sizeof(int));return dst;}
double run_and_average(void (*fn)(int*,size_t,Metrics*), const int *arr, size_t n, Metrics *out_m){
    double total_ms=0; long long total_steps=0;
    for(int i=0;i<REPEAT;i++){
        int *tmp=copy_array(arr,n);
        Metrics m; reset_metrics(&m);
        clock_t t0=clock(); fn(tmp,n,&m); clock_t t1=clock();
        total_ms+=1000.0*(t1-t0)/CLOCKS_PER_SEC;
        total_steps+=m.steps_cmp+m.steps_swap;
        free(tmp);
    }
    long long avg=total_steps/REPEAT;
    out_m->steps_cmp=avg;
    return total_ms/REPEAT;
}
static int *gen_random_vec(size_t n,int maxv){int *v=malloc(n*sizeof(int));for(size_t i=0;i<n;i++)v[i]=rand()%(maxv+1);return v;}
int main(){
    srand(time(NULL));
    const char *rgm="045620920";
    size_t rl=strlen(rgm);
    int *rv=malloc(rl*sizeof(int));
    for(size_t i=0;i<rl;i++) rv[i]=rgm[i]-'0';
    size_t Ns[3]={100,1000,10000};
    printf("metodo,N,caso,passos,tempo_ms
");
    Metrics m; double t;
    t=run_and_average(insertion_sort,rv,rl,&m); printf("insertion,%zu,rgm,%lld,%.3f
",rl,m.steps_cmp,t);
    t=run_and_average(quick_sort,rv,rl,&m); printf("quick,%zu,rgm,%lld,%.3f
",rl,m.steps_cmp,t);
    t=run_and_average(merge_sort,rv,rl,&m); printf("merge,%zu,rgm,%lld,%.3f
",rl,m.steps_cmp,t);
    for(int k=0;k<3;k++){
        size_t N=Ns[k];
        int *base=gen_random_vec(N,1000000);
        t=run_and_average(insertion_sort,base,N,&m); printf("insertion,%zu,aleatorio,%lld,%.3f
",N,m.steps_cmp,t);
        t=run_and_average(quick_sort,base,N,&m); printf("quick,%zu,aleatorio,%lld,%.3f
",N,m.steps_cmp,t);
        t=run_and_average(merge_sort,base,N,&m); printf("merge,%zu,aleatorio,%lld,%.3f
",N,m.steps_cmp,t);
        free(base);
    }
    free(rv); return 0;
}