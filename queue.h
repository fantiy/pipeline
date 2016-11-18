/*queue size Must be an exponent of 2*/

/*lock-free queue*/
typedef struct {
      void* queue;
      int qsize;
      int qmask;
      int _head;
      int _tail;
} LF_queue_t；

void initqueue(LF_queue_t *lq, int size);
void destroyqueue(LF_queue_t *lq);
void producer(LF_queue_t *lq, void *data);
void *consumer(LF_queue_t *lq);
