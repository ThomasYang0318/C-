#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STONES 7

void arrange(int stones[]);  //排列各個石頭的堅硬程度
void voice(int type);  //音叉聲音

int main() {
    int stones[NUM_STONES] = { 1, 2, 2, 3, 3, 3, 3 };  //7顆石頭
    int hp = 100;  //生命值
    int stone_index = 0;
    int bombs = 2;  //2顆炸彈

    arrange(stones);

    while (hp > 0 && stone_index < NUM_STONES) {
        printf("第%d顆石頭  波奇:%d  炸彈數量:%d\n", stone_index + 1, hp, bombs);
        printf("<1>音叉 <2>鐵鎚 <3>電鑽 <4>炸彈 <5>放棄 >> 選擇:");

        int option;
        scanf("%d", &option);

        switch (option) {  //玩家選擇工具
        case 1:
            voice(stones[stone_index]);
            
            break;
        
        case 2:
            if (stones[stone_index] >= 3) {
                printf("\n<<成功擊碎石頭>>\n\n");
                stone_index++;
            
            }
            
            else {
                printf("\n<<石頭產生裂痕>>\n\n");
            
            }