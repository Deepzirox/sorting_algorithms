#include "sort.h"


int num_nodes(listint_t *h)
{
    int c = 0;

    while (h->next != NULL)
    {
        c++;
        h = h->next;
    }

    return (c);
}


listint_t *get_node(listint_t **list_to_get, int idx)
{
    int index = 0;
    listint_t *tmp = (*list_to_get);

    while (index != idx)
    {
        tmp = tmp->next;
        index++;
    }
    return (tmp);
}
/** Treat list like an array? **/
void insertion_sort_list(listint_t **list)
{

    int nodes = num_nodes((*list)), i = 0, j = 0, key;
    listint_t *tmp = (*list), *next, *current;


    if (nodes >= 2)
    {
        for (i = 1; i < nodes; i++)
        {
            key = get_node(list, i)->n;
            j = i - 1;

            while(j >= 0 && get_node(list, j)->n > key)
            {
                next =  get_node(list, i + 1);
                current = get_node(list, i);
                next->n = current->n;

            }
        }
        printf("%d", get_node(list, nodes)->n);
    }
}