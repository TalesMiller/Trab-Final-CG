#include <GL/glut.h>
#include <GL/freeglut.h>

#include<SDL2/SDL.h>
#include<SDL2/SDL_test_images.h>

#include <stdlib.h>
#include <stdio.h>

// Variáveis para controles de navegação

GLfloat angle, fAspect, roda = 0, voa = 0, voa2 = 0, braco = 0, fren = 0, bracao = 0;

GLfloat rotX, rotY, rotX_ini, rotY_ini;

GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;

GLubyte teclado;

int x_ini, y_ini, bot;

GLfloat x = 0.0, y = 0.0, z = 0.0;

// Função responsável pela especificação dos parâmetros de iluminação

void DefineIluminacao(void)
{

    GLfloat luzAmbiente[4] = {0.4, 0.4, 0.4, 1.0};

    GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0}; // "cor"

    GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"

    GLfloat posicaoLuz[4] = {100.0 - roda, 100.0, 0.0, 1.0};

    // Capacidade de brilho do material

    GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};

    GLint especMaterial = 60;

    // Define a refletância do material

    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

    // Define a concentração do brilho

    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

    // Ativa o uso da luz ambiente

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);

    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);

    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

void carro()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0, 0.0, 0.0);

    glScalef(1, 0.5, 1);

    glutSolidCube(20.0);
    glTranslatef(20, 0.0, 0.0);
    glutSolidCube(20.0);
    glScalef(0.5, 1, 1);
    glTranslatef(-7.5, 12.5, 0.0);
    glutSolidCube(20.0);

    glColor3f(0.0f, 0.0f, 0.0f);
    glScalef(2, 2, 1);
    glPopMatrix();

    // roda
    glPushMatrix();
    glTranslatef(22.5, -5.5, 11.0);
    glRotatef(roda, 0, 0, 1);
    glutSolidTorus(1.5, 3, 50, 50);
    glColor3f(0.5f, 0.5f, 0.5f);
    glScalef(4, 1, 1);
    glutSolidCube(1);
    glScalef(0.25, 4, 1);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(22.5, -5.5, -11.0);
    glRotatef(roda, 0, 0, 1);
    glutSolidTorus(1.5, 3, 50, 50);
    glColor3f(0.5f, 0.5f, 0.5f);
    glScalef(4, 1, 1);
    glutSolidCube(1);
    glScalef(0.25, 4, 1);
    glutSolidCube(1);
    glPopMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(-1.5, -5.5, -11.0);
    glRotatef(roda, 0, 0, 1);
    glutSolidTorus(1.5, 3, 50, 50);
    glColor3f(0.5f, 0.5f, 0.5f);
    glScalef(4, 1, 1);
    glutSolidCube(1);
    glScalef(0.25, 4, 1);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-1.5, -5.5, 11.0);
    glRotatef(roda, 0, 0, 1);
    glutSolidTorus(1.5, 3, 50, 50);
    glColor3f(0.5f, 0.5f, 0.5f);
    glScalef(4, 1, 1);
    glutSolidCube(1);
    glScalef(0.25, 4, 1);
    glutSolidCube(1);
    glPopMatrix();
    // fim roda


    glColor3f(1.0f, 1.0f, 1.0f);

    // janela
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); // jaela D
    glVertex3f(13.5f, 5.5f, 10.01f);
    glVertex3f(20.0f, 5.5f, 10.01f);
    glVertex3f(20.0f, 10.5f, 10.01f);
    glVertex3f(13.5f, 10.5f, 10.01f);
    glEnd();

    glBegin(GL_QUADS); // Janela E
    glVertex3f(13.5f, 5.5f, -10.01f);
    glVertex3f(20.0f, 5.5f, -10.01f);
    glVertex3f(20.0f, 10.5f, -10.01f);
    glVertex3f(13.0f, 10.5f, -10.01f);
    glEnd();

    glBegin(GL_QUADS); // Janela Frente
    glVertex3f(21.5f, 5.5f, 8.5f);
    glVertex3f(21.5f, 5.5f, -8.5f);
    glVertex3f(21.5f, 10.5f, -8.5f);
    glVertex3f(21.5f, 10.5f, 8.5f);
    glEnd();

    glBegin(GL_QUADS); // Janela Traz
    glVertex3f(11.0f, 5.5f, 8.5f);
    glVertex3f(11.0f, 5.5f, -8.5f);
    glVertex3f(11.0f, 10.5f, -8.5f);
    glVertex3f(11.0f, 10.5f, 8.5f);
    glEnd();

    glBegin(GL_QUADS); // Capota
    glVertex3f(-9.0f, 5.1f, 8.5f);
    glVertex3f(9.5f, 5.1f, 8.5f);
    glVertex3f(9.5f, 5.1f, -8.5f);
    glVertex3f(-9.0f, 5.1f, -8.5f);
    glEnd();
    // fim janela
}

void sol()
{
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix(); // Sol inicia

    glTranslatef(100.0, 100.0, 0);
    glutSolidSphere(20.0, 100, 100);

    glPopMatrix(); // Fim Sol
    
}

void chao()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix(); // Chão inicia

    glScalef(30, 1, 30);

    glTranslatef(0.0, -110.3, 0);
    glutSolidCube(200.0);

    glPopMatrix(); // Fim Chão
}

void arvore()
{
    glPushMatrix();
    glColor3f(0.58f, 0.29f, 0.0f);
    glScalef(1, 8, 1);
    glTranslatef(-45.0, 1, -30);
    glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-45.0, 40, -30);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
}

void casa()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 1.0f);
    glScalef(1.2, 1, 1);
    glTranslatef(0.0, 0.0, -60);
    glutSolidCube(40.0);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    // porta
    glBegin(GL_QUADS);

    glVertex3f(-15.0, -10.5, -39.9);
    glVertex3f(0.0, -10.5, -39.9);
    glVertex3f(0.0, 12.0, -39.9);
    glVertex3f(-15.0, 12.0, -39.0);

    glEnd();
    // fim porta

    // janela
    glBegin(GL_QUADS);

    glVertex3f(5.0, 7.0, -39.9);
    glVertex3f(11.0, 7.0, -39.9);
    glVertex3f(11.0, 12.0, -39.9);
    glVertex3f(5.0, 12.0, -39.9);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(5.0, 0.0, -39.9);
    glVertex3f(11.0, 0.0, -39.9);
    glVertex3f(11.0, 5.0, -39.9);
    glVertex3f(5.0, 5.0, -39.9);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(13.5, 0.0, -39.9);
    glVertex3f(20.0, 0.0, -39.9);
    glVertex3f(20.0, 5.0, -39.9);
    glVertex3f(13.5, 5.0, -39.9);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(13.0, 7.0, -39.9);
    glVertex3f(20.0, 7.0, -39.9);
    glVertex3f(20.0, 12.0, -39.9);
    glVertex3f(13.0, 12.0, -39.9);

    glEnd();
    // fim janela

    // Telhado
    glBegin(GL_TRIANGLES);
    // Frente
    glColor3f(1, 0, 0);
    glVertex3f(-23.75, 20, -40);
    glVertex3f(0, 40, -60);
    glVertex3f(23.75, 20, -40);
    // Direito
    glVertex3f(23.75, 20, -40);
    glVertex3f(23.75, 20, -80);
    glVertex3f(0, 40, -60);
    // Costas
    glVertex3f(23.75, 20, -80);
    glVertex3f(-23.75, 20, -80);
    glVertex3f(0, 40, -60);
    // Esquerda
    glVertex3f(-23.75, 20, -40);
    glVertex3f(0, 40, -60);
    glVertex3f(-23.75, 20, -80);
    glEnd();
}

void Doniveo()
{
    glPushMatrix(); // pé inicia
    glColor3f(0.58f, 0.29f, 0.0f);

    glTranslatef(-2.5, -10.0, -20.0);
    glutSolidCube(5.0);
    glTranslatef(5.0, 0.0, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim pé

    glPushMatrix(); // perna inicia
    glScalef(1, 2, 1);
    glColor3f(0.0f, 0.0f, 1.0f);

    glTranslatef(-2.5, -1.2, -20.0);
    glutSolidCube(5.0);
    glTranslatef(5.0, 0.0, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim perna

    glPushMatrix(); // cintura inicia
    glScalef(1.2, 1, 1);
    glColor3f(0.0f, 0.0f, 1.0f);

    glTranslatef(-2.5, 1, -20.0);
    glutSolidCube(5.0);
    glTranslatef(5.0, 0.0, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim cintura

    glPushMatrix(); // Inicia corpo
    glScalef(1.2, 2, 1);
    glColor3f(1.0f, 0.64f, 0.0f);

    glTranslatef(-2.5, 4.3, -20.0);
    glutSolidCube(5.0);
    glTranslatef(5.0, 0.0, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim corpo

    glPushMatrix(); // Inicia cabeça
    glScalef(1, 1, 1);
    glColor3f(0.82f, 0.41f, 0.11f);

    glTranslatef(0.0, 16.3, -20.0);
    glutSolidCube(5.5);

    glPopMatrix(); // Fim cabeça

    glPushMatrix(); // Inicia braço E
    glScalef(1.2, 1, 1);
    glColor3f(1.0f, 0.64f, 0.0f);

    glTranslatef(-5.5, 10.3, -20.0);
    glutSolidCube(5.0);

    glScalef(0.5, 1.2, 1);
    glColor3f(0.82f, 0.41f, 0.11f);
    glTranslatef(-1.0, -4.3+bracao, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim braço E

    glPushMatrix(); // Inicia braço D
    glScalef(1.2, 1, 1);
    glColor3f(1.0f, 0.64f, 0.0f);

    glTranslatef(5.5, 10.3, -20.0);
    glutSolidCube(5.0);

    glScalef(0.5, 1.2, 1);
    glColor3f(0.82f, 0.41f, 0.11f);
    glTranslatef(1.0, -4.3+bracao, 0.0);
    glutSolidCube(5.0);

    glPopMatrix(); // Fim braço D
}

void nuvem(double xnuvem,double ynuvem,double znuvem)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); // Inic Nuvem

    glTranslatef(xnuvem, 80.0+ynuvem, znuvem);
    glutSolidSphere(15.0, 100, 100);

    glScalef(1, 0.5, 1);

    glTranslatef(-20.0, 0.0, 0);
    glutSolidSphere(10.0, 100, 100);
    glTranslatef(40.0, 0.0, 0);
    glutSolidSphere(10.0, 100, 100);

    glPopMatrix(); // Fim Nuvem
}

// Função callback de redesenho da janela de visualização

void display(void)
{
    
    GLfloat branco[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
    GLint bri = 60;

    // Limpa a janela de visualização com a cor

    // de fundo definida previamente

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /* inicia a matriz*/

    glPushMatrix();

    // Chama a função que especifica os parâmetros de iluminação

    DefineIluminacao();

    // Altera a cor do desenho para azul

    glPushMatrix(); // Inicio Carro/Sol

    glTranslatef(0.0 - roda, 0.0, 0.0);

    carro();

    glPushMatrix();
    sol();

    glPopMatrix();

    glPopMatrix(); // Fim carro/sol

    chao();

    glPushMatrix();

    GLfloat defaultSpecular[4] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT,branco);
    glMaterialfv(GL_FRONT,GL_SPECULAR,defaultSpecular);

    nuvem(-30,0,-50);
    nuvem(20,-10,-30);
    nuvem(20,10,-45);
    nuvem(100,20,-60);
    nuvem(-50,40,-30);

    
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT, GL_SHININESS, bri);

    glPopMatrix();
    
    glPushMatrix();

    glTranslatef(0.0 + voa2, 0.0 + voa, 0.0 + fren);
    Doniveo();

    glPopMatrix();

    arvore();

    casa();

    glPopMatrix();

    glutSwapBuffers();
}

// Função usada para especificar a posição do observador virtual

void PosicionaObservador(void)

{

    // Especifica sistema de coordenadas do modelo

    glMatrixMode(GL_MODELVIEW);

    // Inicializa sistema de coordenadas do modelo

    glLoadIdentity();

    DefineIluminacao();

    // Posiciona e orienta o observador

    glTranslatef(-obsX, -obsY, -obsZ);

    glRotatef(rotX, 1, 0, 0);

    glRotatef(rotY, 0, 1, 0);
}

// Função usada para especificar o volume de visualização

void EspecificaParametrosVisualizacao(void)

{

    // Especifica sistema de coordenadas de projeção

    glMatrixMode(GL_PROJECTION);

    // Inicializa sistema de coordenadas de projeção

    glLoadIdentity();

    // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)

    gluPerspective(angle, fAspect, 0.5, 500);

    PosicionaObservador();
}

// Função callback chamada para gerenciar eventos de teclas normais (ESC)

void Teclado(unsigned char tecla, int x, int y)

{

    if (tecla == 27) // ESC ?

        exit(0);
}

// Função callback para tratar eventos de teclas especiais

void TeclasEspeciais(int tecla, int x, int y)

{

    switch (tecla)

    {

    case GLUT_KEY_HOME:
        if (angle >= 10)
            angle -= 5;

        break;

    case GLUT_KEY_END:
        if (angle <= 150)
            angle += 5;

        break;
    case GLUT_KEY_LEFT:
        roda += 5.0;
        break;
    case GLUT_KEY_RIGHT:
        roda -= 5.0;
        break;

    case GLUT_KEY_F3:
        if(bracao > 0)
            bracao -= 1;
        else
            if (voa > 0)
                voa -= 5.0;
        break;
    case GLUT_KEY_F4:
        voa2 += 5;
        break;
    case GLUT_KEY_F1:
        voa2 -= 5;
        break;
    case GLUT_KEY_F2:
        if(bracao < 9)
            bracao += 1;
        else
            voa += 5.0;
        break;
    case GLUT_KEY_F6:
        fren += 5.0;
        break;
    case GLUT_KEY_F5:
        fren -= 5.0;
        break;
    }

    EspecificaParametrosVisualizacao();

    glutPostRedisplay();
}

// Função callback para eventos de botões do mouse

void GerenciaMouse(int button, int state, int x, int y)

{

    if (state == GLUT_DOWN)

    {

        // Salva os parâmetros atuais

        x_ini = x;

        y_ini = y;

        obsX_ini = obsX;

        obsY_ini = obsY;

        obsZ_ini = obsZ;

        rotX_ini = rotX;

        rotY_ini = rotY;

        bot = button;
    }

    else
        bot = -1;
}

// Função callback para eventos de movimento do mouse

#define SENS_ROT 5.0

#define SENS_OBS 10.0

#define SENS_TRANSL 10.0

void GerenciaMovim(int x, int y)
{

    // Botão esquerdo ?

    if (bot == GLUT_LEFT_BUTTON)

    {

        // Calcula diferenças

        int deltax = x_ini - x;

        int deltay = y_ini - y;

        // E modifica ângulos

        rotY = rotY_ini - deltax / SENS_ROT;

        rotX = rotX_ini - deltay / SENS_ROT;
    }

    // Botão direito ?

    else if (bot == GLUT_RIGHT_BUTTON)

    {

        // Calcula diferença

        int deltaz = y_ini - y;

        // E modifica distância do observador

        obsZ = obsZ_ini + deltaz / SENS_OBS;
    }

    // Botão do meio ?

    else if (bot == GLUT_MIDDLE_BUTTON)

    {

        // Calcula diferenças

        int deltax = x_ini - x;

        int deltay = y_ini - y;

        // E modifica posições

        obsX = obsX_ini + deltax / SENS_TRANSL;

        obsY = obsY_ini - deltay / SENS_TRANSL;
    }

    PosicionaObservador();

    glutPostRedisplay();
}

// Função callback chamada quando o tamanho da janela é alterado

void Reshape(GLsizei w, GLsizei h)
{

    // Para previnir uma divisão por zero

    if (h == 0)
        h = 1;

    // Especifica as dimensões da viewport

    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto

    fAspect = (GLfloat)w / (GLfloat)h;

    EspecificaParametrosVisualizacao();
}

// Função responsável por inicializar parâmetros e variáveis

void init(void)

{

    // Define a cor de fundo da janela de visualização como branca

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

    // Habilita a definição da cor do material a partir da cor corrente

    glEnable(GL_COLOR_MATERIAL);

    // Habilita o uso de iluminação

    glEnable(GL_LIGHTING);

    // Habilita a luz de número 0

    glEnable(GL_LIGHT0);

    // Habilita o depth-buffering

    glEnable(GL_DEPTH_TEST);

    // Habilita o modelo de colorização de Gouraud

    glShadeModel(GL_FLAT);


    // Inicializa a variável que especifica o ângulo da projeção

    // perspectiva

    angle = 45;

    // Inicializa as variáveis usadas para alterar a posição do

    // observador virtual

    rotX = 0;

    rotY = 0;

    obsX = obsY = 0;

    obsZ = 150;
}

// Programa Principal

int main(int argc, char **argv)

{

    glutInit(&argc, argv);

    // Define o modo de operação da GLUT

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Especifica a posição inicial da janela GLUT

    glutInitWindowPosition(5, 5);

    // Especifica o tamanho inicial em pixels da janela GLUT

    glutInitWindowSize(450, 450);

    // Cria a janela passando como argumento o título da mesma

    glutCreateWindow("Trabalho Final CG-PDI");

    // Registra a função callback de redesenho da janela de visualização

    glutDisplayFunc(display);

    // Registra a função callback de redimensionamento da janela de visualização

    glutReshapeFunc(Reshape);

    // Registra a função callback para tratamento das teclas normais

    glutKeyboardFunc(Teclado);

    // Registra a função callback para tratamento das teclas especiais

    glutSpecialFunc(TeclasEspeciais);

    // Registra a função callback para eventos de botões do mouse

    glutMouseFunc(GerenciaMouse);

    // Registra a função callback para eventos de movimento do mouse

    glutMotionFunc(GerenciaMovim);

    // Chama a função responsável por fazer as inicializações

    init();

    // Inicia o processamento e aguarda interações do usuário

    glutMainLoop();

    return 0;
}