#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>

struct stack_node {
       struct stack_node *next;
       int val;
};

struct stack {
       struct stack_node *st_top;
       struct stack_node *st_bottom;
       int st_size;
};

typedef struct stack * stack_t;

static inline int init_stack(stack_t *st)
{
       struct stack_node *null_stn = NULL;

       *st = (stack_t)malloc(sizeof(struct stack));
       if (!(*st)) {
              perror("malloc");
              return -1;
       }

       null_stn = (struct stack_node *)malloc(sizeof(struct stack_node));
       if (!null_stn) {
              perror("malloc");
              return -1;
       }

       null_stn->next = NULL;
       null_stn->val = -1;

       (*st)->st_top = (*st)->st_bottom = null_stn;
       (*st)->st_size = 0;

       return 0;
}

static inline void delete_stack(stack_t st)
{
       struct stack_node *stn = NULL;

       while (st->st_top) {
              stn = st->st_top;
              st->st_top = st->st_top->next;
              free(stn);
              stn = NULL;
       }

       free(st);

       return;
}

static inline int stack_empty(stack_t st)
{
       return st->st_top == st->st_bottom;
}

static inline int stack_push(stack_t st, int val)
{
       struct stack_node *stn = NULL;

       stn = (struct stack_node *)malloc(sizeof(struct stack_node));
       if (!stn) {
              perror("malloc");
              return -1;
       }

       stn->val = val;
       stn->next = st->st_top->next;
       st->st_top->next = stn;

       if (st->st_top == st->st_bottom) {
              st->st_bottom = stn;
       }

       st->st_size++;

       return 0;
}

static inline int stack_pop(stack_t st, int *val)
{
       struct stack_node *stn = NULL;

       if (stack_empty(st)) {
              return st->st_top->val;
       }

       *val = st->st_top->next->val;

       stn = st->st_top->next;
       st->st_top->next = st->st_top->next->next;

       if (st->st_top->next == NULL) {
              st->st_bottom = st->st_top;
       }

       free(stn);
       stn = NULL;

       return 0;
}

#endif
