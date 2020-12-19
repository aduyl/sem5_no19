#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QScrollArea>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMath>
#include <scene.h>
#include <playpole.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int level = 1;

    bool isInt;

    PlayPole *rect;

private slots:
    void on_lineEdit_textChanged();

    void on_playButton_clicked();


    void on_reButton_clicked();

private:
    Ui::Widget *ui;
    Scene *scene;
};
#endif // WIDGET_H
