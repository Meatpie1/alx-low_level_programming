#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list
 * @head: head of thee linked list.
 * Return: no return.
 */
void free_list(list_t *head)
{
list_t *current_node;
list_t *temp;

current_node = head;

while (current_node != NULL)
{
temp = current_node->next;
free(current_node->str);
free(current_node);
current_node = temp;
}
}
