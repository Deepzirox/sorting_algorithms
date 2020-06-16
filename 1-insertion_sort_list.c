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

void printarr(listint_t *h)
{

    for (; h->next != NULL;)
    {
        printf("%d, ", h->n);
        h = h->next;
    }
    putchar('\n');
}

void startsort(listint_t **head_ref, listint_t *newNode)
{
    listint_t *current;

    printarr((newNode));

    if (*head_ref == NULL)
        *head_ref = newNode;

    else if ((*head_ref)->n >= newNode->n) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        while (current->next != NULL &&
               current->next->n < newNode->n)
            current = current->next;

        newNode->next = current->next;

        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}


void insertion_sort_list(listint_t **list)
{
  listint_t *already = NULL, *current = *list;
  listint_t *next = NULL;

  if (num_nodes(*list) >= 2)
  {
    while (current != NULL)
    {
      printarr(*list);
      next = current->next;
      current->prev = current->next = NULL;
      startsort(&already, current);
      current = next;
      *list = already;
    }
  }
}
