#ifndef BLOCK_H_
#define BLOCK_H_

#include <QString>
#include <QVector>
#include "../../Data_Structures/map_vector.h"

using namespace std;

class Block
{
protected:
    QString name;

public:
    Block(QString name);
    void setName(QString name);
    QString getName();
    virtual QVector<Block *> *getValue() = 0;
    virtual Map<QString, QString> *getAttributes() = 0;
    virtual ~Block();
};

#endif /* BLOCK_H_ */
