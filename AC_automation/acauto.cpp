#include <iostream>
#include "AC_automachine.h"
#include <unistd.h>
#include <ctime>
int main() {
    AC_automachine ac;
    List<char*> keyList;
    printf("pid:%d\n",getpid());
    clock_t start_time = clock();
    clock_t end_time;
    FILE *infile = fopen("../pattern.txt", "rb");
    if(infile == NULL) {
        printf("Failed to open pattern.txt\n");
        return -1;
    }
    while(!feof(infile)) {
        char buff[128];             //用于存储一个keyword
        int ch = fgetc(infile);     //读取一个字符
        int idx = 0;
        //逐个读取字符，直到行尾或文件尾
        while(ch != 0x0A && ch != -1) {
            buff[idx] = ch;
            ++idx;
            ch = fgetc(infile);
        }
        buff[idx] = '\0';           //一个keyword读取结束
        char* key = new char[strlen(buff)];
        strcpy(key, buff);
        ac.Insert(key);            //插入ac自动机
    }
    fclose(infile);
    end_time = clock();
    printf("Finished reading pattern.txt\n");
    printf("read pattern.txt: %lu ms\n", (end_time - start_time) * 1000/CLOCKS_PER_SEC);

    ac.Build();
    printf("Build success!\n");
    printf("Build: %lu ms\n", (clock() - end_time) * 1000/CLOCKS_PER_SEC);
    end_time = clock();

    ac.MatchByFile("../string.txt", "rb");
    printf("Match: %lu ms\n", (clock() - end_time) * 1000/CLOCKS_PER_SEC);
    end_time = clock();

    ac.OutputToFile("../result.txt");
    printf("Output: %lu ms\n", (clock() - end_time) * 1000/CLOCKS_PER_SEC);
    end_time = clock();
    printf("All runtime: %lu ms\n", (end_time - start_time) * 1000/CLOCKS_PER_SEC);
    return 0;
}
