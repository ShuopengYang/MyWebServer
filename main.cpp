#include "config.h"

int main(int argc, char *argv[])
{
    //需要修改的数据库信息,登录名,密码,库名
    string user = "root";
    string passwd = "root";
    string databasename = "qgydb";

    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    //日志
    server.log_write();

    //数据库
    server.sql_pool();

    //线程池
    server.thread_pool();

    //触发模式
    server.trig_mode();

    //监听
    server.eventListen();

    //运行
    server.eventLoop();

    return 0;
}
/*
sudo即为super user do的意思，sudo是linux系统管理指令，是允许系统管理员让普通用户执行
一些或者全部的root命令的一个工具，如halt，reboot，su等等。这样不仅减少了root用户的登录
和管理时间，同样也提高了安全性。sudo不是对shell的一个代替，它是面向每个命令的。

su，switch user，su命令是在用户间切换，可以是从普通用户切换到root用户，也可以是从root用户
切换到普通用户，当由普通用户切换到root用户时，需要认证密码。

mysql -u root -p
-u username
-p password

创建数据库
create database 数据库名;
建立yourdb库
create database yourdb;

切换数据库
use 数据库名;
USE yourdb;

创建表
create table 表名(
字段名 类型（长度） 约束,
字段名 类型（长度） 约束
);
创建user表
CREATE TABLE user(
    username char(50) NULL,
    passwd char(50) NULL
)ENGINE=InnoDB;

插入记录
insert into 表(列名1,列名2.....) values(值1,值2...);
INSERT INTO user(username, passwd) VALUES('name', 'passwd');

删除表
drop table 表名;
drop table user;

.sh脚本文件就是存放执行命令的文件
例如：test.sh的内容是：
mkdir test
cd test
touch test.txt
vim tset.txt
如果执行这个脚本文件就相当于在终端执行了以上四句命令。

sh – dash
./ – bash
source --bash

sh test.sh 、bash test.sh 、 ./test.sh

从Ubuntu 6.10开始，默认使用dash(theDebian Almquist Shell)而不是bash
(the GNUBourne-Again Shell). 但Login Shell还是bash. 原因是dash更快、更高效，
而且它符合POSIX规范。Ubuntu在启动的时候会运行很多shell脚本，使用dash可以加快启动速度。
如果解决bash和dash兼容性导致的问题
在需要bash的脚本的第一行写上"#!/bin/bash"
在Makefile中可以设置
SHELL = /bin/bash

sh ./build.sh

make命令是一个常用的编译命令，尤其在C/C++开发中，make命令通过makefile文件中描述源程序之间的依赖关系进行自动编译；
makefile文件是按照规定格式编写，需说明如何编译各个源文件并连接生成可执行文件，并要求定义源文件之间的依赖关系；

makefile中“?=”表示如果该变量没有被赋值，则赋予等号后的值。举例：
VIR ?= new_value
如果VIR在之前没有被赋值，那么现在VIR的值就为new_value

makefile中，$的意思是取变量的意思，比如，a=4;那么在后面的语句中，$a 就代表的是取a的值

+=：意思就是添加等号后面的值

rm是linux系统下删除文件的命令....-r 代表删除这个下面的一切，一切的一切那种的一切。

g++ -o -c -g 功能

-o：指定生成可执行文件的名称。使用方法为：g++ -o afile file.cpp file.h ... （可执行文件不可与待编译或链接文件同名，否则会生成相应可执行文件且覆盖原编译或链接文件），如果不使用-o选项，则会生成默认可执行文件a.out。
-c：只编译不链接，只生成目标文件。
-g：添加gdb调试选项。

g++ helloworld.cpp -o helloworld

-l(小写的L) 给gcc 指定具体的库
例如：gcc需要一个库A
-lA

-O2： 表示编译时使用二级优化。

-g
-g可执行程序包含调试信息
-g为了调试用的
加个-g 是为了gdb 用，不然gdb用不到

ifndef/define/endif
主要目的是防止头文件的重复包含和编译
*/