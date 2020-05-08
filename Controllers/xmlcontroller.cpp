#include "xmlcontroller.h"

XMLController::XMLController(Editor *e, QString filePath):editor(e){
//    completer = new QCompleter(createModelFromFile(openCompleterTemplete(filePath)));
//    e->setCompleter(completer);
    this->filePath = filePath;
}

void XMLController::onTextChanged(){

}

QString XMLController::openCompleterTemplete(QString fp){
    QDir currentDir(fp.mid(0,fp.lastIndexOf("/"))+"/.completer/");
    QString fn = fp.mid(fp.lastIndexOf("/")+1,fp.size()-fp.lastIndexOf("/")-5);
    if(!currentDir.exists()){
        currentDir.mkdir(currentDir.path());
    }
    return currentDir.path()+"/";
}

QAbstractItemModel* XMLController::createModelFromFile(QString fileName){
//    qDebug() << "file name" << fileName;
//    QFile file(fileName);
//    if (!file.open(QFile::ReadOnly))
//        return new QStringListModel();
//    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
//    QStringList words;
//    while (!file.atEnd()) {
//        QByteArray line = file.readLine();
//        if (!line.isEmpty())
//            words << QString::fromUtf8(line.trimmed());
//    }
//    QGuiApplication::restoreOverrideCursor();
//    return new QStringListModel(words);
    // TODO
}
