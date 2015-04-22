#ifndef GAME_H
#define GAME_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_0>
#include <QMatrix4x4>

namespace Ui {
class Game;
}

class Game : public QOpenGLWidget, protected QOpenGLFunctions_3_0
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
    QMatrix4x4 projection;
};

#endif // GAME_H
