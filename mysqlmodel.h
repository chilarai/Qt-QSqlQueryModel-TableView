#ifndef MYSQLMODEL_H
#define MYSQLMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>

class MysqlModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit MysqlModel(QObject *parent = nullptr);

    void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    void setQuery(const QSqlQuery &query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void callSql(QString queryString);

private :
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;


signals:

};

#endif // MYSQLMODEL_H
