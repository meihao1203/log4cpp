 //
 /// @file    usage.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-25 16:07:49
 
 
//编译需要加上 -llog4cpp -lpthread
#include"myLog.h"
#include"add.h"
#include<iostream>
using namespace std;
void func()
{
	logInfo("this is a function");
}
int main()
{
	add();
	logInfo("system is running");
	logWarn("system has a warning");
	logError("system has a error");
	logFatal("system has a fatal");
	logSetpriority(ERROR);  //重新设置优先级
	logWarn("warn again");  //Warn的优先级小于ERROR,这条信息将不会被记录
	logSetpriority(DEBUG);  //为了记录下面代码的日志信息,INFO的优先级也是小于ERROR的
	func();
	logDestroy();  //程序结束，销毁myLog对象
	return 0;
}
//2018-07-18 09:29:05,889: INFO rootCategory : myLog()
//2018-07-18 09:29:05,889: INFO rootCategory : add func {fileName:add.cpp functionName:add lineNumber:12}
//2018-07-18 09:29:05,889: INFO rootCategory : system is running {fileName:usage.cpp functionName:main lineNumber:19}
//2018-07-18 09:29:05,889: WARN rootCategory : system has a warning {fileName:usage.cpp functionName:main lineNumber:20}
//2018-07-18 09:29:05,890: ERROR rootCategory : system has a error {fileName:usage.cpp functionName:main lineNumber:21}
//2018-07-18 09:29:05,890: FATAL rootCategory : system has a fatal {fileName:usage.cpp functionName:main lineNumber:22}
//2018-07-18 09:29:05,890: INFO rootCategory : this is a function {fileName:usage.cpp functionName:func lineNumber:14}
//2018-07-18 09:29:05,890: INFO rootCategory : myLog destroy
//2018-07-18 09:29:05,890: INFO rootCategory : ~mylog()
