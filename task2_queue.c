typedef struct queue_elem {
    double value;
    struct queue_elem *next_elem;
} q_elem;

typedef struct myqueue {
    q_elem *first_elem;
    q_elem *last_elem;
} myq;

void q_push(myq *que, double value) {
    q_elem *tmp = NULL;
    tmp = (q_elem *)malloc(sizeof(q_elem));

    if (tmp) {
        tmp->value = value;
        tmp->next_elem = NULL;
        if (que->last_elem) {
            que->last_elem->next_elem = tmp;
        }
        que->last_elem = tmp;
        if (que->first_elem == NULL) {
            que->first_elem = tmp;
        }
    } else {
        printf("Not enough memory\n");
    }
}

double q_pop(myq *que) {
    double res = 0.0;
    q_elem *tmp = NULL;
    if (que->first_elem) {
        res = que->first_elem->value;
        tmp = que->first_elem;
        que->first_elem = tmp->next_elem;
        free(tmp);
        if (que->first_elem == NULL) {
            que->last_elem = NULL;
        }
    } else {
        printf("Apply queue is empty\n");
    }
    return res;
}

void clear_queue(myq *que) {
    int k = 0;
    q_elem *tmp = NULL;
    while (que->first_elem) {
        tmp = que->first_elem;
        que->first_elem = tmp->next_elem;
        free(tmp);
        k++;
    }

    que->last_elem = NULL;
    printf("clear_queue(): %d elements has been deleted\n", k);
    printf("clear_queue(): queue is empty\n");
}

