
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "queue.h"

 Queue_t* QUEUE1;
 u32 var1=11;
 u32 var2=22;
 u32 var3=33;
 u32 var4=44;
 u32 var5=55;
 u32 var6=55;
void* answer;
s32 counter;
void main()
{

    QueueStatus_t RETURN =Queue_NOK;

 QUEUE1= QueueCreate(5,&RETURN);
 printf("the error check : %d\n",RETURN);
 printf("the address of the object  : %d\n",QUEUE1->QueueRear);


 RETURN= EnqueueElement(QUEUE1,&var1);
 printf("the error check : %d\n",RETURN);
  printf("index  : %d\n",QUEUE1->QueueRear);
 RETURN= EnqueueElement(QUEUE1,&var2);
 printf("the error check : %d\n",RETURN);
  printf("index  : %d\n",QUEUE1->QueueRear);
 RETURN= EnqueueElement(QUEUE1,&var3);
 printf("the error check : %d\n",RETURN);
  printf("index  : %d\n",QUEUE1->QueueRear);
 RETURN= EnqueueElement(QUEUE1,&var4);
 printf("the error check : %d\n",RETURN);
  printf("index  : %d\n",QUEUE1->QueueRear);
 RETURN= EnqueueElement(QUEUE1,&var5);
 printf("the error check : %d\n",RETURN);
  printf("index  : %d\n",QUEUE1->QueueRear);
   RETURN= EnqueueElement(QUEUE1,&var6);
 printf("the error check : %d\n",RETURN);
  printf("===================================== \n");


//   answer=DequeueElement(QUEUE1,&RETURN);
//    printf("dequeed value %d \n ", *(u32*)(answer));
//
//       answer=DequeueElement(QUEUE1,&RETURN);
//    printf("dequeed value %d \n ", *(u32*)(answer));
//
//       answer=DequeueElement(QUEUE1,&RETURN);
//    printf("dequeed value %d \n ", *(u32*)(answer));
//        answer=DequeueElement(QUEUE1,&RETURN);
//    printf("dequeed value %d \n ", *(u32*)(answer));


printf("====================== \n ");

answer= QueueRear (QUEUE1,&RETURN);
if(answer)
{
   printf("Rear is  %d \n", *(u32*)(answer));
}
  answer= QueueFront (QUEUE1,&RETURN);
  if(answer)
  {
      printf("Front  is  %d \n ", *(u32*)(answer));
  }

printf("====================== \n ");

 RETURN=GetElementCounter(QUEUE1,&counter);

 printf("error counter  %d \n ",RETURN);
 printf(" counter  %i \n ",counter);


RETURN= DestroyQueue(QUEUE1);
 printf("aaaaa  %d \n ",RETURN);



 RETURN= EnqueueElement(QUEUE1,&var1);
 RETURN= EnqueueElement(QUEUE1,&var2);
 RETURN= EnqueueElement(QUEUE1,&var3);
 printf("  %d\n",QUEUE1->QueueElementCounter);

}
