/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************            SWC:Queue.c              *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "queue.h"

Queue_t* QueueCreate(u32 Copy_u32MaxSize,QueueStatus_t * Status)
{
    Queue_t* MyQueue;
/*create queue object in the heap*/
    MyQueue=(Queue_t*)malloc(sizeof(Queue_t));

    if(NULL == MyQueue)
    {
      * Status=Queue_NOK;
    }
    else
    {/*create array of <void *> to hold the addresses of the queue element*/
        MyQueue->QueueArray= (void **)calloc(Copy_u32MaxSize,sizeof(void *));
        if(NULL ==(MyQueue->QueueArray))
        {
           * Status=Queue_NOK;
        }
        else{
              MyQueue->QueueMaxSize=  Copy_u32MaxSize;
              MyQueue->QueueElementCounter=0;
              MyQueue->QueueFront=-1;
              MyQueue->QueueRear=-1;
              * Status=Queue_OK;
        }
    }
return MyQueue;
}
QueueStatus_t DestroyQueue(Queue_t* Queue_obj)
{
    QueueStatus_t Local_Status=Queue_NOK;
    if(NULL==Queue_obj)
    {
        Local_Status=Queue_NOK;
    }
    else{
            free(Queue_obj->QueueArray);
            free(Queue_obj);
            Local_Status=Queue_OK;
    }
return Local_Status;
}

QueueStatus_t EnqueueElement(Queue_t* Queue_obj,void* Copy_item)
{
    QueueStatus_t Status =Queue_NOK;
    if((NULL == Queue_obj)||(NULL ==Copy_item ))
    {
    Status =Queue_NOK;
    }
    else{
             /* Validate if the queue is not full */
            if(Queue_obj->QueueElementCounter ==Queue_obj->QueueMaxSize)
            {
                Status =Queue_Full;
                printf("the queue is full\n");
            }
            else{
                /* Increment Queue Rear Index */
                (Queue_obj->QueueRear)++;
                /* Queue wraps to element 0 (Circular Queue) */
                if(Queue_obj->QueueRear == Queue_obj->QueueMaxSize)
                {
                  Queue_obj->QueueRear=0;
                }
                /* Insert the input data in to the rear position */
                Queue_obj->QueueArray[Queue_obj->QueueRear]=Copy_item;
/* validate if the queue was empty, (front and rear points to the first element) */
                if(Queue_obj->QueueElementCounter==0)
                {
                 Queue_obj->QueueFront=0;
                 Queue_obj->QueueElementCounter=1;
                }
                else{
                (Queue_obj->QueueElementCounter)++;
                }
                Status =Queue_OK;
            }
    }
    return Status;
}
void* DequeueElement(Queue_t* Queue_obj,QueueStatus_t * Status)
{
    void * Result=NULL;
    if((NULL == Queue_obj)||(NULL ==Status ))
    {
    *Status =Queue_NOK;
    }
    else{
             /* Check if the queue is empty */
            if(!Queue_obj->QueueElementCounter)
            {
                * Status=Queue_Empty;
                printf("Queue is Empty\n");
            }
            else{/* Queue is not empty */
                    Result=Queue_obj->QueueArray[Queue_obj->QueueFront];
                 /* Increment Queue Front Index */
                   (Queue_obj->QueueFront)++;

                 /* Queue front has wrapped to element 0 (Circular Queue) */
                   if(Queue_obj->QueueFront == Queue_obj->QueueMaxSize)
                   {
                       Queue_obj->QueueFront=0;
                   }
                   else{/*do nothing*/}


                   if(1==Queue_obj->QueueElementCounter)
                   {
                       Queue_obj->QueueFront=-1;
                       Queue_obj->QueueRear=-1;
                   }else{/*do nothing*/}

                   (Queue_obj->QueueElementCounter)--;

              *Status =Queue_OK;
            }
    }
return Result;
}

void* QueueFront (Queue_t* Queue_obj,QueueStatus_t * Status)
{
    void * Result=NULL;
    if((NULL == Queue_obj)||(NULL == Status))
    {
        *Status=Queue_NOK;
    }
    else
    {
         if(!Queue_obj->QueueElementCounter)
            {
                * Status=Queue_Empty;
                printf("Queue is Empty\n");
            }
            else{
                Result=Queue_obj->QueueArray[Queue_obj->QueueFront];
                *Status=Queue_OK;
                }
    }
    return Result;
}

void* QueueRear (Queue_t* Queue_obj,QueueStatus_t * Status)
{

      void * Result=NULL;
    if((NULL == Queue_obj)||(NULL == Status))
    {
        *Status=Queue_NOK;
    }
    else
    {
         if(!Queue_obj->QueueElementCounter)
            {
                * Status=Queue_Empty;
                printf("Queue is Empty\n");
            }
            else{
                Result=Queue_obj->QueueArray[Queue_obj->QueueRear];
                *Status=Queue_OK;
                }
    }
    return Result;
}
QueueStatus_t GetElementCounter(Queue_t* Queue_obj,s32* QueueCounter)
{
    QueueStatus_t Local_Status=Queue_NOK;
    if((NULL==Queue_obj)||(NULL ==QueueCounter))
    {
        Local_Status=Queue_NOK;
    }
    else
    {

         if(!Queue_obj->QueueElementCounter)
            {
                Local_Status=Queue_Empty;
                printf("Queue is Empty\n");
            }
            else{
                * QueueCounter=Queue_obj->QueueElementCounter;
                Local_Status=Queue_OK;
                }
    }
return Local_Status;
}

