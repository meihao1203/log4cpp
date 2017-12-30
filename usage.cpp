 //
 /// @file    useage.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-25 16:07:49
 
 
//编译需要加上 -llog4cpp -lpthread
#include"myLog.h"
#include<iostream>
using namespace std;
void func()
{
	logInfo("this is a function");
}
int main()
{
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
//2017-12-25 19:25:46,050: INFO rootCategory : myLog()
//2017-12-25 19:25:46,050: INFO rootCategory : system is running {fileName:usage.cpp functionName:main lineNumber:17}
//2017-12-25 19:25:46,051: WARN rootCategory : system has a warning {fileName:usage.cpp functionName:main lineNumber:18}
//2017-12-25 19:25:46,051: ERROR rootCategory : system has a error {fileName:usage.cpp functionName:main lineNumber:19}
//2017-12-25 19:25:46,051: FATAL rootCategory : system has a fatal {fileName:usage.cpp functionName:main lineNumber:20}
//2017-12-25 19:25:46,051: INFO rootCategory : this is a function {fileName:usage.cpp functionName:func lineNumber:13}
//2017-12-25 19:25:46,051: INFO rootCategory : myLog destroy
//2017-12-25 19:25:46,051: INFO rootCategory : ~mylog()
