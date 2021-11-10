#include "blockscheme.h"
#include <math.h>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPolygon>
#include <QPointF>

BlockScheme::BlockScheme(QObject *parent) : QObject(parent), QGraphicsItem()
{
   x = 0;
   y = 0;
   brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
   brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
   geometry = Geometry::ELLIPS;                  // По умолчанию - эллипс
   setPos(0,0);
   moving = false;
}




void BlockScheme::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setBrush(brush);
   if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
   if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
   if (geometry == Geometry::STAR) {
       QPolygon poly;

           poly << QPoint(0+x, 85+y) << QPoint(75+x, 75+y)
                << QPoint(100+x, 10+y) << QPoint(125+x, 75+y)
                << QPoint(200+x, 85+y) << QPoint(150+x, 125+y)
                << QPoint(160+x, 190+y) << QPoint(100+x, 150+y)
                << QPoint(40+x, 190+y) << QPoint(50+x, 125+y)
                << QPoint(0+x, 85+y);
           painter->drawPolygon(poly);
//       QPolygonF starPolygon;
//             starPolygon << QPointF(1.0, 0.5);
//       for (int i = 1; i < 5; ++i)
//           starPolygon << QPointF(0.5 + 0.5 * std::cos(0.8 * i * 3.14),
//                                  0.5 + 0.5 * std::sin(0.8 * i * 3.14));

   }
   Q_UNUSED(option)
   Q_UNUSED(widget)
}

QRectF BlockScheme::boundingRect() const         // Обязателен для
                                                 // переопределения
{
   return QRectF(x, y, 200, 100);                // Текущие координаты
}

void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)        // Левая кнопка, режим
                                                 // перемещения
   {
       moving = true;                            // Флаг активности
                                                 // перемещения
       bpoint = event->pos().toPoint();          // Запоминаем начальные
                                                 // координаты мыши
   }
   if (event->button() == Qt::RightButton) {      // Правая кнопка - меняем вид
                                                 // фигуры

       emit reDraw();                            // переотрисовка
   }
}

void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)
   {
       moving = false;                            // Снимаем флаг на перемещение
       if(geometry == Geometry::ELLIPS)
            geometry = Geometry::RECTANGLE;
       else if(geometry == Geometry::RECTANGLE)
            geometry = Geometry::STAR;
       else if(geometry == Geometry::STAR)
            geometry = Geometry::ELLIPS;
       else
           geometry = Geometry::ELLIPS;
       emit reDraw();
   }
}

void BlockScheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (moving)                                    // Если активен флаг
                                                  // перемещения
   {
// Вычисляем вектор смещения
       QPoint p = event->pos().toPoint()-bpoint;
       x += p.x();
       y += p.y();
       bpoint = event->pos().toPoint();           // Запоминаем новую позицию
                                                  // курсора
       emit reDraw();                             // Переотрисовываем
   }
}

