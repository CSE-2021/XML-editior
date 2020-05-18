#ifndef DATA_TREE_H_
#define DATA_TREE_H_

#include <QFile>
#include "Block/object_block.h"
#include "Block/string_block.h"

class DataTree
{
private:
    Block *root = nullptr;
    static QString getText(QFile *inFileStream);
    void parseText(QString fileText);
    QVector<QString> *getPartsOfText(QString fileText);
    void buildTreeFromParts(QVector<QString> *);

public:
    DataTree(QString fileText);
    static DataTree *readFile(Qstring inFileName);
    DataTree(QFile *inFileStream);
    Block *getRoot();
    ~DataTree();
};

#endif // DATA_TREE_H_
