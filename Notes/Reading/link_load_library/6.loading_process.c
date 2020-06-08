#include <stdio.h>
#include <stdlib.h>

// 测试 malloc 最大内存申请数量
int get_maximum_number_malloc()
{
    unsigned blocksize[] = {1024 * 1024, 1024, 1};
    int i, count;
    unsigned max = 0;
    for (i = 0; i < 3; i++)
    {
        for (count = 1;; count++)
        {
            void *block = malloc(max + blocksize[i] * count);
            if (block)
            {
                max = max + blocksize[i] * count;
                free(block);
            }
            else
            {
                break;
            }
        }
    }
    return max;
}

void print_maximum_number_mlloc()
{
    unsigned max = get_maximum_number_malloc();
    float k = max / 1024;
    float g = k / 1024;
    printf("Max malloc size is : %u bytes\n", max);
    printf("Max malloc size is : %f KB\n", k);
    printf("Max malloc size is : %f G\n", g);
}

int main(int argc, char *argv[])
{
    print_maximum_number_mlloc();
}