#include "game.h"
#include <QDebug>

struct BaseComponent{
    virtual void exe() = 0;
};

template <class Type>
struct Component: public BaseComponent{
    void exe(){static_cast<Type*>(this)->exe();}
};


struct Move: public Component<Move>{
void exe(){qDebug() << "Move";}
};
struct Heal: public Component<Heal>{
void exe(){qDebug() << "Heal";}
};

Game::Game(QWidget *parent) :
    QOpenGLWidget(parent)
{
    QList<BaseComponent *> list;
    list << new Move();
    list << new Heal();

    for(BaseComponent * c:list){
        c->exe();
    }
}

Game::~Game()
{
}


void Game::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void Game::resizeGL(int w, int h)
{
    projection.setToIdentity();
    projection.perspective(60.0f,w/float(h),0.01f,1000.0f);
}

void Game::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
}
