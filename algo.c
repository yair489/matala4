#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"
//#include "node.c"
#include <limits.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int long_a;
pnode mygraph;
int weight;



int shortsPath_cmd(pnode head, int source, int target){

    // printf("find source\n");
    //if not exsist
    pnode sourceNode = find(&head,source);
    // printf("find source  \n");
    if(sourceNode == NULL){
        // printf("dont found");
        return -1;
    }
    pnode targeteNode = find(&head,target);
    // printf("find source  \n");
    if(targeteNode == NULL){
        // printf("dont found");
        return -1;
    }

    // //initalion all v to max
    pnode temp=head;
    while(temp!=NULL){
        temp->short_p=INT_MAX;
        temp->inQ=1;
        temp=temp->next;
    }
    sourceNode->short_p=0;
    
    temp = head;
    pnode smallest=NULL;
    pedge edge_h;
    int check= INT_MAX;
    while(1){
        while(temp){
            if(check>temp->short_p && temp->inQ){
                check=temp->short_p;
                smallest=temp;
            }
            temp=temp->next;
        }
        if(!smallest){
            break;
        }
        smallest->inQ=0;
        edge_h = smallest->edges;
        while (edge_h){
            if(edge_h->endpoint->inQ){
                int minimum = MIN(edge_h->endpoint->short_p, smallest->short_p+edge_h->weight);
                edge_h->endpoint->short_p = minimum;
            }
            edge_h = edge_h->next;
        }
        //RESET:
        check=INT_MAX;
        temp = head;
        smallest=NULL;
    }
    if(targeteNode->short_p==INT_MAX){
        return -1;
    }
    return targeteNode->short_p;
}


void cpy_deep(int *f, int *t, int len_of_array)
{
    for (int i = 0; i < len_of_array; ++i)
    {
        t[i] = f[i];
    }
}
void swap(int *array, int x, int y)
{
    int helper =array[x];
    array[x] = array[y];
   array[y] = helper;
}

void calculation_p(int *array, int len_of_array)
{
    int w_2 = 0;
    for (int i = 0; i < len_of_array - 1; ++i)
    {
        int len = shortsPath_cmd(mygraph,array[i], array[i + 1]);
        if (len == -1)
        {
            w_2 = INT_MAX;
            return;
        }
       w_2 += len;
    }
    if (w_2 < weight)
    {
        weight = w_2;
    }
}

void permotion(int s, int *arr, int len_of_array)
{
    if (s == len_of_array - 1)
    {
        calculation_p(arr, len_of_array);
        return;
    }
    for (int i = s; i < len_of_array; ++i)
    {
        int *temp_arr = (int *)(calloc(len_of_array, sizeof(int)));
        cpy_deep(arr, temp_arr, len_of_array);
        swap(temp_arr, s, i);
        permotion(s + 1, temp_arr,len_of_array);
        free(temp_arr);
    }
}

void TSP_cmd(pnode head)
{
    long_a = -1;
	weight = INT_MAX;
    mygraph = head;
    scanf("%d", &long_a);
    int *myarr= (int *)(calloc(long_a, sizeof(int)));
    for (int i = 0; i < long_a; i++)
    {
        scanf("%d", &myarr[i]);
    }
    int *arrCopy = (int *)(calloc(long_a, sizeof(int)));
    cpy_deep(myarr, arrCopy, long_a);
    permotion(0, arrCopy, long_a);
    free(myarr);
    free(arrCopy);
    if (weight == INT_MAX)
    {
        weight = -1;
    }
    printf("TSP shortest path: %d \n", weight);
}
