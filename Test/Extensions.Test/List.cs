using System;
using Xunit;

using Extensions;
using System.Collections.Generic;
using Xunit.Abstractions;

namespace Extensions.List
{
    public class RemoveDuplicates : IDisposable
    {
        private readonly ITestOutputHelper output;
        public RemoveDuplicates(ITestOutputHelper output)
        {
            this.output = output;   
        }
        public void Dispose()
        {
        }

        [Fact(DisplayName = "NoDuplicates")]
        public void NoDuplicates()
        {
            output.WriteLine("Item 00");
            List<int> list_00 = new List<int>();
            list_00.Add(2);
            list_00.RemoveDuplicates();
            Assert.Single(list_00);
            Assert.Equal(new List<int>(new int[] { 2 }), list_00);
            output.WriteLine("Item 01");
            List<int> list_01 = new List<int>();
            list_01.Add(2);
            list_01.Add(3);
            list_01.RemoveDuplicates();
            Assert.Equal(2, list_01.Count);
            Assert.Equal(new List<int>(new int[] { 2, 3 }), list_01);
        }

        [Fact]
        public void OneDuplicate()
        {
            output.WriteLine("Item 00");
            List<int> list_00 = new List<int>();
            list_00.Add(2);
            list_00.Add(2);
            list_00.RemoveDuplicates();
            Assert.Single(list_00);
            Assert.Equal(new List<int>(new int[] { 2}), list_00);
            output.WriteLine("Item 01");
            List<int> list_01 = new List<int>();
            list_01.Add(2);
            list_01.Add(3);
            list_01.Add(3);
            list_01.RemoveDuplicates();
            Assert.Equal(2, list_01.Count);
            Assert.Equal(new List<int>(new int[]{ 2, 3 }), list_01);
        }

        [Fact]
        public void MultipleDuplicates()
        {
            output.WriteLine("Item 00");
            List<int> list_00 = new List<int>();
            list_00.Add(2);
            list_00.Add(3);
            list_00.Add(2);
            list_00.Add(3);
            list_00.RemoveDuplicates();
            Assert.Equal(2, list_00.Count);
            Assert.Equal(new List<int>(new int[] { 2, 3 }), list_00);
        }
    }

}
