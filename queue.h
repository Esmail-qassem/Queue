/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************            SWC:Queue.h              *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct{
void **QueueArray;          /* Pointer to array of void pointers */
u32 QueueMaxSize;          /* Maximum elements in the Queue */
s32 QueueElementCounter;   /* Number of elements in the Queue */
s32 QueueFront;            /* Index of the front elements */
s32 QueueRear;             /* Index of the rear elements */
}Queue_t;

typedef enum{

Queue_NOK=0,
Queue_OK,
Queue_Full,
Queue_Empty

}QueueStatus_t;

Queue_t* QueueCreate(u32 Copy_u32MaxSize,QueueStatus_t * Status);

QueueStatus_t DestroyQueue(Queue_t* Queue_obj);

QueueStatus_t EnqueueElement(Queue_t* Queue_obj,void* Copy_item);
void* DequeueElement(Queue_t* Queue_obj,QueueStatus_t * Status);

  void* QueueFront (Queue_t* Queue_obj,QueueStatus_t * Status);
  void* QueueRear (Queue_t* Queue_obj,QueueStatus_t * Status);

QueueStatus_t GetElementCounter(Queue_t* Queue_obj,s32* QueueCounter);




#endif // QUEUE_H_
