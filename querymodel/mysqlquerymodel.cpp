#include "mysqlquerymodel.h"
#include <QSqlQuery>
#include <QColor>

MySqlQueryModel::MySqlQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

Qt::ItemFlags MySqlQueryModel::flags(
        const QModelIndex &index) const //���ر���Ƿ�ɸ��ĵı�־
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1) //�ڶ����ֶοɸ���
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool MySqlQueryModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
//�������
{
    if (index.column() < 1 || index.column() > 2)
        return false;
    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt(); //��ȡid��
    clear();
    bool ok;
    if (index.column() == 1) //�ڶ����ֶοɸ���
        ok = setName(id, value.toString());
    refresh();
    return ok;
}

void MySqlQueryModel::refresh() //������ʾ
{
    setQuery("select * from student");
    setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
}

//���name�ֶε�ֵ
bool MySqlQueryModel::setName(int studentId, const QString &name)
{
    QSqlQuery query;
    query.prepare("update student set name = ? where id = ?");
    query.addBindValue(name);
    query.addBindValue(studentId);
    return query.exec();
}

//����������ʾ��ʽ
QVariant MySqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    //��һ���ֶε�������ɫΪ��ɫ
    if (role == Qt::TextColorRole && index.column() == 0)
        return qVariantFromValue(QColor(Qt::red));
    return value;
}
