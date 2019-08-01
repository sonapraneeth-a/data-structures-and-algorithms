using System;
using System.Threading.Tasks;
using Xunit;
using Xunit.Abstractions;
using Xunit.Sdk;

namespace Base
{
    public class BaseUnitTest
    {
        private readonly ITestOutputHelper output;

        public BaseUnitTest(ITestOutputHelper output)
        {
            this.output = output;
        }
        [Fact]
        public void Func1Test()
        {
            Assert.Equal(10, Base.func1());
            output.WriteLine("This is output from {0}", "Func1Test");
        }
        [Fact]
        public void Func2Test()
        {
            Assert.Equal(10, Base.func2(10));
        }
        [Fact]
        public void Func2ExceptionTest()
        {
            Exception ex = Assert.Throws<Exception>(() => Base.func2(20));
            Assert.Equal("Unknown value", ex.Message);
        }
        // Reference: https://stackoverflow.com/questions/20282111/xunit-net-how-can-i-specify-a-timeout-how-long-a-test-should-maximum-need
        [Fact(Timeout = 2, DisplayName = "Sleeptest", Skip = "Skipping temporarily as timeout is not working")]
        public void Func3SleepTest()
        {
            Assert.Equal(10, Base.func3());
        }
        [Fact(Timeout = 9000, DisplayName = "Sleep2test")]
        public async void Func3SleepTwoTest()
        {
            Exception ex = await Assert.ThrowsAsync<TestTimeoutException>(() => Task.Delay(50000));
            
            /*Exception ex = await Assert.ThrowsAsync<TestTimeoutException>(
                () => Task.Run(
                    () => {
                        Assert.Equal(10, Base.func3());
                    })
                );*/
            Assert.Equal("Test execution timed out after 9000 milliseconds", ex.Message);
            
            // await Assert.ThrowsAsync<TestTimeoutException>(() => Task.Run(Base.func3()));
        }
    }
}
