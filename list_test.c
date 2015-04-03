#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "default_setting.h"
#include "list.h"

void out(list_p list)
{
        lnode_p p = list->head->next;
        while (p&&p->next)
        {
                printf("%d ", *(int*)p->data);
                p = p->next;
        }
        if (p) printf("%d ", *(int*)p->data);
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
}

int main()
{
        list_p list,list2,list3;
        list_iter_p iter;
        int i = 0;
        while (1)
        {
                i = 0;
                list = create_list();

                list_push_back(list, &i, sizeof(int));
                //out(list);
                i = 2;
                list_push_front(list, &i, sizeof(int));
                //out(list);
                iter = list_iter_begin(list);
                i = 3;
                list_insert(list, iter, &i, sizeof(int));
                //out(list);
                list_iter_next(iter);
                list_iter_next(iter);
                list_iter_next(iter);
                i = 4;
                list_insert(list, iter, &i, sizeof(int));
                //out(list);
                iter = list_iter_destroy(iter);
                iter = list_iter_begin(list);
                iter = list_remove(list, iter);
                //out(list);
                iter = list_remove(list, iter);
                //out(list);
                iter = list_remove(list, iter);
                //out(list);
                iter = list_remove(list, iter);
                //out(list);
                i = 5;
                list_push_back(list, &i, sizeof(int));
                //out(list);
                i = 6;
                list_push_front(list, &i, sizeof(int));
                //out(list);
                list_pop_front(list);
                //out(list);
                list_pop_front(list);
                //out(list);
                iter = list_iter_destroy(iter);
                iter = list_iter_begin(list);
                list_remove(list, iter);
                //out(list);
                i = 7;
                list_push_back(list, &i, sizeof(int));
                //out(list);
                list_pop_back(list);
                list_pop_back(list);
                list_pop_front(list);
                list_pop_front(list);
                //out(list);
                i = 8;
                list_insert(list, iter, &i, sizeof(int));
                //out(list);
                //printf("%d", *(int*)list_front(list));
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                //printf("%d", *(int*)list_back(list));
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                i = 9;
                list_push_back(list, &i, sizeof(int));
                //printf("%d", *(int*)list_front(list));
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                //printf("%d", *(int*)list_back(list));
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                //printf("%d", list_size(list));
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                //out(list);
                i = 10;
                list_push_back(list, &i, sizeof(int));
                i = 11;
                list_push_back(list, &i, sizeof(int));
                i = 12;
                list_push_back(list, &i, sizeof(int));
                i = 13;
                list_push_back(list, &i, sizeof(int));
                //out(list);
                iter = list_iter_destroy(iter);
                for (iter = list_iter_begin(list);
                    list_iter_end(iter) == false;
                    list_iter_next(iter))
                {
                    //printf("%d ", *(int*)list_iter_deref(iter));
                }
                iter = list_iter_destroy(iter);
                //printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                for (iter = list_iter_rbegin(list);
                    list_iter_rend(iter) == false;
                    list_iter_prev(iter))
                {
                    //printf("%d ", *(int*)list_iter_deref(iter));
                }
                iter = list_iter_destroy(iter);
                // printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n");
                list_push_back(list, &i, sizeof(int));
                list_push_back(list, &i, sizeof(int));
                list_push_back(list, &i, sizeof(int));
                list_push_back(list, &i, sizeof(int));
                list2 = create_list();
                list_merge_to(list2, list);
                //out(list);
               // out(list2);
                list3 = list_merge(list, list2);
                //out(list3);
                list = list_destroy(list);
                list2 = list_destroy(list2);
                list3 = list_destroy(list3);
                //break;
        }
        return 0;
}