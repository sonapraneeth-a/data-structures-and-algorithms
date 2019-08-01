using System;
using Xunit;

using Algorithms.Lib;
using System.Collections.Generic;

namespace Algorithms.Number
{
    public class EuclideanGCDIterative : IDisposable
    {
        public List<Tuple<long, long, long>> CoPrimesList { get; private set; }

        public EuclideanGCDIterative()
        {
            CoPrimesList = new List<Tuple<long, long, long>>()
            {
                Tuple.Create((long)1, (long)1, (long)2),
            };
        }
        public void Dispose()
        {
            CoPrimesList.Clear();
        }

        [Fact]
        public void OneOfTheNumberIsGCD()
        {
            Assert.Equal(2, Factorization.EuclideanGCDIterative(10, 2));
        }

        [Fact]
        public void CoPrimes()
        {
            foreach (var item in CoPrimesList)
            {
                Assert.Equal(item.Item1, Factorization.EuclideanGCDIterative(item.Item2, item.Item3));
            }
        }
    }

}
