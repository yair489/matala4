#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "graph.h"


void delet_all_edge(pedge head){

    if(! head ){
        return;
    }
    pedge p = head;

    while(head){
        // printf("EDGE to: %d, deleted\n",p->endpoint->node_num);
        p = p->next;
        free(head);
        head=p;
        
    }
    
}
void deleteGraph_cmd(pnode* head){
    
    if (! *head ){
        return;
    }
    pnode temp = *head;
    while ((temp->next)){
        if ((temp->edges)){
            delet_all_edge(temp->edges);
            temp->edges=NULL;
        }
        deleteGraph_cmd(&(temp->next));
    }
    if ((temp->edges)){
        delet_all_edge(temp->edges);
        temp->edges=NULL;
    }
    free(temp);
    *head = NULL;
    // printf("node deletd\n");
    
} 
void build_graph_cmd(pnode *head,int num) 
{
    deleteGraph_cmd(head);
    
    char node = 'A';
    // scanf("%c", &node);
    for (int i = 0; i < num; ++i)
    {
        scanf("%c", &node);
        insert_node_cmd(head);
    }
}


