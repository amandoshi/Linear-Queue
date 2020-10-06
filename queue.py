class Queue:
    """Queue Implementation Class

    Queue implemented as a static array (implicit)
    Contains necessary methods associated with queues (enqueue, dequeue)
    Uses helper functions (queue_empty, queue_full) to assist main methods

    Attributes:
        _queue_size (int): The maximum size of the queue, default set to 10
        _queue (obj:`list` of :obj:`int`): Array (implicit) which stores elements of queue.
        _head (int): Pointer pointing to index of front of queue
        _tail (int, None): Pointer pointing to index of end of queue, pointer is None if queue is empty
    """

    def __init__(self, queue_size: int = 10):
        """Initialise Queue

        Args:
            queue_size (int): how long queue can be (maximum number of elements it can store)
        """

        self._queue_size = queue_size
        self._queue = [None] * queue_size
        self._head = 0
        self._tail = None

    def enqueue(self, value: int) -> bool:
        """Equeue method

        enqueues value to the end of queue at the index of tail pointer

        Args:
            value (int): New element which will be added to end of queue

        Returns:
            bool, True if action was successful, False if action was unsuccessful
        """

        if not self.queue_full():
            # set tail if array is empty
            if self.queue_empty():
                self._tail = self._head
            else:
                self._tail += 1

            # set new value in queue
            self._queue[self._tail] = value

            return True

        # unsuccessful action, value could not be enqueued
        return False
    
    def dequeue(self) -> [int, bool]:
        """Dequeue method

        dequeues element from queue at the index of head pointer

        Returns:
            int, which is value dequeued from queue, or bool, if action was unsuccessful (queue was empty)
        """

        if not self.queue_empty():
            # copy of element which will be dequeued
            return_value = self._queue[self._head]

            # dequeue item at index of head pointer
            self._queue[self._head] = None

            # set tail to None if array is empty
            if self._head == self._tail:
                self._tail = None
            else:
                self._head += 1

            return return_value

        # unsuccessful action, element could not be dequeued
        return False

    def queue_empty(self) -> bool:
        """Helper Function: checks if queue is empty

        Returns:
            bool, specifies if queue is empty or not empty
        """
        return self._queue[self._head] == None

    def queue_full(self) -> bool:
        """Helper Function: checks if queue is full

        Returns:
            bool, specifies if queue is full or not full
        """
        return self._tail == self._queue_size - 1