#include "GUI/xml_Editor.h"
#include "Controllers/guiController.h"
#include "Controllers/editorcontroller.h"

#include <QApplication>

#include "sqliteDriver/sqlite.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QFile styleFile ("://style.css");
    styleFile.open(QIODevice::ReadOnly);
    QString style = styleFile.readAll();
    a.setStyleSheet(style);

    MainWindow w;
    GUIContoller::registerMainWindow(&w);
    EditorController::registerMainWindow(&w);
    w.show();

//    SQLite s;
//    if (s.open("/home/mgtm/Projects/build-IDE-Desktop_Qt_5_13_2_GCC_64bit-Debug/test.db.sqlite")) qDebug("Opened");
//    s.sql_create("CompleterWords", {"id", "word", "occurence"},{"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT"});
//    s.sql_close();
    return a.exec();
}
