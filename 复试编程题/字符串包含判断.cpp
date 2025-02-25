//
// Created by jagger on 25-2-23.
//
/*
字符串包含判断：判断s1字符串中是否包含s2字符串。如："china123"包含"na12"，但不包含"abc"。
 */
#include <stdio.h>
#include <string.h>

// 计算模式串的 nextval 数组
void computeNextval(char* pattern, int m, int* nextval)
{
    // i 用于遍历模式串，初始化为 0
    int i = 0;
    // j 用于记录最长公共前后缀的长度，初始化为 -1
    int j = -1;
    // nextval 数组的第一个元素初始化为 -1，表示当模式串第一个字符就不匹配时的处理方式
    nextval[0] = -1;

    // 循环遍历模式串，直到 i 达到 m - 1
    while (i < m - 1)
    {
        // 当 j 为 -1 或者当前 i 位置和 j 位置的字符相等时
        if (j == -1 || pattern[i] == pattern[j])
        {
            // i 和 j 都向后移动一位
            i++;
            j++;
            // 如果当前 i 位置和 j 位置的字符不相等
            if (pattern[i] != pattern[j])
            {
                // nextval[i] 的值为 j
                nextval[i] = j;
            }
            else
            {
                // 如果当前 i 位置和 j 位置的字符相等，
                // 则 nextval[i] 的值等于 nextval[j]，避免不必要的比较
                nextval[i] = nextval[j];
            }
        }
        else
        {
            // 如果当前 i 位置和 j 位置的字符不相等，
            // j 回溯到 nextval[j] 的位置，继续寻找合适的公共前后缀
            j = nextval[j];
        }
    }
}

// KMP 字符串匹配算法（使用 nextval 数组）
int kmpSearchWithNextval(char* text, char* pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int nextval[m];

    // 计算 nextval 数组
    computeNextval(pattern, m, nextval);

    int i = 0; // 文本串的索引
    int j = 0; // 模式串的索引
    while (i < n)
    {
        if (j == -1 || text[i] == pattern[j]) // 匹配成功或者没一个字母匹配上，两个指针都后移
        {
            i++;
            j++;
        }
        else // 否则模式串指针回退到它的最长前缀
        {
            j = nextval[j];
        }

        if (j == m)
        {
            return i - j; // 找到匹配，返回匹配的起始位置
        }
    }

    return -1; // 未找到匹配
}

// 测试用例函数
void runTestCases() {
    // 测试用例 1
    char text1[] = "china123";
    char pattern1[] = "na12";
    int result1 = kmpSearchWithNextval(text1, pattern1);
    if (result1 != -1) {
        printf("测试用例 1: 模式串在文本串中的起始位置是: %d\n", result1);
    } else {
        printf("测试用例 1: 未找到匹配的模式串。\n");
    }

    // 测试用例 2
    char text2[] = "abcdefg";
    char pattern2[] = "xyz";
    int result2 = kmpSearchWithNextval(text2, pattern2);
    if (result2 != -1) {
        printf("测试用例 2: 模式串在文本串中的起始位置是: %d\n", result2);
    } else {
        printf("测试用例 2: 未找到匹配的模式串。\n");
    }

    // 测试用例 3
    char text3[] = "hello world";
    char pattern3[] = "world";
    int result3 = kmpSearchWithNextval(text3, pattern3);
    if (result3 != -1) {
        printf("测试用例 3: 模式串在文本串中的起始位置是: %d\n", result3);
    } else {
        printf("测试用例 3: 未找到匹配的模式串。\n");
    }
}

int main()
{
    char text[1000];
    char pattern[1000];

    // 运行测试用例
    runTestCases();

    // 手动输入主串和子串
    printf("\n请输入主串: ");
    scanf("%s", text);
    printf("请输入子串: ");
    scanf("%s", pattern);

    int result = kmpSearchWithNextval(text, pattern);

    if (result != -1)
    {
        printf("模式串在文本串中的起始位置是: %d\n", result);
    }
    else
    {
        printf("未找到匹配的模式串。\n");
    }

    return 0;
}