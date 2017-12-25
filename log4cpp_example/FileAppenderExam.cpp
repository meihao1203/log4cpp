 ///
 /// @file    FileAppenderExam.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 19:04:49
 ///
 
#include<iostream>
#include<string>
#include<sstream>
#include<log4cpp/Category.hh>
#include<log4cpp/Appender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
using namespace std;
using namespace log4cpp;
int main(int argc,char **argv)
{
	//Layout与Appender是一对一的关系
	//Category与Appender是一对多的关系, 可以同时往两个Appender指定的文件写东西
	//设置日志的输出目的地，这里是两种不同的输出到文件的方式；
	FileAppender* fileAppender = new FileAppender("fileAppender","mylog.log");
	RollingFileAppender* rollingfileAppender = new RollingFileAppender(
	//设置输出目的地，回滚文件大小，备份数量
			"rollingfileAppender","mylogrolling.log",5*1024,1);

	//设置日志格式
	PatternLayout* pLayout1 = new PatternLayout();
	PatternLayout* pLayout2 = new PatternLayout();
	pLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	pLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	fileAppender->setLayout(pLayout1);
	rollingfileAppender->setLayout(pLayout2);

	//设置输出日志
	Category& root = Category::getRoot().getInstance("RootName");
	root.addAppender(fileAppender);
	root.addAppender(rollingfileAppender);

	//写日志
	for(int i=0;i<100;i++)
	{
		string strError;
		ostringstream oss;
		oss<<i<<":Root Error Message!";
		strError = oss.str();
		root.error(strError);
	}
	
	//关闭日志
	Category::shutdown();
	return 0;
}
