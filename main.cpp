#include <iostream>
#include <gtest/gtest.h>
#include "MyGTest.h"

using namespace std;

namespace my_main {


class GlobalTest : public testing::Environment {
public:
    virtual void SetUp() {
        cout << "excute before" << endl;
    }

    virtual void TearDown() {
        cout << "excute after" << endl;
    }
};

int abs(int x) {
    return x > 0 ? x : -x;
}
int add(int a, int b) {
    return a + b;
}

}

TEST(abs_test, abs) {
    ASSERT_TRUE(my_main::abs(-1) == 1);
}

TEST(GlobalTest, absTest) {
    ASSERT_EQ(my_main::abs(1), my_main::abs(-1));
}

TEST(GlobalTest, add) {
    ASSERT_TRUE(my_main::add(2, 3) == 4) << "Expect 5, but given 4";
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);  //将命令行参数传递给gtest

    // 下面这两句代码是使用全局事件必备的
    testing::Environment *env = new my_main::GlobalTest();
    testing::AddGlobalTestEnvironment(env);

    return RUN_ALL_TESTS(); // RUN_ALL_TESTS()运行所有测试用例
}
