#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma comment(lib, "Winmm.lib")
int goal = 0;
//����˼·��ʹ�õ���eazyxͼ�ο⣬��������״��intȡ��16λ��ʽ���棬�з����λ��Ϊ1��û�е�Ϊ0����������״��������s�С���b�����¼��������ʱ���з��飬��Ϊ1��û��Ϊ0������ʱʹ����ϵͳʱ��Ϊseed���������//
void music() //��������//
{
  PlaySound(TEXT("m.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
}
void musicstop() //ֹͣ����//
{
  PlaySound(NULL, NULL, SND_FILENAME);
}

void drawstr() //�������ͼ//
{
  initgraph(1200, 800);
  setlinecolor(GREEN);
  line(29, 29, 331, 29);
  line(29, 29, 29, 631);
  line(331, 29, 331, 631);
  line(29, 631, 331, 631);
}

void linecolor(int color) //��������ɫ//
{
  switch (color) {
  case 0:
    setlinecolor(WHITE);
    break;
  case 1:
    setlinecolor(BLACK);
    break;
  }
}
void reccolor(int color) //�������ɫ//
{
  switch (color) {
  case 0:
    setfillcolor(WHITE);
    break;
  case 1:
    setfillcolor(YELLOW);
    break;
  case 2:
    setfillcolor(GREEN);
    break;
  case 3:
    setfillcolor(CYAN);
    break;
  case 4:
    setfillcolor(RED);
    break;
  case 5:
    setfillcolor(MAGENTA);
    break;
  case 6:
    setfillcolor(BROWN);
    break;
  case 7:
    setfillcolor(BLUE);
    break;
  case 8:
    setfillcolor(DARKGRAY);
    break;
  case 9:
    setfillcolor(LIGHTRED);
    break;
  case 10:
    setfillcolor(BLACK);
    break;
  }
}
void drawrec(int x, int y) //�������//
{
  linecolor(0);
  reccolor(rand() % 10);
  fillrectangle(x, y, x + 30, y + 30);
}
void drawblk(int x, int y) //�������//
{
  linecolor(1);
  reccolor(10);
  fillrectangle(x, y, x + 30, y + 30);
}
int transx(int i) //������ת��Ϊ��Ӧ�ĺ�����//
{
  switch (i) {
  case 0:
  case 4:
  case 8:
  case 12:
    return 30;
    break;
  case 1:
  case 5:
  case 9:
    return 60;
    break;
  case 2:
  case 6:
    return 90;
    break;
  case 3:
    return 120;
    break;
  default:
    return 0;
    break;
  }
}
int transy(int i) //������ת��Ϊ��Ӧ��������//
{
  switch (i) {
  case 0:
  case 1:
  case 2:
  case 3:
    return 30;
    break;
  case 4:
  case 5:
  case 6:
    return 60;
    break;
  case 7:
  case 8:
  case 9:
    return 90;
    break;
  case 12:
    return 120;
    break;
  default:
    return 0;
    break;
  }
}
int croodx(int x) //�����x��߽�//
{
  switch (x) {
  case 15:
    return 180;
    break;
  case 4369:
    return 270;
    break;
  case 51:
  case 306:
  case 561:
  case 785:
  case 547:
  case 802:
  case 275:
  case 562:
  case 305:
    return 240;
    break;
  case 99:
  case 54:
  case 23:
  case 116:
  case 113:
  case 71:
  case 39:
  case 114:
    return 210;
    break;
  default:
    return 0;
    break;
  }
}

void store(int i, int a[]) //������������ת��Ϊ��Ӧ�ķ�����״//
{
  for (int i1 = 0; i1 <= 15; i1++) {
    if (((0x1 << i1) & i) != 0)
      a[i1] = 1;
  }
}

void clear(int b[][21]) //��ȥ���һ�еķ���//
{
  for (int y = 19; y >= 0; y--) {
    int x = 0;
    for (int i = 0; i <= 9; i++)
      x += b[i][y];
    if (x == 10) {
      for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= y; j++)
          if (b[i][j] == 1)
            drawblk((i + 1) * 30, (j + 1) * 30);
      for (int i = 0; i <= 9; i++) {
        b[i][y] = 0;
        b[i][0] = 0;
      }
      for (int j = y; j >= 1; j--)
        for (int i = 0; i <= 9; i++) {
          b[i][j] = b[i][j - 1];
          b[i][j - 1] = 0;
        }
      linecolor(1);
      reccolor(10);
      fillrectangle(30, 30, 330, 630);
      linecolor(0);
      reccolor(rand() % 8 + 2);
      for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 19; j++)
          if (b[i][j] == 1)
            fillrectangle((i + 1) * 30, (j + 1) * 30, (i + 2) * 30,
                          (j + 2) * 30);
      goal += 10;
    } else {
      linecolor(1);
      reccolor(10);
      fillrectangle(30, 30, 330, 630);
      linecolor(0);
      reccolor(rand() % 8 + 2);
      for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 19; j++)
          if (b[i][j] == 1)
            fillrectangle((i + 1) * 30, (j + 1) * 30, (i + 2) * 30,
                          (j + 2) * 30);
    }
  }
}

void clear1(int b[][21]) {
  for (int y = 19; y >= 0; y--) {
    int x = 0;
    for (int i = 0; i <= 9; i++)
      x += b[i][y];
    if (x == 10) {
      for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= y; j++)
          if (b[i][j] == 1)
            drawblk((i + 1) * 30, (j + 1) * 30);
      for (int i = 0; i <= 9; i++) {
        b[i][y] = 0;
        b[i][0] = 0;
      }
      for (int j = y; j >= 1; j--)
        for (int i = 0; i <= 9; i++) {
          b[i][j] = b[i][j - 1];
          b[i][j - 1] = 0;
        }
      linecolor(1);
      reccolor(10);
      fillrectangle(30, 30, 330, 630);
      linecolor(0);
      reccolor(rand() % 8 + 2);
      for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 19; j++)
          if (b[i][j] == 1)
            fillrectangle((i + 1) * 30, (j + 1) * 30, (i + 2) * 30,
                          (j + 2) * 30);
      goal += 10;
    }
  }
}
int transrecfor(int x, int s[]) //�������//
{
  switch (x) {
  case 2:
    return s[1];
    break;
  case 4:
    return s[3];
    break;
  case 6:
    return s[5];
    break;
  case 10:
    return s[7];
    break;
  case 14:
    return s[11];
    break;
  case 18:
    return s[15];
    break;
  case 19:
    return s[19];
    break;
  default:
    return s[x + 1];
    break;
  }
}

int transrecmarkfor(int x) //�ı䷽�����//
{
  switch (x) {
  case 2:
    return 1;
    break;
  case 4:
    return 3;
    break;
  case 6:
    return 5;
    break;
  case 10:
    return 7;
    break;
  case 14:
    return 11;
    break;
  case 18:
    return 15;
    break;
  case 19:
    return 19;
    break;
  default:
    return x + 1;
    break;
  }
}

int transrecpre(int x, int s[]) //����ָ�ǰһ�α任//
{
  switch (x) {
  case 1:
    return s[2];
    break;
  case 3:
    return s[4];
    break;
  case 5:
    return s[6];
    break;
  case 7:
    return s[10];
    break;
  case 11:
    return s[14];
    break;
  case 15:
    return s[18];
    break;
  case 19:
    return s[19];
    break;
  default:
    return s[x - 1];
    break;
  }
}

int transrecmarkpre(int x) //������Żָ�ǰһ�α任//
{
  switch (x) {
  case 1:
    return 2;
    break;
  case 3:
    return 4;
    break;
  case 5:
    return 6;
    break;
  case 7:
    return 10;
    break;
  case 11:
    return 14;
    break;
  case 15:
    return 18;
    break;
  case 19:
    return 19;
    break;
  default:
    return x - 1;
    break;
  }
}

int drop(int zbx, int a[], int b[][21], int s[], int sx) //��������//
{
  int time = 30;
  int ends = 0;
  int x = 0;
  int y = 0;
  int left = 0;
  int right = 0;
  int xright, i;
  char c = 0;
  time = time - ((goal / 100) * 5);
  if (time <= 5)
    time = 5;
  while (y <= 600 && ends == 0) {
    xright = croodx(zbx);
    if (_kbhit() && x >= 0 && x <= 270) {
      int ends0 = 0;
      c = _getch();
      switch (c) {
      case 75: //����//
        left = 0;
        for (i = 0; i <= 15; i++) {
          if ((a[i] == 1) && ((y + 1) % 30 != 0) &&
              ((b[((transx(i) + x - 31) / 30)][(transy(i) + y - 30) / 30] ==
                1) ||
               (b[((transx(i) + x - 31) / 30)][(transy(i) + y - 30) / 30 + 1] ==
                1)))
            left = 1;
          if ((a[i] == 1) && ((y + 1) % 30 == 0) &&
              (b[((transx(i) + x - 31) / 30)][(transy(i) + y - 30) / 30 + 1] ==
               1))
            left = 1;
        }
        if ((x <= 0) || left == 1)
          break;
        else
          x -= 30;
        break;
      case 77: //����//
        right = 0;
        for (i = 0; i <= 15; i++) {
          if ((a[i] == 1) && ((y + 1) % 30 != 0) &&
              ((b[((transx(i) + x - 1) / 30 + 1)][(transy(i) + y - 30) / 30] ==
                1) ||
               (b[((transx(i) + x - 1) / 30 + 1)]
                 [(transy(i) + y - 30) / 30 + 1] == 1)))
            right = 1;
          if ((a[i] == 1) && ((y + 1) % 30 == 0) &&
              (b[((transx(i) + x - 1) / 30) + 1]
                [(transy(i) + y - 30) / 30 + 1] == 1))
            right = 1;
        }
        if ((x >= xright) || right == 1)
          break;
        else
          x += 30;
        break;
      case 32: //����//
        time -= 15;
        if (time <= 0)
          time = 1;
        break;
      case 72: //����//
        for (i = 0; i <= 15; i++)
          a[i] = 0;
        store(transrecfor(sx, s), a);
        zbx = transrecfor(sx, s);
        sx = transrecmarkfor(sx);
        for (i = 0; i <= 15; i++) {
          if ((a[i] == 1) && (b[((transx(i) + x - 30) / 30)]
                               [(transy(i) + y - 31) / 30 + 1] == 1))
            ends0 = 1;
        }
        if (ends0 == 1) {
          for (i = 0; i <= 15; i++)
            a[i] = 0;
          store(transrecpre(sx, s), a);
          zbx = transrecpre(sx, s);
          sx = transrecmarkpre(sx);
        }
        break;
      case 'p': //��ͣ//
        for (i = 0; i <= 15; i++) {
          if (a[i] == 1)
            drawrec((transx(i) + x), (transy(i) + y));
        }
        _getch();
        break;
      case 'x': //ֹͣ���ֲ���//
        musicstop();
        break;
      case 'z': //��ʼ���ֲ���//
        music();
        break;
      default:
        break;
      }
    }
    for (i = 0; i <= 15; i++) {
      if (a[i] == 1)
        drawrec((transx(i) + x), (transy(i) + y));
    }
    Sleep(time);
    for (i = 0; i <= 15; i++) {
      if (a[i] == 1)
        drawblk((transx(i) + x), (transy(i) + y));
    }
    for (i = 0; i <= 15; i++) {
      if ((a[i] == 1) &&
          (b[((transx(i) + x - 30) / 30)][(transy(i) + y) / 30] == 1)) {
        ends = 1;
      }
    }
    y++;
  }
  for (i = 0; i <= 15; i++) {
    if (a[i] == 1)
      drawrec((transx(i) + x), (transy(i) + y));
  }
  for (i = 0; i <= 15; i++) {
    if (a[i] == 1)
      b[(transx(i) + x - 30) / 30][(transy(i) + y - 30) / 30] = 1;
  }
  clear(b);
  clear1(b);
  clear1(b);
  clear1(b);
  for (i = 0; i <= 9; i++)
    if (b[i][0] == 1)
      return 1;
  return 0;
}

void initial() //��ʼ����Ϸ���//
{
  drawstr();
  line(400, 160, 600, 160);
  line(600, 160, 600, 360);
  line(400, 360, 600, 360);
  line(400, 160, 400, 360);
  outtextxy(500, 50, _T("����˵��"));
  outtextxy(400, 80, _T("�������͡��������Ʒ��򣬡�������ת���飬�ո�����½� ( ")
                     _T("�������� ) ,��p����ͣ��Ϸ"));
  outtextxy(400, 110, _T("��z������ʼ�������֣���x����ֹͣ����"));
  outtextxy(400, 400, _T("��������һ�����ֵ�ͼ�Ρ�����"));
  outtextxy(400, 430, _T("���� ( ÿ����һ��������1�֣���ȥһ�л��10�� ) "));
  outtextxy(400, 500, _T("��ǰ�Ѷȵȼ���"));
  line(400, 460, 430, 460);
  line(430, 460, 430, 490);
  line(430, 490, 400, 490);
  line(400, 490, 400, 460);
  outtextxy(50, 80, _T("��ʼ��Ϸǰ�뽫�������뷨�رգ�"));
  outtextxy(50, 50, _T("���������ʼ��Ϸ!"));
  _getch();
  reccolor(10);
  linecolor(1);
  fillrectangle(50, 50, 300, 300);
}

int main(void) {
  TCHAR goalc[5];
  int k1 = 0;
  int k2 = 0;
  int cs = 0;
  int s[] = {
      0,   15,  4369, 99, 306, 54,  561, 785, 23, 547, 116,
      802, 113, 275,  71, 39,  562, 114, 305, 51}; //��ʼ�����飬��������ʾ������״//
  int a[16] = {0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0}; //��ǰ����ķ���//
  int a1[16] = {0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0}; //��һ������ķ���//
  int b[11][21];                         //��¼ĳλ���Ƿ��з���//
  int i, j;
  initial();
  for (i = 0; i <= 9; i++)
    for (j = 0; j <= 19; j++)
      b[i][j] = 0;
  for (i = 0; i <= 9; i++)
    b[i][20] = 1;
  for (i = 0; i <= 19; i++)
    b[10][i] = 1;
  srand((unsigned)time(NULL));
  k2 = rand() % 19 + 1;
  for (j = 0; j <= 10000; j++) {
    _stprintf(goalc, _T("%d"), goal / 100 + 1);
    outtextxy(500, 500, goalc);
    for (i = 0; i <= 18; i++) {
      a[i] = 0;
      a1[i] = 0;
    }
    k1 = rand() % 19 + 1;
    store(s[k1], a1);
    for (i = 0; i <= 18; i++)
      if (a1[i] == 1)
        drawrec(transx(i) + 430, transy(i) + 190);
    store(s[k2], a);
    goal += 1;
    cs = drop(s[k2], a, b, s, k2);
    for (i = 0; i <= 18; i++)
      if (a1[i] == 1)
        drawblk(transx(i) + 430, transy(i) + 190);
    if (cs == 1) {
      reccolor(10);
      linecolor(1);
      fillrectangle(30, 30, 330, 630);
      outtextxy(50, 50, _T("GAME OVER!"));
      break;
    }
    k2 = k1;
    _stprintf(goalc, _T("%d"), goal);
    outtextxy(405, 465, goalc);
  }
  while (1)
    char end = _getch();
}

