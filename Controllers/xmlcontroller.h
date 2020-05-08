#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H

#include <QObject>
#include <QTextDocument>
#include <QDebug>
#include <QStringListModel>
#include <QAbstractItemModel>
#include <QGuiApplication>
#include <QCompleter>
#include <QDir>
#include <QtSql/QSqlDatabase>
#include "GUI/editor.h"

class XMLController : public QObject{
    Q_OBJECT
public:
    XMLController(Editor *e, QString filePath);
    void onTextChanged();
    static QAbstractItemModel* createModelFromFile(QString);

private:
    Editor *editor;
    QCompleter *completer;
    QString filePath;
    QString openCompleterTemplete(QString path);
};

#endif // XMLCONTROLLER_H
