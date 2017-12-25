 ///
 /// @file    HelloLog4Cpp.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 15:33:50
 ///
 
//系统中可以有多个Category，它们都继承自同一个跟root，每个Category负责记录自己的日志；
//每个Category可以添加多个Appender(目的地，日志要输出到哪),每个Appender制定了一个日志的目的地；
//这个目的地可以是文件，字符流或者windows日志，当Category记录一条日志时，该日志被写入所有
//附加到此Category的Appender；
//每个Append都包含一个Layout,该Layout定义了这个Appender上日志的格式。
//
//步骤：
//1. 创建一个Appender，并指定其包含的Layout；
//2. 从系统中得到Category的根，将Appender添加到该Category中；
//3. 设置Category的优先级；
//4. 记录日志；
//5. 关闭Category。
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>
using namespace std;
//引入命名空间log4cpp就可以不用加作用名限定log4cpp::
int main(int argc,char *argv[])
{
	//指定日志输出目的地;附加目的地，cout，输出终端;堆对象，防止超出作用域被释放
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	//设置格式化日志信息;设置APPender的布局
	osAppender->setLayout(new log4cpp::BasicLayout());
	//负责输出日志；得到系统的根root
	log4cpp::Category& root = log4cpp::Category::getRoot();
	//把设置好的Append添加到系统root下
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	//写日志
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");
	//关闭日志
	log4cpp::Category::shutdown();
	return 0;
}
//1514104975 ERROR  : Hello log4cpp in a Error Message!
//1514104975 WARN  : Hello log4cpp in a Warning Message!
