using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Data_Structures
{
    class QueueX
    {
        private int[] queue;
        private int maxSize;
        private int front;
        private int rear;
        private int numOfItems;

        public QueueX(int size)
        {
            maxSize = size;
            queue = new int[maxSize];
            front = 0;
            rear = -1;
            numOfItems = 0;
        }

        public void push(int item)
        {
            if(rear == maxSize - 1) //if the rear index is at the last index of the queue, rear is set at 0 for next inserion
            {
                rear = -1;
            }
            rear++;
            queue[rear] = item;
            numOfItems++;
        }

        public int pop()
        {
            int temp = queue[front++];
            if(front == maxSize - 1) // if front reaches the last index, it will move to the start of queue for next insertion
            {
                front = 0;
            }
            numOfItems--;
            return temp;
        }

        public int peekFront()
        {
            return queue[front];
        }

        public int peekRear()
        {
            return queue[rear];
        }

        public bool isFull()
        {
            if(numOfItems == maxSize)
            {
                return true;
            }
            return false;
        }

        public bool isEmpty()
        {
            if (numOfItems == 0)
            {
                return true;
            }
            return false;
        }
    }
}
