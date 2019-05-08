#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s = 1, h;                    // 数值和高度
    int i, j;                        // 循环计数

    scanf("%d", &h);
    printf("1\n");  // 输出第一行 1

    for (i = 2; i <= h; s=1, i++){  // 从第二行开始 ,i 代表行数
        printf("1 ");

        for (j = 1; j <= (i-2); j++){ // 列位置 j 绕过第一个直接开始循环
            printf("%d ", (s = (i-j)*s/j) ); // 这个公式很nb，它将行和列相差，然后乘以前一列的值，再除以列
        }

        printf("1\n");
    }

    return 0;
}