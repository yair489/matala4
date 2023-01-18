#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <limits.h>
#include "graph.h"
#include <ctype.h>


int main()
{
    pnode help = NULL;
    pnode *head = &help;
    char c ;
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'A')
        {
            int num = 0;
            scanf("%d", &num);
            build_graph_cmd(head,num);
        }
        if (c == 'B')
        {
            insert_node_cmd(head);
        }
        if (c == 'D')
        {
            int data=-1;
	        scanf("%d", &data);
            delete_node_cmd(head,data);
        }
        if (c == 'S')
        {
            int source = -1, dest = -1;
            scanf("%d ", &source);
            scanf("%d " ,&dest);
            int dis = shortsPath_cmd(*head, source, dest);
            printf("Dijsktra shortest path: %d \n", dis);
        }
        if (c == 'T') 
        {
            TSP_cmd(*head);
        }
    }
    deleteGraph_cmd(head);
    return 0;
}