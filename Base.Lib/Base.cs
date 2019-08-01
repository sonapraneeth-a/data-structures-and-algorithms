using System;
using System.Threading;

namespace Base
{
    public class Base
    {
        public static int func1()
        {
            return 10;
        }
        public static int func2(int data)
        {
            int value = data;
            if (value != 10)
            {
                throw new Exception("Unknown value");
            }
            return value;
        }
        public static int func3()
        {
            Thread.Sleep(10000);
            return 10;
        }
    }
}
