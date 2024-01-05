using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Data_Structures
{
    class StackX
    {
        private int maxSize;
        private int[] stack;
        private int top;

        public StackX(int maxSize)
        {
            this.maxSize = maxSize;
            stack = new int[maxSize];
            top = -1;
        }

        public void push(int insert)
        {
            top++;
            stack[top] = insert;
        }

        public int pop()
        {
            top--;
            return stack[top];
        }

        public void peek()
        {
            Console.WriteLine(stack[top]);
        }

        public void display()
        {
            for(int i = 0; i < top; i++)
            {
                Console.Write(stack[i] + " ");
            }
        }

        public bool isEmpty()
        {
            return (top == -1);
        }

        public bool isFull()
        {
            return (top == maxSize - 1);
        }
    }
}
