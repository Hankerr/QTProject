#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QDomNode>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument doc;
    QFile file("myxml.xml");

    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"File Open Fail";

    if(!doc.setContent(&file)){
        file.close();
        qDebug()<<"document";
    }
    file.close();

    QDomNode firstNode=doc.firstChild();
    //qDebug()<<firstNode.nodeName()<<":"<<firstNode.nodeValue()<<endl;
    qDebug()<<qPrintable(firstNode.nodeName())<<":"<<qPrintable(firstNode.nodeValue())<<endl;

    QDomElement docElem=doc.documentElement();//返回根元素
    QDomNode n=docElem.firstChild();
    while(!n.isNull()){
        if(n.isElement()){
            QDomElement e=n.toElement();
            qDebug()<<qPrintable(e.tagName())
                   <<qPrintable(e.attribute("id"));
            //输出标签中内容
            QDomNodeList list=e.childNodes();
            for(int i=0;i<list.count();i++){
                QDomNode node=list.at(i);
                qDebug()<<" "<<qPrintable(node.toElement().tagName())
                       <<" "<<qPrintable(node.toElement().nodeValue());
            }
        }
        n=n.nextSibling();
    }
    return a.exec();
}
