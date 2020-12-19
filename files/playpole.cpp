#include "playpole.h"


PlayPole::PlayPole(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}

PlayPole::~PlayPole()
{

}

void PlayPole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPoint startPoint;
    QPoint finPoint;
    QPoint pointSecond;
    QPoint secondFin;

    painter->setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine, Qt::FlatCap));
    painter->drawRect(0,0,600,600);
    painter->setBrush(QColor(255, 99, 71));
    painter->drawRect(0, 570, 30, 30);
    painter->setBrush(QColor(65, 105, 225));
    painter->drawRect(570, 0, 30, 30);

    segment = 600 / level;
    startPoint.setX(0);
    startPoint.setY(570);
    pointSecond.setX(30);
    pointSecond.setY(600);
    for(int i = 0; i < level - 1; i++){
        int x = qrand() % ((segment * (i + 1) - segment * i) + segment * i);
        int y = qrand() % ((segment * (i + 1) - segment * i) + segment * i);
        finPoint.setX(x);
        finPoint.setY(y);
        secondFin.setX(finPoint.x() + 42);
        secondFin.setY(finPoint.y() + 42);
        painter->drawLine(startPoint, finPoint);
        painter->drawLine(pointSecond, secondFin);
        startPoint = finPoint;
        pointSecond = secondFin;
    }
    painter->drawLine(startPoint.x(), startPoint.y(), 570, 0);
    painter->drawLine(pointSecond.x(), pointSecond.y(), 600, 30);
    startPoint.setX(0);
    startPoint.setY(0);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}



void PlayPole::getLevel(int Level)
{
    level = Level;
}


QRectF PlayPole::boundingRect() const
{
    return QRectF(0,0,605,605);
}
