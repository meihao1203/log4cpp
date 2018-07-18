 ///
 /// @file    myLog.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-25 15:03:32
 ///
 
#ifndef __MYLOG_H__
#define __MYLOG_H__
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/Appender.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<string>
#include<sstream>
using namespace std;
//using namespace log4cpp;   //为了程序可读性好,下面都自己加上作用域限定
//单例类封装log4cpp

enum myPriority{EMERG,FATAL,ALERT,CRIT,ERROR,WARN,NOTICE,INFO,DEBUG};
class myLog
{
	public:
		static myLog* getInstance();   
		static void destroy();
		void setPriority(myPriority priority);   //myPriority 我把它定义为一种enum类型
		void fatal(const char* msg);
		void error(const char* msg);
		void warn(const char* msg);
		void info(const char* msg);
		void debug(const char* msg);
	private:
		static myLog* _plog;
		log4cpp::Category& rootCategory;
	private:
		myLog();
		~myLog();
};
/***********************myLog类定义完毕***********************/
/***********************定义一些宏，引用的时候直接展开，让myLog使用更方便***********************/
//把要输出的消息拼接上文件名，所在函数名，所在行号;msg是const char*，所以最后用c_str()函数进行转换
//__FILE__ __func__ __LINE 这几个宏定义是编译器识别的，__LINE__是int类型
//分别是文件名，函数名，所在行号
//防止在函数中调用，减少调用开销，声明成内联函数
string int2string(int lineNumber);
#define catMsg(msg) string(msg).append(" {fileName:")\
	.append(__FILE__).append(" functionName:")\
	.append(__func__).append(" lineNumber:")\
	.append(int2string(__LINE__)).append("}").c_str()
//单例类，只有一个对象
static myLog* log  = myLog::getInstance();
#define logSetpriority(priority) log->setPriority(priority)
#define logError(msg) log->error(catMsg(msg))
#define logWarn(msg) log->warn(catMsg(msg))
#define logInfo(msg) log->info(catMsg(msg))
#define logDebug(msg) log->debug(catMsg(msg))
#define logFatal(msg) log->fatal(catMsg(msg))
#define logDestroy() myLog::destroy()

#endif
