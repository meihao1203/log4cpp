 ///
 /// @file    myLog.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-18 09:14:46
 ///
 
#include<iostream>
#include"myLog.h"
using namespace std;
myLog* myLog::_plog = NULL;
//构造函数
myLog::myLog():rootCategory(log4cpp::Category::getRoot().getInstance("rootCategory"))
{
	//获取根Category，引用成员必须在成员初始化列表初始化
	
	//根Category下添加子Category
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	log4cpp::PatternLayout* pLayout1 = new log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	osAppender->setLayout(pLayout1);
	rootCategory.addAppender(osAppender);
	rootCategory.setPriority(log4cpp::Priority::DEBUG);

	//log文件会一直记录
	log4cpp::FileAppender*fileAppender = new log4cpp::FileAppender("fileAppender","log");
	log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout();
	pLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	fileAppender->setLayout(pLayout2);
	rootCategory.addAppender(fileAppender);
	rootCategory.setPriority(log4cpp::Priority::DEBUG);

	//logrolling.log不超过指定大小，默认10M；这里我设置了5M,备份文件5个
//如果想要用备份带回卷的日志文件记录方式，就把这里的注释去掉
//	log4cpp::RollingFileAppender* rollingfileAppender = new log4cpp::RollingFileAppender(
//			"rollingfileAppender","logrolling.log",5*1024,5);
//	log4cpp::PatternLayout* pLayout3 = new log4cpp::PatternLayout();
//	pLayout3->setConversionPattern("%d: %p %c %x: %m%n");
//	rollingfileAppender->setLayout(pLayout3);
//	rootCategory.addAppender(rollingfileAppender);
//	rootCategory.setPriority(log4cpp::Priority::DEBUG);
	
	rootCategory.info("myLog()");
}
myLog::~myLog()
{
	rootCategory.info("~mylog()");
	rootCategory.shutdown();   
}
void myLog::destroy()
{
	_plog->rootCategory.info("myLog destroy");   //静态函数内部没有隐士传递的this指针，所以必须要用_plog对象指针来调用
	delete _plog;   //delete的处理方式是：先调用析构函数，然后在释放空间；
	//所以可以在析构函数里再向日志里打印信息，然后再关掉rootCategory
	_plog = NULL;
}
myLog* myLog::getInstance()
{
	if(NULL==_plog)
	{
		_plog = new myLog();
	}
	return _plog;
}
//类对象调用,重新设置rootCategory优先级
void myLog::setPriority(myPriority priority)
{
	switch(priority)
	{
		case FATAL:rootCategory.setPriority(log4cpp::Priority::FATAL);break;
		case ERROR:rootCategory.setPriority(log4cpp::Priority::ERROR);break;
		case WARN:rootCategory.setPriority(log4cpp::Priority::WARN);break;
		case INFO:rootCategory.setPriority(log4cpp::Priority::INFO);break;
		case DEBUG:rootCategory.setPriority(log4cpp::Priority::DEBUG);break;
		default:
				   rootCategory.setPriority(log4cpp::Priority::DEBUG);break;
	}
}
void myLog::error(const char* msg)
{
	rootCategory.error(msg);
}
void myLog::warn(const char* msg)
{
	rootCategory.warn(msg);
}
void myLog::info(const char* msg)
{
	rootCategory.info(msg);
}
void myLog::debug(const char* msg)
{
	rootCategory.debug(msg);
}
void myLog::fatal(const char* msg)
{
	rootCategory.fatal(msg);
}
string int2string(int lineNumber)
{
	ostringstream oss;
	oss<<lineNumber;
	return oss.str();
}
