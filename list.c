
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "default_setting.h"
#include "list.h"

list_p create_list()
{
        list_p list = (list_p)malloc(sizeof(struct list));
        list->size = 0;
        list->head = (lnode_p)malloc(sizeof(struct linked_node));
        list->head->next=NULL;
        list->head->prev=NULL;
        list->head->size = 0;
        list->tail = NULL;
        return list;
}

list_iter_p list_iter_begin(list_p list)
{
        list_iter_p iter = (list_iter_p)malloc(sizeof(struct list_iter));
        iter->current = list->head->next;
        return iter;
}

list_iter_p list_iter_rbegin(list_p list)
{
        list_iter_p iter = (list_iter_p)malloc(sizeof(struct list_iter));
        iter->current = list->tail;
        return iter;
}

bool list_iter_end(list_iter_p iter)
{
        if (iter&&!iter->current) return true;
        return false;
}

bool list_iter_rend(list_iter_p iter)
{
        if (iter&&iter->current&&iter->current->prev == NULL)
        {
                return true;
        }
        return false;
}

void list_push_back(list_p list, void* data, size_t size)
{
        lnode_p node= (lnode_p)malloc(sizeof(struct linked_node));
        node->data = malloc(size);
        memcpy(node->data,data,size);
        node->size = size;
        node->next = NULL;
        if(list->size == 0)
        {
                list->head->next = node;
                list->tail = node;
                node->prev = list->head;
        }
        else
        {
                list->tail->next = node;
                node->prev = list->tail;
                list->tail = node;
        }
        list->size++;
}

void list_push_front(list_p list, void* data, size_t size)
{
        lnode_p node = (lnode_p)malloc(sizeof(struct linked_node));
        node->data = malloc(size);
        memcpy(node->data,data,size);
        node->size = size;
        node->prev = list->head;
        if(list->size == 0)
        {
                list->head->next = node;
                list->tail = node;
                node->next = NULL;
        }
        else
        {
                list->head->next->prev = node;
                node->next = list->head->next;
                list->head->next = node;
        }
        list->size++;
}

void list_pop_back(list_p list)
{
        if(list->size == 0) return;
        free(list->tail->data);
        lnode_p tmp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(tmp);
        list->size--;
}

void list_pop_front(list_p list)
{
        if(list->size == 0) return;
        free(list->head->next->data);
        lnode_p  tmp = list->head->next;
        list->head->next = list->head->next->next;
        if (list->head->next) list->head->next->prev = list->head;
        free(tmp);
        list->size--;
}

void list_insert(list_p list, list_iter_p iter, void* data, size_t size)
{
        if(list_iter_has_next(iter)==false)
        {
            list_push_back(list,data,size);
            return;
        }

        lnode_p node = (lnode_p)malloc(sizeof(struct linked_node));
        node->data = malloc(size);
        memcpy(node->data, data, size);
        node->size = size;
        node->next = iter->current->next;
        node->prev = iter->current;   
        iter->current->next->prev = node;
        iter->current->next = node;
        list->size++;
}

//TODU: remove和insert对front和back 的影响
list_iter_p list_remove(list_p list, list_iter_p iter)
{
        if(iter->current == NULL) return NULL;
        if(list_iter_has_next(iter) == false)
        {
                list_pop_back(list);
                iter->current = NULL;
                return iter;
        }
        if(list_iter_has_prev(iter) == false)
        {
                list_pop_front(list);
                iter->current = list->head->next;
                return iter;
        }

        lnode_p pp = iter->current->prev;
        lnode_p pn = iter->current->next;
        pp->next = pn;
        pn->prev= pp;
        free(iter->current->data);
        free(iter->current);
        iter->current = pn;
        list->size--;
        return iter;


}

void* list_iter_deref(list_iter_p iter)
{
        if(!iter) return NULL;
        if(iter->current) return iter->current->data;
        return NULL;
}

void* list_iter_next_deref(list_iter_p iter)
{
        if(list_iter_has_next(iter))
        {
                return iter->current->next->data;
        }
        return NULL;
        
}

void* list_iter_prev_deref(list_iter_p iter)
{
        if(list_iter_has_prev(iter))
        {
                return iter->current->prev->data;
        }
        return NULL;
}

bool list_iter_has_next(list_iter_p iter)
{
        if(!iter) return false;
        if(!iter->current) return false;
        if(!iter->current->next) return false;
        return true;
}

bool list_iter_has_prev(list_iter_p iter)
{
        if(!iter) return false;
        if(!iter->current) return false;
        if(!iter->current->prev) return false;
        if(!iter->current->prev->prev) return false;
        return true;
}

void list_iter_next(list_iter_p iter)
{
        iter->current = iter->current->next;
}

void list_iter_prev(list_iter_p iter)
{
        iter->current = iter->current->prev;
}

void* list_front(list_p list)
{
        if(list->size>=1)
        {
                return list->head->next->data;
        }
        return NULL;
}

void* list_back(list_p list)
{
        if(list->size>=1)
        {
                return list->tail->data;
        }
        return NULL;
}

size_t list_size(list_p list)
{
        return list->size;
}

bool list_empty(list_p list)
{
        return list->size == 0 ? true:false;
}

void* list_destroy(list_p list)
{
        lnode_p ptr;
        while(list->head->next)
        {
                ptr = list->head->next;
                list->head->next = ptr->next;
                free(ptr->data); 
                free(ptr);
        }
        free(list->head);
        free(list);
        return NULL;
}

void* list_iter_destroy(list_iter_p iter)
{
        free(iter);
        return NULL;
}


list_p list_merge(list_p list1, list_p list2)
{
        list_p list=create_list();
        list_merge_to(list, list1);
        list_merge_to(list, list2);
        return list;
        
}

void list_merge_to(list_p listd, list_p lists)
{
        list_iter_p iter = list_iter_begin(lists);
        while(list_iter_end(iter)==false)
        {
                list_push_back(listd,
                    iter->current->data,
                    iter->current->size);
                list_iter_next(iter);
        }
        iter = list_iter_destroy(iter);
}