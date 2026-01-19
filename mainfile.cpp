#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

bool scenarioMeraz = true;
bool scenarioMohaiminul = false;
bool scenarioMohaimuiul = false;

/// **************************************************************************************************************************************************
/// ******************************************************** >>> MERAZ <<< ************************************************************************
/// **************************************************************************************************************************************************
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}

void V_cloud3()
{
    glPushMatrix();
    glTranslatef(V_moveCloud3, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 700, y = 650, r = 20;
    circle(x, y-15, r);
    circle(x+25, y-10, r);
    circle(x-25, y-10, r);
    circle(x-50, y, r);
    circle(x+50, y, r);
    circle(x+30, y+15, r+5);
    circle(x, y+25, r+5);
    circle(x-30, y+15, r+5);

    glBegin(GL_QUADS);
    glVertex2f(650,630);
    glVertex2f(750,630);
    glVertex2f(750,670);
    glVertex2f(650,670);
    glEnd();

    glPopMatrix();
}

void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud3(int value)
{
    if(!V_cloudPaused3)
    {
        V_moveCloud3 -= V_cloudSpeed3;
        if (V_moveCloud3 < -800)
        {
            V_moveCloud3 = 420;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, V_updateCloud3, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

/// ##############################################################  Garden  ###############################################################
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
    /// Triangle Tree
    int shift = 70;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,205);
        glVertex2f(25 + shift * i,205);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(10  + shift * i,225);
        glVertex2f(30 + shift * i,225);
        glVertex2f(20 + shift * i,235);

        glVertex2f(10  + shift * i,230);
        glVertex2f(30 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }
}

/// ##############################################################  Train  ###############################################################
float moveTrain = 0.0f;
float trainSpeed =1.0f;
float savedTrainSpeed = 0.0f;
bool trainPaused = false;

void train()
{
    glPushMatrix();
    glTranslatef(moveTrain, 0.0f, 0.0f);

    // Main body
    if (isDay)
        glColor3f(0.70f, 0.20f, 0.20f);
    else
        glColor3f(0.50f, 0.18f, 0.18f);

    glBegin(GL_POLYGON);
    glVertex2f(300.0f, 290.0f);
    glVertex2f(720.0f, 290.0f);
    glVertex2f(720.0f, 335.0f);
    glVertex2f(680.0f, 355.0f);
    glVertex2f(320.0f, 355.0f);
    glVertex2f(300.0f, 345.0f);
    glEnd();

    //Top stripe above windows
    if (isDay)
        glColor3f(0.20f, 0.70f, 0.18f);
    else
        glColor3f(0.15f, 0.35f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(310.0f, 340.0f);
    glVertex2f(690.0f, 340.0f);
    glVertex2f(690.0f, 345.0f);
    glVertex2f(310.0f, 345.0f);
    glEnd();

    // Outline for top stripe
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(310.0f, 340.0f);
    glVertex2f(690.0f, 340.0f);
    glVertex2f(690.0f, 345.0f);
    glVertex2f(310.0f, 345.0f);
    glEnd();

    // === Bottom stripe below windows ===
    if (isDay)
    {
        glColor3f(0.95f, 0.12f, 0.18f);
    }
    else
    {
        glColor3f(0.55f, 0.15f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(310.0f, 293.5f);
        glVertex2f(700.0f, 293.5f);
        glVertex2f(700.0f, 298.5f);
        glVertex2f(310.0f, 298.5f);
        glEnd();
    }

    // Outline for bottom stripe
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(310.0f, 293.5f);
    glVertex2f(700.0f, 293.5f);
    glVertex2f(700.0f, 298.5f);
    glVertex2f(310.0f, 298.5f);
    glEnd();

    // === Window row ===
    float wx = 340.0f;
    for (int i = 0; i < 6; ++i)
    {
        // window fill
        if (isDay)
            glColor3f(0.92f, 0.98f, 1.0f);
        else
            glColor3f(0.95f, 0.94f, 0.65f);

        glBegin(GL_QUADS);
        glVertex2f(wx, 305.0f);
        glVertex2f(wx + 52.0f, 305.0f);
        glVertex2f(wx + 52.0f, 333.0f);
        glVertex2f(wx, 333.0f);
        glEnd();

        // window frame
        glColor3f(0.06f, 0.06f, 0.06f);
        glLineWidth(4.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(wx, 305.0f);
        glVertex2f(wx + 52.0f, 305.0f);
        glVertex2f(wx + 52.0f, 333.0f);
        glVertex2f(wx, 333.0f);
        glEnd();

        wx += 60.0f;
    }

    //   cabin
    if (isDay)
        glColor3f(0.38f, 0.84f, 1.0f);
    else
        glColor3f(0.18f, 0.64f, 0.80f);
    glBegin(GL_POLYGON);
    glVertex2f(300.0f, 305.0f);
    glVertex2f(318.0f, 315.0f);
    glVertex2f(318.0f, 332.0f);
    glVertex2f(300.0f, 340.0f);
    glEnd();

    // Front glass
    if (isDay)
        glColor3f(0.02f, 0.12f, 0.20f);
    else
        glColor3f(0.98f, 0.92f, 0.30f);
    glBegin(GL_POLYGON);
    glVertex2f(305.0f, 310.0f);
    glVertex2f(316.0f, 315.0f);
    glVertex2f(316.0f, 328.0f);
    glVertex2f(305.0f, 329.0f);
    glEnd();

    // Front headlight
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(298.0f, 300.0f);
    glVertex2f(305.0f, 300.0f);
    glVertex2f(305.0f, 305.0f);
    glVertex2f(298.0f, 305.0f);
    glEnd();

    //Back light (yellow square at rear)
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(715.0f, 300.0f);
    glVertex2f(720.0f, 300.0f);
    glVertex2f(720.0f, 308.0f);
    glVertex2f(715.0f, 308.0f);
    glEnd();

    // Back bumper trim
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(710.0f, 290.0f);
    glVertex2f(720.0f, 290.0f);
    glVertex2f(720.0f, 296.0f);
    glVertex2f(710.0f, 296.0f);
    glEnd();

    //Small underbody shadow
    glColor3f(0.08f, 0.08f, 0.08f);
    glBegin(GL_QUADS);
    glVertex2f(310.0f, 284.5f);
    glVertex2f(700.0f, 284.5f);
    glVertex2f(700.0f, 292.0f);
    glVertex2f(310.0f, 292.0f);
    glEnd();

    glPopMatrix();
}

void updateTrain(int value)
{
    if (!trainPaused)
    {
        moveTrain -= trainSpeed;
        if (moveTrain < -800.0f)
        {
            moveTrain = 750.0f;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateTrain, 0);
}


/// ##############################################################  Flyover  ###############################################################
void flyOver()
{
    ///Pillar
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    for(int x = 50; x<1000; x+=100)
    {
        glVertex2f(x,   205);
        glVertex2f(x+15,205);
        glVertex2f(x+15,275);
        glVertex2f(x,   275);
    }
    glEnd();

    /// Pillar upper box
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_TRIANGLES);
    for(int x = 40; x<1000; x+=100)
    {
        glVertex2f(x,     275);
        glVertex2f(x+35,  275);
        glVertex2f(x+15,255);
    }
    glEnd();

    if(isDay)
        glColor3f(0.80f, 0.80f, 0.80f);
    else
        glColor3f(.4,.4,.4);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0,   275);
    glVertex2f(1000,275);
    glEnd();

    ///Bridge body
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(0,   277);
    glVertex2f(1000,277);
    glVertex2f(1000,288);
    glVertex2f(0,   288);
    glEnd();
}

/// ##############################################################  Road  ###############################################################
void road()
{
    if (isDay)
        glColor3f(.37f, .37f, .37f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.15f, 0.15f, 0.15f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// ##############################################################  Bus  ###################################################################
float V_moveBus = 0.0f;
float V_busSpeed =1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

void bus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    // --- BODY & LIGHTS (No Changes here) ---
    glBegin(GL_QUADS);
    if (isDay) glColor3f(1.00f, 0.60f, 0.29f);
    else       glColor3f(0.70f, 0.35f, 0.20f);

    glVertex2f(400, 130); glVertex2f(550, 130);
    glVertex2f(550, 190); glVertex2f(400, 190);

    glVertex2f(550, 130); glVertex2f(570, 130);
    glVertex2f(570, 160); glVertex2f(550, 190);
    glEnd();

    // FRONT Light
    if(isDay) glColor3f(1,1,1); else glColor3f(1,1,0);
    glBegin(GL_QUADS);
    glVertex2f(565, 135); glVertex2f(570, 135);
    glVertex2f(570, 142); glVertex2f(565, 142);
    if(!isDay) {
        glColor3f(1,1,.6);
        glVertex2f(570, 135); glVertex2f(640, 125);
        glVertex2f(640, 152); glVertex2f(570, 142);
    }
    // REAR LIGHT
    if(isDay) glColor3f(1,1,1); else glColor3f(1,0,0);
    glVertex2f(400, 135); glVertex2f(405, 135);
    glVertex2f(405, 142); glVertex2f(400, 142);
    glEnd();

    // WINDOWS
    if (isDay) glColor3f(0.92f, 1.0f, 0.996f); else glColor3f(1,1,.6);
    glBegin(GL_QUADS);
    glVertex2f(410, 160); glVertex2f(530, 160);
    glVertex2f(530, 180); glVertex2f(410, 180);
    glEnd();

    glColor3f(1.00f, 0.60f, 0.29f);
    glLineWidth(4);
    glBegin(GL_LINES);
    for(int x = 432; x<530; x+=25) {
        glVertex2f(x,160); glVertex2f(x,180);
    }
    glEnd();

    if (isDay) glColor3f(0.92f, 1.0f, 0.996f); else glColor3f(1,1,.6);
    glBegin(GL_QUADS);
    glVertex2f(533, 180); glVertex2f(550, 180);
    glVertex2f(565, 150); glVertex2f(533, 160);
    glEnd();

    // ==========================================
    // FIX: WHEELS (Logic corrected)
    // ==========================================

    // --- REAR TIRE ---
    glColor3f(0,0,0);
    halfCircle(425,130,12); // Fender

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-425, -130, 0);

    // 1. Tire Body
    if (isDay) glColor3f(0.8f, 0.8f, 0.8f);
    else       glColor3f(0.5f, 0.5f, 0.5f);
    circle(425,130,11); // <--- MOVED OUTSIDE ELSE

    // 2. Rim / Hubcap
    if (isDay) glColor3f(1.0f, 1.0f, 1.0f);
    else       glColor3f(0.7f, 0.7f, 0.7f);
    circle(425,130,5);  // <--- MOVED OUTSIDE ELSE

    // 3. Spokes
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130); glVertex2f(436,130);
    glEnd();
    glPopMatrix();

    // --- FRONT TIRE ---
    glColor3f(0,0,0);
    halfCircle(540,130,12); // Fender

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-540, -130, 0);

    // 1. Tire Body
    if (isDay) glColor3f(0.8f, 0.8f, 0.8f);
    else       glColor3f(0.5f, 0.5f, 0.5f);
    circle(540,130,11); // <--- MOVED OUTSIDE ELSE

    // 2. Rim / Hubcap
    if (isDay) glColor3f(1.0f, 1.0f, 1.0f);
    else       glColor3f(0.7f, 0.7f, 0.7f);
    circle(540,130,5);  // <--- MOVED OUTSIDE ELSE

    // 3. Spokes
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(529,130); glVertex2f(551,130);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void V_updateBus(int value)
{
    if(!V_busPaused)
    {
        V_moveBus += V_busSpeed+1;
        if (V_moveBus > 700)
        {
            V_moveBus = -550;
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);


}
/// ######################################################## Cargo Track ########################################################
float V_moveCargo = 0.0f;
float V_cargoSpeed =3.0f;
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

void cargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, 0, 0);

    /// Head and Body joint
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(760, 73);
    glVertex2f(730, 73);
    glVertex2f(730, 110);
    glVertex2f(760, 83);
    glEnd();

    ///  ********> Body <********
    if (isDay)
        glColor3f(0.51f, 0.86f, 0.92f);
    else
        glColor3f(0.22f, 0.46f, 0.55f);

    glBegin(GL_QUADS);
    glVertex2f(900, 83);
    glVertex2f(750, 83);
    glVertex2f(750, 150);
    glVertex2f(900, 150);
    glEnd();


    /// Head
    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// upper quad
    glBegin(GL_QUADS);
    glVertex2f(745, 138);
    glVertex2f(715, 138);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    if (isDay)
        glColor3f(0.69f, 0.92f, 0.95f);
    else
        glColor3f(0.32f, 0.55f, 0.65f);

    glVertex2f(690, 113);
    glVertex2f(693, 111);
    glVertex2f(713, 132);
    glVertex2f(711, 135);

    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// down quad
    glVertex2f(745, 75);
    glVertex2f(690, 70);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    glEnd();

    if (isDay)
        glColor3f(0.07f, 0.64f, 0.70f);
    else
        glColor3f(0.04f, 0.38f, 0.50f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(740, 133);
    glVertex2f(717, 133);

    glVertex2f(740, 134);
    glVertex2f(740, 87);

    glVertex2f(740, 87);
    glVertex2f(720, 87);

    glVertex2f(720, 87);
    glVertex2f(710, 80);

    glVertex2f(710, 80);
    glVertex2f(693, 83);

    glVertex2f(717, 133);
    glVertex2f(693, 110);

    glVertex2f(693, 110);
    glVertex2f(693, 83);

    glEnd();

    /// window glass
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(718, 130);
    glVertex2f(737, 130);
    glVertex2f(737, 105);
    glVertex2f(697, 100);
    glVertex2f(697, 110);
    glEnd();

    /// inner glass
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(0.60f, 0.75f, 0.78f);

    glBegin(GL_POLYGON);
    glVertex2f(720, 128);
    glVertex2f(735, 128);
    glVertex2f(735, 107);
    glVertex2f(699, 102);
    glVertex2f(701, 110);
    glEnd();

    ///******> door holder
    if (isDay)
        glColor3f(0.1f, 0.1f, 0.4f);
    else
        glColor3f(0.05f, 0.05f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(735, 102);
    glVertex2f(735, 98);
    glVertex2f(727, 98);
    glVertex2f(727, 102);
    glEnd();

    /// *********>  REAR Light  <***********
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(895, 78);
    glVertex2f(900, 78);
    glVertex2f(900, 90);
    glVertex2f(895, 90);
    glEnd();


    /// *********>  FRONT Light  <***********
    if (isDay)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.8f, 0.8f, 0.2f);

    glBegin(GL_QUADS);
    glVertex2f(689, 82);
    glVertex2f(695, 85);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    if (isDay)
        glColor3f(1.0f, 0.68f, 0.016f);
    else
        glColor3f(0.8f, 0.5f, 0.01f);

    glVertex2f(689, 94);
    glVertex2f(695, 95);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    glEnd();

    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.68f, 0.016f);
        glVertex2f(689, 94);
        glVertex2f(600, 97);
        glVertex2f(600, 50);
        glVertex2f(689, 84);

        glEnd();
    }

    /// Under The Body Black bar
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(900, 73);
    glVertex2f(730, 73);
    glVertex2f(725, 83);
    glVertex2f(900, 83);

    glEnd();

    /// Front Black Bumper
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_POLYGON);
    glVertex2f(690, 70);
    glVertex2f(730, 70);
    glVertex2f(730, 75);
    glVertex2f(695, 75);
    glVertex2f(695, 85);
    glVertex2f(685, 80);

    glEnd();

    /// ********> body design <********
    if (isDay)
        glColor3f(0.31f, 0.81f, 0.88f);
    else
        glColor3f(0.15f, 0.45f, 0.55f);

    glBegin(GL_QUADS);

    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);
        glVertex2f(x-7, 145);
        glVertex2f(x, 145);
    }
    glEnd();

    /// Body sky blue 3 quads
    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.4f, 0.6f, 0.7f);

    glBegin(GL_QUADS);
    glVertex2f(755, 145);
    glVertex2f(775, 145);
    glVertex2f(810, 88);
    glVertex2f(790, 88);

    glVertex2f(785, 145);
    glVertex2f(825, 145);
    glVertex2f(860, 88);
    glVertex2f(820, 88);

    glVertex2f(835, 145);
    glVertex2f(860, 145);
    glVertex2f(895, 88);
    glVertex2f(870, 88);

    glEnd();

    /// blue design shadow
    /// side shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.3f, 0.35f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 889; x>750; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x, 145);
    }
    glEnd();

    /// body up-down shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.28f, 0.32f);

    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);

        glVertex2f(x, 145);
        glVertex2f(x-7, 145);
    }
    glEnd();

    /// REAR TIRE
    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(865,69,14);

    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(865,69,12);

    glPushMatrix();
    glTranslatef(865, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-865, -69, 0);

    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.4f, 0.4f, 0.35f);

    circle(865,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(865,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.3f, 0.32f, 0.33f);

    circle(865,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(865,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(865,69,4);

    glPopMatrix();

    /// FRONT TIRE

    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(725,69,14);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(725,69,12);

    glPushMatrix();
    glTranslatef(725, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-725, -69, 0);

    // Front Tire
    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.45f, 0.45f, 0.4f);

    circle(725,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(725,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.35f, 0.38f, 0.39f);

    circle(725,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.45f, 0.45f, 0.45f);

    circle(725,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(725,69,4);

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(.5,.5,.5);

    glBegin(GL_TRIANGLES);
    glVertex2f(722,70);
    glVertex2f(728,70);
    glVertex2f(725,66);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void V_updateCargo(int value)
{
    if(!V_cargoPaused)
    {
        V_moveCargo -= V_cargoSpeed;
        if (V_moveCargo < -940)
        {
            V_moveCargo = 450;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateCargo, 0);


}

/// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.839f, 0.443f, 0.235f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);

    for(int x = 10; x<1000; x+=20)
    {
        glVertex2f(x,170);
        glVertex2f(x,175);

        glVertex2f(x+10,175);
        glVertex2f(x+10,180);

        glVertex2f(x,180);
        glVertex2f(x,185);

        glVertex2f(x+10,185);
        glVertex2f(x+10,190);
    }

    glEnd();

    //Upper 2 lines
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(0,   200);
    glVertex2f(1000,200);

    glVertex2f(0,   205);
    glVertex2f(1000,205);

    for(int i = 0; i< 1000; i+=45)
    {
        glLineWidth(1);
        glVertex2f(i, 190);
        glVertex2f(i, 205);

        glVertex2f(i+5, 190);
        glVertex2f(i+5, 205);
    }
    glEnd();

}

/// ####################################################################### Building ###########################################################
void building()
{
    /// 1st Building
    if(isDay)
        glColor3f(0.92f, 0.92f, 0.92f);
    else
        glColor3f(0.55f, 0.55f, 0.55f);

    // body
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    // Top
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // window
    glBegin(GL_QUADS);
    for(int x = 18; x<80; x+=27 )
    {
        for(int y = 500; y>200; y-=60)
        {
            if(isDay)
                glColor3f(1,1,1);
            else
                glColor3f(0.15f, 0.07f, 0.03f);

            glVertex2f(x-2,  y+7);
            glVertex2f(x+22, y+7);
            glVertex2f(x+22, y-20);
            glVertex2f(x-2,  y-20);

            if(isDay)
                glColor3f(0.52f, 0.78f, 0.96f);
            else
                glColor3f(1.0f, 1.0f, 0.5f);

            glVertex2f(x,  y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,  y-20);
        }
    }

    // Window white border
    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    for(int y = 480; y > 200; y -= 60 )
    {
        glVertex2f(5,   y   );
        glVertex2f(105, y   );
        glVertex2f(105, y-15);
        glVertex2f(5,   y-15);
    }
    glEnd();

    /// $$$$$$$$$$$$$$$$$$ 2nd Building $$$$$$$$$$$$$$
    glBegin(GL_QUADS);

    //body Left half
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);

    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    //right half
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glVertex2f(135,  200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135,  400);

    // Top
    if(isDay)
        glColor3f(0.45f, 0.24f, 0.13f);
    else
        glColor3f(0.25f, 0.15f, 0.10f);

    glVertex2f(90,  400);
    glVertex2f(180, 400);
    glVertex2f(165, 425);
    glVertex2f(105, 425);
    glEnd();

    // Left triangles
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(115, 400);
    glVertex2f(135, 425);
    glEnd();

    // Right triangles
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(155, 400);
    glVertex2f(135, 425);
    glEnd();

    // All border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(88, 400);
    glVertex2f(115, 400);

    glVertex2f(115, 398);
    glVertex2f(135, 427);

    glVertex2f(135, 427);
    glVertex2f(155, 400);

    glVertex2f(153, 400);
    glVertex2f(182, 400);

    //body Lines
    glVertex2f(90, 340);
    glVertex2f(180,340);

    glVertex2f(90, 280);
    glVertex2f(180,280);

    glVertex2f(90, 220);
    glVertex2f(180,220);

    glEnd();

    //window
    //Outer quad
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 100; x<180; x+=45)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }
    }

    if(isDay)
        glColor3f(0.67f, 0.77f, 0.89f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    //inner quad
    for(int x = 102; x<180; x+=45)
    {
        for(int y = 382; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+21, y);
            glVertex2f(x+21, y-25);
            glVertex2f(x,    y-25);
        }
    }
    glEnd();

    // On window border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x =100; x<180; x+=45)
        for(int y = 372; y>200; y-=60)
        {
            {
                glVertex2f(x,y);
                glVertex2f(x+25,y);

                glVertex2f(x+12.5,y+10);
                glVertex2f(x+12.5,y);
            }
        }

    glEnd();

    /// 3rd Building
    // Left side
    if (isDay)
        glColor3f(0.84f, 0.30f, 0.37f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    // Right side
    if (isDay)
        glColor3f(0.90f, 0.45f, 0.50f);
    else
        glColor3f(0.60f, 0.25f, 0.30f);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);
    ;
    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 198; x < 280; x += 47)
    {
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    }
    glEnd();

    // blue
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 202; x < 280; x += 47)
    {
        for(int y=450; y>220; y-=70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }
    }
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 198; x < 280; x += 47)
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x+13, y);
            glVertex2f(x+13, y-32);

            glVertex2f(x, y-13);
            glVertex2f(x+26, y-13);

            glVertex2f(x,    y-22);
            glVertex2f(x+26, y-22);

        }

    glEnd();

    ///              ***> 4th Building <***
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    //Top White
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    // Body white quard
    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200);
    glVertex2f(320, 510);

    glVertex2f(340, 200);
    glVertex2f(340, 520);

    glVertex2f(360, 200);
    glVertex2f(360, 530);

    glVertex2f(380, 200);
    glVertex2f(380, 535);

    if (isDay)
        glColor3f(0.30f, 0.42f, 0.51f);
    else
        glColor3f(0.18f, 0.28f, 0.36f);


    for(int y = 455; y> 200; y-=30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);


    glEnd();

    /// 6th Building
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    //Body
    glVertex2f(550, 200);
    glVertex2f(640, 200);
    glVertex2f(640, 400);
    glVertex2f(550, 400);

    //top red
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glVertex2f(550, 415);
    glVertex2f(640, 415);
    glVertex2f(640, 400);
    glVertex2f(550, 400);
    glEnd();

    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    for(int x = 555; x<640; x+=13)
        circle(x,400,7);

    //body red lines
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2f(550, 290);
    glVertex2f(640, 290);

    glVertex2f(550, 350);
    glVertex2f(640, 350);

    glVertex2f(550, 230);
    glVertex2f(640, 230);
    glEnd();

    // Window white color
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glBegin(GL_QUADS);
    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {

            glVertex2f(x,  y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,  y-30);
        }
    }
    // window blue glass
    if(isDay)
        glColor3f(0.44f, 0.63f, 0.78f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {
            glVertex2f(x+3,  y-3);
            glVertex2f(x+22, y-3);
            glVertex2f(x+22, y-27);
            glVertex2f(x+3,  y-27);
        }
    }
    glEnd();

    /// Window white line
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 561; x<640; x+=40)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,  y);
            glVertex2f(x+22, y);

            glVertex2f(x+12, y);
            glVertex2f(x+12, y-20);
        }
    }
    glEnd();

    /// 5th Building
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.96f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
    //Main Body
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    //Upper box
    glVertex2f(440, 440);
    glVertex2f(530, 440);
    glVertex2f(530, 480);
    glVertex2f(440, 480);

    glVertex2f(450, 495);
    glVertex2f(520, 495);
    glVertex2f(520, 505);
    glVertex2f(450, 505);

    glVertex2f(460, 505);
    glVertex2f(510, 505);
    glVertex2f(510, 515);
    glVertex2f(460, 515);

    //Top Bar
    glVertex2f(470, 515);
    glVertex2f(500, 515);
    glVertex2f(500, 525);
    glVertex2f(470, 525);

    glEnd();

    //Body white bar
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(417, 420);
    glVertex2f(553, 420);
    glEnd();

    //top white
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(435, 495);
    glVertex2f(535, 495);
    glVertex2f(535, 480);
    glVertex2f(435, 480);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(437, 479);
    glVertex2f(533, 479);
    glEnd();

    //blue glass
    if (isDay)
        glColor3f(0.38f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    //body
    glBegin(GL_QUADS);
    for(int x = 435; x<550; x+=40)
    {
        glVertex2f(x, 200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x, 400);
    }

    //top
    for(int x = 450; x<520; x+=20)
    {
        glVertex2f(x,    470);
        glVertex2f(x+11, 470);
        glVertex2f(x+11, 440);
        glVertex2f(x,    440);
    }
    glEnd();

    glColor3f(0.38f, 0.54f, 0.66f);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(455, 499);
    glVertex2f(515, 499);

    glVertex2f(465, 509);
    glVertex2f(505, 509);

    glVertex2f(475, 519);
    glVertex2f(495, 519);

    glEnd();

    //Flag
    if(isDay)
        glColor3f(0.00f, 0.42f, 0.31f);
    else
        glColor3f(0.00f, 0.25f, 0.18f);

    glBegin(GL_QUADS);
    glVertex2f(485, 555);
    glVertex2f(510, 555);
    glVertex2f(510, 540);
    glVertex2f(485, 540);
    glEnd();

    if(isDay)
        glColor3f(0.96f, 0.16f, 0.25f);
    else
        glColor3f(0.6f, 0.1f, 0.15f);

    circle(497.5, 547.5, 4);

    // Bamboo
    if(isDay)
        glColor3f(0.83f, 0.65f, 0.42f);
    else
        glColor3f(0.55f, 0.45f, 0.30f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(485, 525);
    glVertex2f(485, 555);
    glEnd();



    /// 7th Building
    if (isDay)
        glColor3f(0.84f, 0.74f, 0.62f);
    else
        glColor3f(0.50f, 0.40f, 0.30f);

    //body
    glBegin(GL_QUADS);
    glVertex2f(640, 200);
    glVertex2f(720, 200);
    glVertex2f(720, 380);
    glVertex2f(640, 380);

    //window
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int y = 373; y>200; y-=30)
    {
        glVertex2f(647, y);
        glVertex2f(713, y);
        glVertex2f(713, y-21);
        glVertex2f(647, y-21);
    }

    if (isDay)
        glColor3f(0.52f, 0.78f, 0.96f);
    else
        glColor3f(0.94f, 0.69f, 0.35f);

    for(int y = 370; y>200; y-=30)
    {
        glVertex2f(650, y);
        glVertex2f(710, y);
        glVertex2f(710, y-15);
        glVertex2f(650, y-15);
    }
    glEnd();

    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    // window lines
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 670; x<710; x+=20)
        for(int y = 370; y>200; y-=30)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-15);
        }
    glEnd();

    /// 8th Building
    if (isDay)
        glColor3f(0.39f, 0.30f, 0.32f);
    else
        glColor3f(0.19f, 0.15f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    // top bar
    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //4 corner window
    glBegin(GL_QUADS);
    for(int x=759; x<950; x+=150)
        for(int y = 400; y>250; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x, y-40);
        }
    // middle 2 window
    for(int x=743; x<950; x+=182)
    {
        glVertex2f(x,    340);
        glVertex2f(x+32, 340);
        glVertex2f(x+32, 300);
        glVertex2f(x,    300);
    }
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //window white circle
    //4 corner
    for(int x = 759; x<940; x+=150)
        for(int y = 360; y>200; y-=120)
            for(int xx = x; xx<x+34; xx+=8)
                circle(xx,y,4);
    for(int x = 743; x<950; x+=182)
        for(int xx = x; xx<x+34; xx+=8)
            circle(xx,300,4);

    if(isDay)
        glColor3f(0.44f, 0.65f, 0.80f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    // blue glass
    for(int x=763; x<950; x+=150)
        for(int y = 397; y>250; y-=120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }

    for(int x=747; x<950; x+=182)
    {
        glVertex2f(x,    337);
        glVertex2f(x+24, 337);
        glVertex2f(x+24, 303);
        glVertex2f(x,    303);
    }

    glEnd();

    // Lines of windows
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x<940; x+=150)
        for(int y = 400; y>200; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }

    // Middle window lines
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 759; x<950; x+=182)
    {
        glVertex2f(x, 340);
        glVertex2f(x, 300);
    }

    glEnd();

    /// ***> 9th Building <***
    if (isDay)
        glColor3f(0.51f, 0.73f, 0.75f);
    else
        glColor3f(0.29f, 0.42f, 0.43f);

    glBegin(GL_QUADS);
    glVertex2f(800, 200);
    glVertex2f(850, 200);
    glVertex2f(850, 480);
    glVertex2f(800, 480);

    if (isDay)
        glColor3f(0.47f, 0.67f, 0.69f);
    else
        glColor3f(0.23f, 0.34f, 0.35f);

    glVertex2f(850, 200);
    glVertex2f(900, 200);
    glVertex2f(900, 480);
    glVertex2f(850, 480);

    // Top bar
    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    glVertex2f(795, 490);
    glVertex2f(905, 490);
    glVertex2f(905, 475);
    glVertex2f(795, 475);

    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    for (int y = 410; y > 200; y -= 70)
    {
        glVertex2f(800, y);
        glVertex2f(900, y);
        glVertex2f(900, y - 10);
        glVertex2f(800, y - 10);
    }

    glEnd();

// Window
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for (int x = 810; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glVertex2f(x, y);
            glVertex2f(x + 26, y);
            glVertex2f(x + 26, y - 30);
            glVertex2f(x, y - 30);
        }
    }
    glEnd();

    halfCircle(823, 450, 13);
    halfCircle(877, 450, 13);
    halfCircle(823, 380, 13);
    halfCircle(877, 380, 13);
    halfCircle(823, 310, 13);
    halfCircle(877, 310, 13);
    halfCircle(823, 240, 13);
    halfCircle(877, 240, 13);

// Red
    glColor3f(1, 0, 0);
    for (int x = 814; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + 18, y);
            glVertex2f(x + 18, y - 27);
            glVertex2f(x, y - 27);
            glEnd();
        }
    }

    halfCircle(823, 450, 9);
    halfCircle(877, 450, 9);
    halfCircle(823, 380, 9);
    halfCircle(877, 380, 9);
    halfCircle(823, 310, 9);
    halfCircle(877, 310, 9);
    halfCircle(823, 240, 9);
    halfCircle(877, 240, 9);

    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 823; x<900; x+=54)
        for(int y = 460; y>200; y-=70)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);

            glVertex2f(x-13, y-12);
            glVertex2f(x+13, y-12);

            glVertex2f(x-13, y-25);
            glVertex2f(x+13, y-25);

        }
    glEnd();
}

float moveCar = 0.0f;
float carSpeed =1.0f;
float savedCarSpeed = 0.0f;
float carTireAngle = 0.0f;
bool carPaused = false;

void car()
{
    glPushMatrix();
    glTranslatef(moveCar, 0, 0);

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100,125);
    glVertex2i(100,140);
    glVertex2i(105,150);
    glVertex2i(193,150);
    glVertex2i(205,145);
    glVertex2i(205,125);
    glEnd();

    /// ***> Light <***
    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,.7);
    /// Front light
    glVertex2i(200,128);
    glVertex2i(205,128);
    glVertex2i(205,135);
    glVertex2i(200,135);

    /// Rear light
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glVertex2i(100,128);
    glVertex2i(105,128);
    glVertex2i(105,135);
    glVertex2i(100,135);

    /// Yellow light for night
    if(!isDay)
    {
        glColor3f(1,1,.7);
        glVertex2i(205,128);
        glVertex2i(260,115);
        glVertex2i(260,140);
        glVertex2i(205,135);

    }

    glEnd();

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(110,145);
    glVertex2i(121,168);
    glVertex2i(170,168);
    glVertex2i(190,145);

    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,150);
    glVertex2i(123,162);
    glVertex2i(145,162);
    glVertex2i(145,150);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,152);
    glVertex2i(125,160);
    glVertex2i(143,160);
    glVertex2i(143,152);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152,151);
    glVertex2i(152,162);
    glVertex2i(168,162);
    glVertex2i(177,151);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(154,149);
    glVertex2i(154,160);
    glVertex2i(166,160);
    glVertex2i(175,149);
    glEnd();




    //first car chakka/////////////////////////
    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(125,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(125,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(125,125,3);

    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(175,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(175,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(175,125,3);

    glPopMatrix();
}
void updateCar(int value)
{
    if(!carPaused)
    {

        moveCar += carSpeed+1;
        if (moveCar > 900)
        {
            moveCar = -350;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(10, updateCar, 0);
}

void specialKeys(int key, int x, int y)
{
    //Day Mode Metro speed control
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            trainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            trainSpeed -= 0.2f;
            if (trainSpeed < 0) trainSpeed = 0;
            break;
        }
    }
    //Night Mode Metro speed control
    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            trainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            trainSpeed -= 0.2f;
            if (trainSpeed < 0) trainSpeed = 0;
            break;
        }
    }
//Sun Speed
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            sunSpeed += 0.2f;
            break;
        case GLUT_KEY_LEFT:
            sunSpeed -= 0.2f;
            if (sunSpeed < 0) sunSpeed = 0;
            break;
        }
    }
//Moon Speed
    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            moonSpeed += 0.2f;
            break;
        case GLUT_KEY_LEFT:
            moonSpeed -= 0.2f;
            if (moonSpeed < 0) moonSpeed = 0;
            break;
        }
    }
    //Cargoo Truck Speed
     if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_PAGE_UP:
            V_cargoSpeed += 0.2f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            V_cargoSpeed -= 0.2f;
            if (V_cargoSpeed < 0) V_cargoSpeed = 0;
            break;
        }
    }
     if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_PAGE_UP:
            V_cargoSpeed += 0.2f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            V_cargoSpeed -= 0.2f;
            if (V_cargoSpeed < 0) V_cargoSpeed = 0;
            break;
        }
    }

}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }

    if (key == ' ')
    {
        /// Cargo Stop and Start
       V_cargoPaused = !V_cargoPaused;

       if(V_cargoPaused)
       {
           V_savedCargoSpeed = V_cargoSpeed;
           V_cargoSpeed = 0;
       }
       else
       {
           V_cargoSpeed = V_savedCargoSpeed;
       }

        /// Car Stop and Start
        carPaused = !carPaused;

        if(carPaused)
        {
            savedCarSpeed = carSpeed;
            carSpeed = 0;
        }
        else
        {
            carSpeed = savedCarSpeed;
        }

        /// Bus Stop and Start
        V_busPaused = !V_busPaused;

        if(V_busPaused)
        {
            V_savedBusSpeed = V_busSpeed;
            V_busSpeed = 0;
        }
        else
        {
            V_busSpeed = V_savedBusSpeed;
        }

        /// Train Stop and Start
        trainPaused = !trainPaused;

        if (trainPaused)
        {
            savedTrainSpeed = trainSpeed;
            trainSpeed = 0;
        }
        else
        {
            trainSpeed = savedTrainSpeed;
        }

        /// Cloud Stop and Start
        // Cloud 1
        V_cloudPaused1 = !V_cloudPaused1;

        if (V_cloudPaused1)
        {
            V_savedCloudSpeed1 = V_cloudSpeed1;
            V_cloudSpeed1 = 0;
        }
        else
        {
            V_cloudSpeed1 = V_savedCloudSpeed1;
        }

        // Cloud 2
        V_cloudPaused2 = !V_cloudPaused2;

        if (V_cloudPaused2)
        {
            V_savedCloudSpeed2 = V_cloudSpeed2;
            V_cloudSpeed2 = 0;
        }
        else
        {
            V_cloudSpeed2 = V_savedCloudSpeed2;
        }

        // Cloud 3
        V_cloudPaused3 = !V_cloudPaused3;

        if (V_cloudPaused3)
        {
            V_savedCloudSpeed3 = V_cloudSpeed3;
            V_cloudSpeed3 = 0;
        }
        else
        {
            V_cloudSpeed3 = V_savedCloudSpeed3;
        }

        // Cloud 4
        V_cloudPaused4 = !V_cloudPaused4;

        if (V_cloudPaused4)
        {
            V_savedCloudSpeed4 = V_cloudSpeed4;
            V_cloudSpeed4 = 0;
        }
        else
        {
            V_cloudSpeed4 = V_savedCloudSpeed4;
        }

        /// Sun Stop and Start
        sunPaused = !sunPaused;

        if (sunPaused)
        {
            savedSunSpeed = sunSpeed;
            sunSpeed = 0;
        }
        else
        {
            sunSpeed = savedSunSpeed;
        }

        /// Moon Stop and Start
        moonPaused = !moonPaused;

        if (moonPaused)
        {
            savedMoonSpeed = moonSpeed;
            moonSpeed = 0;
        }
        else
        {
            moonSpeed = savedMoonSpeed;
        }
    }


    if(key == 27)
        exit(0);
}

void mouse(int button, int state, int x, int y)
{
    //Train
    if(isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            trainPaused = !trainPaused;
            if (trainPaused)
            {
                savedTrainSpeed = trainSpeed;
                trainSpeed = 0;
            }
            else
            {
                trainSpeed = savedTrainSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            trainPaused = !trainPaused;
            if (trainPaused)
            {
                savedTrainSpeed = trainSpeed;
                trainSpeed = 0;
            }
            else
            {
                trainSpeed = savedTrainSpeed;
            }
        }
    }
    //Sun
    if(isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            sunPaused = !sunPaused;
            if (sunPaused)
            {
                savedSunSpeed = sunSpeed;
                sunSpeed = 0;
            }
            else
            {
                sunSpeed = savedSunSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            moonPaused = !moonPaused;
            if (moonPaused)
            {
                savedMoonSpeed = moonSpeed;
                moonSpeed = 0;
            }
            else
            {
                moonSpeed = savedMoonSpeed;
            }
        }
    }
    //Cargoo Truck
    if(!isDay)
    {
        if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            V_cargoPaused = !V_cargoPaused;

            if (V_cargoPaused)
            {
                V_savedCargoSpeed = V_cargoSpeed;
                V_cargoSpeed = 0;
            }
            else
            {
                V_cargoSpeed = V_savedCargoSpeed;
            }
        }
    }
    if(isDay)
    {
        if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            V_cargoPaused = !V_cargoPaused;

            if (V_cargoPaused)
            {
                V_savedCargoSpeed = V_cargoSpeed;
                V_cargoSpeed = 0;
            }
            else
            {
                V_cargoSpeed = V_savedCargoSpeed;
            }
        }
    }
}

void Meraz()
{
    glDisable(GL_LIGHTING);
    sky();

    // ==========================================
    // SUN/MOON LIGHTING SETUP (GL_LIGHT0)
    // ==========================================

    if(isDay)
    {
        // DAY MODE: SUN
        float sunX_Meraz = 50.0f + moveSun;
        float sunY_Meraz = 650.0f;
        GLfloat lightPos[] = { sunX_Meraz, sunY_Meraz, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);
        GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }
    else
    {
        // NIGHT MODE: MOON
        float moonX_Meraz = 850.0f + moveMoon;
        float moonY_Meraz = 650.0f;
        GLfloat lightPos[] = { moonX_Meraz, moonY_Meraz, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat moonLightColor[] = { 0.4f, 0.4f, 0.5f, 1.0f }; // Dimmer light for night
        glLightfv(GL_LIGHT0, GL_DIFFUSE, moonLightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, moonLightColor);
        GLfloat ambientColor[] = { 0.25f, 0.25f, 0.3f, 1.0f }; // Increased ambient for brighter night
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }

    // Draw sun/moon (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    moon();
    sun();
    glEnable(GL_LIGHTING);
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();
    building();
    train();
    flyOver();
    garden();
    road();
    roadSideWall();
    bus();
    car();
    cargoTruck();
}

/// =======================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================


/// **************************************************************************************************************************************************
/// ******************************************************** >>> Avishek<<< ****************************************************************************
/// **************************************************************************************************************************************************

bool isDayM=true;

void circleM(int centerX, int centerY, int radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

//half circle

void halfCircleM(int centerX, int centerY, int radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

///cloud

int moveCloud1M = 0;
void cloud1M()
{
    glPushMatrix();
    glTranslatef(moveCloud1M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);

//cloud-1
    circleM(50,650,15);
    circleM(70,660,15);
    circleM(90,650,15);
    circleM(110,645,15);
    circleM(70,640,15);
    circleM(90,640,15);

    glPopMatrix();

}

void updateCloud1M(int value)
{
    moveCloud1M += 1;
    if (moveCloud1M > 1000)
    {
        moveCloud1M = -400;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud1M, 0);
}


//cloud-2

int moveCloud2M = 0;
void cloud2M()
{
    glPushMatrix();
    glTranslatef(moveCloud2M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(500,650,20);
    circleM(510,670,20);
    circleM(530,640,20);
    circleM(560,645,20);
    circleM(545,670,20);

    glPopMatrix();
}

void updateCloud2M(int value)
{
    moveCloud2M -= 1;
    if (moveCloud2M < -1000)
    {
        moveCloud2M = 500;
    }

    glutPostRedisplay();
    glutTimerFunc(18, updateCloud2M, 0);
}
//cloud-3

int moveCloud3M = 0;
void cloud3M()
{
    glPushMatrix();
    glTranslatef(moveCloud3M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(700,650,20);
    circleM(710,670,20);
    circleM(730,650,15);
    circleM(755,645,15);
    circleM(745,670,20);
    circleM(770,670,15);

    glPopMatrix();

}

void updateCloud3M(int value)
{
    moveCloud3M += 1;
    if (moveCloud3M > 1000)
    {
        moveCloud3M = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud3M, 0);
}


///car1

float moveCar1M = 0;
float car1MSpeed = 1.0f;
float savedcar1MSpeed = 0.0f;
float car1MTireAngle = 0.0f;
bool car1MPaused = false;

void car1M()
{
    glPushMatrix();
    glTranslatef(moveCar1M, 0, 0);


    // car body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.1f, 0.1f); // Red
    glVertex2f(150, 440);
    glVertex2f(225, 440);
    glVertex2f(215, 450);
    glVertex2f(160, 450);
    glEnd();


    // Draw the  roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f); // Darker red
    glVertex2f(165, 450);
    glVertex2f(210, 450);
    glVertex2f(205, 460);
    glVertex2f(170, 460);
    glEnd();

    // Draw the window
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(170, 450);
    glVertex2f(205, 450);
    glVertex2f(200, 457);
    glVertex2f(175, 457);
    glEnd();

    // front wheel
    glPushMatrix();
    glTranslatef(165, 440, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-165, -440, 0);


    glColor3f(0.0f, 0.0f, 0.0f); //black
    circleM(165, 440, 6);

    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(165, 440, 4);


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(160, 440);
    glVertex2f(170, 440);
    glEnd();

    glPopMatrix();

    //  rear wheel

    glPushMatrix();
    glTranslatef(210, 440, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-210, -440, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(210, 440, 6);


    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(210, 440, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(205, 440);
    glVertex2f(215, 440);
    glEnd();

    glPopMatrix();


    glPopMatrix();
}

void updateCar1M(int value)
{
    moveCar1M += car1MSpeed;
    if (moveCar1M > 1000)
    {
        moveCar1M = -300;

    }

    car1MTireAngle +=1;


    glutPostRedisplay();
    glutTimerFunc(16, updateCar1M, 0);
}

///car5

float moveMcar5 = 0.0f;
float Mcar5Speed =1.0f;
float savedMcar5Speed = 0.0f;
bool Mcar5Paused = false;

void Mcar5()
{
    glPushMatrix();
    glTranslatef(moveMcar5, 0, 0);

    glBegin(GL_POLYGON); //1st car//////////////////
    //glColor3f(1.f, 1.f, 1.f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2i(100, 400);
    glVertex2i(100, 415);
    glVertex2i(105, 425);
    glVertex2i(193, 425);
    glVertex2i(205, 420);
    glVertex2i(205, 400);

    glBegin(GL_POLYGON); //1st car

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2i(110, 420);
    glVertex2i(121, 443);
    glVertex2i(170, 443);
    glVertex2i(190, 420);

    glEnd();

//headlight

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2i(205, 415);
    glVertex2i(205, 410);
    glVertex2i(200, 410);
    glVertex2i(200, 415);
    glEnd();

//back light

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2i(100, 415);
    glVertex2i(100, 410);
    glVertex2i(105, 410);
    glVertex2i(105, 415);
    glEnd();



    glBegin(GL_QUADS); // Glass
    glColor3f(0.27f, 0.28f, 0.29f);

    glVertex2i(123, 425);
    glVertex2i(123, 437);
    glVertex2i(145, 437);
    glVertex2i(145, 425);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.28f, 0.29f);

    glVertex2i(125, 427);
    glVertex2i(125, 435);
    glVertex2i(143, 435);
    glVertex2i(143, 427);
    glEnd();

    glBegin(GL_QUADS); // Glass
    glColor3f(0.27f, 0.28f, 0.29f);

    glVertex2i(152, 426);
    glVertex2i(152, 437);
    glVertex2i(168, 437);
    glVertex2i(177, 426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.28f, 0.29f);

    glVertex2i(154, 424);
    glVertex2i(154, 435);
    glVertex2i(166, 435);
    glVertex2i(175, 424);
    glEnd();

// Wheels
    glColor3f(0.34f, 0.34f, 0.34f);

    halfCircleM(125, 400, 10);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(125, 400, 9);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(125, 400, 3);

    glColor3f(0.34f, 0.34f, 0.34f);
    circleM(175, 400, 10);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(175, 400, 9);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(175, 400, 3);

    glPopMatrix();
}

void updateMcar5(int value)
{
    moveMcar5 += Mcar5Speed;
    if (moveMcar5 > 1000)
    {
        moveMcar5 = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(15, updateMcar5, 0);
}

///car5

float moveMcar5_night = 0.0f;
float Mcar5_nightSpeed =1.0f;
float savedMcar5_nightSpeed = 0.0f;
bool Mcar5_nightPaused = false;

void Mcar5_night()
{
    glPushMatrix();
    glTranslatef(moveMcar5_night, 0, 0);

    glBegin(GL_POLYGON); //1st car//////////////////


    glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100, 400);
    glVertex2i(100, 415);
    glVertex2i(105, 425);
    glVertex2i(193, 425);
    glVertex2i(205, 420);
    glVertex2i(205, 400);

    glBegin(GL_POLYGON); //1st car

    glColor3f(0.5f, 0.0f, 0.0f);


    glVertex2i(110, 420);
    glVertex2i(121, 443);
    glVertex2i(170, 443);
    glVertex2i(190, 420);

    glEnd();

//light
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex2i(205, 415);
    glVertex2i(260, 430);
    glVertex2i(260, 390);
    glVertex2i(205, 412);
    glEnd();

//back light

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2i(100, 415);
    glVertex2i(100, 410);
    glVertex2i(105, 410);
    glVertex2i(105, 415);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex2i(205, 415);
    glVertex2i(205, 410);
    glVertex2i(200, 410);
    glVertex2i(200, 415);
    glEnd();


    glBegin(GL_QUADS); // Glass
    glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(123, 425);
    glVertex2i(123, 437);
    glVertex2i(145, 437);
    glVertex2i(145, 425);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);


    glVertex2i(125, 427);
    glVertex2i(125, 435);
    glVertex2i(143, 435);
    glVertex2i(143, 427);
    glEnd();

    glBegin(GL_QUADS); // Glass
    glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152, 426);
    glVertex2i(152, 437);
    glVertex2i(168, 437);
    glVertex2i(177, 426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);


    glVertex2i(154, 424);
    glVertex2i(154, 435);
    glVertex2i(166, 435);
    glVertex2i(175, 424);
    glEnd();

// Wheels
    glColor3f(0.34f, 0.34f, 0.34f);

    halfCircleM(125, 400, 10);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(125, 400, 9);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(125, 400, 3);

    glColor3f(0.34f, 0.34f, 0.34f);
    circleM(175, 400, 10);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(175, 400, 9);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(175, 400, 3);

    glPopMatrix();
}

void updateMcar5_night(int value)
{
    moveMcar5_night += Mcar5_nightSpeed;
    if (moveMcar5_night > 1000)
    {
        moveMcar5_night = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(15, updateMcar5_night, 0);
}

///truck

float moveTruckM = 0.0f;
float truckMSpeed = 1.0f;
float savedTruckMSpeed = 0.0f;
float truckMTireAngle = 0.0f;
bool truckMPaused = false;

void truckM()
{
    glPushMatrix();
    glTranslatef(moveTruckM, 0, 0);

    // Main body - Converted to SUV shape
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.5f, 0.8f);  // Blue SUV body

    glVertex2f(450,530);
    glVertex2f(360,530);
    glVertex2f(360,500);
    glVertex2f(450,500);
    glEnd();

    // Windows and glass areas
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.8f, 0.9f);  // Light blue window tint

    // Front window
    glVertex2f(365,525);
    glVertex2f(385,525);
    glVertex2f(385,515);
    glVertex2f(365,515);

    // Side windows
    glVertex2f(395,525);
    glVertex2f(445,525);
    glVertex2f(445,515);
    glVertex2f(395,515);
    glEnd();

    // Roof rack
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray roof rack
    glVertex2f(365,535);
    glVertex2f(445,535);
    glVertex2f(445,530);
    glVertex2f(365,530);
    glEnd();

    // Door handles
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(390,510);
    glVertex2f(400,510);
    glVertex2f(400,508);
    glVertex2f(390,508);
    glEnd();

    // Front grille and bumper
    glBegin(GL_QUADS);
    glColor3f(0.15f, 0.15f, 0.15f); // Black grille
    glVertex2f(340,505);
    glVertex2f(360,505);
    glVertex2f(360,495);
    glVertex2f(340,495);
    glEnd();

    // Headlights
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.7f); // Headlight color
    glVertex2f(340,510);
    glVertex2f(345,510);
    glVertex2f(345,505);
    glVertex2f(340,505);
    glEnd();

    // SUV running boards/side step
    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(360,495);
    glVertex2f(450,495);
    glVertex2f(450,492);
    glVertex2f(360,492);
    glEnd();

    // Rear bumper
    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(450,500);
    glVertex2f(455,500);
    glVertex2f(455,492);
    glVertex2f(450,492);
    glEnd();

    // Front wheel (SUV style - larger)
    glPushMatrix();
    glTranslatef(353, 493, 0);
    glRotatef(truckMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-353, -493, 0);

    glColor3f(0.1f, 0.1f, 0.1f); // Tire
    circleM(353, 493, 10);  // Larger radius for SUV
    glColor3f(0.8f, 0.8f, 0.8f); // Alloy wheel
    circleM(353, 493, 7);
    glColor3f(0.3f, 0.3f, 0.3f); // Wheel center
    circleM(353, 493, 3);

    // Wheel spokes
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    for(int i = 0; i < 360; i += 30)
    {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(353, 493);
        glVertex2f(353 + cos(angle)*6, 493 + sin(angle)*6);
    }
    glEnd();

    glPopMatrix();

    // Rear wheel (SUV style - larger)
    glPushMatrix();
    glTranslatef(433, 493, 0);
    glRotatef(truckMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-433, -493, 0);

    glColor3f(0.1f, 0.1f, 0.1f); // Tire
    circleM(433, 493, 10);  // Larger radius for SUV
    glColor3f(0.8f, 0.8f, 0.8f); // Alloy wheel
    circleM(433, 493, 7);
    glColor3f(0.3f, 0.3f, 0.3f); // Wheel center
    circleM(433, 493, 3);

    // Wheel spokes
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    for(int i = 0; i < 360; i += 30)
    {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(433, 493);
        glVertex2f(433 + cos(angle)*6, 493 + sin(angle)*6);
    }
    glEnd();

    glPopMatrix();

    // SUV roof antenna
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(405, 535);
    glVertex2f(405, 540);
    glEnd();

    glPopMatrix();
}

void updateTruckM(int value)
{
    moveTruckM -= 1;
    if (moveTruckM < -500)
    {
        moveTruckM = 800;
    }

    truckMTireAngle += 1;

    glutPostRedisplay();
    glutTimerFunc(8, updateTruckM, 0);
}

///Ambulance

float moveAmbulanceM = 0.0f;
float ambulanceMSpeed = 1.0f;
float savedAmbulanceMSpeed = 0.0f;
float ambulanceMTireAngle = 0.0f;
bool ambulanceMPaused = false;
void ambulanceM()
{
    glPushMatrix();
    glTranslatef(moveAmbulanceM, 0, 0);

    // Draw the ambulance body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); // White body

    glVertex2f(200, 440);
    glVertex2f(280, 440);
    glVertex2f(290, 420);
    glVertex2f(300, 410);
    glVertex2f(300, 390);
    glVertex2f(190, 390);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    circleM(271, 447, 4);

    // Upper light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(267.5, 448);
    glVertex2f(275, 448);
    glVertex2f(275, 440);
    glVertex2f(267.5, 440);
    glEnd();

    // Black parts (black body)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(185, 400);
    glVertex2f(200, 400);
    glVertex2f(200, 390);
    glVertex2f(185, 390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(293, 400);
    glVertex2f(305, 400);
    glVertex2f(305, 390);
    glVertex2f(293, 390);
    glEnd();

    // Red line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(300, 410);
    glVertex2f(190, 410);
    glEnd();

    // Red light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(190, 420);
    glVertex2f(195, 420);
    glVertex2f(195, 410);
    glVertex2f(190, 410);
    glEnd();

    // Yellow light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(285, 408);
    glVertex2f(300, 408);
    glVertex2f(300, 405);
    glVertex2f(285, 405);
    glEnd();

    // Windows
    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(260, 435);
    glVertex2f(275, 435);
    glVertex2f(283, 420);
    glVertex2f(260, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(255, 435);
    glVertex2f(230, 435);
    glVertex2f(230, 420);
    glVertex2f(255, 420);
    glEnd();

    // Red cross
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(205, 425);
    glVertex2f(225, 425);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(215, 435);
    glVertex2f(215, 415);
    glEnd();

    // Wheels

    glPushMatrix();
    glTranslatef(220, 390, 0);
    glRotatef(ambulanceMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-220, -390, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(220, 390, 10);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(220, 390, 6);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(215, 390);
    glVertex2f(230, 390);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(270, 390, 0);
    glRotatef(ambulanceMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-270, -390, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(270, 390, 10);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(270, 390, 6);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(265, 390);
    glVertex2f(275, 390);
    glEnd();
    glPopMatrix();


    glPopMatrix();

    glPopMatrix();
}

void updateAmbulanceM(int value)
{
    moveAmbulanceM += ambulanceMSpeed;
    if (moveAmbulanceM > 1000)
    {
        moveAmbulanceM = -350;
    }

    ambulanceMTireAngle -= 2;
    glutPostRedisplay();
    glutTimerFunc(10, updateAmbulanceM, 0);
}

///bus

float moveBusM = 0.0f;
float busMSpeed = 1.0f;
float savedBusMSpeed = 0.0f;
float busMTireAngle = 0.0f;
bool busMPaused = false;



void busM()
{
    glPushMatrix();
    glTranslatef(moveBusM, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.00f, 0.00f, 0.00f);  //bus body
    glVertex2f(785,520);
    glVertex2f(920,520);
    glVertex2f(920,480);
    glVertex2f(780,480);
    glVertex2f(780,500);
    glVertex2f(785,520);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 0.00f);
    glVertex2f(780,485);
    glVertex2f(787,485);
    glVertex2f(787,480);
    glVertex2f(780,480);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 1.00f);  //bus light
    glVertex2f(780,497);
    glVertex2f(785,497);
    glVertex2f(785,492);
    glVertex2f(780,489);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 0.00f);
    glVertex2f(913,485);
    glVertex2f(920,485);
    glVertex2f(920,480);
    glVertex2f(913,480);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);  //door
    glVertex2f(800,515);
    glVertex2f(815,515);
    glVertex2f(815,490);
    glVertex2f(800,490);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); //front window
    glVertex2f(783,515);
    glVertex2f(795,515);
    glVertex2f(795,500);
    glVertex2f(780,500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);  //rear window
    glVertex2f(820,515);
    glVertex2f(915,515);
    glVertex2f(915,500);
    glVertex2f(820,500);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(820,515);
    glVertex2f(915,515);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(820,500);
    glVertex2f(915,500);
    glEnd();

    for(int i=820; i<=915; i+=16)
    {
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,515);
        glVertex2f(i,500);
        glEnd();

    }

    //wheels

    glPushMatrix();
    glTranslatef(800,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-800, -480, 0);

    glColor3f(0.00f, 0.00f, 0.00f);
    circleM(800,480,7);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(800,480,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-900, -480, 0);

    glColor3f(0.00f, 0.00f, 0.00f);
    circleM(900,480,7);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(900,480,5);
    glPopMatrix();

    glPopMatrix();


}

void updateBusM(int value)
{
    moveBusM -= 1;
    if (moveBusM <-1000)
    {
        moveBusM= 350;
    }

    busMTireAngle +=1;
    glutPostRedisplay();
    glutTimerFunc(10, updateBusM, 0);
}



///boats

//boat 1
int moveBoat1M = 0;
void boat1M()
{
    glPushMatrix();
    glTranslatef(moveBoat1M, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.00f, 0.00f); // hash
    glVertex2f(900,50);
    glVertex2f(970,50);
    glVertex2f(960,40);
    glVertex2f(910,40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.00f, 0.10f, 0.60f); // hash
    glVertex2f(910,50);
    glVertex2f(920,60);
    glVertex2f(930,50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 0.10f, 0.60f); // hash
    glVertex2f(918,60);
    glVertex2f(950,60);
    glVertex2f(958,50);
    glVertex2f(930,50);
    glEnd();

    glPopMatrix();

}

void updateBoat1M(int value)
{
    moveBoat1M -= 1;
    if (moveBoat1M < -1000)
    {
        moveBoat1M = 100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat1M, 0);
}

//boat 2

int moveBoat2M = 0;
void boat2M()
{
    glPushMatrix();
    glTranslatef(moveBoat2M, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(200,90);
    glVertex2f(320,90);
    glVertex2f(310,70);
    glVertex2f(210,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(270,90);
    glVertex2f(280,105);
    glVertex2f(328,105);
    glVertex2f(320,90);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.82f, 0.74f); // upper body
    glVertex2f(280,105);
    glVertex2f(270,90);
    glVertex2f(210,90);
    glVertex2f(220,120);
    glVertex2f(300,120);
    glVertex2f(310,105);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(230,100);
    glVertex2f(230,110);
    glVertex2f(240,110);
    glVertex2f(240,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(240,110);
    glVertex2f(240,100);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(250,100);
    glVertex2f(250,110);
    glVertex2f(260,110);
    glVertex2f(260,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(260,110);
    glVertex2f(260,100);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();


    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,110);
    glVertex2f(270,110);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(270,100);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(230,110);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(240,100);
    glVertex2f(240,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(260,100);
    glVertex2f(260,110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.66f, 0.65f);
    glVertex2f(225,120);
    glVertex2f(230,140);
    glVertex2f(290,140);
    glVertex2f(295,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(235,140);
    glVertex2f(235,160);
    glVertex2f(250,160);
    glVertex2f(260,140);

    glEnd();

    glPopMatrix();
}

void updateBoat2M(int value)
{
    moveBoat2M += 1;
    if (moveBoat2M > 1000)
    {
        moveBoat2M = -450;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updateBoat2M, 0);
}
///boat3
int moveBoat3M = 0;
void boat3M()
{
    glPushMatrix();
    glTranslatef(moveBoat3M, 0, 0);
    // Boat Body (Brown)
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(450, 300);
    glVertex2f(550, 300);
    glVertex2f(540, 290);
    glVertex2f(460, 290);
    glEnd();

    // Mast (Gray)
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(500, 300);
    glVertex2f(500, 350);
    glEnd();

    // Sail (White)
    glColor3f(0.03f, 0.89f, 0.69f);
    glBegin(GL_TRIANGLES);
    glVertex2f(500, 350);
    glVertex2f(520, 300);
    glVertex2f(500, 300);
    glEnd();

    glPopMatrix();
}
void updateBoat3M(int value)
{
    moveBoat3M += 1;
    if (moveBoat3M > 1000)
    {
        moveBoat3M = -550;
    }

    glutPostRedisplay();
    glutTimerFunc(19, updateBoat3M, 0);

}


///Train///
int moveTrainM = 0;
void trainM()
{

    glPushMatrix();
    glTranslatef(moveTrainM, 0, 0);

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(100,239);
    glVertex2f(620,239);

    glEnd();

    for(int i=130; i<=550; i+=94)
    {
        //  rear wheel
        glColor3f(0.0f, 0.0f, 0.0f);
        circleM(i, 232, 8);
        circleM(i+30, 232, 8);

        glColor3f(0.3f, 0.3f, 0.3f);
        circleM(i, 232, 6);
        circleM(i+30, 232, 6);

    }

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(585, 232, 8);
    circleM(610, 232, 8);

    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(585, 232, 6);
    circleM(610, 232, 6);



    for (int i = 100; i <= 500; i += 94)
    {

        // Train body
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.4f, 0.0f);
        glVertex2f(i, 270);
        glVertex2f(i + 90, 270);
        glVertex2f(i + 90, 231);
        glVertex2f(i, 231);
        glEnd();

        glLineWidth(5.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // White line
        glVertex2f(i, 247);
        glVertex2f(i+90, 247);
        glEnd();

        glLineWidth(2.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); // White line
        glVertex2f(i, 270);
        glVertex2f(i+90, 270);
        glEnd();

        // Door 1 (left door)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i + 5, 265);
        glVertex2f(i + 15, 265);
        glVertex2f(i + 15, 235);
        glVertex2f(i + 5, 235);
        glEnd();

        // Door 2 (right door)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i + 75, 265);
        glVertex2f(i + 85, 265);
        glVertex2f(i + 85, 235);
        glVertex2f(i + 75, 235);
        glEnd();

        // Windows
        for (int j = 23; j <= 59; j += 12)
        {
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(i + j, 260);
            glVertex2f(i + j + 8, 260);   //(8 units wide)
            glVertex2f(i + j + 8, 252);
            glVertex2f(i + j, 252);
            glEnd();
        }
    }

//front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex2f(570,270);
    glVertex2f(620,270);
    glVertex2f(630,265);
    glVertex2f(630,231);
    glVertex2f(570,231);

    glEnd();
//red line
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.00f, 0.0f);
    glVertex2f(570,270);
    glVertex2f(620,270);
    glVertex2f(630,265);
    glVertex2f(570,265);

    glEnd();
//front window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(630,265);
    glVertex2f(595,265);
    glVertex2f(610,250);
    glVertex2f(630,250);
    glEnd();

//front door
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(585,265);
    glVertex2f(585,238);
    glVertex2f(600,238);
    glVertex2f(600,250);
    glEnd();

    glPopMatrix();

}

void updateTrainM(int value)
{
    moveTrainM += 1;
    if (moveTrainM > 1000)
    {
        moveTrainM = -700;
    }

    glutPostRedisplay();
    glutTimerFunc(5, updateTrainM, 0);
}


//sun
int moveSunM = 0;

void sunM()
{
    glPushMatrix();
    glTranslatef(moveSunM, 0, 0);

    glColor3f(0.97,0.49,0.00);
    circleM(200,650,30);
    glPopMatrix();
}

void updateSunM(int value)
{
    moveSunM += 1;
    if (moveSunM > 1000)
    {
        moveSunM = -300;
    }

    glutPostRedisplay();
    glutTimerFunc(80, updateSunM, 0);
}

///road light

void roadLightM()
{

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < 1000; i += 200)
    {
        // First vertical line
        glLineWidth(6);
        glBegin(GL_LINES);

        glVertex2f(150 + i, 445);
        glVertex2f(150 + i, 620);
        glEnd();

        // Left diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(90 + i, 600);
        glVertex2f(150 + i, 610);
        glEnd();

        // Right diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(210 + i, 620);
        glVertex2f(150 + i, 608);
        glEnd();
    }
//light

    glColor3f(1.0f,1.0f,1.0f);
    circleM(95,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(208,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(295,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(408,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(495,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(608,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(695,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(808,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(895,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(1008,615,5);
    glEnd();


}

void lineM()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glEnd();


}

void riverM()
{
    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.51f, 0.71f);
    glVertex2f(0,349);
    glVertex2f(1000,349);
    glVertex2f(1000,0);
    glVertex2f(0,0);

    glEnd();

}

void line2M()
{
    glLineWidth(10);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glEnd();
}

void bridgeM()
{

    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f); // hash
    glVertex2f(0,280);
    glVertex2f(0,200);             //under
    glVertex2f(1000,200);
    glVertex2f(1000,280);

    glEnd();

///railline path

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,260);
    glVertex2f(1000,260);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,255);
    glVertex2f(1000,255);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,230);
    glVertex2f(1000,230);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,225);
    glVertex2f(1000,225);

    glEnd();

//upper road

    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f); // hash
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glVertex2f(1000,500);
    glVertex2f(0,500);

    glEnd();


//lines of road

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,497);
    glVertex2f(1000,497);
    glEnd();

//upper road middle lines

    glLineWidth(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 120)
    {
        glBegin(GL_LINES);
        glVertex2f(i,473);
        glVertex2f(i + 90,473);
        glEnd();
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 160)
    {
        glBegin(GL_QUADS);
        glVertex2f(5 + i, 405);
        glVertex2f(150 + i, 405);
        glVertex2f(145 + i, 400);
        glVertex2f(0 + i, 400);
        glEnd();
    }

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,450);
    glVertex2f(1000,450);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,445);
    glVertex2f(1000,445);
    glEnd();


    for (int i = 50; i <= 850; i += 400)
    {
        glBegin(GL_QUADS);
        glColor3f(0.00f, 0.50f, 0.50f); // Teal
        glVertex2f(i,195);
        glVertex2f(i + 150,195);
        glVertex2f(i + 105,170);
        glVertex2f(i + 45,170);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.75f, 0.75f, 0.75f); // Black
        glVertex2f(i + 45,170);
        glVertex2f(i + 105,170);
        glVertex2f(i + 95,100);
        glVertex2f(i + 55,100);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.36f, 0.40f, 0.39f); // White
        glVertex2f(i + 30,100);
        glVertex2f(i + 120,100);
        glVertex2f(i + 110,90);
        glVertex2f(i + 40,90);
        glEnd();
    }


}

///raillng

void raillingM()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,390);
    glVertex2f(1000,390);
    glEnd();

    for(int i= 20; i<=1000; i+=50)
    {
        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,390);
        glVertex2f(i,350);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,390);
        glVertex2f(i+20,350);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+20,350);
        glVertex2f(i+40,390);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+10,390);
        glVertex2f(i+20,370);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+20,370);
        glVertex2f(i+30,390);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+40,390);
        glVertex2f(i+40,350);
        glEnd();

    }
}
//crosses

//big crosses
void bigCrossM()
{

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,340);
    glVertex2f(220,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(220,205);
    glVertex2f(440,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(440,340);
    glVertex2f(660,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(660,205);
    glVertex2f(880,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(880,340);
    glVertex2f(1050,205);
    glEnd();

}
//small crosses

void smallCrossM()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 430)
    {
        glBegin(GL_QUADS);

        // First quad
        glVertex2f(100 + i, 350);
        glVertex2f(130 + i, 350);
        glVertex2f(230 + i, 280);
        glVertex2f(210 + i, 280);

        glEnd();

        glBegin(GL_QUADS);

        // Second quad
        glVertex2f(228 + i, 280);
        glVertex2f(250 + i, 280);
        glVertex2f(370 + i, 350);
        glVertex2f(340 + i, 350);

        glEnd();
    }
}



void skyM()
{

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.81f, 0.98f); // sky
    glVertex2f(0,500);
    glVertex2f(1000,500);
    glVertex2f(1000,700);
    glVertex2f(0,700);

    glEnd();

}





//////////////////////////////////////////////////////////////////////////night//////////////////////////////////////////


int moveCloud1M_night = 0;
void cloud1M_night()
{
    glPushMatrix();
    glTranslatef(moveCloud1M_night, 0, 0);

    glColor3f(0.80f, 0.80f, 0.80f);

//cloud-1
    circleM(50,650,15);
    circleM(70,660,15);
    circleM(90,650,15);
    circleM(110,645,15);
    circleM(70,640,15);
    circleM(90,640,15);

    glPopMatrix();

}

void updateCloud1M_night(int value)
{
    moveCloud1M_night -= 1;
    if (moveCloud1M_night <- 1000)
    {
        moveCloud1M_night = 950;
    }

    glutPostRedisplay();
    glutTimerFunc(25, updateCloud1M_night, 0);
}


//cloud-2

int moveCloud2M_night = 0;
void cloud2M_night()
{
    glPushMatrix();
    glTranslatef(moveCloud2M_night, 0, 0);

    glColor3f(0.80f, 0.80f, 0.80f);
    circleM(500,650,20);
    circleM(510,670,20);
    circleM(530,640,20);
    circleM(560,645,20);
    circleM(545,670,20);

    glPopMatrix();
}

void updateCloud2M_night(int value)
{
    moveCloud2M_night += 1;
    if (moveCloud2M_night >1000)
    {
        moveCloud2M_night = -600;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateCloud2M_night, 0);
}



///plane

float movePlaneM = 0;
float planeMSpeed = 1.0f;
float savedPlaneMSpeed = 0.0f;
float planeMTireAngle = 0.0f;
bool planeMPaused = false;

void planeM()
{
    glPushMatrix();
    glTranslatef(movePlaneM, 0, 0);

    glColor3f(0,1,1);;
    circleM(459,635,10);
    glColor3f(0.698f, 0.75f, 0.709f);
    circleM(448,640,10);
    circleM(453,635,10);


    glBegin(GL_POLYGON);
    glColor3f(0.698f, 0.75f, 0.709f); // body
    glVertex2f(300, 650);
    glVertex2f(450, 650);
    glVertex2f(455, 635);
    glVertex2f(450, 625);
    glVertex2f(330, 625);
    glVertex2f(300, 640);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex2f(330, 633);
    glVertex2f(462, 633);
    glVertex2f(462, 625);
    glVertex2f(330, 625);
    glEnd();

    //upper tail light
    glColor3f(1,0,0);
    circleM(403,665,4);
    circleM(407,655,4);


    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // upper tail
    glVertex2f(390, 675);
    glVertex2f(400, 670);
    glVertex2f(410, 650);
    glVertex2f(385, 650);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // upper border
    glVertex2f(390, 675);
    glVertex2f(396, 670);
    glVertex2f(395, 650);
    glVertex2f(385, 650);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(396,671);
    glVertex2f(395,650);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail
    glVertex2f(415, 628);
    glVertex2f(390, 628);
    glVertex2f(370, 590);
    glVertex2f(390, 595);
    glEnd();


    glColor3f(1,0,0);
    circleM(416,615,5);

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail light
    glVertex2f(410, 620);
    glVertex2f(403, 610);
    glVertex2f(415, 610);
    glVertex2f(415, 620);
    glEnd();


    glColor3f(1,0,0);
    circleM(406,603.5f,4);
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail light
    glVertex2f(397,607);
    glVertex2f(387,600);
    glVertex2f(405,600);
    glVertex2f(405, 607);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0,1,1); //lower border
    glVertex2f(390, 628);
    glVertex2f(403, 628);
    glVertex2f(382, 595);
    glVertex2f(370, 590);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(403, 628);
    glVertex2f(382, 594);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // upper back
    glVertex2f(310, 648);
    glVertex2f(325, 648);
    glVertex2f(315, 675);
    glVertex2f(305, 670);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // upper back border
    glVertex2f(310, 648);
    glVertex2f(318, 648);
    glVertex2f(310, 672);
    glVertex2f(305, 670);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(318, 648);
    glVertex2f(310, 672);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // lower back
    glVertex2f(315, 635);
    glVertex2f(330, 630);
    glVertex2f(315, 610);
    glVertex2f(307, 616);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // lower back border
    glVertex2f(315, 635);
    glVertex2f(320, 630);
    glVertex2f(312, 613);
    glVertex2f(307, 616);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex2f(330, 625);
    glVertex2f(330,633);
    glVertex2f(300,645);
    glVertex2f(300,640);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(330,633);
    glVertex2f(300,645);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(320, 630);
    glVertex2f(312, 613);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(330,632);
    glVertex2f(462,632);
    glEnd();

    for(int i=330; i<=380; i+=10)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.50f); // window
        glVertex2f(i, 643);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();

    }
    for(int i=330; i<=380; i+=10)
    {
        // window border
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,643);
        glVertex2f(i+8,643);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,643);
        glVertex2f(i, 635);
        glEnd();

    }

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);  //door
    glVertex2f(390, 645);
    glVertex2f(400, 645);
    glVertex2f(400, 630);
    glVertex2f(390, 630);
    glEnd();

    for(int i=404; i<=430; i+=10)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.50f); // window
        glVertex2f(i, 643);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();
    }

    for(int i=404; i<=430; i+=10)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i,643);
        glVertex2f(i+8,643);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i+8,643);
        glVertex2f(i+8,635);
        glEnd();


        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i+8,635);
        glVertex2f(i,635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i,635);
        glVertex2f(i,643);
        glEnd();
    }


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(456, 643);
    glVertex2f(435, 643);
    glVertex2f(435, 635);
    glVertex2f(461, 635);
    glEnd();

    /*glColor3f(0.0f, 0.0f, 0.0f);
       circleM(457,639,4.5f);*/


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(457, 643);
    glVertex2f(435, 643);
    glVertex2f(435, 635);
    glVertex2f(464, 635);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.50f);
    glVertex2f(456, 642);
    glVertex2f(436, 642);
    glVertex2f(436, 636);
    glVertex2f(463, 636);
    glEnd();


    glPopMatrix();
}

void updatePlaneM(int value)
{
    movePlaneM += planeMSpeed;
    if (movePlaneM > 1000)
    {
        movePlaneM = -500;
    }

    glutPostRedisplay();
    glutTimerFunc(16,updatePlaneM, 0);
}


///car3

float M_moveCar3_night = 0;
float M_car3_nightSpeed = 1.0f;
float M_savedCar3_nightSpeed = 0.0f;
float M_car3_nightTireAngle = 0.0f;
bool  M_car3_nightPaused = false;

void M_car3_night()
{
    glPushMatrix();
    glTranslatef(M_moveCar3_night, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.451f, 0.576f, 0.702f);  //car body
    glVertex2f(735, 507);
    glVertex2f(750,520);
    glVertex2f(800, 520);
    glVertex2f(805, 500);
    glVertex2f(805, 480);
    glVertex2f(700, 480);
    glVertex2f(710, 505);
    glVertex2f(770, 500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.0f);  //car light
    glVertex2f(710,500);
    glVertex2f(715,500);
    glVertex2f(715,495);
    glVertex2f(705,492);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.60f);
    glVertex2f(710,500);
    glVertex2f(650,520);
    glVertex2f(650,480);
    glVertex2f(710,495);
    glEnd();


    glBegin(GL_QUADS);    //window
    glColor3f(1,1,0.6);
    glVertex2f(750,515);
    glVertex2f(765,515);
    glVertex2f(765,503);
    glVertex2f(742,503);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.6);
    glVertex2f(770,515);
    glVertex2f(795,515);
    glVertex2f(797,503);
    glVertex2f(770,503);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);

    glVertex2f(805,500);
    glVertex2f(810,500);
    glVertex2f(810,490);
    glVertex2f(805,490);
    glEnd();

    //wheel
    glPushMatrix();
    glTranslatef(720,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-720,-480, 0);

    glColor3f(0,0,0);
    circleM(720,480,7);
    glColor3f(0.3,0.3,0.3);
    circleM(720,480,5);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(790,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-790,-480, 0);

    glColor3f(0,0,0);
    circleM(790,480,7);
    glColor3f(0.3,0.3,0.3);
    circleM(790,480,5);

    glPopMatrix();

    glPopMatrix();

}

void M_updateCar3_night(int value)
{
    M_moveCar3_night -= 1;
    if (M_moveCar3_night <- 1000)
    {
        M_moveCar3_night = 400;
    }

    M_car3_nightTireAngle +=1;
    glutPostRedisplay();
    glutTimerFunc(20,M_updateCar3_night, 0);
}



///car4_night

float M_moveCar4_night = 0;
float M_car4_nightSpeed = 1.0f;
float M_savedCar4_nightSpeed = 0.0f;
float M_car4_nightTireAngle = 0.0f;
bool  M_car4_nightPaused = false;

void M_car4_night()
{

    glPushMatrix();
    glTranslatef(M_moveCar4_night, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.431, 0.149, 0.055); // BODY
    glVertex2f(500,440);
    glVertex2f(590,440);
    glVertex2f(590,400);
    glVertex2f(500,400);
    //glVertex2f();
    glEnd();

    glColor3f(1,1,0);   //light
    circleM(667,423,7);

    glBegin(GL_QUADS);
    glColor3f(1,1,0.87); // light
    glVertex2f(672,425);
    glVertex2f(740,440);
    glVertex2f(740,410);
    glVertex2f(672,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.584, 0.271, 0.208);
    glVertex2f(590,400); //front body
    glVertex2f(590,470);
    glVertex2f(630,470);
    glVertex2f(630,467);
    glVertex2f(625,467);
    glVertex2f(640,440);
    glVertex2f(670,440);
    glVertex2f(670,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex2f(600,460);  //window
    glVertex2f(620,460);
    glVertex2f(630,440);
    glVertex2f(600,440);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); //black
    glVertex2f(493, 405);
    glVertex2f(510, 405);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.10f);
    glVertex2f(500, 425);          //back light
    glVertex2f(505, 425);
    glEnd();

    //wheel
    glPushMatrix();
    glTranslatef(525,400, 0);
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-525,-400, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(525,400,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(525,400,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600,400, 0);
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-600,-400, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(600,400,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(600,400,5);
    glPopMatrix();


    glPopMatrix();

}

void M_updateCar4_night(int value)
{
    M_moveCar4_night += 1;
    if (M_moveCar4_night > 1000)
    {
        M_moveCar4_night = -750;
    }

    M_car4_nightTireAngle +=1;

    glutPostRedisplay();
    glutTimerFunc(6, M_updateCar4_night, 0);
}


//car1night

float moveCar1_nightM = 0;
float car1_nightMSpeed = 1.0f;
float savedcar1_nightMSpeed = 0.0f;
float car1_nightMTireAngle = 0.0f;
bool car1_nightMPaused = false;

void car1_nightM()
{
    glPushMatrix();
    glTranslatef(moveCar1_nightM, 0, 0);



    // car body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.1f, 0.1f); // Red
    glVertex2f(150, 435);
    glVertex2f(225, 435);
    glVertex2f(215, 445);
    glVertex2f(160, 445);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.87f); // yellow light
    glVertex2f(220, 443);
    glVertex2f(270, 455);
    glVertex2f(270, 430);
    glVertex2f(220, 440);
    glEnd();

    // Draw the minimized roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f); // Darker red
    glVertex2f(165, 445);
    glVertex2f(210, 445);
    glVertex2f(205, 455);
    glVertex2f(170, 455);
    glEnd();

    // Draw the window
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(170, 445);
    glVertex2f(205, 445);
    glVertex2f(200, 452);
    glVertex2f(175, 452);
    glEnd();


    // front wheel
    glPushMatrix();
    glTranslatef(165, 435, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-165, -435, 0);


    glColor3f(0.0f, 0.0f, 0.0f); //black
    circleM(165, 435, 6);

    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(165, 435, 4);


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(160, 435);
    glVertex2f(170, 435);
    glEnd();

    glPopMatrix();

    //  rear wheel

    glPushMatrix();
    glTranslatef(210, 435, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-210, -435, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(210, 435, 6);


    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(210, 435, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(205, 435);
    glVertex2f(215, 435);
    glEnd();

    glPopMatrix();


    glPopMatrix();
}

void updateCar1_nightM(int value)
{
    moveCar1_nightM += 1;
    if (moveCar1_nightM > 1000)
    {
        moveCar1_nightM = -300;
    }

    car1_nightMTireAngle +=1;

    glutPostRedisplay();
    glutTimerFunc(16, updateCar1_nightM, 0);
}


///raillng night

void raillingM_night()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,390);
    glVertex2f(1000,390);
    glEnd();

    for(int i= 20; i<=1000; i+=50)
    {
        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i,390);
        glVertex2f(i,350);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i,390);
        glVertex2f(i+20,350);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+20,350);
        glVertex2f(i+40,390);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+10,390);
        glVertex2f(i+20,370);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+20,370);
        glVertex2f(i+30,390);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+40,390);
        glVertex2f(i+40,350);
        glEnd();

    }
}


///boats

//boat 1
int moveBoat1_nightM = 0;
void boat1_nightM()
{
    glPushMatrix();
    glTranslatef(moveBoat1_nightM, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.00f, 0.00f);
    glVertex2f(900,50);
    glVertex2f(990,50);
    glVertex2f(980,40);
    glVertex2f(910,40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00f, 1.0f, 0.05f);
    glVertex2f(910,50);
    glVertex2f(920,60);
    glVertex2f(930,50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.20f, 0.60f);
    glVertex2f(918,60);
    glVertex2f(950,60);
    glVertex2f(958,50);
    glVertex2f(930,50);
    glEnd();

    glPopMatrix();

}

void updateBoat1_nightM(int value)
{
    moveBoat1_nightM -= 1;
    if (moveBoat1_nightM < -1000)
    {
        moveBoat1_nightM = 100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat1_nightM, 0);
}

//boat 2

int moveBoat2_nightM = 0;
void boat2_nightM()
{
    glPushMatrix();
    glTranslatef(moveBoat2_nightM, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(200,90);
    glVertex2f(390,90);
    glVertex2f(380,70);
    glVertex2f(210,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(270,90);
    glVertex2f(280,105);
    glVertex2f(328,105);
    glVertex2f(320,90);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.65f, 0.58f);  //upper body
    glVertex2f(280,105);
    glVertex2f(270,90);
    glVertex2f(210,90);
    glVertex2f(220,120);
    glVertex2f(300,120);
    glVertex2f(310,105);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5); // window
    glVertex2f(230,100);
    glVertex2f(230,110);
    glVertex2f(240,110);
    glVertex2f(240,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5); // window
    glVertex2f(240,110);
    glVertex2f(240,100);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5); // window
    glVertex2f(250,100);
    glVertex2f(250,110);
    glVertex2f(260,110);
    glVertex2f(260,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5); // window
    glVertex2f(260,110);
    glVertex2f(260,100);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();


    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,110);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(270,100);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(230,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(240,100);
    glVertex2f(240,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(260,100);
    glVertex2f(260,110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.63f, 0.53f, 0.52f);
    glVertex2f(225,120);
    glVertex2f(230,140);
    glVertex2f(290,140);
    glVertex2f(295,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54f, 0.68f, 0.72f);
    glVertex2f(235,140);
    glVertex2f(235,160);
    glVertex2f(250,160);
    glVertex2f(260,140);

    glEnd();

    for(int i=215; i<=310; i+=10)
    {
        glColor3f(1.0f, 1.0f, 0.0f);
        circleM(i,80,3);
    }


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.4f);
    glVertex2f(323,90);
    glVertex2f(390,100);
    glVertex2f(390,76);
    glVertex2f(323,85);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(325,90);
    glVertex2f(380,100);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(323,85);
    glVertex2f(390,76);
    glEnd();

    glPopMatrix();
}

void updateBoat2_nightM(int value)
{
    moveBoat2_nightM += 1;
    if (moveBoat2_nightM > 1000)
    {
        moveBoat2_nightM = -450;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat2_nightM, 0);
}

//moon
int moveMoonM = 0;

void moonM()
{
    glPushMatrix();
    glTranslatef(moveMoonM, 0, 0);
    glDisable(GL_LIGHTING); // FIX: Lighting OFF for pure color
    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(800, 650, 30);
    glColor3f(0.21f, 0.27f, 0.3098f); // Shadow matches Sky
    circleM(785, 660, 30);
    glEnable(GL_LIGHTING); // FIX: Lighting Back ON for next objects
    glPopMatrix();
}


void updateMoonM(int value)
{
    moveMoonM -= 1;
    if (moveMoonM <- 1000)
    {
        moveMoonM = 300;
    }

    glutPostRedisplay();
    glutTimerFunc(80, updateMoonM, 0);
}

void M_star()
{
    glPointSize(2); // Set point size
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100,650);
    glVertex2f(300,650);
    glVertex2f(500,640);
    glVertex2f(700,670);
    glVertex2f(400,600);
    glVertex2f(900,650);
    glVertex2f(200,550);


    glEnd();

}

///road light night

void roadLight_nightM()
{

    glColor3f(0.8f, 0.8f, 0.8f);

    for (int i = 0; i < 1000; i += 200)
    {
        // First vertical line
        glLineWidth(6);
        glBegin(GL_LINES);

        glVertex2f(150 + i, 445);
        glVertex2f(150 + i, 620);
        glEnd();

        // Left diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(90 + i, 600);
        glVertex2f(150 + i, 610);
        glEnd();

        // Right diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(210 + i, 620);
        glVertex2f(150 + i, 608);
        glEnd();
    }
}

///light

void light_nightM()
{

    glColor3f(1.0f,1.0f,0.0f);
    circleM(95,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(208,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(295,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(408,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(495,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(608,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(695,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(808,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(895,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(1008,615,5);
    glEnd();


}



void line_nightM()
{
    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glEnd();


}


///train_night


float moveTrainM_night = 0;
float trainM_nightSpeed = 1.0f;
float savedTrainM_nightSpeed = 0.0f;
float trainM_nightTireAngle = 0.0f;
bool trainM_nightPaused = false;

void trainM_night()
{

    glPushMatrix();
    glTranslatef(moveTrainM_night, 0, 0);

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(90,239);
    glVertex2f(560,239);

    glEnd();

    for(int i=130; i<=550; i+=94)
    {
        //  rear wheel
        glColor3f(0.0f, 0.0f, 0.0f);
        circleM(i, 232, 8);
        circleM(i+30, 232, 8);

        glColor3f(0.3f, 0.3f, 0.3f);
        circleM(i, 232, 6);
        circleM(i+30, 232, 6);

    }

//front wheel

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(50, 232, 8);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(50, 232, 6);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(80, 232, 8);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(80, 232, 6);




    for (int i = 100; i <= 500; i += 94)
    {

        // Train body
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(i, 270);
        glVertex2f(i + 90, 270);
        glVertex2f(i + 90, 231);
        glVertex2f(i, 231);
        glEnd();

        glLineWidth(5.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // White line
        glVertex2f(i, 247);
        glVertex2f(i+90, 247);
        glEnd();

        glLineWidth(2.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); // White line
        glVertex2f(i, 270);
        glVertex2f(i+90, 270);
        glEnd();

        // Door 1 (left door)
        glBegin(GL_QUADS);
        glColor3f(1,1,0.5f);
        glVertex2f(i + 5, 265);
        glVertex2f(i + 15, 265);
        glVertex2f(i + 15, 235);
        glVertex2f(i + 5, 235);
        glEnd();

        // Door 2 (right door)
        glBegin(GL_QUADS);
        glColor3f(1,1,0.5f);
        glVertex2f(i + 75, 265);
        glVertex2f(i + 85, 265);
        glVertex2f(i + 85, 235);
        glVertex2f(i + 75, 235);
        glEnd();

        // Windows
        for (int j = 23; j <= 59; j += 12)
        {
            glBegin(GL_QUADS);
            glColor3f(1,1,0.5f);
            glVertex2f(i + j, 260);
            glVertex2f(i + j + 8, 260);   //(8 units wide)
            glVertex2f(i + j + 8, 252);
            glVertex2f(i + j, 252);
            glEnd();
        }
    }

//front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(95,270);
    glVertex2f(45,270);
    glVertex2f(35,265);
    glVertex2f(35,231);
    glVertex2f(95,231);

    glEnd();
//red line
    glBegin(GL_QUADS);
    glColor3f(0.80f, 0.00f, 0.0f);
    glVertex2f(95,270);
    glVertex2f(45,270);
    glVertex2f(35,265);
    glVertex2f(95,265);

    glEnd();
//front window
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5f);
    glVertex2f(35,265);
    glVertex2f(70,265);
    glVertex2f(55,250);
    glVertex2f(35,250);
    glEnd();

//front door
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5f);
    glVertex2f(75,265);
    glVertex2f(75,238);
    glVertex2f(60,238);
    glVertex2f(60,250);
    glEnd();

    glPopMatrix();

}

void updateTrainM_night(int value)
{
    if(!trainM_nightPaused)
    {
        moveTrainM_night -= trainM_nightSpeed;
        if (moveTrainM_night <- 1000)
        {
            moveTrainM_night = 950;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(5, updateTrainM_night, 0);
}



void river_nightM()
{
    glBegin(GL_QUADS);
    //glColor3f(0.118f, 0.16f, 0.24f);
    glColor3f(0.039f, 0.059f, 0.137f);
    glVertex2f(0,349);
    glVertex2f(1000,349);
    glVertex2f(1000,0);
    glVertex2f(0,0);

    glEnd();

}

void line2_nightM()
{
    glLineWidth(10);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glEnd();
}

void bridge_nightM()
{

    glBegin(GL_QUADS);
    glColor3f(0.10f, 0.10f, 0.10f); // hash
    glVertex2f(0,280);
    glVertex2f(0,200);             //under
    glVertex2f(1000,200);
    glVertex2f(1000,280);

    glEnd();

//railline path
    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,260);
    glVertex2f(1000,260);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,255);
    glVertex2f(1000,255);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,230);
    glVertex2f(1000,230);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,225);
    glVertex2f(1000,225);

    glEnd();

//upper road

    glBegin(GL_QUADS);
    glColor3f(0.10f, 0.10f, 0.10f); // hash
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glVertex2f(1000,500);
    glVertex2f(0,500);

    glEnd();


//lines of road

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,497);
    glVertex2f(1000,497);
    glEnd();

//upper road middle lines

    glLineWidth(2);
    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 1000; i += 120)
    {
        glBegin(GL_LINES);
        glVertex2f(i,473);
        glVertex2f(i + 90,473);
        glEnd();
    }

    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 1000; i += 160)
    {
        glBegin(GL_QUADS);
        glVertex2f(5 + i, 405);
        glVertex2f(150 + i, 405);
        glVertex2f(145 + i, 400);
        glVertex2f(0 + i, 400);
        glEnd();
    }

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,450);
    glVertex2f(1000,450);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,445);
    glVertex2f(1000,445);
    glEnd();


//pillers of bridge

    for (int i = 50; i <= 850; i += 400)
    {
        glBegin(GL_QUADS);
        glColor3f(0.00f, 0.20f, 0.20f); // Teal
        glVertex2f(i,195);
        glVertex2f(i + 150,195);
        glVertex2f(i + 105,170);
        glVertex2f(i + 45,170);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.75f, 0.75f, 0.75f); // Black
        glVertex2f(i + 45,170);
        glVertex2f(i + 105,170);
        glVertex2f(i + 95,100);
        glVertex2f(i + 55,100);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.36f, 0.40f, 0.39f); // White
        glVertex2f(i + 30,100);
        glVertex2f(i + 120,100);
        glVertex2f(i + 110,90);
        glVertex2f(i + 40,90);
        glEnd();
    }


}

//crosses

//big crosses
void M_bigCross_night()
{

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0,340);
    glVertex2f(220,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(220,205);
    glVertex2f(440,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(440,340);
    glVertex2f(660,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(660,205);
    glVertex2f(880,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(880,340);
    glVertex2f(1050,205);
    glEnd();

}

void sky_nightM()
{

    glDisable(GL_LIGHTING);
    glBegin(GL_QUADS);
    glColor3f(0.21f, 0.27f, 0.3098f);
    glVertex2f(0,500);
    glVertex2f(1000,500);
    glVertex2f(1000,700);
    glVertex2f(0,700);

    glEnd();

}



/////////   function calling for day/////////

void dayM()
{

    glClear(GL_COLOR_BUFFER_BIT);

    riverM();
    boat3M();
    bridgeM();
    lineM();
    line2M();
    trainM();
    bigCrossM();
    smallCrossM();
    boat1M();
    boat2M();
    skyM();

    // ==========================================
    // SUN LIGHTING SETUP (GL_LIGHT0)
    // ==========================================
    float sunX_M = 200.0f + moveSunM;
    float sunY_M = 650.0f;
    GLfloat lightPos[] = { sunX_M, sunY_M, 200.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);
    GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    // Draw sun (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    sunM();
    glEnable(GL_LIGHTING);
    truckM();
    busM();
    cloud1M();
    cloud2M();
    cloud3M();
    roadLightM();
    //tollM();
    car1M();
    Mcar5();
    ambulanceM();
    raillingM();



}

/////////   function calling for night /////////

void nightM()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glDisable(GL_LIGHTING);

    river_nightM();
    bridge_nightM();
    line_nightM();
    line2_nightM();
    boat1_nightM();
    boat2_nightM();
    sky_nightM();

    // ==========================================
    // MOON LIGHTING SETUP (GL_LIGHT0)
    // ==========================================
    float moonX_M = 800.0f + moveMoonM;
    float moonY_M = 650.0f;
    GLfloat lightPos[] = { moonX_M, moonY_M, 200.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    GLfloat moonLightColor[] = { 0.4f, 0.4f, 0.5f, 1.0f }; // Dimmer light for night
    glLightfv(GL_LIGHT0, GL_DIFFUSE, moonLightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, moonLightColor);
    GLfloat ambientColor[] = { 0.25f, 0.25f, 0.3f, 1.0f }; // Increased ambient for brighter night
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
    glEnable(GL_LIGHT0);

    // ==========================================
    // LAMPPOST LIGHTING SETUP (GL_LIGHT1)
    // ==========================================
    glEnable(GL_LIGHT1);
    // Position: Central position for lampposts (they are spread across the scene)
    GLfloat lampPos[] = { 500.0f, 600.0f, 150.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, lampPos);

    GLfloat yellowLight[] = { 0.8f, 0.8f, 0.5f, 1.0f }; // Yellow lamppost light
    GLfloat lampAmbient[] = { 0.15f, 0.15f, 0.1f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, yellowLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, yellowLight);
    glLightfv(GL_LIGHT1, GL_AMBIENT, lampAmbient);

    // Attenuation for lampposts
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.003f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0003f);

    glEnable(GL_LIGHTING);

    // Draw moon and stars (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    moonM();
    M_star();
    glEnable(GL_LIGHTING);

    cloud1M_night();
    cloud2M_night();
    planeM();
    M_car3_night();
    roadLight_nightM();
    car1_nightM();
    Mcar5_night();

    // Draw lamppost lights (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    light_nightM();
    glEnable(GL_LIGHTING);
    trainM_night();
    M_bigCross_night();
    M_star();
    M_car4_night();
    raillingM_night();

}

void keyboardM(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDayM = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDayM = false;
        glutPostRedisplay();
    }
    if(key == 'm' || key == 'M')
    {
        scenarioMeraz = false;
        scenarioMohaimuiul = true;
        scenarioMohaiminul = false;
    }

    if(key == 's' || key == 'S')
    {
        scenarioMohaiminul = true;
        scenarioMeraz = false;
        scenarioMohaimuiul = false;
    }

    if(key == 'v' || key == 'V')
    {
        scenarioMeraz = true;
        scenarioMohaimuiul = false;
        scenarioMohaiminul = false;
    }

    if(key == 27)
        exit(0);

}

void specialKeysM(int key, int x, int y)
{
    if (isDayM)  // Check if it's day
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            car1MSpeed += 0.5f;
            break;

        case GLUT_KEY_DOWN:
            car1MSpeed -= 0.5f;
            if (car1MSpeed < 0) car1MSpeed = 0;
            break;

        case GLUT_KEY_RIGHT:
            ambulanceMSpeed += 0.5f;
            break;

        case GLUT_KEY_LEFT:
            ambulanceMSpeed -= 0.5f;
            break;
        }
    }
    else  // If it's night
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            planeMSpeed += 0.6f;
            break;

        case GLUT_KEY_DOWN:
            planeMSpeed -= 0.6f;
            if (planeMSpeed < 0) planeMSpeed = 0;
            break;
        }
    }
}


void M_mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
    {
        car1MPaused = !car1MPaused;
        if (car1MPaused)
        {
            savedcar1MSpeed = car1MSpeed;
            car1MSpeed = 0;
        }
        else
        {
            car1MSpeed =  savedcar1MSpeed;

        }

    }


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
    {
        trainM_nightPaused = !trainM_nightPaused;
        if (trainM_nightPaused)
        {
            savedTrainM_nightSpeed = trainM_nightSpeed;
            trainM_nightSpeed = 0;
        }
        else
        {
            trainM_nightSpeed =  savedTrainM_nightSpeed;

        }

    }
}

void Avishek()
{
    // Depending on the time of day, call day or night function
    if (isDayM)
    {
        dayM();  // Call the day setup
    }
    else
    {
        nightM();  // Call the night setup
    }
}
/// =======================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================
/// =========================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================


/// **************************************************************************************************************************************************
/// ******************************************************** >>> Mohaiminul (KLCC) <<< ******************************************************************
/// **************************************************************************************************************************************************

// Helper Functions and Variables
const float KLCC_PI = 3.1415926535f;
bool isDayM2 = true;
float sunX = 150.0f;
float sunY = 600.0f;
float sunSpeedM2 = 0.5f;

// Moon variables
float moonX = 850.0f;
float moonY = 600.0f;
float moonSpeedM2 = 0.5f;  // Moon movement speed

// --- CLOUD VARIABLES ---
float c1_off = 0.0f; float s1 = 0.8f;
float c2_off = 0.0f; float s2 = 1.0f;
float c3_off = 0.0f; float s3 = 0.6f;
float c4_off = 0.0f; float s4 = 0.8f;
float c5_off = 0.0f; float s5 = 0.5f;

//Train Variables
float trainKLCCX = 1000.0f;
float trainKLCCSpeed = 2.0f;

// --- Cybertruck Variables ---
float carKLCCX = -150.0f;
float carKLCCSpeed = 3.0f;
float carWheelAngle = 0.0f;

// ====================
// BUS VARIABLES
// ====================
float busXM2 = 1150.0f;
bool busFaceRightM2 = true;
float busWheelAngleM2 = 0.0f;
float busSpeedM2 = 4.5f;

//Fountains
int fountainStageM2 = 0;

// Toggle variables
bool lampsOnM2 = true;  // Lampposts on/off
bool fountainsOnM2 = true;  // Fountains on/off
bool isTrainPausedM2 = false; // False = Train is running by default

// Circle
void drawCircle(float cx, float cy, float radius, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float rad = i * KLCC_PI / 180.0f;
        glVertex2f(cx + radius * cos(rad), cy + radius * sin(rad));
    }
    glEnd();
}

// Cloud
void drawCloud(float x, float y, float scale)
{
    // Bottom puffs
    drawCircle(x - 40 * scale, y, 20 * scale, 1.0f, 1.0f, 1.0f);
    drawCircle(x, y - 5 * scale, 25 * scale, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 40 * scale, y, 20 * scale, 1.0f, 1.0f, 1.0f);
    // Top puffs
    drawCircle(x - 20 * scale, y + 15 * scale, 18 * scale, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 20 * scale, y + 15 * scale, 18 * scale, 1.0f, 1.0f, 1.0f);
    drawCircle(x, y + 25 * scale, 20 * scale, 1.0f, 1.0f, 1.0f);
}

void drawCybertruckKLCC(float x, float y, float s, bool faceRight)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(s, s, 1.0f);

    if (faceRight)
    {
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(-16.0f, 0.0f, 0.0f);
    }

    glDisable(GL_LIGHTING);

    // --- BODY ---
    glColor3f(0.75f, 0.75f, 0.75f); // Silver
    glBegin(GL_POLYGON);
    glVertex2f(0.5f, 3.0f);
    glVertex2f(0.5f, 4.5f);
    glVertex2f(8.0f, 7.5f);
    glVertex2f(15.5f, 5.0f);
    glVertex2f(15.5f, 3.0f);
    glEnd();

    // --- SKIRT ---
    glColor3f(0.3f, 0.3f, 0.3f); // Dark Grey
    glBegin(GL_QUADS);
    glVertex2f(0.5f, 2.0f);
    glVertex2f(15.5f, 2.0f);
    glVertex2f(15.5f, 3.0f);
    glVertex2f(0.5f, 3.0f);
    glEnd();

    // --- FENDERS ---
    glColor3f(0.2f, 0.2f, 0.2f); // Black
    glBegin(GL_POLYGON);
    glVertex2f(1.5f, 2.0f);
    glVertex2f(2.2f, 4.5f);
    glVertex2f(5.3f, 4.5f);
    glVertex2f(6.0f, 2.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(10.7f, 4.5f);
    glVertex2f(13.8f, 4.5f);
    glVertex2f(14.5f, 2.0f);
    glEnd();

    // --- WINDOWS ---
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(2.5f, 4.5f);
    glVertex2f(7.8f, 7.3f);
    glVertex2f(11.5f, 6.0f);
    glVertex2f(11.0f, 4.5f);
    glEnd();

    // --- HEADLIGHT ---
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.2f, 4.2f);
    glVertex2f(0.8f, 4.2f);
    glVertex2f(0.8f, 4.7f);
    glVertex2f(0.2f, 4.7f);
    glEnd();

    // --- TAILLIGHT ---
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(15.2f, 4.8f);
    glVertex2f(15.6f, 4.8f);
    glVertex2f(15.6f, 5.1f);
    glVertex2f(15.2f, 5.1f);
    glEnd();

    // --- VISUAL BEAM ---
    if (!isDayM2)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(1.0f, 1.0f, 0.8f, 0.4f);

        glBegin(GL_TRIANGLES);
        glVertex2f(0.2f, 4.45f);
        glVertex2f(-15.0f, 0.0f);
        glVertex2f(-15.0f, 12.0f);
        glEnd();
        glDisable(GL_BLEND);
    }

    // --- WHEELS ---
    auto drawSpokes = [](float r)
    {
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for(int i=0; i<360; i+=45)
        {
            float rad = i*3.1416f/180.0f;
            if((i/45)%2==0) glColor3f(1,1,1);
            else glColor3f(1,1,0);
            glVertex2f(0,0);
            glVertex2f(cos(rad)*r, sin(rad)*r);
        }
        glEnd();
    };

    // Front Wheel
    glPushMatrix();
    glTranslatef(3.75f, 2.0f, 0);
    drawCircle(0, 0, 1.8f, 0.1f, 0.1f, 0.1f); // Tire (Black)
    drawCircle(0, 0, 1.0f, 0.3f, 0.3f, 0.3f); // Rim (Dark Grey)
    glRotatef(carWheelAngle, 0,0,1);
    drawSpokes(1.0f);
    glPopMatrix();

    // Rear Wheel
    glPushMatrix();
    glTranslatef(12.25f, 2.0f, 0);
    drawCircle(0, 0, 1.8f, 0.1f, 0.1f, 0.1f); // Tire (Black)
    drawCircle(0, 0, 1.0f, 0.3f, 0.3f, 0.3f); // Rim (Dark Grey)
    glRotatef(carWheelAngle, 0,0,1);
    drawSpokes(1.0f);
    glPopMatrix();

    glEnable(GL_LIGHTING);

    glPopMatrix();
}


void drawBusKLCC(float x, float y, float s, bool faceRight)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(s, s, 1.0f);

    // --- DIRECTION LOGIC ---
    if (!faceRight)
    {
        // Rotate 180 degrees to face left
        glTranslatef(80.0f, 0.0f, 0.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(-80.0f, 0.0f, 0.0f);

        glNormal3f(0.0f, 0.0f, -1.0f);
    }
    else
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
    }

    // ====================
    // 1. MAIN BODY
    // ====================

    // Lower Body (Darker Red)
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 10);
        glVertex2f(160, 10);
        glVertex2f(160, 45);
        glVertex2f(0, 45);
    glEnd();

    // Upper Body (Lighter Red)
    glColor3f(0.9f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 45);
        glVertex2f(160, 45);
        glVertex2f(155, 80);
        glVertex2f(5, 80);
    glEnd();

    // Roof Top (Grey)
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2f(5, 80);   glVertex2f(155, 80);
        glVertex2f(153, 85); glVertex2f(7, 85);
    glEnd();

    // ===========================
    // 2. WINDOWS & GLASS
    // ===========================
    glColor3f(0.2f, 0.7f, 0.9f); // Glass Blue

    // Front Windshield
    glBegin(GL_POLYGON);
        glVertex2f(150, 45);
        glVertex2f(160, 45);
        glVertex2f(155, 78);
        glVertex2f(135, 78);
    glEnd();

    // Side Windows
    glBegin(GL_QUADS);
        glVertex2f(10, 50);  glVertex2f(130, 50);
        glVertex2f(130, 75); glVertex2f(10, 75);
    glEnd();

    // Window Pillars
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(40, 50); glVertex2f(40, 75);
        glVertex2f(70, 50); glVertex2f(70, 75);
        glVertex2f(100, 50); glVertex2f(100, 75);
    glEnd();

    // ======================
    // DETAILS
    // ======================

    // Bumpers
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        // Front Bumper
        glVertex2f(158, 5); glVertex2f(162, 5);
        glVertex2f(162, 20); glVertex2f(158, 20);
        // Rear Bumper
        glVertex2f(-2, 5);  glVertex2f(2, 5);
        glVertex2f(2, 20);  glVertex2f(-2, 20);
    glEnd();

    // Wheel Fenders
    glColor3f(0.15f, 0.15f, 0.2f);
    // Rear Arch
    glBegin(GL_POLYGON);
        glVertex2f(20, 10); glVertex2f(50, 10);
        glVertex2f(50, 25); glVertex2f(20, 25);
    glEnd();
    // Front Arch
    glBegin(GL_POLYGON);
        glVertex2f(115, 10); glVertex2f(145, 10);
        glVertex2f(145, 25); glVertex2f(115, 25);
    glEnd();

    // Headlight
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(158, 15); glVertex2f(161, 15);
        glVertex2f(161, 25); glVertex2f(158, 25);
    glEnd();

    // Taillight
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1, 15); glVertex2f(1, 15);
        glVertex2f(1, 35); glVertex2f(-1, 35);
    glEnd();

    // ==========================================
    // 4. WHEELS
    // ==========================================
    auto drawSpokes = [](float r) {
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for(int i=0; i<360; i+=45) {
            float rad = i * 3.1416f / 180.0f;
            if((i/45)%2 == 0) glColor3f(1.0f, 1.0f, 1.0f);
            else glColor3f(0.0f, 0.5f, 1.0f);
            glVertex2f(0, 0);
            glVertex2f(cos(rad)*r, sin(rad)*r);
        }
        glEnd();
    };

    // Rear Wheel
    glPushMatrix();
        glTranslatef(35.0f, 10.0f, 0.0f);
        drawCircle(0, 0, 11, 0.1f, 0.1f, 0.1f);
        drawCircle(0, 0, 7, 0.2f, 0.2f, 0.2f);
        glRotatef(busWheelAngleM2, 0, 0, 1);
        drawSpokes(7.0f);
    glPopMatrix();

    // Front Wheel
    glPushMatrix();
        glTranslatef(130.0f, 10.0f, 0.0f);
        drawCircle(0, 0, 11, 0.1f, 0.1f, 0.1f);
        drawCircle(0, 0, 7, 0.2f, 0.2f, 0.2f);
        glRotatef(busWheelAngleM2, 0, 0, 1);
        drawSpokes(7.0f);
    glPopMatrix();

    // =======================
    // 5. VISUAL BEAM
    // =======================
    if (!isDayM2)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(1.0f, 1.0f, 0.8f, 0.3f);

        glBegin(GL_TRIANGLES);
            glVertex2f(161, 20);
            glVertex2f(350, 0);
            glVertex2f(350, 40);
        glEnd();
        glDisable(GL_BLEND);
    }



    glPopMatrix();
    glNormal3f(0.0f, 0.0f, 1.0f);
}



// Sun update function
void updateSunM2(int value)
{
    if(isDayM2)
    {
        sunX += sunSpeedM2;
        if (sunX > 1050)
        {
            sunX = -80;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateSunM2, 0);
}

// Moon update function
void updateMoonM2(int value)
{
    if(!isDayM2)
    {
        moonX -= moonSpeedM2;


        if (moonX < -100)
        {


            moonX = 1050;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoonM2, 0);
}

// Cloud update function

void updateCloudsKLCC(int value)
{
    if (scenarioMohaiminul)
    {
        // --- CLOUD 1  ---
        c1_off -= s1;
        if (150 + c1_off < -150)
            c1_off = 900;

        // --- CLOUD 2  ---
        c2_off -= s2;
        if (350 + c2_off < -150)
            c2_off = 700;

        // --- CLOUD 3  ---
        c3_off -= s3;
        if (550 + c3_off < -150)
            c3_off = 500;

        // --- CLOUD 4  ---
        c4_off -= s4;
        if (800 + c4_off < -150)
            c4_off = 250;

        // --- CLOUD 5 ---
        c5_off -= s5;
        if (920 + c5_off < -150)
            c5_off = 130;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateCloudsKLCC, 0);
}

void updateFountainAnimM2(int value)
{
    if (fountainsOnM2)
    {
        fountainStageM2++;
        if (fountainStageM2 > 3)
        {
            fountainStageM2 = 0;
        }
        glutPostRedisplay();

        glutTimerFunc(300, updateFountainAnimM2, 0);
    }
}

void updateCarKLCC(int value)
{
    // Move Car Forward
    carKLCCX += carKLCCSpeed;


    carWheelAngle += carKLCCSpeed * 5.0f;

    if (carWheelAngle > 360.0f) carWheelAngle -= 360.0f;

    if (carKLCCX > 1100)
    {
        carKLCCX = -200;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCarKLCC, 0);
}

void setHeadlightKLCC(float x, float y, bool faceRight)
{
    if (isDayM2)
    {
        glDisable(GL_LIGHT3);
        return;
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    GLfloat lightColor[] = { 0.8f, 0.8f, 0.6f, 1.0f };

    float lightX = faceRight ? (x + 15.0f) : (x + 0.5f);
    GLfloat lightPos[] = { lightX, y + 4.5f, 100.0f, 1.0f };

    GLfloat spotDir[] = { faceRight ? 1.0f : -1.0f, -0.1f, -0.5f };

    glLightfv(GL_LIGHT7, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT7, GL_SPECULAR, lightColor);
    glLightfv(GL_LIGHT7, GL_POSITION, lightPos);

    glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spotDir);
    glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 60.0f);
    glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 2.0f);


    glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.0f);
}

void setBusHeadlight(float x, float y, bool faceRight)
{
    if (isDayM2)
    {
        glDisable(GL_LIGHT5);
        return;
    }

    // Enable Light 5
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT6);

    //Configure Properties (White/Yellow Beam)
    GLfloat lightColor[] = { 1.0f, 1.0f, 0.9f, 1.0f };


    float lightX = faceRight ? (x + 130.0f) : x;
    float lightY = y + 25.0f; // Headlight height

    // Position
    GLfloat lightPos[] = { lightX, lightY, 50.0f, 1.0f };

    // Direction Calculations:
    GLfloat spotDir[] = { faceRight ? 1.0f : -1.0f, -0.3f, 0.0f };

    // Apply
    glLightfv(GL_LIGHT6, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT6, GL_SPECULAR, lightColor);
    glLightfv(GL_LIGHT6, GL_POSITION, lightPos);

    // Spotlight Effect
    glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotDir);
    glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 60.0f);   // Cone Width
    glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 2.0f);

    // Attenuation
    glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.0f);
}

void updateTrainKLCC(int value)
{
    if (!isTrainPausedM2)
    {
        trainKLCCX -= trainKLCCSpeed;

        if (trainKLCCX < -420)
        {
            trainKLCCX = 1050;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateTrainKLCC, 0);
}

void updateBusKLCC(int value)
{
    if (scenarioMohaiminul)
    {
        busFaceRightM2 = false;

        //  Move Left
        busXM2 -= busSpeedM2;

        // Teleport Loop
        if (busXM2 < -250.0f)
        {
            busXM2 = 1100.0f;
        }


        busWheelAngleM2 -= busSpeedM2 * 3.0f;

        if (busWheelAngleM2 < 0.0f) busWheelAngleM2 += 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateBusKLCC, 0);
}


void Mohaiminul()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    // SKY BACKGROUND
    glBegin(GL_QUADS);
    if(isDayM2)
        glColor3f(0.0f, 0.6f, 0.9f); // Deep Sky Blue color (Day)
    else
        glColor3f(0.10f, 0.13f, 0.22f); // Dark blue/night sky color
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 700);
    glVertex2f(0, 700);
    glEnd();




    // ==========================================
    // THE SUN/MOON & DYNAMIC LIGHT SOURCE
    // ==========================================

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    if(isDayM2)
    {
        // DAY MODE: SUN

        GLfloat lightPos[] = { sunX, sunY, 500.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        // Set sun light color properties for day mode
        GLfloat sunColor[] = { 0.7f, 0.65f, 0.5f, 1.0f }; // Softer sunlight
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);

        GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);

        // Enable GL_LIGHT0 for day mode
        glEnable(GL_LIGHT0);

        // DRAW THE VISUAL SUN (Unlit)

        glDisable(GL_LIGHTING);

        // Sun Body
        drawCircle(sunX, sunY, 35, 1.0f, 0.85f, 0.0f);

        // Sun Rays
        glColor3f(1.0f, 0.85f, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for(int i=0; i<360; i+=30)
        {
            float rad = i * 3.1416 / 180.0;
            float rStart = 40.0f;
            float rEnd = 65.0f;
            glVertex2f(sunX + rStart*cos(rad), sunY + rStart*sin(rad));
            glVertex2f(sunX + rEnd*cos(rad), sunY + rEnd*sin(rad));
        }
        glEnd();

        // RE-ENABLE LIGHTING
        glEnable(GL_LIGHTING);
    }
    else
    {
        // NIGHT MODE: MOON

        GLfloat lightPos[] = { moonX, moonY, 200.0f, 1.0f };

        GLfloat moonLightColor[] = { 0.1f, 0.1f, 0.2f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, moonLightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, moonLightColor);

        GLfloat moonAmbient[] = { 0.05f, 0.05f, 0.1f, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, moonAmbient);

        // DRAW THE VISUAL MOON (Unlit)
        glDisable(GL_LIGHTING);

        // Moon Body
        drawCircle(moonX, moonY, 40, 1.0f, 1.0f, 1.0f);

        drawCircle(moonX - 8, moonY - 5, 12, 0.85f, 0.85f, 0.85f);
        drawCircle(moonX + 10, moonY + 8, 8, 0.9f, 0.9f, 0.9f);
        drawCircle(moonX - 5, moonY + 12, 6, 0.88f, 0.88f, 0.88f);

        // RE-ENABLE LIGHTING
        glEnable(GL_LIGHTING);

        // Restore sun light color for next day cycle
        GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);

        // stars for night mode
        glDisable(GL_LIGHTING);
        glPointSize(2.0f);
        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);

        // Random star positions
        glVertex2f(100, 650);
        glVertex2f(200, 620);
        glVertex2f(300, 660);
        glVertex2f(400, 640);
        glVertex2f(500, 680);
        glVertex2f(600, 630);
        glVertex2f(700, 650);
        glVertex2f(800, 620);
        glVertex2f(900, 640);
        glVertex2f(150, 580);
        glVertex2f(250, 600);
        glVertex2f(350, 580);
        glVertex2f(450, 600);
        glVertex2f(550, 580);
        glVertex2f(650, 600);
        glVertex2f(750, 580);
        glVertex2f(850, 600);
        glVertex2f(950, 580);
        glEnd();
        glEnable(GL_LIGHTING);
    }

    // ===================
    // CLOUDS LAYER
    // ===================

    // Common Lighting & Color Setup
    glEnable(GL_LIGHTING);
    glNormal3f(0.0f, 0.0f, 1.0f);

    float cloudR, cloudG, cloudB;
    if(isDayM2) {
        cloudR = 1.0f; cloudG = 1.0f; cloudB = 1.0f;
    } else {
        cloudR = 0.75f; cloudG = 0.75f; cloudB = 0.75f;
    }

    // --- CLOUD 1: Left Side ---
    glPushMatrix();
    glTranslatef(c1_off, 0.0f, 0.0f);
        // Bottom
        drawCircle(118, 520, 16, cloudR, cloudG, cloudB);
        drawCircle(150, 516, 20, cloudR, cloudG, cloudB);
        drawCircle(182, 520, 16, cloudR, cloudG, cloudB);
        // Top
        drawCircle(134, 532, 14, cloudR, cloudG, cloudB);
        drawCircle(166, 532, 14, cloudR, cloudG, cloudB);
        drawCircle(150, 540, 16, cloudR, cloudG, cloudB);
    glPopMatrix();

    // --- CLOUD 2: Center-Left ---
    glPushMatrix();
    glTranslatef(c2_off, 0.0f, 0.0f); //
        // Bottom
        drawCircle(326, 580, 12, cloudR, cloudG, cloudB);
        drawCircle(350, 577, 15, cloudR, cloudG, cloudB);
        drawCircle(374, 580, 12, cloudR, cloudG, cloudB);
        // Top
        drawCircle(338, 589, 11, cloudR, cloudG, cloudB);
        drawCircle(362, 589, 11, cloudR, cloudG, cloudB);
        drawCircle(350, 595, 12, cloudR, cloudG, cloudB);
    glPopMatrix();

    // --- CLOUD 3: Top Center ---
    glPushMatrix();
    glTranslatef(c3_off, 0.0f, 0.0f);
        // Bottom
        drawCircle(522, 650, 14, cloudR, cloudG, cloudB);
        drawCircle(550, 646, 17, cloudR, cloudG, cloudB);
        drawCircle(578, 650, 14, cloudR, cloudG, cloudB);
        // Top
        drawCircle(536, 660, 12, cloudR, cloudG, cloudB);
        drawCircle(564, 660, 12, cloudR, cloudG, cloudB);
        drawCircle(550, 667, 14, cloudR, cloudG, cloudB);
    glPopMatrix();

    // --- CLOUD 4: Right Side ---
    glPushMatrix();
    glTranslatef(c4_off, 0.0f, 0.0f);
        // Bottom
        drawCircle(760, 580, 18, cloudR, cloudG, cloudB);
        drawCircle(800, 575, 25, cloudR, cloudG, cloudB);
        drawCircle(840, 580, 20, cloudR, cloudG, cloudB);
        // Top
        drawCircle(780, 595, 18, cloudR, cloudG, cloudB);
        drawCircle(820, 595, 18, cloudR, cloudG, cloudB);
        drawCircle(800, 605, 20, cloudR, cloudG, cloudB);
    glPopMatrix();

    // --- CLOUD 5: Far Right ---
    glPushMatrix();
    glTranslatef(c5_off, 0.0f, 0.0f);
        // Bottom
        drawCircle(876, 620, 22, cloudR, cloudG, cloudB);
        drawCircle(920, 614, 27, cloudR, cloudG, cloudB);
        drawCircle(964, 620, 22, cloudR, cloudG, cloudB);
        // Top
        drawCircle(898, 636, 20, cloudR, cloudG, cloudB);
        drawCircle(942, 636, 20, cloudR, cloudG, cloudB);
        drawCircle(920, 647, 22, cloudR, cloudG, cloudB);
    glPopMatrix();



    // ==========================================
    // BACKGROUND SILHOUETTES
    // ==========================================

    glColor3f(0.15f, 0.15f, 0.45f); // Indigo Color

    glBegin(GL_QUADS);
    // Far Left
    glVertex2f(0, 302);
    glVertex2f(80, 302);
    glVertex2f(80, 360);
    glVertex2f(0, 360);

    // Left Peak
    glVertex2f(60, 302);
    glVertex2f(150, 302);
    glVertex2f(150, 420);
    glVertex2f(60, 420);

    // Small Connector
    glVertex2f(140, 302);
    glVertex2f(210, 302);
    glVertex2f(210, 380);
    glVertex2f(140, 380);

    // Tall Spire Area
    glVertex2f(200, 302);
    glVertex2f(290, 302);
    glVertex2f(290, 450);
    glVertex2f(200, 450);

    // Wide Block
    glVertex2f(280, 302);
    glVertex2f(380, 302);
    glVertex2f(380, 350);
    glVertex2f(280, 350);

    // Mid-Left Block (Mid-High)
    glVertex2f(370, 302);
    glVertex2f(460, 302);
    glVertex2f(460, 410);
    glVertex2f(370, 410);

    // Center Peak (High)
    glVertex2f(450, 302);
    glVertex2f(540, 302);
    glVertex2f(540, 430);
    glVertex2f(450, 430);

    // Mid-Right (Mid)
    glVertex2f(530, 302);
    glVertex2f(620, 302);
    glVertex2f(620, 390);
    glVertex2f(530, 390);

    // Tall Right Block (High)
    glVertex2f(610, 302);
    glVertex2f(700, 302);
    glVertex2f(700, 440);
    glVertex2f(610, 440);

    // Low Wide connector (Low)
    glVertex2f(690, 302);
    glVertex2f(800, 302);
    glVertex2f(800, 360);
    glVertex2f(690, 360);

    // Far Right Peak (High)
    glVertex2f(790, 302);
    glVertex2f(900, 302);
    glVertex2f(900, 415);
    glVertex2f(790, 415);

    // Edge Block (Mid)
    glVertex2f(890, 302);
    glVertex2f(1000, 302);
    glVertex2f(1000, 380);
    glVertex2f(890, 380);
    glEnd();


    // ==========================================
    // LAYER: GREEN GRASS FIELD
    // ==========================================

    if(isDayM2) {
        glColor3f(0.4f, 0.7f, 0.3f); // Bright green for day
    } else {
        glColor3f(0.25f, 0.5f, 0.2f); // Darker green for night
    }
    glBegin(GL_QUADS);
    glVertex2f(0, 120);
    glVertex2f(1000, 120);
    glVertex2f(1000, 302);
    glVertex2f(0, 302);
    glEnd();

    // Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 120);
    glVertex2f(1000, 120);
    glVertex2f(1000, 302);
    glVertex2f(0, 302);
    glEnd();

    // ==========================================
    // FOOTPATH
    // ==========================================

    // --- Side Face ---

    // Fill
    glColor3f(0.5f, 0.5f, 0.55f);
    glBegin(GL_QUADS);
    glVertex2f(0, 90);
    glVertex2f(1000, 90);
    glVertex2f(1000, 100);
    glVertex2f(0, 100);
    glEnd();

    // 2. Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 90);
    glVertex2f(1000, 90);
    glVertex2f(1000, 100);
    glVertex2f(0, 100);
    glEnd();

    // --- Top Face ---

    // Fill
    glColor3f(0.7f, 0.7f, 0.75f);
    glBegin(GL_QUADS);
    glVertex2f(0, 100);
    glVertex2f(1000, 100);
    glVertex2f(1000, 120);
    glVertex2f(0, 120);
    glEnd();

    // 2. Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 100);
    glVertex2f(1000, 100);
    glVertex2f(1000, 120);
    glVertex2f(0, 120);
    glEnd();


    // ==========================================
    // ROAD
    // ==========================================

    // --- Main Road Block ---

    glNormal3f(0.0f, 0.0f, 1.0f);

    glColor3f(0.3f, 0.3f, 0.35f);


    for(int i = 0; i < 1000; i += 20)
    {
        glBegin(GL_QUADS);
        glVertex2f(i, 0);
        glVertex2f(i + 20, 0);
        glVertex2f(i + 20, 90);
        glVertex2f(i, 90);
        glEnd();
    }

    // Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 90);
    glVertex2f(0, 90);
    glEnd();

    // ==========================================
    // ROAD STRIPES
    // ==========================================

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);

    for(int i = 20; i < 1000; i += 120)
    {
        glVertex2f(i, 40);
        glVertex2f(i + 60, 40);
        glVertex2f(i + 60, 50);
        glVertex2f(i, 50);
    }

    glEnd();


    // ==========================================
    // THE LAKE COMPLEX
    // ==========================================

    // --- LAYER 1: OUTER PAVEMENT ---

    // Fill
    glColor3f(0.87f, 0.74f, 0.62f); // Beige
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(500, 150);

    glVertex2f(250, 120);
    glVertex2f(130, 205);
    glVertex2f(310, 250);
    glVertex2f(240, 280);
    glVertex2f(310, 290);
    glVertex2f(710, 290);
    glVertex2f(780, 280);
    glVertex2f(720, 250);
    glVertex2f(880, 205);
    glVertex2f(760, 120);
    glVertex2f(250, 120);
    glEnd();

    if(isDayM2) {
        glColor3f(0.4f, 0.7f, 0.3f); // Bright green for day (same as grass)
    } else {
        glColor3f(0.25f, 0.5f, 0.2f); // Darker green for night (same as grass)
    }
    glBegin(GL_TRIANGLES);
    // Left Patch
    glVertex2f(130, 205);
    glVertex2f(310, 250);
    glVertex2f(240, 280);

    // Right Patch
    glVertex2f(880, 205);
    glVertex2f(720, 250);
    glVertex2f(780, 280);
    glEnd();

    // Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 120);
    glVertex2f(130, 205);
    glVertex2f(310, 250);
    glVertex2f(240, 280);
    glVertex2f(310, 290);
    glVertex2f(710, 290);
    glVertex2f(780, 280);
    glVertex2f(720, 250);
    glVertex2f(880, 205);
    glVertex2f(760, 120);
    glEnd();

    // --- LAYER 2: WATER ---

    // Fill
    glColor3f(0.0f, 0.6f, 0.9f); // Blue
    glBegin(GL_POLYGON);
    glVertex2f(200, 195);
    glVertex2f(500, 240);
    glVertex2f(800, 195);
    glVertex2f(690, 120);
    glVertex2f(310, 120);
    glEnd();

    // Outline
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_LINE_LOOP);
    glVertex2f(200, 195);
    glVertex2f(500, 240);
    glVertex2f(800, 195);
    glVertex2f(690, 120);
    glVertex2f(310, 120);
    glEnd();

    // ==========================================
    // 3 FOUNTAINS (Loop - Realistic Spray)
    // ==========================================


    for (int i = 0; i < 3; i++)
    {
        float x = 400.0f + (i * 100.0f);
        float baseY = 160.0f;

        // --- PEDESTAL ---
        // Lower Base
        glColor3f(0.7f, 0.7f, 0.75f);
        glBegin(GL_QUADS);
        glVertex2f(x - 14, baseY);
        glVertex2f(x + 14, baseY);
        glVertex2f(x + 12, baseY + 10);
        glVertex2f(x - 12, baseY + 10);
        glEnd();

        // Upper Base
        glColor3f(0.55f, 0.55f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(x - 10, baseY + 10);
        glVertex2f(x + 10, baseY + 10);
        glVertex2f(x + 8, baseY + 18);
        glVertex2f(x - 8, baseY + 18);
        glEnd();

        // --- STRAIGHT JETS (Core Water) ---
        if(fountainsOnM2)
        {
            glColor3f(0.8f, 0.95f, 1.0f); // Light Blue
            glLineWidth(2.0f);
            glBegin(GL_LINES);
            // Center High Jet
            glVertex2f(x, baseY + 18);
            glVertex2f(x, baseY + 95);
            // Inner Fan
            glVertex2f(x, baseY + 18);
            glVertex2f(x - 12, baseY + 85);
            glVertex2f(x, baseY + 18);
            glVertex2f(x + 12, baseY + 85);
            // Outer Fan
            glVertex2f(x, baseY + 18);
            glVertex2f(x - 22, baseY + 65);
            glVertex2f(x, baseY + 18);
            glVertex2f(x + 22, baseY + 65);
            glEnd();

            // ---  SPRAY ARCS ---

            // STAGE 3: Top High Spray (Curves down)
            if (fountainStageM2 >= 3)
            {
                glBegin(GL_LINE_STRIP);
                for(int j=0; j<=180; j+=10)
                {
                    float rad = j * 3.1416f / 180.0f;
                    glVertex2f(x + 25 * cos(rad), baseY + 70 + 25 * sin(rad));
                }
                glEnd();
            }

            // STAGE 2: Middle Spray (Wider)
            if (fountainStageM2 >= 2)
            {
                glBegin(GL_LINE_STRIP);
                for(int j=0; j<=180; j+=10)
                {
                    float rad = j * 3.1416f / 180.0f;
                    glVertex2f(x + 35 * cos(rad), baseY + 50 + 20 * sin(rad));
                }
                glEnd();
            }

            // STAGE 1: Low Wide Splash
            if (fountainStageM2 >= 1)
            {
                glBegin(GL_LINE_STRIP);
                for(int j=0; j<=180; j+=10)
                {
                    float rad = j * 3.1416f / 180.0f;
                    glVertex2f(x + 45 * cos(rad), baseY + 30 + 15 * sin(rad));
                }
                glEnd();
            }
        }

        // ==========================================
        // BUILDING 1 (Tall Left Tower + Windows)
        // ==========================================

        // --- SIDE FACE---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.37f, 0.56f, 0.62f);
        glBegin(GL_QUADS);
        glVertex2f(420, 590);
        glVertex2f(430, 580);
        glVertex2f(430, 285);
        glVertex2f(420, 280);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(420, 590);
        glVertex2f(430, 580);
        glVertex2f(430, 285);
        glVertex2f(420, 280);
        glEnd();

        // --- FRONT FACE (Main) ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.94f, 0.93f);
        glBegin(GL_QUADS);
        glVertex2f(360, 590);
        glVertex2f(420, 590);
        glVertex2f(420, 280);
        glVertex2f(360, 280);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(360, 590);
        glVertex2f(420, 590);
        glVertex2f(420, 280);
        glVertex2f(360, 280);
        glEnd();

        // ==========================================
        // WINDOWS (Controlled by GL_LIGHT2)
        // ==========================================


        if(!isDayM2 && lampsOnM2)
        {
            // VISUAL: Make the window polygons yellow
            glColor3f(1.0f, 0.85f, 0.5f);

            // LIGHT SOURCE: Enable Light 2
            glEnable(GL_LIGHT2);

            // Position
            GLfloat windowPos[] = { 500.0f, 400.0f, 250.0f, 1.0f };
            glLightfv(GL_LIGHT2, GL_POSITION, windowPos);


            GLfloat windowDiffuse[]  = { 0.2f, 0.18f, 0.1f, 1.0f };
            GLfloat windowSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
            GLfloat windowAmbient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };

            glLightfv(GL_LIGHT2, GL_DIFFUSE, windowDiffuse);
            glLightfv(GL_LIGHT2, GL_SPECULAR, windowSpecular);
            glLightfv(GL_LIGHT2, GL_AMBIENT, windowAmbient);

            glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0f);
            glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.01f);
            glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.001f);
        }
        else
        {
            // Day mode or lamps off
            glColor3f(0.3f, 0.6f, 0.9f);
            glDisable(GL_LIGHT2);
        }

        glBegin(GL_QUADS);
        for(int row = 0; row < 29; row++)
        {
            float yTop = 575 - (row * 10);
            float yBot = 570 - (row * 10);

            for(int col = 0; col < 3; col++)
            {
                float xLeft = 368 + (col * 16);
                float xRight = 378 + (col * 16);

                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
            }
        }
        glEnd();

        // Windows Outline (Black)
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int row = 0; row < 29; row++)
        {
            float yTop = 575 - (row * 10);
            float yBot = 570 - (row * 10);

            for(int col = 0; col < 3; col++)
            {
                float xLeft = 368 + (col * 16);
                float xRight = 378 + (col * 16);

                glBegin(GL_LINE_LOOP);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
                glEnd();
            }
        }

        // ==========================================
        // BUILDING 2 (Blue Tower with Windows)
        // ==========================================

        float b2r = 0.07f, b2g = 0.47f, b2b = 0.7f;

        // --- PART 1: MAIN BODY ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(b2r, b2g, b2b);
        glBegin(GL_QUADS);
        glVertex2f(220, 450);
        glVertex2f(265, 450);
        glVertex2f(265, 295);
        glVertex2f(220, 295);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(220, 450);
        glVertex2f(265, 450);
        glVertex2f(265, 295);
        glVertex2f(220, 295);
        glEnd();

        // --- PART 2: ROOF/TOP DETAIL ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(b2r, b2g, b2b);
        glBegin(GL_QUADS);
        glVertex2f(227, 460);
        glVertex2f(257, 460);
        glVertex2f(257, 450);
        glVertex2f(227, 450);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(227, 460);
        glVertex2f(257, 460);
        glVertex2f(257, 450);
        glVertex2f(227, 450);
        glEnd();

        // --- WINDOWS ---

        if(!isDayM2 && lampsOnM2)
        {
            // Night mode with lamps on: Warm yellow/orange glow
            glColor3f(1.0f, 0.85f, 0.5f); // Warm yellow/orange
        }
        else
        {
            // Day mode or lamps off: Light Cyan
            glColor3f(0.8f, 0.9f, 1.0f);
        }
        glBegin(GL_QUADS);
        for(int row = 0; row < 12; row++)
        {
            float yTop = 443 - (row * 11);
            float yBot = 432 - (row * 11);

            for(int col = 0; col < 3; col++)
            {
                float xLeft = 225 + (col * 14);
                float xRight = 233 + (col * 14);

                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
            }
        }
        glEnd();

        // Window Outline (Black)
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int row = 0; row < 12; row++)
        {
            float yTop = 443 - (row * 11);
            float yBot = 432 - (row * 11);

            for(int col = 0; col < 3; col++)
            {
                float xLeft = 225 + (col * 14);
                float xRight = 233 + (col * 14);

                glBegin(GL_LINE_LOOP);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
                glEnd();
            }
        }

        // ==========================================
        // BUILDING 6 (Blue Tapered Building)
        // ==========================================

        // Body

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.04f, 0.42f, 0.62f);
        glBegin(GL_QUADS);
        glVertex2f(640, 430);
        glVertex2f(680, 430);
        glVertex2f(670, 290);
        glVertex2f(640, 290);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(640, 430);
        glVertex2f(680, 430);
        glVertex2f(670, 290);
        glVertex2f(640, 290);
        glEnd();


        glColor3f(1.0f, 1.0f, 1.0f); // White
        glLineWidth(1.0f);
        glBegin(GL_LINES);
        for(int i = 0; i < 15; i++)
        {
            float y = 422.0f - (i * 8.0f);

            glVertex2f(647, y);
            glVertex2f(674, y);
        }
        glEnd();


        // ==========================================
        // BUILDING 3 (Yellow Tower with Double Windows)
        // ==========================================

        // --- SIDE FACE ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.91f, 0.54f, 0.18f);
        glBegin(GL_QUADS);
        glVertex2f(660, 520);
        glVertex2f(670, 530);
        glVertex2f(670, 280);
        glVertex2f(660, 290);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(660, 520);
        glVertex2f(670, 530);
        glVertex2f(670, 280);
        glVertex2f(660, 290);
        glEnd();

        // --- FRONT FACE (Yellow Main) ---


        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.99f, 0.86f, 0.36f);
        glBegin(GL_QUADS);
        glVertex2f(670, 530);
        glVertex2f(710, 530);
        glVertex2f(710, 280);
        glVertex2f(670, 280);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(670, 530);
        glVertex2f(710, 530);
        glVertex2f(710, 280);
        glVertex2f(670, 280);
        glEnd();

        // ==========================================
        // WINDOW SERIES 1 (Upper)
        // ==========================================

        if(!isDayM2 && lampsOnM2)
        {
            glColor3f(1.0f, 0.75f, 0.3f); // Brighter orange/yellow glow
        }
        else
        {
            glColor3f(0.91f, 0.54f, 0.18f); // Orange Fill (day/default)
        }
        glBegin(GL_QUADS);
        for(int row = 0; row < 8; row++)
        {
            float yTop = 520 - (row * 13);
            float yBot = 515 - (row * 13);

            for(int col = 0; col < 2; col++)
            {
                float xLeft = 675 + (col * 18);
                float xRight = 687 + (col * 18);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
            }
        }
        glEnd();

        // Outline Series 1
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int row = 0; row < 8; row++)
        {
            float yTop = 520 - (row * 13);
            float yBot = 515 - (row * 13);
            for(int col = 0; col < 2; col++)
            {
                float xLeft = 675 + (col * 18);
                float xRight = 687 + (col * 18);
                glBegin(GL_LINE_LOOP);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
                glEnd();
            }
        }

        // ==========================================
        // WINDOW SERIES 2 (Lower)
        // ==========================================

        if(!isDayM2 && lampsOnM2)
        {
            glColor3f(1.0f, 0.75f, 0.3f); // Brighter orange/yellow glow
        }
        else
        {
            glColor3f(0.91f, 0.54f, 0.18f); // Orange Fill (day/default)
        }
        glBegin(GL_QUADS);
        for(int row = 0; row < 8; row++)
        {
            float yTop = 395 - (row * 13);
            float yBot = 390 - (row * 13);

            for(int col = 0; col < 2; col++)
            {
                float xLeft = 675 + (col * 18);
                float xRight = 687 + (col * 18);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
            }
        }
        glEnd();

        // Outline Series 2
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int row = 0; row < 8; row++)
        {
            float yTop = 395 - (row * 13);
            float yBot = 390 - (row * 13);
            for(int col = 0; col < 2; col++)
            {
                float xLeft = 675 + (col * 18);
                float xRight = 687 + (col * 18);
                glBegin(GL_LINE_LOOP);
                glVertex2f(xLeft, yTop);
                glVertex2f(xRight, yTop);
                glVertex2f(xRight, yBot);
                glVertex2f(xLeft, yBot);
                glEnd();
            }
        }

        // ==========================================
        // BUILDING 4 ( Teal Tower)
        // ==========================================

        // Colors
        float t4r = 0.51f, t4g = 0.74f, t4b = 0.78f;
        float t4dr = 0.09f, t4dg = 0.50f, t4db = 0.57f;
        float skyR = 0.0f, skyG = 0.6f, skyB = 0.9f; // Sky Color

        // --- MAIN FRONT BODY ---


        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(t4r, t4g, t4b);
        glBegin(GL_QUADS);
        glVertex2f(275, 605); // 95
        glVertex2f(325, 565); // 135
        glVertex2f(325, 275); // 425
        glVertex2f(275, 275); // 425
        glEnd();
        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(275, 605);
        glVertex2f(325, 565);
        glVertex2f(325, 275);
        glVertex2f(275, 275);
        glEnd();

        // --- SIDE STRIP (Dark) ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(t4dr, t4dg, t4db);
        glBegin(GL_QUADS);
        glVertex2f(325, 565);
        glVertex2f(340, 550);
        glVertex2f(340, 285);
        glVertex2f(325, 275);
        glEnd();
        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(325, 565);
        glVertex2f(340, 550);
        glVertex2f(340, 285);
        glVertex2f(325, 275);
        glEnd();

        // --- DARK QUAD PATCH ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(t4dr, t4dg, t4db);
        glBegin(GL_QUADS);
        glVertex2f(280, 590);
        glVertex2f(320, 560);
        glVertex2f(320, 515);
        glVertex2f(280, 545);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(280, 590);
        glVertex2f(320, 560);
        glVertex2f(320, 515);
        glVertex2f(280, 545);
        glEnd();

        // --- LIGHT QUAD PATCH ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(t4r, t4g, t4b);
        glBegin(GL_QUADS);
        glVertex2f(327, 550);
        glVertex2f(337, 540);
        glVertex2f(337, 500);
        glVertex2f(327, 510);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(327, 550);
        glVertex2f(337, 540);
        glVertex2f(337, 500);
        glVertex2f(327, 510);
        glEnd();



        // --- SKY CUTOUT 1 (Top Left) ---

        if(isDayM2) {
            glColor3f(0.0f, 0.6f, 0.9f); // Day sky color
        } else {
            glColor3f(0.10f, 0.13f, 0.22f); // Night sky color
        }
        glBegin(GL_QUADS);
        glVertex2f(282, 580);
        glVertex2f(290, 572);
        glVertex2f(290, 545);
        glVertex2f(280, 545);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(280, 580);
        glVertex2f(290, 572);
        glVertex2f(290, 545);
        glVertex2f(280, 545);
        glEnd();

        // --- 7. SKY CUTOUT 2 (Top Right) ---

        if(isDayM2) {
            glColor3f(0.0f, 0.6f, 0.9f); // Day sky color
        } else {
            glColor3f(0.10f, 0.13f, 0.22f); // Night sky color
        }
        glBegin(GL_QUADS);
        glVertex2f(295, 570);
        glVertex2f(320, 553);
        glVertex2f(320, 545);
        glVertex2f(295, 545);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(295, 570);
        glVertex2f(320, 553);
        glVertex2f(320, 545);
        glVertex2f(295, 545);
        glEnd();



        // --- HORIZONTAL LINES ---

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        for(int i = 0; i < 20; i++)
        {
            float y = 505 - (i * 10);
            glVertex2f(280, y);
            glVertex2f(320, y);
        }
        glEnd();


        // ==========================================
        // BUILDING 5 (Your Exact Code + Right Extension)
        // ==========================================


        // --- PART 1: MAIN CENTER BODY ---
        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.82f, 0.58f);
        glBegin(GL_QUADS);
        glVertex2f(105, 450);
        glVertex2f(145, 450);
        glVertex2f(145, 270);
        glVertex2f(105, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(105, 450);
        glVertex2f(145, 450);
        glVertex2f(145, 270);
        glVertex2f(105, 270);
        glEnd();

        //Side Strip for main Square
        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.76f, 0.65f, 0.45f); // Dark Beige
        glBegin(GL_QUADS);
        glVertex2f(145, 450);
        glVertex2f(155, 445);
        glVertex2f(155, 275);
        glVertex2f(145, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(145, 450);
        glVertex2f(155, 445);
        glVertex2f(155, 275);
        glVertex2f(145, 270);
        glEnd();

        // --- PART 2: BLACK HORIZONTAL LINES ---
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        for(int i = 0; i < 26; i++)
        {
            float y = 435 - (i * 6);
            glVertex2f(110, y);
            glVertex2f(135, y);
        }
        glEnd();

        // --- PART 3: RIGHT WING ---
        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.82f, 0.58f);
        glBegin(GL_QUADS);
        glVertex2f(128, 445);
        glVertex2f(145, 445);
        glVertex2f(145, 270);
        glVertex2f(128, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(128, 445);
        glVertex2f(145, 445);
        glVertex2f(145, 270);
        glVertex2f(128, 270);
        glEnd();

        // --- PART 4: LEFT WING ---
        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.82f, 0.58f);
        glBegin(GL_QUADS);
        glVertex2f(97, 445);
        glVertex2f(110, 445);
        glVertex2f(110, 270);
        glVertex2f(97, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(97, 445);
        glVertex2f(110, 445);
        glVertex2f(110, 270);
        glVertex2f(97, 270);
        glEnd();

        // --- PART 5: SHADOW STRIP ---
        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.76f, 0.65f, 0.45f); // Dark Beige
        glBegin(GL_QUADS);
        glVertex2f(110, 445);
        glVertex2f(116, 440);
        glVertex2f(116, 270);
        glVertex2f(110, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(110, 445);
        glVertex2f(116, 440);
        glVertex2f(116, 270);
        glVertex2f(110, 270);
        glEnd();

        // --- PART 6: WINDOW SERIES 1 (Left) ---
        glColor3f(0.76f, 0.65f, 0.45f); // Dark Beige
        glBegin(GL_QUADS);
        for(int i = 0; i < 15; i++)
        {
            float yTop = 440 - (i * 11);
            float yBot = 435 - (i * 11);
            glVertex2f(101, yTop);
            glVertex2f(106, yTop);
            glVertex2f(106, yBot);
            glVertex2f(101, yBot);
        }
        glEnd();

        // Outlines
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int i = 0; i < 15; i++)
        {
            float yTop = 440 - (i * 11);
            float yBot = 435 - (i * 11);
            glBegin(GL_LINE_LOOP);
            glVertex2f(101, yTop);
            glVertex2f(106, yTop);
            glVertex2f(106, yBot);
            glVertex2f(101, yBot);
            glEnd();
        }

        // --- PART 7: WINDOW SERIES 2 (Right) ---
        glColor3f(0.76f, 0.65f, 0.45f); //Dark Beige
        glBegin(GL_QUADS);
        for(int i = 0; i < 15; i++)
        {
            float yTop = 440 - (i * 11);
            float yBot = 435 - (i * 11);
            glVertex2f(133, yTop);
            glVertex2f(138, yTop);
            glVertex2f(138, yBot);
            glVertex2f(133, yBot);
        }
        glEnd();

        // Outlines
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int i = 0; i < 15; i++)
        {
            float yTop = 440 - (i * 11);
            float yBot = 435 - (i * 11);
            glBegin(GL_LINE_LOOP);
            glVertex2f(133, yTop);
            glVertex2f(138, yTop);
            glVertex2f(138, yBot);
            glVertex2f(133, yBot);
            glEnd();
        }

        // --- PART 8: RIGHT WING EXTENSION (NEW) ---

        // Fill
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.76f, 0.64f, 0.42f);
        glBegin(GL_QUADS);
        glVertex2f(145, 445);
        glVertex2f(158, 438);
        glVertex2f(158, 275);
        glVertex2f(145, 270);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(145, 445);
        glVertex2f(158, 438);
        glVertex2f(158, 275);
        glVertex2f(145, 270);
        glEnd();

        // ==========================================
        // BUILDING 7 (The "Silver Lance" - KL Style)
        // ==========================================

        // --- MAIN BODY (Metallic Silver) ---


        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.75f, 0.75f, 0.75f); // Silver Grey
        glBegin(GL_QUADS);
        glVertex2f(755, 500);
        glVertex2f(775, 500);
        glVertex2f(790, 290);
        glVertex2f(740, 290);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(755, 500);
        glVertex2f(775, 500);
        glVertex2f(790, 290);
        glVertex2f(740, 290);
        glEnd();

        // --- VERTICAL SPINE (Darker Grey) ---

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.50f, 0.55f, 0.60f); // Darker Steel
        glBegin(GL_QUADS);
        glVertex2f(760, 500);
        glVertex2f(770, 500);
        glVertex2f(770, 290);
        glVertex2f(760, 290);
        glEnd();

        // Outline Spine
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(760, 500);
        glVertex2f(770, 500);
        glVertex2f(770, 290);
        glVertex2f(760, 290);
        glEnd();

        // --- HORIZONTAL RINGS ---

        glColor3f(0.85f, 0.75f, 0.40f);
        for(int i = 0; i < 5; i++)
        {
            float y = 330.0f + (i * 40.0f);

            float taperFactor = (y - 290) / 210.0f;
            float currentLeft = 740 + (15 * taperFactor);
            float currentRight = 790 - (15 * taperFactor);

            glBegin(GL_QUADS);
            glVertex2f(currentLeft - 2, y + 4);
            glVertex2f(currentRight + 2, y + 4);
            glVertex2f(currentRight + 2, y - 4);
            glVertex2f(currentLeft - 2, y - 4);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(currentLeft - 2, y + 4);
            glVertex2f(currentRight + 2, y + 4);
            glVertex2f(currentRight + 2, y - 4);
            glVertex2f(currentLeft - 2, y - 4);
            glEnd();
        }

        // --- SPIRE) ---
        glColor3f(0.40f, 0.45f, 0.50f); // Dark Steel
        glBegin(GL_TRIANGLES);
        glVertex2f(762, 500);
        glVertex2f(765, 560); // Tall tip
        glVertex2f(768, 500);
        glEnd();

        // Spire Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(762, 500);
        glVertex2f(765, 560);
        glVertex2f(768, 500);
        glEnd();

        // Antenna Line on top
        glBegin(GL_LINES);
        glVertex2f(765, 560);
        glVertex2f(765, 580);
        glEnd();



        // ==========================================
        // KL TOWER
        // ==========================================

        // MAIN TOWER

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.73f, 0.53f, 0.34f);
        glBegin(GL_QUADS);
        glVertex2f(810, 510);
        glVertex2f(820, 510);
        glVertex2f(826, 278);
        glVertex2f(806, 278);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(810, 510);
        glVertex2f(820, 510);
        glVertex2f(826, 278);
        glVertex2f(806, 278);
        glEnd();

        // LOWER 3RD LAYER

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.44f, 0.31f, 0.17f);
        glBegin(GL_QUADS);
        glVertex2f(789, 548);
        glVertex2f(842, 548);
        glVertex2f(834, 522);
        glVertex2f(796, 522);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(789, 548);
        glVertex2f(842, 548);
        glVertex2f(834, 522);
        glVertex2f(796, 522);
        glEnd();

        // LOWER 2ND LAYER

        glColor3f(0.66f, 0.40f, 0.26f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(815, 518);

        glVertex2f(796, 522);
        glVertex2f(800, 525);
        glVertex2f(805, 526);
        glVertex2f(810, 526);
        glVertex2f(815, 526);
        glVertex2f(820, 526);
        glVertex2f(825, 526);
        glVertex2f(830, 524);
        glVertex2f(834, 522);
        glVertex2f(830, 520);
        glVertex2f(825, 517);
        glVertex2f(824, 514);
        glVertex2f(823, 513);
        glVertex2f(822, 511);
        glVertex2f(821, 510);
        glVertex2f(810, 510);
        glVertex2f(809, 512);
        glVertex2f(808, 514);
        glVertex2f(806, 516);
        glVertex2f(805, 518);
        glVertex2f(802, 520);
        glVertex2f(800, 522);
        glVertex2f(796, 522);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(796, 522);
        glVertex2f(800, 525);
        glVertex2f(805, 526);
        glVertex2f(810, 526);
        glVertex2f(815, 526);
        glVertex2f(820, 526);
        glVertex2f(825, 526);
        glVertex2f(830, 524);
        glVertex2f(834, 522);
        glVertex2f(830, 520);
        glVertex2f(825, 517);
        glVertex2f(824, 514);
        glVertex2f(823, 513);
        glVertex2f(822, 511);
        glVertex2f(821, 510);
        glVertex2f(810, 510);
        glVertex2f(809, 512);
        glVertex2f(808, 514);
        glVertex2f(806, 516);
        glVertex2f(805, 518);
        glVertex2f(802, 520);
        glVertex2f(800, 522);
        glVertex2f(796, 522);
        glEnd();

        // 6TH LOWER LAYER

        glColor3f(0.57f, 0.39f, 0.27f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(807, 574);
        glVertex2f(809, 575);
        glVertex2f(820, 575);
        glVertex2f(822, 574);
        glVertex2f(824, 574);
        glVertex2f(824, 558);
        glVertex2f(808, 558);
        glVertex2f(807, 574);

        glEnd();
        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(807, 574);
        glVertex2f(809, 575);
        glVertex2f(820, 575);
        glVertex2f(822, 574);
        glVertex2f(824, 574);
        glVertex2f(824, 558);
        glVertex2f(808, 558);
        glVertex2f(807, 574);
        glEnd();

        // 5TH LOWER LAYER

        glColor3f(0.73f, 0.53f, 0.34f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(794, 554);
        glVertex2f(796, 556);
        glVertex2f(798, 557);
        glVertex2f(800, 558);
        glVertex2f(802, 559);
        glVertex2f(804, 560);
        glVertex2f(827, 560);
        glVertex2f(829, 559);
        glVertex2f(831, 558);
        glVertex2f(833, 557);
        glVertex2f(835, 556);
        glVertex2f(837, 555);
        glVertex2f(837, 547);
        glVertex2f(794, 547);
        glVertex2f(794, 554);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(794, 554);
        glVertex2f(796, 556);
        glVertex2f(798, 557);
        glVertex2f(800, 558);
        glVertex2f(802, 559);
        glVertex2f(804, 560);
        glVertex2f(827, 560);
        glVertex2f(829, 559);
        glVertex2f(831, 558);
        glVertex2f(833, 557);
        glVertex2f(835, 556);
        glVertex2f(837, 555);
        glVertex2f(837, 547);
        glVertex2f(794, 547);
        glVertex2f(794, 554);
        glEnd();

        // LOWER 4TH LAYER
        glColor3f(0.73f, 0.53f, 0.34f);

        // --- LEFT HALF ---
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(800, 548);

        glVertex2f(815, 554);
        glVertex2f(808, 553);
        glVertex2f(805, 553);
        glVertex2f(801, 552);
        glVertex2f(798, 551);
        glVertex2f(796, 550);
        glVertex2f(793, 549);
        glVertex2f(792, 548);
        glVertex2f(791, 548);
        glVertex2f(790, 547);
        glVertex2f(789, 546);
        glVertex2f(788, 546);
        glVertex2f(787, 546);

        glVertex2f(790, 542);
        glVertex2f(792, 542);
        glVertex2f(793, 543);
        glVertex2f(796, 544);
        glVertex2f(799, 545);
        glVertex2f(802, 546);
        glVertex2f(805, 547);
        glVertex2f(815, 547);
        glEnd();

        // --- RIGHT HALF ---
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(830, 548);

        glVertex2f(815, 554);
        glVertex2f(823, 553);
        glVertex2f(827, 553);
        glVertex2f(830, 552);
        glVertex2f(832, 551);
        glVertex2f(835, 550);
        glVertex2f(838, 549);
        glVertex2f(841, 547);
        glVertex2f(844, 546);

        glVertex2f(842, 542);
        glVertex2f(839, 543);
        glVertex2f(835, 544);
        glVertex2f(831, 546);
        glVertex2f(827, 547);
        glVertex2f(815, 547);
        glEnd();

        // --- OUTLINE ---
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        // Top Edge Left to Right
        glVertex2f(787, 546);
        glVertex2f(788, 546);
        glVertex2f(789, 546);
        glVertex2f(790, 547);
        glVertex2f(791, 548);
        glVertex2f(792, 548);
        glVertex2f(793, 549);
        glVertex2f(796, 550);
        glVertex2f(798, 551);
        glVertex2f(801, 552);
        glVertex2f(805, 553);
        glVertex2f(808, 553);
        glVertex2f(815, 554);
        glVertex2f(823, 553);
        glVertex2f(827, 553);
        glVertex2f(830, 552);
        glVertex2f(832, 551);
        glVertex2f(835, 550);
        glVertex2f(838, 549);
        glVertex2f(841, 547);
        glVertex2f(844, 546);

        // Bottom Edge Right to Left
        glVertex2f(842, 542);
        glVertex2f(839, 543);
        glVertex2f(835, 544);
        glVertex2f(831, 546);
        glVertex2f(827, 547);
        glVertex2f(815, 547);
        glVertex2f(805, 547);
        glVertex2f(802, 546);
        glVertex2f(799, 545);
        glVertex2f(796, 544);
        glVertex2f(793, 543);
        glVertex2f(792, 542);
        glVertex2f(790, 542);
        glEnd();

        // LOWER 7TH LAYER

        glColor3f(0.57f, 0.39f, 0.27f);
        glBegin(GL_QUADS);
        glVertex2f(814, 624);
        glVertex2f(817, 624);
        glVertex2f(818, 574);
        glVertex2f(813, 574);
        glEnd();
        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(814, 624);
        glVertex2f(817, 624);
        glVertex2f(818, 574);
        glVertex2f(813, 574);
        glEnd();

        // ANTENNA
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(815, 642);
        glVertex2f(816, 642);
        glVertex2f(816, 624);
        glVertex2f(815, 624);
        glEnd();

        // ==========================================
        // MASJID JAMEK
        // ==========================================

        // --- MAIN BUILDING BODY ---

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_QUADS);
        glVertex2f(845, 320);
        glVertex2f(990, 320);
        glVertex2f(990, 260);
        glVertex2f(845, 260);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(845, 320);
        glVertex2f(990, 320);
        glVertex2f(990, 260);
        glVertex2f(845, 260);
        glEnd();

        // --- MAIN BUILDING 2ND LAYER ---

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_QUADS);
        glVertex2f(867, 343);
        glVertex2f(954, 343);
        glVertex2f(954, 320);
        glVertex2f(867, 320);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(867, 343);
        glVertex2f(954, 343);
        glVertex2f(954, 320);
        glVertex2f(867, 320);
        glEnd();

        // --- MINAR (The Tower) ---

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_QUADS);
        glVertex2f(969, 353);
        glVertex2f(984, 353);
        glVertex2f(984, 320);
        glVertex2f(969, 320);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(969, 353);
        glVertex2f(984, 353);
        glVertex2f(984, 320);
        glVertex2f(969, 320);
        glEnd();

        // Layer 2

        glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
        glColor3f(0.45f, 0.55f, 0.56f);
        glBegin(GL_QUADS);
        glVertex2f(965, 362);
        glVertex2f(987, 362);
        glVertex2f(984, 353);
        glVertex2f(969, 353);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(965, 362);
        glVertex2f(987, 362);
        glVertex2f(984, 353);
        glVertex2f(969, 353);
        glEnd();

        // Layer 3
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_QUADS);
        glVertex2f(970, 383);
        glVertex2f(982, 383);
        glVertex2f(982, 362);
        glVertex2f(970, 362);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(970, 383);
        glVertex2f(982, 383);
        glVertex2f(982, 362);
        glVertex2f(970, 362);
        glEnd();

        // Layer 4
        glColor3f(0.45f, 0.55f, 0.56f);
        glBegin(GL_QUADS);
        glVertex2f(966, 391);
        glVertex2f(986, 391);
        glVertex2f(982, 383);
        glVertex2f(970, 383);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(966, 391);
        glVertex2f(986, 391);
        glVertex2f(982, 383);
        glVertex2f(970, 383);
        glEnd();

        // Layer 5
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_QUADS);
        glVertex2f(971, 413);
        glVertex2f(981, 413);
        glVertex2f(981, 391);
        glVertex2f(971, 391);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(971, 413);
        glVertex2f(981, 413);
        glVertex2f(981, 391);
        glVertex2f(971, 391);
        glEnd();

        // Layer 6 (Top Spire)
        glColor3f(0.94f, 0.94f, 0.91f);

        // Top Needle (Rectangle)
        glBegin(GL_QUADS);
        glVertex2f(975, 422);
        glVertex2f(976, 422);
        glVertex2f(976, 432);
        glVertex2f(975, 432);
        glEnd();

        // Bottom Base (Trapezoid)
        glBegin(GL_QUADS);
        glVertex2f(971, 413);
        glVertex2f(981, 413);
        glVertex2f(976, 422);
        glVertex2f(975, 422);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(971, 413);
        glVertex2f(975, 422);
        glVertex2f(975, 432);
        glVertex2f(976, 432);
        glVertex2f(976, 422);
        glVertex2f(981, 413);
        glEnd();

        // --- GOMBUJ (Dome) ---


        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(911, 364);

        // --- LEFT SIDE (Going Up) ---
        glVertex2f(873, 343);
        glVertex2f(873, 364);

        glVertex2f(874, 372);
        glVertex2f(876, 376);
        glVertex2f(878, 379);
        glVertex2f(880, 381);
        glVertex2f(883, 384);
        glVertex2f(886, 386);
        glVertex2f(889, 388);
        glVertex2f(893, 390);
        glVertex2f(897, 391);
        glVertex2f(901, 392);
        glVertex2f(906, 393);

        // --- TOP (Flat Peak) ---
        glVertex2f(911, 393);
        glVertex2f(916, 393);

        // --- RIGHT SIDE (Going Down) ---
        glVertex2f(921, 392);
        glVertex2f(925, 391);
        glVertex2f(929, 390);
        glVertex2f(933, 388);
        glVertex2f(936, 386);
        glVertex2f(939, 384);
        glVertex2f(942, 381);
        glVertex2f(944, 379);
        glVertex2f(946, 376);
        glVertex2f(948, 372);

        glVertex2f(949, 364);
        glVertex2f(949, 343);

        glVertex2f(873, 343);
        glEnd();

        // --- OUTLINE ---
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(873, 343);
        glVertex2f(873, 364);
        glVertex2f(874, 372);
        glVertex2f(876, 376);
        glVertex2f(878, 379);
        glVertex2f(880, 381);
        glVertex2f(883, 384);
        glVertex2f(886, 386);
        glVertex2f(889, 388);
        glVertex2f(893, 390);
        glVertex2f(897, 391);
        glVertex2f(901, 392);
        glVertex2f(906, 393);
        glVertex2f(911, 393);
        glVertex2f(916, 393);
        glVertex2f(921, 392);
        glVertex2f(925, 391);
        glVertex2f(929, 390);
        glVertex2f(933, 388);
        glVertex2f(936, 386);
        glVertex2f(939, 384);
        glVertex2f(942, 381);
        glVertex2f(944, 379);
        glVertex2f(946, 376);
        glVertex2f(948, 372);
        glVertex2f(949, 364);
        glVertex2f(949, 343);
        glVertex2f(873, 343);
        glEnd();

        // Gombuj Needle
        glColor3f(0.94f, 0.94f, 0.91f);
        glBegin(GL_TRIANGLES);
        glVertex2f(908, 393);
        glVertex2f(911, 423);
        glVertex2f(913, 393);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(908, 393);
        glVertex2f(911, 423);
        glVertex2f(913, 393);
        glEnd();


        // --- EXTERIOR DOORS ---


        // 2 sets of 3 doors
        for(int s = 0; s < 2; s++)
        {
            for(int i = 0; i < 3; i++)
            {


                float dX = 855.0f + (i * 18.0f);

                if (s == 1)
                {
                    dX = 855.0f + 74.0f + (i * 18.0f);
                }

                glColor3f(0.45f, 0.55f, 0.56f);
                glBegin(GL_POLYGON);
                glVertex2f(dX, 260);
                glVertex2f(dX, 301);
                glVertex2f(dX + 6, 306);
                glVertex2f(dX + 11, 301);
                glVertex2f(dX + 11, 260);
                glEnd();

                // Door Outline
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINE_LOOP);
                glVertex2f(dX, 260);
                glVertex2f(dX, 301);
                glVertex2f(dX + 6, 306);
                glVertex2f(dX + 11, 301);
                glVertex2f(dX + 11, 260);
                glEnd();
            }
        }

        // ==========================================
        // PETRONAS TWIN TOWERS (Fixed Seams)
        // ==========================================

        for(int t = 0; t < 2; t++)
        {
            float offX = (t == 0) ? 0.0f : 108.0f;

            // --- LAYER 1 ---
            // Q1 (Teal)
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(460 + offX, 510);
            glVertex2f(473 + offX, 512);
            glVertex2f(473 + offX, 275);
            glVertex2f(460 + offX, 275);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(460 + offX, 510);
            glVertex2f(473 + offX, 512);
            glVertex2f(473 + offX, 275);
            glVertex2f(460 + offX, 275);
            glEnd();

            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(473 + offX, 512);
            glVertex2f(489 + offX, 514);
            glVertex2f(489 + offX, 275);
            glVertex2f(473 + offX, 275);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(473 + offX, 512);
            glVertex2f(489 + offX, 514);
            glVertex2f(489 + offX, 275);
            glVertex2f(473 + offX, 275);
            glEnd();

            // Q3 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(489 + offX, 514);
            glVertex2f(505 + offX, 512);
            glVertex2f(505 + offX, 275);
            glVertex2f(489 + offX, 275);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(489 + offX, 514);
            glVertex2f(505 + offX, 512);
            glVertex2f(505 + offX, 275);
            glVertex2f(489 + offX, 275);
            glEnd();

            // Q4 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(505 + offX, 512);
            glVertex2f(520 + offX, 510);
            glVertex2f(520 + offX, 275);
            glVertex2f(505 + offX, 275);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(505 + offX, 512);
            glVertex2f(520 + offX, 510);
            glVertex2f(520 + offX, 275);
            glVertex2f(505 + offX, 275);
            glEnd();

            // --- LAYER 2 ---
            // Q1 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(464 + offX, 555);
            glVertex2f(475 + offX, 557);
            glVertex2f(475 + offX, 512);
            glVertex2f(464 + offX, 510);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(464 + offX, 555);
            glVertex2f(475 + offX, 557);
            glVertex2f(475 + offX, 512);
            glVertex2f(464 + offX, 510);
            glEnd();

            // Q2 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(475 + offX, 557);
            glVertex2f(489 + offX, 559);
            glVertex2f(489 + offX, 515);
            glVertex2f(475 + offX, 512);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(475 + offX, 557);
            glVertex2f(489 + offX, 559);
            glVertex2f(489 + offX, 515);
            glVertex2f(475 + offX, 512);
            glEnd();

            // Q3 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(489 + offX, 559);
            glVertex2f(502 + offX, 557);
            glVertex2f(502 + offX, 512);
            glVertex2f(489 + offX, 515);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(489 + offX, 559);
            glVertex2f(502 + offX, 557);
            glVertex2f(502 + offX, 512);
            glVertex2f(489 + offX, 515);
            glEnd();

            // Q4 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(502 + offX, 557);
            glVertex2f(515 + offX, 555);
            glVertex2f(515 + offX, 510);
            glVertex2f(502 + offX, 512);
            glEnd();
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(502 + offX, 557);
            glVertex2f(515 + offX, 555);
            glVertex2f(515 + offX, 510);
            glVertex2f(502 + offX, 512);
            glEnd();

            // Q1 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(468 + offX, 587);
            glVertex2f(478 + offX, 589);
            glVertex2f(478 + offX, 558);
            glVertex2f(468 + offX, 556);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(468 + offX, 587);
            glVertex2f(478 + offX, 589);
            glVertex2f(478 + offX, 558);
            glVertex2f(468 + offX, 556);
            glEnd();

            // Q2 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(478 + offX, 589);
            glVertex2f(489 + offX, 591);
            glVertex2f(489 + offX, 559);
            glVertex2f(478 + offX, 558); // Fixed
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(478 + offX, 589);
            glVertex2f(489 + offX, 591);
            glVertex2f(489 + offX, 559);
            glVertex2f(478 + offX, 558);
            glEnd();

            // Q3 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(489 + offX, 591);
            glVertex2f(501 + offX, 589);
            glVertex2f(501 + offX, 558);
            glVertex2f(489 + offX, 559);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(489 + offX, 591);
            glVertex2f(501 + offX, 589);
            glVertex2f(501 + offX, 558);
            glVertex2f(489 + offX, 559);
            glEnd();

            // Q4 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(501 + offX, 589);
            glVertex2f(511 + offX, 587);
            glVertex2f(511 + offX, 556);
            glVertex2f(501 + offX, 558);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(501 + offX, 589);
            glVertex2f(511 + offX, 587);
            glVertex2f(511 + offX, 556);
            glVertex2f(501 + offX, 558);
            glEnd();

            // --- LAYER 4 ---
            // Q1 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(473 + offX, 606);
            glVertex2f(481 + offX, 608);
            glVertex2f(481 + offX, 590);
            glVertex2f(473 + offX, 588);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(473 + offX, 606);
            glVertex2f(481 + offX, 608);
            glVertex2f(481 + offX, 590);
            glVertex2f(473 + offX, 588);
            glEnd();

            // Q2 (Teal)
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(481 + offX, 608);
            glVertex2f(489 + offX, 609);
            glVertex2f(489 + offX, 591);
            glVertex2f(481 + offX, 590);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(481 + offX, 608);
            glVertex2f(489 + offX, 609);
            glVertex2f(489 + offX, 591);
            glVertex2f(481 + offX, 590);
            glEnd();

            // Q3 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(489 + offX, 609);
            glVertex2f(498 + offX, 608);
            glVertex2f(498 + offX, 590);
            glVertex2f(489 + offX, 591);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(489 + offX, 609);
            glVertex2f(498 + offX, 608);
            glVertex2f(498 + offX, 590);
            glVertex2f(489 + offX, 591);
            glEnd();

            // Q4 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(498 + offX, 608);
            glVertex2f(507 + offX, 606);
            glVertex2f(507 + offX, 589);
            glVertex2f(498 + offX, 590);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(498 + offX, 608);
            glVertex2f(507 + offX, 606);
            glVertex2f(507 + offX, 589);
            glVertex2f(498 + offX, 590);
            glEnd();

            // --- LAYER 5 ---
            // Q1 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(476 + offX, 620);
            glVertex2f(483 + offX, 620);
            glVertex2f(483 + offX, 609);
            glVertex2f(476 + offX, 608);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(476 + offX, 620);
            glVertex2f(483 + offX, 620);
            glVertex2f(483 + offX, 609);
            glVertex2f(476 + offX, 608);
            glEnd();

            // Q2 (Teal)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(483 + offX, 620);
            glVertex2f(489 + offX, 622);
            glVertex2f(489 + offX, 609);
            glVertex2f(483 + offX, 609);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(483 + offX, 620);
            glVertex2f(489 + offX, 622);
            glVertex2f(489 + offX, 609);
            glVertex2f(483 + offX, 609);
            glEnd();

            // Q3 (Grey)
            glNormal3f(0.0f, 0.0f, 1.0f); // Normal for lighting
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_QUADS);
            glVertex2f(489 + offX, 622);
            glVertex2f(497 + offX, 619);
            glVertex2f(497 + offX, 608);
            glVertex2f(489 + offX, 609);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(489 + offX, 622);
            glVertex2f(497 + offX, 619);
            glVertex2f(497 + offX, 608);
            glVertex2f(489 + offX, 609);
            glEnd();

            // Q4 (Teal)
            glColor3f(0.40f, 0.56f, 0.58f);
            glBegin(GL_QUADS);
            glVertex2f(497 + offX, 619);
            glVertex2f(503 + offX, 620);
            glVertex2f(503 + offX, 607);
            glVertex2f(497 + offX, 608);
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(497 + offX, 619);
            glVertex2f(503 + offX, 620);
            glVertex2f(503 + offX, 607);
            glVertex2f(497 + offX, 608);
            glEnd();



            // --- TRIANGLE FAN (Below Top) ---
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(489 + offX, 625); // Hub

            glVertex2f(480 + offX, 620); // 80
            glVertex2f(480 + offX, 627); // 73
            glVertex2f(482 + offX, 628); // 72
            glVertex2f(484 + offX, 629); // 71
            glVertex2f(495 + offX, 629); // 71
            glVertex2f(497 + offX, 628); // 72
            glVertex2f(499 + offX, 627); // 73
            glVertex2f(499 + offX, 620); // 80
            glVertex2f(480 + offX, 620); // Close
            glEnd();

            // Fan Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(480 + offX, 620);
            glVertex2f(480 + offX, 627);
            glVertex2f(482 + offX, 628);
            glVertex2f(484 + offX, 629);
            glVertex2f(495 + offX, 629);
            glVertex2f(497 + offX, 628);
            glVertex2f(499 + offX, 627);
            glVertex2f(499 + offX, 620);
            glEnd();

            // --- TRIANGLE TOP ---
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_TRIANGLES);
            glVertex2f(484 + offX, 629); // 71
            glVertex2f(489 + offX, 644); // 56
            glVertex2f(497 + offX, 628); // 72
            glEnd();

            // Top Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(484 + offX, 629);
            glVertex2f(489 + offX, 644);
            glVertex2f(497 + offX, 628);
            glEnd();

            // --- CIRCLE ABOVE TOP ---
            glColor3f(0.69f, 0.76f, 0.79f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(489 + offX, 650); // Center
            for(int i = 0; i <= 360; i+=10)
            {
                float theta = i * 3.14159f / 180.0f;
                glVertex2f((489 + offX) + 6 * cos(theta), 650 + 6 * sin(theta));
            }
            glEnd();

            // Circle Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for(int i = 0; i <= 360; i+=10)
            {
                float theta = i * 3.14159f / 180.0f;
                glVertex2f((489 + offX) + 6 * cos(theta), 650 + 6 * sin(theta));
            }
            glEnd();

            // --- ANTENNA ---

            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINES);
            glVertex2f(489 + offX, 650);
            glVertex2f(489 + offX, 680);
            glEnd();
            glLineWidth(1.0f); // Reset width

            // --- LIFT / CENTRAL BODY ---


            // Lift Surface
            glColor3f(0.69f, 0.76f, 0.79f); // Grey Base
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(489 + offX, 394); // Hub

            glVertex2f(473 + offX, 444);
            glVertex2f(475 + offX, 445);
            glVertex2f(477 + offX, 447);
            glVertex2f(480 + offX, 448);
            glVertex2f(499 + offX, 448);
            glVertex2f(501 + offX, 447);
            glVertex2f(503 + offX, 446);
            glVertex2f(505 + offX, 445);

            glVertex2f(505 + offX, 275);
            glVertex2f(473 + offX, 275);
            glVertex2f(473 + offX, 444);
            glEnd();

            // Lift Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(473 + offX, 444);
            glVertex2f(475 + offX, 445);
            glVertex2f(477 + offX, 447);
            glVertex2f(480 + offX, 448);
            glVertex2f(499 + offX, 448);
            glVertex2f(501 + offX, 447);
            glVertex2f(503 + offX, 446);
            glVertex2f(505 + offX, 445);
            glVertex2f(505 + offX, 275);
            glVertex2f(473 + offX, 275);
            glEnd();

            // 20 Horizontal Lines

            glColor3f(0.0f, 0.0f, 0.0f); // Dark Teal Lines
            for(int k = 0; k < 18; k++)
            {
                float yShift = k * 9.0f;

                glBegin(GL_LINE_STRIP);
                glVertex2f(473 + offX, 441 - yShift);
                glVertex2f(475 + offX, 442 - yShift);
                glVertex2f(478 + offX, 443 - yShift);
                glVertex2f(481 + offX, 444 - yShift);
                glVertex2f(497 + offX, 444 - yShift);
                glVertex2f(499 + offX, 443 - yShift);
                glVertex2f(502 + offX, 442 - yShift);
                glVertex2f(505 + offX, 441 - yShift);
                glEnd();
            }
        }

        // ==========================================
        // SKYBRIDGE (Connects the two towers)
        // ==========================================

        // Part 1: Top Bar
        glColor3f(0.69f, 0.76f, 0.79f);
        glBegin(GL_QUADS);
        glVertex2f(514, 455);
        glVertex2f(574, 455);
        glVertex2f(574, 451);
        glVertex2f(514, 451);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Outline
        glVertex2f(514, 455);
        glVertex2f(574, 455);
        glVertex2f(574, 451);
        glVertex2f(514, 451);
        glEnd();

        // Part 2: Glass/Gap
        glColor3f(0.0f, 0.6f, 0.9f);
        glBegin(GL_QUADS);
        glVertex2f(514, 451);
        glVertex2f(574, 451);
        glVertex2f(574, 444);
        glVertex2f(514, 444);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Box Outline
        glVertex2f(514, 451);
        glVertex2f(574, 451);
        glVertex2f(574, 444);
        glVertex2f(514, 444);
        glEnd();

        // Part 3: Bottom Bar
        glColor3f(0.69f, 0.76f, 0.79f);
        glBegin(GL_QUADS);
        glVertex2f(514, 444);
        glVertex2f(574, 444);
        glVertex2f(574, 440);
        glVertex2f(514, 440);

        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Outline
        glVertex2f(514, 444);
        glVertex2f(574, 444);
        glVertex2f(574, 440);
        glVertex2f(514, 440);
        glEnd();

        // Part 4: Center Support/Detail
        glColor3f(0.69f, 0.76f, 0.79f);
        glBegin(GL_QUADS);
        glVertex2f(541, 451);
        glVertex2f(547, 451);
        glVertex2f(547, 444);
        glVertex2f(541, 444);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Outline
        glVertex2f(541, 451);
        glVertex2f(547, 451);
        glVertex2f(547, 444);
        glVertex2f(541, 444);
        glEnd();

        // ===========================
        // SKYBRIDGE SUPPORTS
        // ===========================

        // --- SUPPORT 1 (Left Leg) ---

        glColor3f(0.69f, 0.76f, 0.79f); // Grey
        glBegin(GL_POLYGON);
        glVertex2f(540, 440);
        glVertex2f(543, 440);
        glVertex2f(543, 437);
        glVertex2f(520, 401);
        glVertex2f(520, 406);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(540, 440);
        glVertex2f(543, 440);
        glVertex2f(543, 437);
        glVertex2f(520, 401);
        glVertex2f(520, 406);
        glEnd();

        // --- SUPPORT 2 (Right Leg) ---

        glColor3f(0.69f, 0.76f, 0.79f); // Grey
        glBegin(GL_POLYGON);
        glVertex2f(543, 440);
        glVertex2f(546, 440);
        glVertex2f(568.5f, 406);
        glVertex2f(568.5f, 401);
        glVertex2f(543, 437);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(543, 440);
        glVertex2f(546, 440);
        glVertex2f(568.5f, 406);
        glVertex2f(568.5f, 401);
        glVertex2f(543, 437);
        glEnd();

        // ==========================================
        // SURIA KLCC (Base & Entrance) - Fixed Gap
        // ==========================================


        // --- 1. LEFT WING FRONT ---

        // Shape 1 (Far Left)

        glColor3f(0.976f, 0.839f, 0.510f);
        glBegin(GL_POLYGON);
        glVertex2f(341, 305);
        glVertex2f(405, 297);
        glVertex2f(405, 250);
        glVertex2f(341, 264);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(341, 305);
        glVertex2f(405, 297);
        glVertex2f(405, 250);
        glVertex2f(341, 264);
        glEnd();


        // Shape 2 (Inner Left)


        glColor3f(0.976f, 0.839f, 0.510f);
        glBegin(GL_POLYGON);
        glVertex2f(405, 297);
        glVertex2f(510, 303);
        glVertex2f(510, 259);
        glVertex2f(405, 250);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(405, 297);
        glVertex2f(510, 303);
        glVertex2f(510, 259);
        glVertex2f(405, 250);
        glEnd();


        // --- 2. CENTER ENTRANCE STRUCTURE ---


        glColor3f(0.976f, 0.839f, 0.510f); // Main Building Color
        glBegin(GL_QUADS);
        glVertex2f(510, 318); // Top Left
        glVertex2f(576, 318); // Top Right
        glVertex2f(576, 259); // Bottom Right
        glVertex2f(510, 259); // Bottom Left
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(510, 318);
        glVertex2f(576, 318);
        glVertex2f(576, 259);
        glVertex2f(510, 259);
        glEnd();

        // Center Line

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(510, 312);
        glVertex2f(576, 312);
        glEnd();

        // Center Cyan Block


        glColor3f(0.467f, 0.765f, 0.859f); // Cyan
        glBegin(GL_QUADS);
        glVertex2f(510, 305);
        glVertex2f(576, 305);
        glVertex2f(576, 282);
        glVertex2f(510, 282);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(510, 305);
        glVertex2f(576, 305);
        glVertex2f(576, 282);
        glVertex2f(510, 282);
        glEnd();



        // Vertical Lines in Cyan Block

        glBegin(GL_LINES);
        glVertex2f(532, 305);
        glVertex2f(532, 282);
        glVertex2f(554, 305);
        glVertex2f(555, 282);

        glEnd();



        // Dark Grey Bottom Strip

        glColor3f(0.420f, 0.459f, 0.427f); // Dark Grey
        glBegin(GL_QUADS);
        glVertex2f(510, 276);
        glVertex2f(576, 276);
        glVertex2f(576, 260);
        glVertex2f(510, 260);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(510, 276);
        glVertex2f(576, 276);
        glVertex2f(576, 260);
        glVertex2f(510, 260);
        glEnd();



        // Pillars inside Dark Grey Strip

        // Left Pillar

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_QUADS);
        glVertex2f(530, 276);
        glVertex2f(534, 276);
        glVertex2f(534, 260);
        glVertex2f(530, 260);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(530, 276);
        glVertex2f(534, 276);
        glVertex2f(534, 260);
        glVertex2f(530, 260);
        glEnd();



        // Right Pillar

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_QUADS);
        glVertex2f(552, 276);
        glVertex2f(556, 276);
        glVertex2f(556, 260);
        glVertex2f(552, 260);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(552, 276);
        glVertex2f(556, 276);
        glVertex2f(556, 260);
        glVertex2f(552, 260);
        glEnd();

        // --- RIGHT WING FRONT  ---


        glColor3f(0.976f, 0.839f, 0.510f);// Cyan
        glBegin(GL_POLYGON);
        glVertex2f(577, 302);
        glVertex2f(680, 295);
        glVertex2f(680, 247);
        glVertex2f(577, 259);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(577, 302);
        glVertex2f(680, 295);
        glVertex2f(680, 247);
        glVertex2f(577, 259);
        glEnd();



        // Shape 9 (Far Right)



        glColor3f(0.976f, 0.839f, 0.510f); // Cyan
        glBegin(GL_POLYGON);
        glVertex2f(680, 295);
        glVertex2f(744, 304);
        glVertex2f(744, 263);
        glVertex2f(680, 247);
        glEnd();

        // Outline

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(680, 295);
        glVertex2f(744, 304);
        glVertex2f(744, 263);
        glVertex2f(680, 247);
        glEnd();



        // --- 4. ROOF CONNECTORS ---

        // Connector 1

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_POLYGON);
        glVertex2f(341, 320);
        glVertex2f(413, 313);
        glVertex2f(413, 296);
        glVertex2f(341, 305);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(341, 320); // Changed from 351
        glVertex2f(413, 313);
        glVertex2f(413, 296);
        glVertex2f(341, 305); // Changed from 351
        glEnd();



        // Connector 2

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_POLYGON);
        glVertex2f(413, 313);
        glVertex2f(510, 318);
        glVertex2f(510, 303);
        glVertex2f(413, 298);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(413, 313);
        glVertex2f(510, 318);
        glVertex2f(510, 303);
        glVertex2f(413, 298);
        glEnd();


        // Connector 3

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_POLYGON);
        glVertex2f(576, 318);
        glVertex2f(673, 311);
        glVertex2f(673, 295);
        glVertex2f(576, 303);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(576, 318);
        glVertex2f(673, 311);
        glVertex2f(673, 295);
        glVertex2f(576, 303);
        glEnd();

        // Connector 4

        glColor3f(0.976f, 0.839f, 0.510f); // Main Color
        glBegin(GL_POLYGON);
        glVertex2f(673, 311);
        glVertex2f(733, 317);
        glVertex2f(734, 302);
        glVertex2f(673, 295);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(673, 311);
        glVertex2f(733, 317);
        glVertex2f(734, 302);
        glVertex2f(673, 295);
        glEnd();

        // ==========================================
        // ROOF
        // ==========================================

        glColor3f(0.976f, 0.839f, 0.510f); // Beige
        glBegin(GL_TRIANGLE_FAN);

        // Hub
        glVertex2f(540, 321);

        // Vertices
        glVertex2f(341, 320);
        glVertex2f(468, 323);
        glVertex2f(624, 323);
        glVertex2f(733, 317);
        glVertex2f(673, 311);
        glVertex2f(576, 318);
        glVertex2f(510, 318);
        glVertex2f(510, 318); // Duplicate point from list
        glVertex2f(413, 313);
        glVertex2f(341, 320); // Closing loop

        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(341, 320);
        glVertex2f(468, 323);
        glVertex2f(624, 323);
        glVertex2f(733, 317);
        glVertex2f(673, 311);
        glVertex2f(576, 318);
        glVertex2f(510, 318);
        glVertex2f(510, 318);
        glVertex2f(413, 313);
        glVertex2f(341, 320);
        glEnd();

        // --- 5. DOORS ---


        // LEFT DOOR

        // Side 1

        glColor3f(0.584f, 0.655f, 0.671f);
        glBegin(GL_POLYGON);
        glVertex2f(360, 272);
        glVertex2f(368, 273);
        glVertex2f(368, 258);
        glVertex2f(360, 260);

        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(360, 272);
        glVertex2f(368, 273);
        glVertex2f(368, 258);
        glVertex2f(360, 260);
        glEnd();

        // Side 2
        glColor3f(0.584f, 0.655f, 0.671f);
        glBegin(GL_POLYGON);
        glVertex2f(377, 271);
        glVertex2f(387, 273);
        glVertex2f(387, 254);
        glVertex2f(377, 256);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(377, 271);
        glVertex2f(387, 273);
        glVertex2f(387, 254);
        glVertex2f(377, 256);

        glEnd();



        //Door Front
        glColor3f(0.757f, 0.761f, 0.780f);
        glBegin(GL_POLYGON);
        glVertex2f(368, 273);
        glVertex2f(377, 271);
        glVertex2f(377, 256);
        glVertex2f(368, 258);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(368, 273);
        glVertex2f(377, 271);
        glVertex2f(377, 256);
        glVertex2f(368, 258);
        glEnd();

        // Top

        glColor3f(0.757f, 0.761f, 0.780f);
        glBegin(GL_POLYGON);
        glVertex2f(365, 278);
        glVertex2f(387, 273);
        glVertex2f(377, 268);
        glVertex2f(359, 273);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(365, 278);
        glVertex2f(387, 273);
        glVertex2f(377, 268);
        glVertex2f(359, 273);
        glEnd();



        // RIGHT DOOR

        // Side 1

        glColor3f(0.584f, 0.655f, 0.671f);
        glBegin(GL_POLYGON);
        glVertex2f(698, 271);
        glVertex2f(707, 267);
        glVertex2f(707, 253);
        glVertex2f(698, 252);
        glEnd();


        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(698, 271);
        glVertex2f(707, 267);
        glVertex2f(707, 253);
        glVertex2f(698, 252);
        glEnd();

        // Side 2

        glColor3f(0.584f, 0.655f, 0.671f);
        glBegin(GL_POLYGON);
        glVertex2f(717, 271);
        glVertex2f(725, 272);
        glVertex2f(725, 258);
        glVertex2f(717, 256);
        glEnd();


        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(717, 271);
        glVertex2f(725, 272);
        glVertex2f(725, 258);
        glVertex2f(717, 256);
        glEnd();

        // Top

        glColor3f(0.757f, 0.761f, 0.780f);
        glBegin(GL_POLYGON);
        glVertex2f(698, 271);
        glVertex2f(721, 275);
        glVertex2f(727, 271);
        glVertex2f(707, 267);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(698, 271);
        glVertex2f(721, 275);
        glVertex2f(727, 271);
        glVertex2f(707, 267);
        glEnd();

        // ==========================================
        // 6. WINDOWS
        // ==========================================

        // --- WINDOW GROUP 1 (Far Left / Far Right) ---

        // Left Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(417, 292);
        glVertex2f(433, 293);
        glVertex2f(433, 286);
        glVertex2f(417, 285);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(417, 292);
        glVertex2f(433, 293);
        glVertex2f(433, 286);
        glVertex2f(417, 285);
        glEnd();

        // Left Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(417, 274);
        glVertex2f(433, 275);
        glVertex2f(433, 268);
        glVertex2f(417, 267);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(417, 274);
        glVertex2f(433, 275);
        glVertex2f(433, 268);
        glVertex2f(417, 267);
        glEnd();

        // Right Top (Mirrored)
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(668, 292);
        glVertex2f(652, 293);
        glVertex2f(652, 286);
        glVertex2f(668, 285);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(668, 292);
        glVertex2f(652, 293);
        glVertex2f(652, 286);
        glVertex2f(668, 285);
        glEnd();

        // Right Bottom (Mirrored)
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(668, 274);
        glVertex2f(652, 275);
        glVertex2f(652, 268);
        glVertex2f(668, 267);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(668, 274);
        glVertex2f(652, 275);
        glVertex2f(652, 268);
        glVertex2f(668, 267);
        glEnd();

        // WINDOW GROUP 2

        // Left Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(433, 293);
        glVertex2f(450, 294);
        glVertex2f(450, 287);
        glVertex2f(433, 286);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(433, 293);
        glVertex2f(450, 294);
        glVertex2f(450, 287);
        glVertex2f(433, 286);
        glEnd();

        // Left Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(433, 275);
        glVertex2f(450, 276);
        glVertex2f(450, 269);
        glVertex2f(433, 268);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(433, 275);
        glVertex2f(450, 276);
        glVertex2f(450, 269);
        glVertex2f(433, 268);
        glEnd();

        // Right Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(652, 293);
        glVertex2f(635, 294);
        glVertex2f(635, 287);
        glVertex2f(652, 286);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(652, 293);
        glVertex2f(635, 294);
        glVertex2f(635, 287);
        glVertex2f(652, 286);
        glEnd();

        // Right Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(652, 275);
        glVertex2f(635, 276);
        glVertex2f(635, 269);
        glVertex2f(652, 268);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(652, 275);
        glVertex2f(635, 276);
        glVertex2f(635, 269);
        glVertex2f(652, 268);
        glEnd();


        // --- WINDOW GROUP 3 ---

        // Left Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(450, 294);
        glVertex2f(468, 295);
        glVertex2f(468, 288);
        glVertex2f(450, 287);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(450, 294);
        glVertex2f(468, 295);
        glVertex2f(468, 288);
        glVertex2f(450, 287);
        glEnd();

        // Left Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(450, 276);
        glVertex2f(468, 277);
        glVertex2f(468, 270);
        glVertex2f(450, 269);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(450, 276);
        glVertex2f(468, 277);
        glVertex2f(468, 270);
        glVertex2f(450, 269);
        glEnd();

        // Right Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(635, 294);
        glVertex2f(617, 295);
        glVertex2f(617, 288);
        glVertex2f(635, 287);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(635, 294);
        glVertex2f(617, 295);
        glVertex2f(617, 288);
        glVertex2f(635, 287);
        glEnd();

        // Right Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(635, 276);
        glVertex2f(617, 277);
        glVertex2f(617, 270);
        glVertex2f(635, 269);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(635, 276);
        glVertex2f(617, 277);
        glVertex2f(617, 270);
        glVertex2f(635, 269);
        glEnd();

        // Window Group 4 Left Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(468, 295);
        glVertex2f(484, 296);
        glVertex2f(484, 289);
        glVertex2f(468, 288);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(468, 295);
        glVertex2f(484, 296);
        glVertex2f(484, 289);
        glVertex2f(468, 288);
        glEnd();

        // Window Group 4 Left Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(468, 277);
        glVertex2f(484, 278);
        glVertex2f(484, 271);
        glVertex2f(468, 270);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(468, 277);
        glVertex2f(484, 278);
        glVertex2f(484, 271);
        glVertex2f(468, 270);
        glEnd();

        // Window Group 4 Right Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(617, 295);
        glVertex2f(601, 296);
        glVertex2f(601, 289);
        glVertex2f(617, 288);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(617, 295);
        glVertex2f(601, 296);
        glVertex2f(601, 289);
        glVertex2f(617, 288);
        glEnd();

        // Window Group 4 Right Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(617, 277);
        glVertex2f(601, 278);
        glVertex2f(601, 271);
        glVertex2f(617, 270);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(617, 277);
        glVertex2f(601, 278);
        glVertex2f(601, 271);
        glVertex2f(617, 270);
        glEnd();

        // Window Group 5 Left Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(484, 296);
        glVertex2f(499, 297);
        glVertex2f(499, 290);
        glVertex2f(484, 289);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(484, 296);
        glVertex2f(499, 297);
        glVertex2f(499, 290);
        glVertex2f(484, 289);
        glEnd();

        // Window Group 5 Left Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(484, 278);
        glVertex2f(499, 279);
        glVertex2f(499, 272);
        glVertex2f(484, 271);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(484, 278);
        glVertex2f(499, 279);
        glVertex2f(499, 272);
        glVertex2f(484, 271);
        glEnd();

        // Window Group 5 Right Top
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(601, 296);
        glVertex2f(586, 297);
        glVertex2f(586, 290);
        glVertex2f(601, 289);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(601, 296);
        glVertex2f(586, 297);
        glVertex2f(586, 290);
        glVertex2f(601, 289);
        glEnd();

        // Window Group 5 Right Bottom
        glColor3f(0.467f, 0.765f, 0.859f);
        glBegin(GL_POLYGON);
        glVertex2f(601, 278);
        glVertex2f(586, 279);
        glVertex2f(586, 272);
        glVertex2f(601, 271);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(601, 278);
        glVertex2f(586, 279);
        glVertex2f(586, 272);
        glVertex2f(601, 271);
        glEnd();

        // ==========================================
        // METRO TRACK & PILLARS (Hardcoded Colors)
        // ==========================================

        // --- 1. MAIN TRACK (Horizontal Strip) ---
        glColor3f(0.67f, 0.675f, 0.65f);
        glBegin(GL_QUADS);
        glVertex2f(0, 336);
        glVertex2f(1000, 336);
        glVertex2f(1000, 325);
        glVertex2f(0, 325);
        glEnd();

        // Track Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 336);
        glVertex2f(1000, 336);
        glVertex2f(1000, 325);
        glVertex2f(0, 325);
        glEnd();

        // --- 2. PILLARS & SUPPORTS (Repeated 4 times) ---

        for(int i = 0; i <= 4; i++)
        {
            float xShift = i * 210.0f;

            // --- SUPPORT BASE (Trapezoid) ---

            glColor3f(0.67f, 0.675f, 0.65f);
            glBegin(GL_POLYGON);
            glVertex2f(65 + xShift, 325);
            glVertex2f(95 + xShift, 325);
            glVertex2f(90 + xShift, 313);
            glVertex2f(70 + xShift, 313);
            glEnd();

            // Support Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(65 + xShift, 325);
            glVertex2f(95 + xShift, 325);
            glVertex2f(90 + xShift, 313);
            glVertex2f(70 + xShift, 313);
            glEnd();

            // --- VERTICAL PILLAR ---

            glColor3f(0.67f, 0.675f, 0.65f);
            glBegin(GL_QUADS);
            glVertex2f(74 + xShift, 313);
            glVertex2f(86 + xShift, 313);
            glVertex2f(86 + xShift, 247);
            glVertex2f(74 + xShift, 247);
            glEnd();

            // Pillar Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(74 + xShift, 313);
            glVertex2f(86 + xShift, 313);
            glVertex2f(86 + xShift, 247);
            glVertex2f(74 + xShift, 247);
            glEnd();
        }

        // ============================
        // 3 TREES ON THE LEFT SIDE
        // ============================

        for(int i = 0; i < 3; i++)
        {
            float treeShift = i * 86.0f;

            // --- TRUNK ---
            glColor3f(0.56f, 0.33f, 0.15f);
            glBegin(GL_POLYGON);
            glVertex2f(31 + treeShift, 180);
            glVertex2f(43 + treeShift, 180);
            glVertex2f(44 + treeShift, 135);
            glVertex2f(30 + treeShift, 135);
            glEnd();

            // Trunk Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(31 + treeShift, 180);
            glVertex2f(43 + treeShift, 180);
            glVertex2f(44 + treeShift, 135);
            glVertex2f(30 + treeShift, 135);
            glEnd();

            // --- LOWER FOLIAGE (Big Circle) ---
            drawCircle(37 + treeShift, 204, 33, 0.07f, 0.33f, 0.17f);

            // Lower Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for(int j=0; j<=360; j++)
            {
                float rad = j * 3.1416 / 180.0;
                glVertex2f((37 + treeShift) + 33 * cos(rad), 204 + 33 * sin(rad));
            }
            glEnd();

            // --- UPPER FOLIAGE (Small Circle) ---
            // CHECK IF MIDDLE TREE (i == 1)
            if (i == 1)
            {
                drawCircle(37 + treeShift, 209, 28, 0.38f, 0.65f, 0.24f);
            }
            else
            {
                // Original Dark Green
                drawCircle(37 + treeShift, 209, 28, 0.07f, 0.55f, 0.27f);
            }
        }

        // ==========================================
        // 3 TREES ON THE RIGHT SIDE
        // ==========================================

        glNormal3f(0.0f, 0.0f, 1.0f);

        for(int i = 0; i < 3; i++)
        {
            float xShift = i * 86.0f;

            // --- TRUNK ---
            glColor3f(0.56f, 0.33f, 0.15f);

            float trunkL = 806 + xShift;
            float trunkR = 818 + xShift;
            float trunkY_Bot = 135;
            float trunkY_Top = 180;
            float step = (trunkY_Top - trunkY_Bot) / 5.0f;

            glBegin(GL_QUADS);
            for(int k=0; k<5; k++)
            {
                float y1 = trunkY_Bot + k*step;
                float y2 = trunkY_Bot + (k+1)*step;

                glVertex2f(trunkL, y1);
                glVertex2f(trunkR, y1);
                glVertex2f(trunkR, y2);
                glVertex2f(trunkL, y2);
            }
            glEnd();

            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(trunkL, trunkY_Top);
            glVertex2f(trunkR, trunkY_Top);
            glVertex2f(819 + xShift, 135);
            glVertex2f(805 + xShift, 135);
            glEnd();

            // --- LOWER FOLIAGE ---
            glColor3f(0.07f, 0.33f, 0.17f);
            drawCircle(812 + xShift, 204, 33, 0.07f, 0.33f, 0.17f);

            // Lower Outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for(int j=0; j<=360; j+=10)
            {
                float rad = j * 3.1416 / 180.0;
                glVertex2f((812 + xShift) + 33 * cos(rad), 204 + 33 * sin(rad));
            }
            glEnd();

            // --- UPPER FOLIAGE ---
            if (i == 1)
            {
                // Middle Tree Lighter Green
                glColor3f(0.38f, 0.65f, 0.24f);
                drawCircle(812 + xShift, 209, 28, 0.38f, 0.65f, 0.24f);
            }
            else
            {
                // Normal Dark Green
                glColor3f(0.07f, 0.55f, 0.27f);
                drawCircle(812 + xShift, 209, 28, 0.07f, 0.55f, 0.27f);
            }
        }

        // ==========================================
        // MONORAIL / METRO TRAIN
        // ==========================================

        glPushMatrix();
        glTranslatef(trainKLCCX, 0.0f, 0.0f);

        // --- 1. ENGINE / FRONT COACH (Coach 1) ---

        // Main Body
        glColor3f(0.95f, 0.93f, 0.89f);
        glBegin(GL_POLYGON);
        glVertex2f(194, 362);
        glVertex2f(241, 362);
        glVertex2f(241, 359);
        glVertex2f(241, 340);
        glVertex2f(241, 331);
        glVertex2f(189, 331);
        glVertex2f(181, 338);
        glVertex2f(181, 340);
        glVertex2f(181, 343);
        glVertex2f(183, 346);
        glVertex2f(189, 357);
        glVertex2f(191, 359);
        glVertex2f(194, 362);
        glEnd();

        // Outline
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(194, 362);
        glVertex2f(241, 362);
        glVertex2f(241, 359);
        glVertex2f(241, 340);
        glVertex2f(241, 331);
        glVertex2f(189, 331);
        glVertex2f(181, 338);
        glVertex2f(181, 340);
        glVertex2f(181, 343);
        glVertex2f(183, 346);
        glVertex2f(189, 357);
        glVertex2f(191, 359);
        glVertex2f(194, 362);
        glEnd();

        // Inner Designs
        glColor3f(0.87f, 0.16f, 0.13f);
        // Top Stripe
        glBegin(GL_POLYGON);
        glVertex2f(194, 362);
        glVertex2f(241, 362);
        glVertex2f(241, 359);
        glVertex2f(191, 359);
        glEnd();
        // Bottom Stripe
        glBegin(GL_POLYGON);
        glVertex2f(241, 340);
        glVertex2f(241, 331);
        glVertex2f(189, 331);
        glVertex2f(181, 338);
        glVertex2f(181, 340);
        glEnd();

        // Windows

        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange

            glEnable(GL_LIGHT4);
            GLfloat metroPos[] = { 500.0f, 345.0f, 180.0f, 1.0f };
            glLightfv(GL_LIGHT4, GL_POSITION, metroPos);

            // Warm yellow/orange light for metro
            GLfloat metroDiffuse[] = { 1.0f, 0.9f, 0.65f, 1.0f };
            GLfloat metroSpecular[] = { 1.0f, 0.9f, 0.65f, 1.0f };
            GLfloat metroAmbient[] = { 0.35f, 0.3f, 0.2f, 1.0f };
            glLightfv(GL_LIGHT4, GL_DIFFUSE, metroDiffuse);
            glLightfv(GL_LIGHT4, GL_SPECULAR, metroSpecular);
            glLightfv(GL_LIGHT4, GL_AMBIENT, metroAmbient);

            // Attenuation for metro window light
            glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0f);
            glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.008f);
            glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0004f);
        } else {
            // Day mode: Normal blue windows
            glColor3f(0.50f, 0.74f, 0.83f);
            glDisable(GL_LIGHT4);
        }

        // Window 1 (Driver) - 4 points provided
        glBegin(GL_POLYGON);
        glVertex2f(189, 357);
        glVertex2f(195, 357);
        glVertex2f(195, 346);
        glVertex2f(183, 346);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(189, 357);
        glVertex2f(195, 357);
        glVertex2f(195, 346);
        glVertex2f(183, 346);
        glEnd();

        // Window 2
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(215, 357);
        glVertex2f(224, 357);
        glVertex2f(224, 348);
        glVertex2f(215, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(215, 357);
        glVertex2f(224, 357);
        glVertex2f(224, 348);
        glVertex2f(215, 348);
        glEnd();

        // Window 3
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(228, 357);
        glVertex2f(237, 357);
        glVertex2f(237, 348);
        glVertex2f(228, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(228, 357);
        glVertex2f(237, 357);
        glVertex2f(237, 348);
        glVertex2f(228, 348);
        glEnd();

        // Doors
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Left Panel
        glVertex2f(199, 357);
        glVertex2f(205, 357);
        glVertex2f(205, 340);
        glVertex2f(199, 340);
        glEnd();
        glBegin(GL_POLYGON); // Right Panel
        glVertex2f(205, 357);
        glVertex2f(210, 357);
        glVertex2f(210, 340);
        glVertex2f(205, 340);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(199, 357);
        glVertex2f(210, 357);
        glVertex2f(210, 340);
        glVertex2f(199, 340);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(205, 357);
        glVertex2f(205, 340);
        glEnd(); // Center line

        // --- 2. COACH CONNECTOR 1 ---
        glColor3f(0.30f, 0.31f, 0.27f);
        glBegin(GL_POLYGON);
        glVertex2f(241, 359);
        glVertex2f(248, 359);
        glVertex2f(248, 334);
        glVertex2f(241, 334);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(241, 359);
        glVertex2f(248, 359);
        glVertex2f(248, 334);
        glVertex2f(241, 334);
        glEnd();

        // --- 3. COACH 2 (Middle) ---

        // Body
        glColor3f(0.95f, 0.93f, 0.89f);
        glBegin(GL_POLYGON);
        glVertex2f(248, 362);
        glVertex2f(295, 362);
        glVertex2f(295, 331);
        glVertex2f(248, 331);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(248, 362);
        glVertex2f(295, 362);
        glVertex2f(295, 331);
        glVertex2f(248, 331);
        glEnd();

        // Inner Designs (Red)
        glColor3f(0.87f, 0.16f, 0.13f);
        glBegin(GL_POLYGON); // Top Stripe
        glVertex2f(248, 362);
        glVertex2f(295, 362);
        glVertex2f(295, 359);
        glVertex2f(248, 359);
        glEnd();
        glBegin(GL_POLYGON); // Bottom Stripe
        glVertex2f(248, 340);
        glVertex2f(295, 340);
        glVertex2f(295, 331);
        glVertex2f(248, 331);
        glEnd();

        // Windows (Coach 2)
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Left
        glVertex2f(252, 356);
        glVertex2f(261, 356);
        glVertex2f(261, 348);
        glVertex2f(252, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Left Outline
        glVertex2f(252, 356);
        glVertex2f(261, 356);
        glVertex2f(261, 348);
        glVertex2f(252, 348);
        glEnd();

        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Right
        glVertex2f(281, 356);
        glVertex2f(290, 356);
        glVertex2f(290, 348);
        glVertex2f(281, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); // Right Outline
        glVertex2f(281, 356);
        glVertex2f(290, 356);
        glVertex2f(290, 348);
        glVertex2f(281, 348);
        glEnd();

        // Doors (Coach 2)
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Left Panel
        glVertex2f(265, 356);
        glVertex2f(271, 356);
        glVertex2f(271, 340);
        glVertex2f(265, 340);
        glEnd();
        glBegin(GL_POLYGON); // Right Panel
        glVertex2f(271, 356);
        glVertex2f(277, 356);
        glVertex2f(277, 340);
        glVertex2f(271, 340);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(265, 356);
        glVertex2f(277, 356);
        glVertex2f(277, 340);
        glVertex2f(265, 340);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(271, 356);
        glVertex2f(271, 340);
        glEnd();

        // --- 4. COACH CONNECTOR 2 ---
        glColor3f(0.30f, 0.31f, 0.27f);
        glBegin(GL_POLYGON);
        glVertex2f(295, 359);
        glVertex2f(302, 359);
        glVertex2f(302, 334);
        glVertex2f(295, 334);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(295, 359);
        glVertex2f(302, 359);
        glVertex2f(302, 334);
        glVertex2f(295, 334);
        glEnd();

        // --- 5. COACH 3 (Replica of Coach 2) ---
        float c3 = 54.0f;

        // Body
        glColor3f(0.95f, 0.93f, 0.89f);
        glBegin(GL_POLYGON);
        glVertex2f(248+c3, 362);
        glVertex2f(295+c3, 362);
        glVertex2f(295+c3, 331);
        glVertex2f(248+c3, 331);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(248+c3, 362);
        glVertex2f(295+c3, 362);
        glVertex2f(295+c3, 331);
        glVertex2f(248+c3, 331);
        glEnd();

        // Red Stripes
        glColor3f(0.87f, 0.16f, 0.13f);
        glBegin(GL_POLYGON);
        glVertex2f(248+c3, 362);
        glVertex2f(295+c3, 362);
        glVertex2f(295+c3, 359);
        glVertex2f(248+c3, 359);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(248+c3, 340);
        glVertex2f(295+c3, 340);
        glVertex2f(295+c3, 331);
        glVertex2f(248+c3, 331);
        glEnd();

        // Windows
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Left
        glVertex2f(252+c3, 356);
        glVertex2f(261+c3, 356);
        glVertex2f(261+c3, 348);
        glVertex2f(252+c3, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(252+c3, 356);
        glVertex2f(261+c3, 356);
        glVertex2f(261+c3, 348);
        glVertex2f(252+c3, 348);
        glEnd();

        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON); // Right
        glVertex2f(281+c3, 356);
        glVertex2f(290+c3, 356);
        glVertex2f(290+c3, 348);
        glVertex2f(281+c3, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(281+c3, 356);
        glVertex2f(290+c3, 356);
        glVertex2f(290+c3, 348);
        glVertex2f(281+c3, 348);
        glEnd();

        // Doors
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(265+c3, 356);
        glVertex2f(277+c3, 356);
        glVertex2f(277+c3, 340);
        glVertex2f(265+c3, 340);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(265+c3, 356);
        glVertex2f(277+c3, 356);
        glVertex2f(277+c3, 340);
        glVertex2f(265+c3, 340);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(271+c3, 356);
        glVertex2f(271+c3, 340);
        glEnd();

        // --- 6. COACH CONNECTOR 3 ---
        // Coach 3 ends at 295+54 = 349
        glColor3f(0.30f, 0.31f, 0.27f);
        glBegin(GL_POLYGON);
        glVertex2f(349, 359);
        glVertex2f(356, 359);
        glVertex2f(356, 334);
        glVertex2f(349, 334);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(349, 359);
        glVertex2f(356, 359);
        glVertex2f(356, 334);
        glVertex2f(349, 334);
        glEnd();

        // --- 7. ENGINE / REAR COACH (Mirrored Coach 1) ---

        // Body
        glColor3f(0.95f, 0.93f, 0.89f);
        glBegin(GL_POLYGON);
        glVertex2f(403, 362);
        glVertex2f(356, 362);
        glVertex2f(356, 359);
        glVertex2f(356, 340);
        glVertex2f(356, 331);
        glVertex2f(408, 331);
        glVertex2f(416, 338);
        glVertex2f(416, 340);
        glVertex2f(416, 343);
        glVertex2f(414, 346);
        glVertex2f(408, 357);
        glVertex2f(406, 359);
        glVertex2f(403, 362);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(403, 362);
        glVertex2f(356, 362);
        glVertex2f(356, 359);
        glVertex2f(356, 340);
        glVertex2f(356, 331);
        glVertex2f(408, 331);
        glVertex2f(416, 338);
        glVertex2f(416, 340);
        glVertex2f(416, 343);
        glVertex2f(414, 346);
        glVertex2f(408, 357);
        glVertex2f(406, 359);
        glVertex2f(403, 362);
        glEnd();

        // Red Designs
        glColor3f(0.87f, 0.16f, 0.13f);
        glBegin(GL_POLYGON); // Top
        glVertex2f(403, 362);
        glVertex2f(356, 362);
        glVertex2f(356, 359);
        glVertex2f(406, 359);
        glEnd();
        glBegin(GL_POLYGON); // Bottom
        glVertex2f(356, 340);
        glVertex2f(356, 331);
        glVertex2f(408, 331);
        glVertex2f(416, 338);
        glVertex2f(416, 340);
        glEnd();

        // Windows
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        // Rear Driver
        glBegin(GL_POLYGON);
        glVertex2f(408, 357);
        glVertex2f(402, 357);
        glVertex2f(402, 346);
        glVertex2f(414, 346);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(408, 357);
        glVertex2f(402, 357);
        glVertex2f(402, 346);
        glVertex2f(414, 346);
        glEnd();

        // Win 2
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(382, 357);
        glVertex2f(373, 357);
        glVertex2f(373, 348);
        glVertex2f(382, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(382, 357);
        glVertex2f(373, 357);
        glVertex2f(373, 348);
        glVertex2f(382, 348);
        glEnd();

        // Win 3
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(369, 357);
        glVertex2f(360, 357);
        glVertex2f(360, 348);
        glVertex2f(369, 348);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(369, 357);
        glVertex2f(360, 357);
        glVertex2f(360, 348);
        glVertex2f(369, 348);
        glEnd();

        // Door
        if(!isDayM2) {
            glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow/orange at night
        } else {
            glColor3f(0.50f, 0.74f, 0.83f); // Normal blue during day
        }
        glBegin(GL_POLYGON);
        glVertex2f(398, 357);
        glVertex2f(387, 357);
        glVertex2f(387, 340);
        glVertex2f(398, 340);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(398, 357);
        glVertex2f(387, 357);
        glVertex2f(387, 340);
        glVertex2f(398, 340);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(392, 357);
        glVertex2f(392, 340);
        glEnd();

        glPopMatrix();

        // ==========================================
        // CYBER TRUCK
        // ==========================================

        setHeadlightKLCC(carKLCCX, 50.0f, true);

        drawCybertruckKLCC(carKLCCX, 50.0f, 10.0f, true);



        // SETUP LIGHTS
        setBusHeadlight(busXM2, 5.0f, false);
        drawBusKLCC(busXM2, 5.0f, 1.0f, false);

        // ==========================================
        // LAMP POSTS (Controlled by GL_LIGHT1)
        // ==========================================

        if(!isDayM2 && lampsOnM2)
    {
        // --- CLEANUP: Kill Global Ambient ---
        GLfloat globalDark[] = { 0.05f, 0.05f, 0.05f, 1.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalDark);

        glDisable(GL_LIGHT2);

        // --- SPOTLIGHT SETTINGS ---
        GLfloat spotDir[]   = { 0.0f, -1.0f, 0.0f };
        GLfloat spotCutoff  = 45.0f;
        GLfloat spotExp     = 2.0f;

        // --- COLOR ---
        GLfloat lampColor[] = { 0.8f, 0.6f, 0.2f, 1.0f };
        GLfloat noAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };

        // --- ATTENUATION ---
        GLfloat kC = 1.0f;
        GLfloat kL = 0.005f;
        GLfloat kQ = 0.0f;

        // --- LIGHT 1  ---
        glEnable(GL_LIGHT1);
        GLfloat pos1[] = { 90.0f, 220.0f, 50.0f, 1.0f };
        glLightfv(GL_LIGHT1, GL_POSITION, pos1);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff);
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotExp);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lampColor);
        glLightfv(GL_LIGHT1, GL_SPECULAR, lampColor);
        glLightfv(GL_LIGHT1, GL_AMBIENT, noAmbient);
        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, kC);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, kL);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, kQ);

        // --- LIGHT 2  ---
        glEnable(GL_LIGHT2);
        GLfloat pos2[] = { 430.0f, 220.0f, 50.0f, 1.0f };
        glLightfv(GL_LIGHT2, GL_POSITION, pos2);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDir);
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotCutoff);
        glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotExp);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lampColor);
        glLightfv(GL_LIGHT2, GL_SPECULAR, lampColor);
        glLightfv(GL_LIGHT2, GL_AMBIENT, noAmbient);
        glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, kC);
        glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, kL);
        glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, kQ);

        // --- LIGHT 3  ---
        glEnable(GL_LIGHT5);
        GLfloat pos3[] = { 940.0f, 220.0f, 50.0f, 1.0f };
        glLightfv(GL_LIGHT5, GL_POSITION, pos3);
        glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotDir);
        glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, spotCutoff);
        glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, spotExp);
        glLightfv(GL_LIGHT5, GL_DIFFUSE, lampColor);
        glLightfv(GL_LIGHT5, GL_SPECULAR, lampColor);
        glLightfv(GL_LIGHT5, GL_AMBIENT, noAmbient);
        glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, kC);
        glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, kL);
        glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, kQ);
    }
    else
    {
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT3);

        // Restore Day Ambient
        if(isDayM2) {
            GLfloat globalDay[] = { 0.2f, 0.2f, 0.2f, 1.0f };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalDay);
        }
    }

    // ==========================================
    // 2. DRAW ALL POSTS
    // ==========================================
    for (int i = 90; i < 1000; i += 170)
    {
        float x = (float)i;

        // --- POLE ---
        glColor3f(0.18f, 0.18f, 0.22f);
        glBegin(GL_QUADS);
            glVertex2f(x - 3, 120);
            glVertex2f(x + 3, 120);
            glVertex2f(x + 3, 210);
            glVertex2f(x - 3, 210);
        glEnd();

        // --- HEAD ---
        glColor3f(0.22f, 0.22f, 0.28f);
        glBegin(GL_QUADS);
            glVertex2f(x - 8, 210);
            glVertex2f(x + 8, 210);
            glVertex2f(x + 8, 225);
            glVertex2f(x - 8, 225);
        glEnd();

        // --- BULB VISUAL ---
        if(isDayM2 || !lampsOnM2)
        {
             glColor3f(0.4f, 0.4f, 0.4f); // Off
        }
        else
        {
             // Bulb glows orange to match the light
             glColor3f(1.0f, 0.9f, 0.2f);
        }

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, 222);
        for (int j = 0; j <= 360; j+=20)
        {
            float rad = j * 3.1416f / 180.0f;
            glVertex2f(x + 6 * cos(rad), 222 + 6 * sin(rad));
        }
        glEnd();
    }}

/// =========================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================




/// =========================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================

}

void selectKeyboard(unsigned char key, int x, int y)
{
    // ==========================================
    // 1. GLOBAL SCENE SWITCHING (Always Active)
    // ==========================================
    if(key == 'm' || key == 'M')
    {
        scenarioMeraz = false;
        scenarioMohaimuiul = true;
        scenarioMohaiminul = false;
        glutPostRedisplay();
    }
    else if(key == 's' || key == 'S')
    {
        scenarioMohaiminul = true;
        scenarioMeraz = false;
        scenarioMohaimuiul = false;
        glutPostRedisplay();
    }
    else if(key == 'v' || key == 'V')
    {
        scenarioMeraz = true;
        scenarioMohaimuiul = false;
        scenarioMohaiminul = false;
        glutPostRedisplay();
    }
    else if(key == 27) // Escape key
    {
        exit(0);
    }

    // ==========================================
    // 2. SCENE SPECIFIC INPUTS
    // ==========================================

    // --- Scene 1: Meraz ---
    if (scenarioMeraz)
    {
        keyboard(key, x, y);
    }

    // --- Scene 2: Mohaimuiul ---
    if(scenarioMohaimuiul)
    {
        keyboardM(key, x, y);
    }

    // --- Scene 3: Mohaiminul (KLCC) ---
    if (scenarioMohaiminul)
    {
        // Day/Night Toggle
        if(key == 'd' || key == 'D')
        {
            isDayM2 = true;
            glutPostRedisplay();
        }
        if(key == 'n' || key == 'N')
        {
            isDayM2 = false;
            glutPostRedisplay();
        }

        // Lamp Toggle
        if(key == 'l' || key == 'L')
        {
            lampsOnM2 = !lampsOnM2;
            glutPostRedisplay();
        }

        // Fountain Toggle
        if(key == 'f' || key == 'F')
        {
            fountainsOnM2 = !fountainsOnM2;
            if (fountainsOnM2)
            {
                fountainStageM2 = 0; // Reset animation
                updateFountainAnimM2(0);
            }
            glutPostRedisplay();
        }
    }
}

void selectSpecialKeys(int key, int x, int y)
{
    // --- Scene 1: Meraz ---
    if (scenarioMeraz)
    {
        specialKeys(key, x, y);
    }

    // --- Scene 2: Mohaimuiul ---
    if(scenarioMohaimuiul)
    {
        specialKeysM(key, x, y);
    }

    // --- Scene 3: Mohaiminul (KLCC) ---
    if (scenarioMohaiminul)
    {
        // ---------------------------------------------------------
        // 1. TRAIN SPEED (UP/DOWN) - Works in both Day and Night
        // ---------------------------------------------------------
        if (key == GLUT_KEY_UP)
        {
            trainKLCCSpeed += 0.5f; // Train goes faster
        }

        if (key == GLUT_KEY_DOWN)
        {
            trainKLCCSpeed -= 0.5f; // Train slows down

            if (trainKLCCSpeed < 0.1f) trainKLCCSpeed = 0.0f;
        }

        if (key == GLUT_KEY_PAGE_UP)
        {
            carKLCCSpeed += 0.5f;
        }

        if (key == GLUT_KEY_PAGE_DOWN)
        {
            carKLCCSpeed -= 0.5f;

            if (carKLCCSpeed < 0.0f){
                carKLCCSpeed = 0.0f;
            }
        }

        if( key == GLUT_KEY_HOME){
            busSpeedM2 += 0.5f;
        }

        if (key == GLUT_KEY_END)
        {
            busSpeedM2 -= 0.5f;

            if (busSpeedM2 < 0.0f){
                busSpeedM2 = 0.0f;
            }
        }

        // ---------------------------------------------------------
        // 2. SUN & MOON SPEED (LEFT/RIGHT)
        // ---------------------------------------------------------
        if (isDayM2)
        {
            // === DAY MODE:  ===
            if (key == GLUT_KEY_RIGHT)
            {
                sunSpeedM2 += 0.5f;
            }
            if (key == GLUT_KEY_LEFT)
            {
                sunSpeedM2 -= 0.5f;
                if (sunSpeedM2 < 0.1f) sunSpeedM2 = 0.1f;
            }
        }
        else
        {
            // === NIGHT MODE: ===
            if (key == GLUT_KEY_RIGHT)
            {
                moonSpeedM2 += 0.5f;
            }
            if (key == GLUT_KEY_LEFT)
            {
                moonSpeedM2 -= 0.5f;
                if (moonSpeedM2 < 0.1f) moonSpeedM2 = 0.1f;
            }
        }

        glutPostRedisplay();
    }
}

void selectMouse(int button, int state, int x, int y)
{
    if (scenarioMeraz)
    {
        mouse(button, state, x, y);
    }

    if(scenarioMohaimuiul)
    {
        M_mouse(button, state, x, y);
    }

    if (scenarioMohaiminul)
    {
        // Toggle Train Pause on Left Click
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            isTrainPausedM2 = !isTrainPausedM2;
        }

    }
}

/// ##############################################################  Display  ###############################################################
void display()
{
    if(scenarioMeraz) Meraz();
    if(scenarioMohaimuiul) Avishek();
    if(scenarioMohaiminul) Mohaiminul();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // --- 1. Console Instructions (From Code 1) ---
    // ==========================================
    // 1. UNIVERSAL / GLOBAL CONTROLS (Work Everywhere)
    // ==========================================
    cout<<"********** >>> UNIVERSAL CONTROLS <<< **********"<<endl;
    cout<<"Press 'd' or 'D' for Day Mode"<<endl;
    cout<<"Press 'n' or 'N' for Night Mode"<<endl;
    cout<<"Press 'v' or 'V' to switch to Main City scenario"<<endl;
    cout<<"Press 'm' or 'M' to switch to Bridge scenario"<<endl;
    cout<<"Press 's' or 'S' to switch to KLCC scenario"<<endl<<endl;

    // ==========================================
    // 2. MAIN CITY CONTROLS
    // ==========================================
    cout<<"********** >>> Main City Specifics <<< **********"<<endl;
    cout<<"Press key_up / key_down    : Train speed (Day/Night)"<<endl;
    cout<<"Press key_left / key_right : Sun speed (Day)/Moon speed (Night)"<<endl;
    cout<<"Press Page Up / Page Down  : Cargo Truck speed (Day/Night)"<<endl<<endl;
    cout<<"Mouse Left Click           : Stop/Start Train (Day) / Moon (Night)"<<endl;
    cout<<"Mouse Right Click          : Stop/Start Sun/Moon"<<endl;
    cout<<"Mouse Middle Click          : Stop/Start Truck (Day/Night)"<<endl;
    cout<<"Press SPACE                : Stop Everything"<<endl;

    // ==========================================
    // 3. BRIDGE CONTROLS
    // ==========================================
    cout<<"********** >>> Bridge Specifics <<< **********"<<endl;
    cout<<"Press key_up / key_down    : Car1 and Plane speed"<<endl;
    cout<<"Press key_left / key_right : Ambulance speed"<<endl;
    cout<<"Mouse Left Click           : Stop Car1"<<endl;
    cout<<"Mouse Right Click          : Stop Night Train"<<endl<<endl;

    // ==========================================
    // 4. KLCC CONTROLS
    // ==========================================
    cout<<"********** >>> KLCC Specifics <<< **********"<<endl;
    cout<<"Press 'l' or 'L'           : Toggle Street Lamps"<<endl;
    cout<<"Press 'f' or 'F'           : Toggle Fountains"<<endl;
    cout<<"Press key_up / key_down    : Metro Train Speed"<<endl;
    cout<<"Press key_left / key_right : Sun/Moon Speed"<<endl;
    cout<<"Mouse Left Click           : Pause/Resume Metro Train"<<endl;
    cout<<"Page Up / Page Down        : CyberTruck Speed Control"<<endl;
    cout<<"Home / End                 : Bus Speed Control"<<endl;

    // --- Window Initialization ---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Going Through Places - A Journey By Car");

    // --- Graphics & Smoothing Setup ---
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Shade Model:
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);


    glEnable(GL_LIGHT0);   // Sun/Moon
    glEnable(GL_LIGHT1);   // Street Lamps Group 1
    glEnable(GL_LIGHT2);   // Street Lamps Group 2
    glEnable(GL_LIGHT3);   // CyberTruck Headlight

    glEnable(GL_COLOR_MATERIAL);

    // Set Initial Light Properties
    GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);

    // Ambient Light
    GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);

    // --- Projection Setup ---
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    // --- Callback Registration ---
    glutDisplayFunc(display);

    // Timers: Meraz
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(16, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(16, V_updateCloud4, 0);
    glutTimerFunc(2, updateSun, 0);
    glutTimerFunc(16, updateMoon, 0);
    glutTimerFunc(16, updateTrain, 0);
    glutTimerFunc(2, V_updateBus, 0);
    glutTimerFunc(2, updateCar, 0);
    glutTimerFunc(16, V_updateCargo, 0);

    // Timers: Avishek
    glutTimerFunc(16, updateBoat1M, 0);
    glutTimerFunc(10, updateBoat2M, 0);
    glutTimerFunc(16, updateCar1M, 0);
    glutTimerFunc(16, updateSunM, 0);
    glutTimerFunc(8, updateTruckM, 0);
    glutTimerFunc(10, updateTrainM, 0);
    glutTimerFunc(10, updateAmbulanceM, 0);
    glutTimerFunc(16, updateCloud1M, 0);
    glutTimerFunc(16, updateCloud2M, 0);
    glutTimerFunc(16, updateCloud3M, 0);
    glutTimerFunc(19, updateBoat3M, 0);
    glutTimerFunc(16, updatePlaneM, 0);
    glutTimerFunc(10, updateBusM, 0);
    glutTimerFunc(10, updateMcar5, 0);
    glutTimerFunc(10, updateMcar5_night, 0);
    glutTimerFunc(16, updateBoat1_nightM, 0);
    glutTimerFunc(10, updateBoat2_nightM, 0);
    glutTimerFunc(16, updateCar1_nightM, 0);
    glutTimerFunc(16, updateMoonM, 0);
    glutTimerFunc(5, updateTrainM_night, 0);
    glutTimerFunc(20, M_updateCar3_night, 0);
    glutTimerFunc(16, M_updateCar4_night, 0);
    glutTimerFunc(16, updateCloud1M_night, 0);
    glutTimerFunc(18, updateCloud2M_night, 0);

    // Timers: Mohaiminul (KLCC scene)
    glutTimerFunc(16, updateSunM2, 0);
    glutTimerFunc(16, updateMoonM2, 0);
    glutTimerFunc(0, updateTrainKLCC, 0);
    glutTimerFunc(0, updateCloudsKLCC, 0);
    glutTimerFunc(0, updateFountainAnimM2, 0);
    glutTimerFunc(0, updateCarKLCC, 0);
    glutTimerFunc(20, updateBusKLCC, 0);

    // Input Callbacks
    glutKeyboardFunc(selectKeyboard);
    glutSpecialFunc(selectSpecialKeys);
    glutMouseFunc(selectMouse);

    glutMainLoop();

    return 0;
}

