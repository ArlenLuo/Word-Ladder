#include <iostream>
#include <string>
#include "vector.h"
#include <fstream>
#include "queue.h"
#include "lexicon.h"
using namespace std;

bool onediff(string a,string b);
bool checknew(string a,Vector<string> vec);
void process(string a);

Vector <string> ladder;
Queue <Vector<string> > que;
Lexicon used;
string dw,tmp;
bool flag=0;

int main()
{
    char ch;//check whether the user wants to quit
    string sw;//sw--start word dw--destination word
//    Vector <string ladder,used;
//	Queue <Vector<string> > que;
    while(1)
    {
        ladder.clear();
		que.clear();
        flag=0;
		cout<<"Enter start word (RETURN to quit): ";
        ch=cin.get();
        if(ch=='\n')
        return 0;
        cin.unget();//放回sw的第一个字母
        cin>>sw;
        cout<<"Enter destination word: ";
        cin>>dw;
        if(sw.length()!=dw.length())
        {
            cout<<"Invalid Input!"<<endl;
            cin.ignore();
			continue;
        }
        ladder.push_back(sw);
        if(onediff(sw,dw))
		{ 
		    ladder.push_back(dw);
			cout<<ladder<<endl;
			cin.ignore();
			ladder.clear();
			continue;
		}
        que.enqueue(ladder);
		Lexicon english("EnglishWords.txt");
		used.add(sw);
//        cout<<ladder<<used;
        while (!que.isEmpty())
         {
            ladder = que.dequeue();
	      //  english.mapAll(process);
     		tmp=ladder.get(ladder.size()-1);
//		    tmp2=ladder[ladder.size()-2];
			english.mapAll(process);
  	    	if(flag)
			{
			    ladder.push_back(dw);
	        	cout<<ladder<<endl;
//				ladder.clear();
				que.clear();
				used.clear();
	            break;				;
            }
       	 }
     cin.ignore();//清除输入缓存区的回车键
    } 
}


bool onediff(string a,string b)
{
    int flag1= 0;
	for(int i=0;i<b.length();i++)
	{
	    if (a[i]!=b[i])  flag1++;
	}
	if (flag1==1) return true;
	return false;
}

void process(string a)
{
 //  string tmp=ladder.get(ladder.size()-1);
 //  string tmp2=ladder.get(ladder.size()-2);
  // cout<<"a"<<(a.length()==tmp.length())<<"b"<<onediff(a,tmp)<<"c"<<used.contains(a);
   if ((a.length()==tmp.length())&&(onediff(a,tmp))&&(!(used.contains(a))))
   {
       ladder.push_back(a);
       que.enqueue(ladder);
	   used.add(a);
//       if(onediff(a,dw))
       if(onediff(a,dw)&&(!onediff(ladder[ladder.size()-2],dw)))
       {  
      	   flag=true;
//	       cout<<ladder;
		   return;
       }
//	   {
//	       ladder.push_back(dw);
//	       cout<<ladder<<endl;
//	       ladder.clear();
//	       que.clear();   
//	       return;
//	   }
//       if(onediff(a,dw)) return;
       ladder.remove(ladder.size()-1);
   }
}  
