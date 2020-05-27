#include "synsetinfo.h"

SynsetInfo::SynsetInfo(QString fileName, QWidget *parent) : QWidget(parent){
    this->setWindowTitle(fileName + " (INFO)");
    this->setWindowFlag(Qt::Drawer);
    wordTXT = new QLineEdit(this);
    availableWordsLST = new QListWidget(this);
    mainLay = new QVBoxLayout();

    this->setLayout(mainLay);
    mainLay->addWidget(wordTXT);
    mainLay->addWidget(availableWordsLST);

}
