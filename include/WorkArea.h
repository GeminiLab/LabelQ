#pragma once

#include <model/Page.h>

#include <QLabel>

class WorkArea : public QLabel {
    Q_OBJECT

private:
    Page *_currentPage;

public:
    explicit WorkArea(QWidget *parent = nullptr);
    ~WorkArea() override = default;

    Page* page() const;
    void setPage(Page *page);

    // zoom management
private:
    static constexpr int MinimumZoomLevelIndex = -15;
    static constexpr int MaximumZoomLevelIndex = 15;
    static constexpr int ZoomLevels[MaximumZoomLevelIndex - MinimumZoomLevelIndex + 1] = {
        25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95,
        100,
        105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 160, 170, 180, 190, 200
    };

    static constexpr int zoomLevel(int index) {
        return ZoomLevels[index - MinimumZoomLevelIndex];
    }

    int currentZoomLevelIndex;
    void setZoomLevelIndex(int newIndex);

public slots:
    void zoom(bool in);
    void zoomReset();

signals:
    void sizeChanged();

    // page and label management
private:
    PageOperator *op;
    QPixmap pic;

public:
    void setPageOperator(PageOperator *op);

public slots:
    void onNewPage();

    void onLabelAppended();
    void onLabelDeleted(QBitArray deleted);
    void onLabelSelectionUpdated(QBitArray selected);
};