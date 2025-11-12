#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    // 检查参数个数是否正确 (程序名 + 1个数值)
    if (argc != 2) {
        fprintf(stderr, "参数的个数不正确\n");
        return 1;
    }

    // 输出汇编头部
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

     // 将命令行参数转换为整数，并嵌入到 mov rax, <整数> 指令中
     printf("  mov rax, %d\n", atoi(argv[1]));

     // 返回指令
     printf("  ret\n");
}