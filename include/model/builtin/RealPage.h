#pragma once

#include "../Page.h"

#include <QFileInfo>

class RealPage : public Page {
private:
    QFileInfo imageFile;
    QPixmap image;

protected:
    void calcPicSize() override;

public:
    explicit RealPage(const QString &path);
    ~RealPage() override = default;

    QString name() override;
    QPixmap pixmap() override;

    void preDisplay() override;
    void postHidden() override;

    static RealPage* fromJsonObject(const QJsonObject &json, const QString &baseDir);
    QJsonObject toJsonObject() override;
};
