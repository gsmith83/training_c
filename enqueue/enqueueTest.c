#include <dof/pcrtypes.h>
#include <dof/pcr.h>
#include <dof/core.h>
#include <dof/oaltypes.h>
#include <dof/value.h>
#include "../../../core-c/dof-oal/include/internal/enqueue.h"
#include <stdio.h>

#define POOLS 3
#define ITEMS 40

typedef struct ItemNode_t     //todo: how to use OALEnqueuItems ?
{
    OALEnqueueItem_t    super;
    uint8               identifier;
}ItemNode_t;

typedef ItemNode_t * ItemNode;

void test_fn(OALThreadPoolItem itemx, boolean shutdown);
void test_fn2(OALThreadPoolItem itemx, boolean shutdown);
void test_fn3(OALThreadPoolItem itemx, boolean shutdown);

uint32 total = 0;

int main(int argc, const char *argv[])
{
    OALThreadPool threadPool;
    OALEnqueue enqueue1;
    OALEnqueue enqueue2;
    OALEnqueue enqueue3;
    uint32 nPools;

    if (argc > 1)
        nPools = atoi(argv[1]);
    else
        nPools = POOLS;

    DOF_Init();

    printf("ENQUEUE TEST START *** Threads = %d\n\n", nPools);

    printf("Create ThreadPool\n");
    threadPool = OALThreadPool_Create(nPools);
    printf("Create Enqueue(s)\n");
    enqueue1 = OALEnqueue_Create(threadPool);
    enqueue2 = OALEnqueue_Create(threadPool);
    enqueue3 = OALEnqueue_Create(threadPool);

    printf("Init EnqueueItem\n");

    printf("Enqueue\n");

    // init loop
    uint32 i;
    for (i = 0; i < ITEMS; i++)
    {
        OALEnqueueItem itemn = (OALEnqueueItem)DOFMem_Alloc(sizeof(OALEnqueueItem_t));
//      ItemNode itemn = (ItemNode)DOFMem_Alloc(sizeof(ItemNode));
        OALEnqueueItem_Init((OALEnqueueItem)itemn, test_fn);
        OALEnqueue_Enqueue(enqueue1, (OALEnqueueItem)itemn);
    }

    for (i = 0; i < ITEMS; i++)
    {
        OALEnqueueItem itemx = (OALEnqueueItem)DOFMem_Alloc(sizeof(OALEnqueueItem_t));
        OALEnqueueItem_Init(itemx, test_fn2);
        OALEnqueue_Enqueue(enqueue2, itemx);
    }

    for (i = 0; i < ITEMS; i++)
    {
        OALEnqueueItem itemz = (OALEnqueueItem)DOFMem_Alloc(sizeof(OALEnqueueItem_t));
        OALEnqueueItem_Init(itemz, test_fn3);
        OALEnqueue_Enqueue(enqueue3, itemz);

    }



    printf("Shutting down\n");
    OALEnqueue_Destroy(enqueue1);
    OALEnqueue_Destroy(enqueue2);
    OALEnqueue_Destroy(enqueue3);
    OALThreadPool_Destroy(threadPool);
    DOF_Shutdown();

    printf("\nENQUEUE - TEST COMPLETE\n");
}

void test_fn(OALThreadPoolItem itemx, boolean shutdown)
{
//  PCRThread_Sleep(150);
//  ItemNode itemn = (ItemNode)itemx;

//  printf("test_fn 1 - Total = %d\tID = %d\n", total++, itemn->identifier);
    printf("test_fn 1 - Total = %d\n", total++);

    if (itemx)
    {
        DOFMem_Free(itemx);
    }

    printf("Exiting test_fn1\n");
}

void test_fn2(OALThreadPoolItem itemx, boolean shutdown)
{
    printf("test_fn 2 - Total = %d\n", total++);

    if(itemx)
    {
        DOFMem_Free(itemx);
    }

    printf("Exiting test_fn2\n");
}

void test_fn3(OALThreadPoolItem itemx, boolean shutdown)
{
//  PCRThread_Sleep(300);

    printf("test_fn 3 - Total = %d\n", total++);

    if (itemx)
    {
        DOFMem_Free(itemx);
    }

    printf("Exiting test_fn3\n");
}
