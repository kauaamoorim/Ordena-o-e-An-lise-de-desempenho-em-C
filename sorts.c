#include "sorts.h"
#include <stdlib.h>
#include <string.h>
#define COUNT_CMP(m) ((m)->steps_cmp++)
#define COUNT_SWAP(m) ((m)->steps_swap++)
void reset_metrics(Metrics *m){m->steps_cmp=0;m->steps_swap=0;}
void insertion_sort(int *v,size_t n,Metrics *m){
    for(size_t i=1;i<n;i++){int key=v[i];size_t j=i;
        while(j>0){COUNT_CMP(m); if(v[j-1]>key){v[j]=v[j-1];COUNT_SWAP(m);j--;} else break;}
        if(j!=i){v[j]=key;COUNT_SWAP(m);}
    }}
static void merge_internal(int *v,int *tmp,size_t l,size_t m,size_t r,Metrics *me){
    size_t i=l,j=m,k=l;
    while(i<m && j<r){COUNT_CMP(me); if(v[i]<=v[j]){tmp[k++]=v[i++];COUNT_SWAP(me);} else {tmp[k++]=v[j++];COUNT_SWAP(me);}}
    while(i<m){tmp[k++]=v[i++];COUNT_SWAP(me);}
    while(j<r){tmp[k++]=v[j++];COUNT_SWAP(me);}
    for(size_t p=l;p<r;p++){v[p]=tmp[p];COUNT_SWAP(me);}
}
static void merge_rec(int *v,int *tmp,size_t l,size_t r,Metrics *m){
    if(r-l<=1)return; size_t mid=l+(r-l)/2;
    merge_rec(v,tmp,l,mid,m); merge_rec(v,tmp,mid,r,m);
    merge_internal(v,tmp,l,mid,r,m);
}
void merge_sort(int *v,size_t n,Metrics *m){
    int *tmp=malloc(n*sizeof(int)); merge_rec(v,tmp,0,n,m); free(tmp);
}
static size_t part(int *v,size_t lo,size_t hi,Metrics *m){
    int p=v[hi-1]; size_t i=lo;
    for(size_t j=lo;j<hi-1;j++){COUNT_CMP(m); if(v[j]<p){int t=v[i];v[i]=v[j];v[j]=t;COUNT_SWAP(m); i++;}}
    int t=v[i];v[i]=v[hi-1];v[hi-1]=t;COUNT_SWAP(m);
    return i;
}
static void qrec(int *v,size_t lo,size_t hi,Metrics *m){
    if(hi-lo<=1)return; size_t p=part(v,lo,hi,m);
    if(p>lo) qrec(v,lo,p,m); qrec(v,p+1,hi,m);
}
void quick_sort(int *v,size_t n,Metrics *m){qrec(v,0,n,m);}