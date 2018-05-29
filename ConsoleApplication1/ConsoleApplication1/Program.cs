using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*
大量數學運算
I5-6400 CPU 2.7GHz
RAM 8G
需要時間: 30秒
*/ 
namespace ConsoleApplication1
{
    class Program
    {
        static void pause()
        {
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }
        static void Main(string[] args)
        {
            double dblSum = 0.0;
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            Console.WriteLine(DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss"));
            
            sw.Start();//碼表開始計時
            for (int i = 0; i < 1000; i++)
            {
                for (int j = 0; j < 10000000; j++)
                {
                    dblSum += j;
                }
            }
            sw.Stop();//碼錶停止

            Console.WriteLine("dblSum=" + dblSum);
            Console.WriteLine(DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss"));
            
            string result1 = sw.Elapsed.TotalSeconds.ToString();
            Console.WriteLine("ALL sec=" + result1);
            pause();
        }
    }
}
