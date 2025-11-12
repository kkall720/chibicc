#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    // 检查参数个数是否正确 (程序名 + 1个数值)
    if (argc != 2) {
        fprintf(stderr, "参数的个数不正确\n");
        return 1;
    }

    char *p = argv[1];

    // 输出汇编头部
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    printf("  mov rax, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "遇到未预期的字符： '%c'\n", *p);
        return 1;
    }

     // 返回指令
     printf("  ret\n");
     return 0;
}