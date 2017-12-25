 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-25 16:07:49
 ///
 
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
	func();
	logDestroy();  //程序结束，销毁myLog对象
	return 0;
}
//2017-12-25 17:22:43,932: INFO rootCategory : myLog()
//2017-12-25 17:22:43,932: INFO rootCategory : system is running {fileName:test.cpp functionName:main lineNumber:17}
//2017-12-25 17:22:43,932: WARN rootCategory : system has a warning {fileName:test.cpp functionName:main lineNumber:18}
//2017-12-25 17:22:43,933: ERROR rootCategory : system has a error {fileName:test.cpp functionName:main lineNumber:19}
//2017-12-25 17:22:43,933: FATAL rootCategory : system has a fatal {fileName:test.cpp functionName:main lineNumber:20}
//2017-12-25 17:22:43,933: INFO rootCategory : this is a function {fileName:test.cpp functionName:func lineNumber:13}
//2017-12-25 17:22:43,933: INFO rootCategory : myLog destroy
//2017-12-25 17:22:43,933: INFO rootCategory : ~mylog()
