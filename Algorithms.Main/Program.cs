using System;
using System.Threading;

using Algorithms.Lib;

namespace Algorithms.Main
{
    class Program
    {
        static void Main(string[] args)
        {
            //var watch_01 = System.Diagnostics.Stopwatch.StartNew();
            //Console.WriteLine("Hello World!");
            //Thread.Sleep(2000);
            //watch_01.Stop();
            //var elapsedMs_01 = watch_01.ElapsedMilliseconds;
            //Console.WriteLine($"Elapsed time: {0} ms", elapsedMs_01);
            var watch_02 = System.Diagnostics.Stopwatch.StartNew();
            Console.WriteLine($"{Factorization.EuclideanGCDIterative(3823485236523624,     43882834845621)}");
            watch_02.Stop();
            var elapsedMs_02 = watch_02.ElapsedMilliseconds;
            Console.WriteLine($"Elapsed time: {0} ms", elapsedMs_02);
        }
    }
}
