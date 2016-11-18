#include <malloc.h>
#include "queue.h"

void initqueue(LF_queue_t *lq, int size)
{
   queue = (void *)malloc(size);
   qsize = size;
   qmast = qsize-1；
   _head = 0;
   _tail = 0;
}

void destroyqueue(LF_queue_t *lq)
{
    if( queue != NULL )
        free(queue);
}

void producer(LF_queue_t *lq, void *data)
{
    if ((lq->_head + 1) & lq->qmask == _tail) {
        /* queue is full, discard data */
        return;
    }   
    /* put data into the queue */
    lq->queue[lq->_head] = data;
    lq->_head = (lq->_head + 1) & lq->qmask;
}

void *consumer(LF_queue_t *lq)
{
    void *data;
    if (lq->_tail == lq->_head) {
        /* have no data */
        return NULL;
    }   
    /* TODO: process data */
    data = lq->queue[lq-->_head];
    lq->_tail = (lq->_tail + 1) & lq->qmask;
    
    return data;
}
