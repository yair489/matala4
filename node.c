#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"


pnode newNode(int data, pnode next) {
    pnode p = (pnode) malloc (sizeof(node));
    if (p==NULL)
    {
        perror("mallock problem");
        exit (0);
    }
    
    //SET node
    p->node_num = data;
    p->next = next;
    p->edges = NULL;
    // printf("new node created with Id: %d\n",data);
    return p;
}

// pnode insert_node_cmd(int data,  pnode *head) {
//     // printf("%d\n", *head );
//     if(!*head){
//         *head=newNode(data,NULL);
//         return *head;
//     }
//     pnode temp = *head;
    
//     while(temp->next){
//         if(temp->node_num==data){
//             delet_all_edge(temp->edges);
//             temp->edges = NULL;
//             return temp;    
//         }
//         temp = (temp->next);    
//     }
//     if(temp->node_num==data){ //check if the last node have the ID.
//         delet_all_edge(temp->edges);
//         temp->edges = NULL;
//         return temp;    
//     }
//     temp->next = newNode(data,NULL);//linked the node to the end.
//     return temp->next;
// }


pnode find( pnode *head,int numNode) 
{
    pnode temp = *head;
    while (temp )
    {
        if (temp->node_num == numNode)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}


void delete_node_cmd(pnode *h,int data){
 
        if(! *h ){
            return;
        }
        node *p = *h;
        node **prev = h;
        while(p) {
            if(p->node_num == data) {
                *prev = p->next;
                free(p);
                p = *prev;
            } else {
                prev = &(p->next);
                p = p->next;
            }
        }
}

/////////////////////////////////////////////////////

void insert_node_cmd(pnode *head)
{
    int x = -1;
    scanf("%d", &x);
    pnode p_get = find(head,x);
    if (p_get == NULL)
    {
        p_get = newNode(x, *head);
        if (p_get == NULL)  {return;}
        *head = p_get;
    }
    else {
        pedge p_e = p_get->edges;
        delet_all_edge(p_e);
     }
    int dest = -1;
    pedge *e_new = &(p_get->edges);
    int d = scanf("%d", &dest);
    while (d != 0 && d != EOF){
        pnode v_d = find(head,dest);
        if (v_d== NULL){
            
            v_d = newNode(dest, *head);
            if (v_d == NULL)
            {
                return;
            }
             *head =v_d;
        }


        int weight = -1;
        scanf("%d", &weight);

        *e_new = (pedge)malloc(sizeof(edge));
        if ((*e_new) == NULL)
        {
            return;
        }
        (*e_new)->weight = weight;
        (*e_new)->endpoint = v_d;
        (*e_new)->next = NULL;
        e_new = &((*e_new)->next);
        d = scanf("%d", &dest);
    }
}
