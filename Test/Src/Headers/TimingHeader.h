//
// Created by pranas on 7/5/2018.
//

#ifndef TIMING_HEADER_H
#define TIMING_HEADER_H

#include <future>

// Reference: http://antonlipov.blogspot.com/2015/08/how-to-timeout-tests-in-gtest.html
// Reference: https://gist.github.com/compomega/4f59aee81bb03e2376d5421ca6282b67
#define TEST_TIMEOUT_BEGIN   {std::promise<bool> promisedFinished; \
                                auto futureResult = promisedFinished.get_future(); \
                                std::thread([&](std::promise<bool>& finished) {

#define TEST_TIMEOUT_FAIL_END(X)  finished.set_value(true); \
                                    }, std::ref(promisedFinished)).detach(); \
                                    EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);}

#define TEST_TIMEOUT_SUCCESS_END(X)  finished.set_value(true); \
                                        }, std::ref(promisedFinished)).detach(); \
                                        EXPECT_FALSE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);}

#endif //TIMING_HEADER_H
