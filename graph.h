#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int short_p;
    int inQ;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

// typedef struct NODE_QUEUE_{
//     pnode head;
//     pnode tail;
//     int size;
// }queue, *pqueue;



int shortsPath_cmd(pnode head, int source, int target);
// void build_graph_cmd(pnode *head);
void build_graph_cmd(pnode *head, int size);
void insert_node_cmd(  pnode *head);
pnode find(pnode *head,int data);
void delete_node_cmd(pnode *h,int data);
void print_graph(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
// void sshortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
void delet_all_edge(pedge head);
void delNode(pnode* head,pnode delNode);
void dellEdge(pnode fromA, pnode toB);
pedge addEdge(pnode pn, pnode location, int weight);
#endif
