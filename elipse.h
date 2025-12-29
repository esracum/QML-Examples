#ifndef ELIPSE_H
#define ELIPSE_H

#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <QPainter>



class Elipse : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(float border READ border WRITE setBorder NOTIFY borderChanged FINAL)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged FINAL)

public:
    Elipse();
    float border() const;
    void setBorder(float newBorder);
    Q_INVOKABLE void setProperties(float newBorder, QColor newcolor);
    void paint(QPainter *painter);

public slots:
    void elipseInfo();
    void onPropertyChanged();

signals:
    void borderChanged();
    void colorChanged();

private:
    float m_border;
    QColor m_color;

    // QQuickPaintedItem interface

};
#endif // ELIPSE_H
