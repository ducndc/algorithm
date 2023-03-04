//
//  jobs.h
//  QueueJobs
//
//  Created by TungDT on 8/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef jobs_h
#define jobs_h

#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FALSE       0

typedef struct
{
    int job_id;
    int agent_id;
    int duration; // in second
} job_data;

typedef struct str_job job;

struct str_job
{
    job_data data;
    job* next;
};

job* create_job(job_data data);
void init_queue(job** jobs_queue);
void clear_queue(job** jobs_queue);
void enqueue(job** jobs_queue, job_data ajob);
job_data dequeue(job** jobs_queue);
int is_empty(job* jobs_queue);
int get_size(job* jobs_queue);

#endif /* jobs_h */
