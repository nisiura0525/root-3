#if 1 //←ここを0にすると #else より下のサンプルプログラムが実行される
      //1の時は真下に自分でプログラムをタイプしていくことができる。

#include"libOne.h"
void gmain() {
    window(1000, 1000);
    struct CIRCLE {
        float x, y, r;
    };
    let a, b, c;
    struct CIRCLE c1,c2;
    while (notQuit) {
        clear(160);
        c1.x = width / 2;
        c1.y = height / 2;
        c1.r = 100;
        c2.x = MouseX;
        c2.y = MouseY;
        c2.r = 150;
        circle(c1.x, c1.y, c1.r*2);
        circle(c2.x, c2.y, c2.r*2);
        line(c1.x, c1.y, c2.x, c2.y);//斜辺
        line(c1.x, c1.y, c2.x, c1.y);//底辺
        line(c2.x, c2.y, c2.x, c1.y);//高さ
        a =  c2.x - c1.x;
        b = c1.y - c2.y;
        c = sqrt(a * a + b * b);

        textSize(50);
        text("底辺　＝" + a,0,60);
        text("高さ　＝" + b, 0, 120);
        text("斜辺　＝" + c, 0, 180);
        if (c < c1.r+c2.r) {//半径＋半径
            fill(255, 0, 0,128);
        }
        else fill(4,252,227);
    }
}










#else

#include"libOne.h"
void gmain() {
    window(1000, 1000);
    struct CIRCLE {
        float x, y;//位置
        float r;//半径 radius
    };
    struct CIRCLE c1, c2;
    //底辺a、高さb、斜辺distance
    float a, b, distance;
    //円１の初期値
    c1.x = width / 2;
    c1.y = height / 2;
    c1.r = 120;
    //円２の初期値
    c2.x = 0;
    c2.y = 0;
    c2.r = 80;
    while (notQuit) {
        //円２の位置を決定
        c2.x = mouseX;
        c2.y = mouseY;
        //円１と円２の距離を求める
        a = c1.x - c2.x;
        b = c1.y - c2.y;
        distance = sqrt(a * a + b * b);
        //当たり判定
        if (distance <= c1.r + c2.r) {
            fill(255, 0, 0, 200);
        }
        else {
            fill(160, 200, 255);
        }
        //描画
        clear(160);
        circle(c1.x, c1.y, c1.r * 2);
        circle(c2.x, c2.y, c2.r * 2);
        //直角三角形
        line(c1.x, c1.y, c2.x, c2.y);
        line(c1.x, c1.y, c2.x, c1.y);
        line(c2.x, c1.y, c2.x, c2.y);
        //テキスト情報
        textSize(50);
        text("距離=" + (let)distance, 0, 60);
    }
}

#endif