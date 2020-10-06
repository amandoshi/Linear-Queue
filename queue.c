#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// queue data structure
typedef struct queue
{
	char name[35];
	struct queue* next;
	struct queue* tail;

}queue;

// declare LINE queue
queue LINE;

// function declartions
void enqueue(char* name);
char* peek(void);
void dequeue(void);

int main(void)
{
	// test QUEUE
	char* names[4] = { "Aman", "Tom", "Pratyush", "Dawud" };

	for (int i = 0; i < 4; i++)
	{
		enqueue(names[i]);
		printf("Peek: %s, Tail: %s\n", peek(), LINE.tail->name);
	}

	for (int i = 0; i < 3; i++)
	{
		dequeue();
	}

	printf("Peek: %s, Tail: %s\n", peek(), LINE.tail->name);

	return 0;
}

void enqueue(char* name)
{
	if (strcmp(LINE.name, "") == false)
	{
		strcpy_s(LINE.name, strlen(name) + 1, name);
	}
	else
	{
		// declare temp. pointer
		queue* tmpPtr;
		do
		{
			tmpPtr = malloc(sizeof(queue));
			if (tmpPtr == NULL)
			{
				free(tmpPtr);
			}
		} while (tmpPtr == NULL);

		tmpPtr->next = NULL;

		// copy name into temp. pointer
		strcpy_s(tmpPtr->name, strlen(name) + 1, name);

		//copy temp. pointer into tail-next of queue

		if (LINE.next == NULL)
		{
			LINE.next = tmpPtr;
		}
		else
		{
			LINE.tail->next = tmpPtr;
		}

		// reset tail
		LINE.tail = tmpPtr;
	}
}

char* peek(void)
{
	if (LINE.next != NULL)
	{
		return LINE.next->name;
	}
	return NULL;
}

void dequeue(void)
{
	if (LINE.next == NULL)
	{
		strcpy_s(LINE.name, strlen("") + 1, "");
	}
	else
	{
		// declare temp. pointer
		queue* tmpPtr;
		do
		{
			tmpPtr = malloc(sizeof(queue));
			if (tmpPtr == NULL)
			{
				free(tmpPtr);
			}
		} while (tmpPtr == NULL);

		// initialise temp. pointer to LINE.next
		tmpPtr = LINE.next;

		// copy LINE.next into LINE
		strcpy_s(LINE.name, strlen(LINE.next->name) + 1, LINE.next->name);
		if (LINE.next->next == NULL)
		{
			LINE.next = NULL;
		}
		else
		{
			LINE.next = LINE.next->next;
		}

		// free temp. pointer
		free(tmpPtr);

		if (LINE.next == NULL)
		{
			LINE.tail = NULL;
		}
	}
}