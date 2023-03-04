//
//  jobs.c
//  QueueJobs
//
//  Created by TungDT on 8/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "jobs.h"

job* create_job(job_data data)
{
    job* j = (job*) malloc(sizeof(job));
    j->data = data;
    j->next = NULL;
    return j;
}
void init_queue(job** jobs_queue)
{
    if (*jobs_queue != NULL) clear_queue(jobs_queue);
}
void clear_queue(job** jobs_queue)
{
    while (*jobs_queue != NULL)
    {
        job* j = *jobs_queue;
        *jobs_queue = j->next;
        free(j);
    }
    
}
void enqueue(job** jobs_queue, job_data ajob)
{
    // TODO
    // create new job
    // check if queue is empty then add new job to queue
    // else add new job to the end of queue
	job *new_job = create_job(ajob);
	if (is_empty(*jobs_queue))
		*jobs_queue = new_job;
	else {
		job *tmp = *jobs_queue;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp = new_job;
	}

}
job_data dequeue(job** jobs_queue)
{
    // TODO
    // check if queue is empty then exit
    // else remove first job in queue, free memory and return job data
	if (is_empty(*jobs_queue))
		exit(1);
	else {
		job *tmp = *jobs_queue;
		job_data data = tmp->data;
		*jobs_queue = tmp->next;
		free(tmp);
		return data;
	}
}

int is_empty(job* jobs_queue)
{
    return jobs_queue == NULL;
}
int get_size(job* jobs_queue)
{
    int size = 0;
    while (jobs_queue != NULL)
    {
        size++;
        jobs_queue = jobs_queue->next;
    }
    return size;
}
