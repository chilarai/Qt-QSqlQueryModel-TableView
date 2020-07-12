# Qt QSqlQueryModel-TableView

This is a sample project to connect TableView in Qml to QSqlQueryModel.

## Important Notes

-   In the `.pro` file, add

```sh
Qt += sql
```

-   **main.cpp**: Change the credentials in `main.cpp`

```sh
dbMysql.setHostName("SERVER");
dbMysql.setPort(3306);
dbMysql.setDatabaseName("DATABASE");
dbMysql.setUserName("DB_USER");
dbMysql.setPassword("DB_PASSWORD");
```

-   **mysqlmodel.h**

In Reference 1 (See References below), the code provided assumes that the select query fields will be finite. However, if we want dynamic queries where we do not know the field names then we have to do the following

```sh
QHash<int, QByteArray> roleNames() const {return m_roleNames;}
```

with

```sh
QHash<int, QByteArray> roleNames() const {return {{Qt::DisplayRole, "display"}};}
```

The above code can be Refactored and moved to `.cpp` file

### References

> [1. https://wiki.qt.io/How_to_Use_a_QSqlQueryModel_in_QML](https://wiki.qt.io/How_to_Use_a_QSqlQueryModel_in_QML)

> [2. https://github.com/eyllanesc/stackoverflow/tree/master/questions/55610163](https://github.com/eyllanesc/stackoverflow/tree/master/questions/55610163)
