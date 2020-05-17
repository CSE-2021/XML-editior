#include <stack>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QStack>
#include "files_converter.h"

FilesConverter::FilesConverter(DataTree *dataTree, QString fileName) : dataTree{dataTree}
{
    QFile *fileStream = new QFile(fileName);
    fileStream->open(QIODevice::WriteOnly | QIODevice::Text);
    out = new QTextStream(fileStream);
}

void FilesConverter::generateXMLFile()
{
}

void FilesConverter::generateJSONFile()
{
    Block *root = dataTree->getRoot();
    (*out) << '{' << endl;
    indentCounter = 1;
    for (int i = 0; i < root->getValue()->size(); i++)
    {
        if (i == root->getValue()->size() - 1)
        {
            generateJSONObject((*(root->getValue()))[i], true);
        }
        else
        {
            generateJSONObject((*(root->getValue()))[i], false);
        }
    }
    (*out) << '}' << endl;
}

void FilesConverter::generateJSONObject(Block *currentBlock, bool isLast)
{
    if (currentBlock->getValue() == nullptr)
    {
        (*out) << '"' << currentBlock->getName() << "\"" << (isLast ? "" : ",") << endl;
    }
    else
    {
        if (currentBlock->getValue()->size() == 1 && (*(currentBlock->getValue()))[0]->getValue() == nullptr)
        {
            for (unsigned i = 0; i < indentCounter; i++)
            {
                (*out) << '\t';
            }
            (*out) << '"' << currentBlock->getName() << "\": ";
            generateJSONObject((*(currentBlock->getValue()))[0], isLast);
        }
        else
        {
            for (unsigned int i = 0; i < indentCounter; i++)
            {
                (*out) << '\t';
            }
            (*out) << '"' << currentBlock->getName() << "\": {" << endl;
            indentCounter++;
            for (int i = 0; i < currentBlock->getValue()->size(); i++)
            {

                if (i == currentBlock->getValue()->size() - 1)
                {
                    generateJSONObject((*(currentBlock->getValue()))[i], true);
                }
                else
                {
                    generateJSONObject((*(currentBlock->getValue()))[i], false);
                }
            }
            indentCounter--;
            for (unsigned int i = 0; i < indentCounter; i++)
            {
                (*out) << '\t';
            }
            (*out) << "}" << (isLast ? "" : ",") << endl;
        }
    }
}

FilesConverter::~FilesConverter()
{
    if (out != nullptr)
        delete out;
}
