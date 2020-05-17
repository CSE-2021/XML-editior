#include "data_tree.h"
#include <QTextStream>
#include <QStack>

DataTree::DataTree(const QString inFileName)
{
    QFile *inFileStream = new QFile(inFileName);
    inFileStream->open(QIODevice::ReadOnly | QIODevice::Text);
    parseText(getText(inFileStream));
}

DataTree::DataTree(QFile *inFileStream)
{
    parseText(getText(inFileStream));
}

Block *DataTree::getRoot()
{
    return this->root;
}

const QString DataTree::getText(QFile *inFileStream)
{
    QString fileText = "";
    QString temp;
    QTextStream in(inFileStream);
    while (!in.atEnd())
    {
        temp = in.readLine();
        fileText.append(temp);
    }
    return fileText;
}

void DataTree::parseText(const QString fileText)
{
    QVector<QString> *parts = getPartsOfText(fileText);
    buildTreeFromParts(parts);
}

QVector<QString> *DataTree::getPartsOfText(const QString fileText)
{
    QVector<QString> *parts = new QVector<QString>();
    QString temp = "";
    bool letterExist = false;
    QChar currentLetter;
    unsigned long length = fileText.length();
    for (unsigned long i = 0; i < length; i++)
    {
        currentLetter = fileText.at(i);
        // push the part inside parts in case a new tag(start tag or end tag) is found
        if (currentLetter == '<' && temp != "")
        {
            parts->push_back(temp);
            temp = "<";
            letterExist = false;
        }
        // push the part inside parts in case the current tag is closed
        else if (currentLetter == '>')
        {
            temp += '>';
            parts->push_back(temp);
            temp = "";
            letterExist = false;
        }
        // add the current character to temp
        else if (letterExist || (currentLetter != ' ' && currentLetter != '\t' && currentLetter != '\n'))
        {
            temp += fileText.at(i);
            letterExist = true;
        }
    }
    return parts;
}

void DataTree::buildTreeFromParts(QVector<QString> *parts)
{
    // root is the root block of the tree
    root = new ObjectBlock("root");
    // A stack to store the blocks and which levels they are in
    QStack<Block *> blocksStack;
    blocksStack.push(root);
    QString part;
    for (int i = 0; i < parts->size(); i++)
    {
        part = (*parts)[i];
        // In case the part was a single character like "x" or "y"
        if (part.length() == 1)
        {
            // It is of course a string
            blocksStack.top()->getValue()->push_back(new StringBlock(part));
        }
        else
        {
            // In case of ending tag
            if (part.mid(0, 2) == "</")
            {
                // In case there was no value between the start tag and the end tag
                if ((*parts)[i - 1][0] == '<' && (*parts)[i - 1][1] != '/')
                {
                    blocksStack.top()->getValue()->push_back(new StringBlock(""));
                }
                blocksStack.pop();
            }
            // In case of start tag
            else if (part[0] == '<')
            {
                Block *temp;
                // Create a new block and take the tag name from the tag string
                temp = new ObjectBlock((*parts)[i].mid(1, (*parts)[i].length() - 2));
                // Put the new tag inside the old tag
                blocksStack.top()->getValue()->push_back(temp);
                // push the tag into the stack
                blocksStack.push(temp);
            }
            // In case of a string(value)
            else
            {
                blocksStack.top()->getValue()->push_back(new StringBlock(part));
            }
        }
    }
}

DataTree::~DataTree()
{
    if (root != nullptr)
        delete root;
}
