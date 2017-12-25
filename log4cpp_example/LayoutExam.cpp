 ///
 /// @file    LayoutExam.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 17:10:49
 ///
 
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;
int main(int argc,char* argv[])
{
	OstreamAppender* osAppender = new OstreamAppender("osAppender",&cout);
	PatternLayout* pLayout = new PatternLayout();
	pLayout->setConversionPattern("%d: %p %c %x: %m%n"); 
	//时间(默认格式) 优先级 Category NDC：消息 换行
	//NDC(嵌套的诊断上下文),%c 到时候就是输出下面的infoCategory
	osAppender->setLayout(pLayout);

	Category& root = Category::getRoot();
	//获取root下的一个实例，因为系统只有一个根，根下可以有多个Category，不能统一直接对root设置样式，除非所有日志记录都采用一样的样式
	Category& infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);
	infoCategory.setPriority(Priority::INFO);

	infoCategory.info("system is running");
	infoCategory.warn("system has a warning");
	infoCategory.error("system has a error,can't find a file");
	infoCategory.fatal("system has a fatal error,must be shutdown");
	infoCategory.info("system shutdown,you can find some information in system log");

	Category::shutdown();
	return 0;
}
//2017-12-24 17:33:56,230: INFO infoCategory : system is running
//2017-12-24 17:33:56,230: WARN infoCategory : system has a warning
//2017-12-24 17:33:56,230: ERROR infoCategory : system has a error,can't find a file
//2017-12-24 17:33:56,230: FATAL infoCategory : system has a fatal error,must be shutdown
//2017-12-24 17:33:56,230: INFO infoCategory : system shutdown,you can find some information in system log
