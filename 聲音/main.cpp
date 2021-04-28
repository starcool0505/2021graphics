#include <windows.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;///要放在專案目錄
void display()///宣告一個變數
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='1') PlaySound("do.wav", NULL, SND_ASYNC);
    if(key=='2') PlaySound("re.wav", NULL, SND_ASYNC);
    if(key=='3') PlaySound("mi.wav", NULL, SND_ASYNC);
    if(key=='4') PlaySound("fa.wav", NULL, SND_ASYNC);
    if(key=='5') PlaySound("so.wav", NULL, SND_ASYNC);
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN&&button==GLUT_LEFT_BUTTON) shot1.Play();
    if(state==GLUT_DOWN&&button==GLUT_MIDDLE_BUTTON) shot2.Play();
    if(state==GLUT_DOWN&&button==GLUT_RIGHT_BUTTON) shot3.Play();
}
int main(int argc, char**argv)
{
    shot1.Load("1.wav");

    mp3.Load("123.mp3");///檔案放在執行目錄
    mp3.Play();///播放

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("08161001");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}
