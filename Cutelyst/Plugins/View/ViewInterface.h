#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H

#include <Context>
#include <QString>

namespace Cutelyst {

class ViewInterface : public QObject
{
    Q_OBJECT
public:
    explicit ViewInterface(QObject *parent = 0) : QObject(parent) {}

    Q_PROPERTY(QStringList includePaths READ includePaths WRITE setIncludePaths)
    virtual QStringList includePaths() const = 0;
    virtual void setIncludePaths(const QStringList &paths) = 0;

    Q_PROPERTY(QString templateExtension READ templateExtension WRITE setTemplateExtension)
    virtual QString templateExtension() const = 0;
    virtual void setTemplateExtension(const QString &extension) = 0;

    Q_PROPERTY(QString wrapper READ wrapper WRITE setWrapper)
    virtual QString wrapper() const = 0;
    virtual void setWrapper(const QString &name) = 0;

    Q_PROPERTY(bool cache READ isCaching WRITE setCache)
    virtual bool isCaching() const = 0;
    virtual void setCache(bool enable) = 0;

    virtual bool render(Cutelyst::Context *c) = 0;
};

}

#define ViewInterface_iid "org.cutelyst.ViewInterface"

Q_DECLARE_INTERFACE(Cutelyst::ViewInterface, ViewInterface_iid)

#endif // VIEWINTERFACE_H
