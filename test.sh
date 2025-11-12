#!/bin/bash

# assert 函数：
# $1: 期望的退出代码 (expected)
# $2: 9cc 的输入 (input)
assert() {
    expected="$1"
    input="$2"

    # 1. 使用 9cc 编译输入，生成汇编文件 tmp.s
    ./9cc "$input" > tmp.s

    # 2. 使用 cc 汇编 tmp.s，生成可执行文件 tmp
    cc -o tmp tmp.s

    # 3. 运行可执行文件 tmp
    ./tmp

    # 4. 获取 tmp 的退出代码
    actual="$?"

    # 5. 比较实际结果与期望结果
    if [ "$actual" = "$expected" ]; then
      echo "$input => $actual"
    else
      # 如果失败，输出错误信息并退出
      echo "$input => $expected expected, but got $actual"
      exit 1
    fi
}

# 运行测试
assert 0 0
assert 30 30

# 所有测试通过
echo OK