#ifndef PLAYPOLE_H
#define PLAYPOLE_H


#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class PlayPole: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PlayPole(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~PlayPole();

    int level = 1;
    int segment = 600 / level - 30;
    int k = 1;



    void getLevel(int Level);
public slots:
    QRectF boundingRect() const;
};

#endif // PLAYPOLE_H

