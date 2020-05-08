#include "xmlHighlighter.h"

XMLHighlighter::XMLHighlighter(QTextDocument *parent):Highlighter(parent){
    addRule(QRegularExpression(QString("<[^>]+>|\\n+")), format(QColor(Qt::magenta), Highlighter::BOLD));
    addRule(QRegularExpression(QString("<|>|/")), format(QColor(Qt::lightGray)));
    addRule(QRegularExpression(QString("[0-9]+")), format(QColor(Qt::darkYellow)));
}
