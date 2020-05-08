#ifndef EDITORCONTROLLER_H
#define EDITORCONTROLLER_H

#include "../GUI/xml_Editor.h"
#include "../GUI/editor.h"
#include "../Highlighter/pythonHighlighter.h"
#include "../Highlighter/xmlHighlighter.h"
#include "xmlcontroller.h"
#include <QObject>
#include <QSyntaxHighlighter>
#include <QAbstractItemModel>
#include <QMap>

class EditorController : public QObject{
    Q_OBJECT
public:
    typedef struct EditorFile{
        QString filePath = "";
        Editor *editor = nullptr;
    } EditorFile;

    static void registerMainWindow(MainWindow*);
    static void addEditor(QString path);
    static void closeEditor(int index);
    static EditorFile getActiveEditorFile();

private:
    static MainWindow *main;
    static QMap <QString, EditorFile*> activeFiles;
    static QPixmap Icon(QString &type);
    static QSyntaxHighlighter *Highlighter(QString &type);
    static void setSyntaxController(QString &type, Editor *e, QString filePath);


};

#endif // EDITORCONTROLLER_H
