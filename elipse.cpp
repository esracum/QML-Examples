#include "elipse.h"

Elipse::Elipse() {
    connect(this, &Elipse::borderChanged, this, &Elipse::onPropertyChanged);
    connect(this, &Elipse::colorChanged, this, &Elipse::onPropertyChanged);

}

float Elipse::border() const
{
    return m_border;
}

void Elipse::setBorder(float newBorder)
{
    if (qFuzzyCompare(m_border, newBorder))
        return;
    m_border = newBorder;
    emit borderChanged();
}

void Elipse::setProperties(float newBorder, QColor newcolor)
{
    setBorder(newBorder);

    if(m_color != newcolor){
        m_color = newcolor;
        emit colorChanged();
    }
}

void Elipse::paint(QPainter *painter)
{
    QPen pen(m_color,m_border);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawEllipse(QRectF(m_border/2, m_border/2, width() - m_border, height() - m_border));

}

void Elipse::elipseInfo()
{
    qInfo() << QString("Elipse's color: %1 - Elipse's border: %2").arg(m_color.name()).arg(m_border);

}

void Elipse::onPropertyChanged()
{
    update();

}
