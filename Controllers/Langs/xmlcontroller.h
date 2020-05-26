#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H

#include "langcontroller.h"
#include "Core/data_tree.h"
#include "Core/Block/block.h"
#include "Data_Structures/map_vector.h"

class XMLController : public LangController{
    Q_OBJECT
public:
    XMLController(Editor *e, QString filePath);
    ~XMLController();
    void onTextChanged() override;
    void beautify();
    void minify();
    int getSynsetNumber();
private:
    typedef struct Info{
        QString tagName;
        Map<QString, QString> *attr;
        TagType type;
    } Info;
    void _readTree(Block *root, int level, QList<QString> &tagList, QList<QPair<Info, int>> &queue);
    static QString _buildXML(QList<QPair<Info, int>> &queue);
    int synsetNumber = 0;
    QList<QString> tagList;
    QList<QPair<Info, int>> l_queue;
};

#endif // XMLCONTROLLER_H
