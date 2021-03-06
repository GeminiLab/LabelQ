#pragma once

#include <QScrollArea>
#include <QWheelEvent>

// TODO: rename this class to WorkAreaContainer, or something else...
class ZoomScrollArea : public QScrollArea {
    Q_OBJECT

public:
    explicit ZoomScrollArea(QWidget *parent = nullptr);
    ~ZoomScrollArea() override;

protected:
    void wheelEvent(QWheelEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void keyPressEvent(QKeyEvent *ev) override;

signals:
    void zoom(bool in);
    void zoomReset();

    void prev();
    void next();
};
