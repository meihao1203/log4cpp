 ///
 /// @file    CategoryExam.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-25 10:34:54
 ///
 
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>
using namespace std;
using namespace log4cpp;
int main(int argc,char **argv)
{
	OstreamAppender* osAppender1 = new OstreamAppender("osAppender1",&cout);
	osAppender1->setLayout(new BasicLayout());

	OstreamAppender* osAppender2 = new OstreamAppender("osAppender2",&cout);
	osAppender2->setLayout(new BasicLayout());

	Category& root = Category::getRoot();   //根Category只有一个，但是可以有多个子Category
	root.setPriority(Priority::DEBUG);

	Category& sub1 = root.getInstance("sub1");
	sub1.addAppender(osAppender1);
	sub1.setPriority(Priority::DEBUG);   //优先级700
	sub1.error("sub error");   //优先级300

	 Category& sub2 = root.getInstance("sub2");
	 sub2.addAppender(osAppender2);
	 sub2.setPriority(101);
	 sub2.warn("sub2 warning");   //优先级400
	 sub2.fatal("sub2 fatal");    //优先级0
	 sub2.alert("sub2 alert");    //优先级0
	 sub2.crit("sub2 crit");      //优先级200

	 Category::shutdown();
	 return 0;
}
//1514170607 ERROR sub1 : sub error
//1514170607 FATAL sub2 : sub2 fatal
//1514170607 ALERT sub2 : sub2 alert
