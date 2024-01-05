using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Data_Structures
{
    class Program
    {
        static void Main(string[] args)
        {
            QueueX queue = new QueueX(10);
            StackX stack = new StackX(10);
            do
            {
                string option = Console.ReadLine();
                if(option == "1")
                {
                    int num = int.Parse(Console.ReadLine());
                    queue.push(num);
                }

                else if (option == "2")
                {
                    Console.WriteLine(queue.pop());
                }

                else if (option == "3")
                {
                    int num = int.Parse(Console.ReadLine());
                    stack.push(num);
                }

                else if (option == "4")
                {
                    Console.WriteLine(stack.pop());
                }

                else if (option == "5")
                {
                    stack.peek();
                }

                else if (option == "6")
                {
                    Console.WriteLine(queue.peekFront());
                }

                else if (option == "7")
                {
                    Console.WriteLine(queue.peekRear());
                }
            } while (true);
        }
    }
}
