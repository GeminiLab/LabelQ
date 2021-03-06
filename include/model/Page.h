#pragma once

#include "./Model.h"
#include "./Label.h"

#include <QBitArray>
#include <QString>
#include <QPixmap>
#include <QJsonObject>

class Page {
private:
    friend class Project;

protected:
    QVector<Label> labels;
    bool dirty = false;

    int picWidth = -1, picHeight = -1;
    virtual void calcPicSize();

public:
    virtual ~Page() = default;

    virtual QString name() = 0;
    virtual QPixmap pixmap() = 0;

    virtual int width();
    virtual int height();

    virtual void preDisplay() = 0;
    virtual void postHidden() = 0;

    virtual bool isDirty();
    virtual void markSaved();
    virtual QJsonObject toJsonObject();

    virtual void addLabel(Label &&label);
    virtual void addLabel(const Label &label);
    virtual Label label(int at);
    virtual void removeLabel(int at);
    virtual int labelCount();
    virtual void updateLabelContent(int at, const QString &content);

public:
    static Page* fromJson(const QJsonObject &json, const QString &baseDir);
};
