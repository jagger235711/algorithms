/*
@Author: 张恩博
@Date:   2022年4月28日
@Function:根据描述完成开题答辩自动分组算法设计问题，写出算法描述过程
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//职称
const int JIAOSHOU = 5;	  //教授
const int FUJIAOSHOU = 4; //副教授
const int JIANGSHI = 3;	  //讲师
const int JIAOSHOU2 = 2;//杜晓盺老师的职位 
const int JIANGSHI2 = 2;//吴迪老师的职位 

//研究方向
const int JAVA = 1;
const int C = 2;
const int CSHARP = 3; //C#
const int PYTHON = 4;
const int ASP = 5;
const int JS = 6;
const int WEB_HTML = 7;	 //前端
const int NET = 8; //NET
const int CPP = 9;
const int H5 = 10; //html5
const int VB = 11;

//研究方向名称
const char* research_str[] = { "NULL", "Java", "C", "C#", "Python", "ASP", "JS","前端编程", "NET", "C++","HTML5","VB" };

struct Teacher
{
	int index;		  //id
	string name;	  //姓名
	int level;		  //职称
	int* research;	  //研究方向
	int research_cnt; //研究方向个数
	int student_cnt;  //学生数量
};

//按职称排序
bool cmp(const Teacher& a, const Teacher& b)
{
	return a.level > b.level;
}

//最大 小组数量
const int maxgroupcnt = 10;
//最大 学生数量
const int student_count = 150;

//老师数量
const int teacher_count = 9;
//小组数量
const int group_count = 2;

//储存老师信息
Teacher t[teacher_count + 1];

//储存规划信息
int dp[teacher_count + 10][student_count + 10];

//初始化教师信息
void init_teacher();
//动态规划分组（两组学生人数相差最少）
void dp_group();

struct GroupInfo
{
	//记录组中的老师ID
	vector<int> group;
	//小组教师人数
	int teacher_cnt;
	//小组学生人数
	int student_cnt;
	//职称
	map<int, int> title;
	//研究方向
	map<int, int> research;
} gi[group_count + 1];

//将小组按教师人数排序
bool cmp_g(const GroupInfo& a, const GroupInfo& b)
{
	return a.teacher_cnt < b.teacher_cnt;
}

//更新教师ID，使ID与数组下标相对应
void updateIndex()
{
	for (int i = 1; i <= teacher_count; i++)
		t[i].index = i;
}

int main()
{
	//初始化教师信息
	init_teacher();
	//按照职称排序教师信息
	sort(t + 1, t + teacher_count, cmp);
	updateIndex();

	cout << "----------以下为所有教师的信息：----------" << endl;
	printf("%-4s %-12s %-10s %-5s", "序号", "姓名", "学生人数", "研究方向\n");
	for (int i = 1; i <= teacher_count; i++)
	{
		printf("%-4d %-12s %-11d", i, t[i].name.c_str(), t[i].student_cnt);

		for (int j = 0; j < t[i].research_cnt; j++)
		{
			if (j == 0)
				printf("%s ", research_str[t[i].research[j]]);
			else
				printf(", %s ", research_str[t[i].research[j]]);
		}
		printf("\n");
	}
	cout << "------------------------------------------" << endl;

	//按学生人数分组
	dp_group();
	return 0;
}

//初始化老师信息
void init_teacher()
{
	t[1].index = 1;
	t[1].name = "张剑飞教授";
	t[1].level = JIAOSHOU;
	t[1].research_cnt = 1;
	t[1].research = new int[t[0].research_cnt];
	t[1].research[0] = JAVA;
	t[1].student_cnt = 16;

	t[2].index = 2;
	t[2].name = "王一萍副教授";
	t[2].level = FUJIAOSHOU;
	t[2].research_cnt = 2;
	t[2].research = new int[t[2].research_cnt];
	t[2].research[0] = C;
	t[2].research[1] = CPP;
	t[2].student_cnt = 15;


	t[3].index = 3;
	t[3].name = "杜晓昕教授";
	t[3].level = JIAOSHOU2;
	t[3].research_cnt = 2;
	t[3].research = new int[t[3].research_cnt];
	t[3].research[0] = JAVA;
	t[3].research[1] = ASP;
	t[3].student_cnt = 20;


	t[4].index = 4;
	t[4].name = "金涛副教授";
	t[4].level = FUJIAOSHOU;
	t[4].research_cnt = 2;
	t[4].research = new int[t[4].research_cnt];
	t[4].research[0] = JAVA;
	t[4].research[1] = CSHARP;
	t[4].student_cnt = 15;

	t[5].index = 5;
	t[5].name = "姜永增副教授";
	t[5].level = FUJIAOSHOU;
	t[5].research_cnt = 4;
	t[5].research = new int[t[5].research_cnt];
	t[5].research[0] = CSHARP;
	t[5].research[1] = ASP;
	t[5].research[2] = H5;
	t[5].research[3] = VB;
	t[5].student_cnt = 15;

	t[6].index = 6;
	t[6].name = "梁伟讲师";
	t[6].level = JIANGSHI;
	t[6].research_cnt = 2;
	t[6].research = new int[t[6].research_cnt];
	t[6].research[0] = JAVA;
	t[6].research[1] = JS;
	t[6].student_cnt = 10;

	t[7].index = 7;
	t[7].name = "吴迪讲师";
	t[7].level = JIANGSHI2;
	t[7].research_cnt = 2;
	t[7].research = new int[t[7].research_cnt];
	t[7].research[0] = PYTHON;
	t[7].research[1] = CSHARP;
	t[7].student_cnt = 10;

	t[8].index = 8;
	t[8].name = "诸葛亮教授";
	t[8].level = JIAOSHOU;
	t[8].research_cnt = 2;
	t[8].research = new int[t[8].research_cnt];
	t[8].research[0] = JAVA;
	t[8].research[1] = PYTHON;
	t[8].student_cnt = 0;

	t[9].index = 9;
	t[9].name = "周瑜副教授";
	t[9].level = FUJIAOSHOU;
	t[9].research_cnt = 2;
	t[9].research = new int[t[9].research_cnt];
	t[9].research[0] = NET;
	t[9].research[1] = WEB_HTML;
	t[9].student_cnt = 0;
}

//输出分组信息
void printGroup()
{
	for (int g = 1; g <= group_count; g++)
	{
		printf("第%d组:", g);
		int isum = 0;
		int lvmax = 0, lvmaxid = 0;
		int lvmin = 0x3f3f3f3f, lvminid = 0;
		for (int i = 0; i < gi[g].teacher_cnt; i++)
		{
			Teacher tmp = t[gi[g].group[i]];
			isum += tmp.student_cnt;
			printf("%s[%d]  ", tmp.name.c_str(), tmp.student_cnt);

			if (tmp.level > lvmax)
			{
				lvmax = tmp.level;
				lvmaxid = tmp.index;
			}
			if (tmp.level <= lvmin)
			{
				lvmin = tmp.level;
				lvminid = tmp.index;
			}
		}
		printf("小组总人数:%d  组长：%s  秘书：%s\n", isum, t[lvmaxid].name.c_str(), t[lvminid].name.c_str());
	}
}

//根据学生人数分组
void dp_group()
{
	//记录学生人数为0的老师（不进入规划分组），即不能包括外援老师
	//未来可以利用此映射进行更多的扩展，例如自定义不进入分组规划的老师等等
	map<int, bool> ban_t;
	//储存不进入规划分组的教师编号
	vector<int> ban_vec;
	//学生总人数
	int sum = 0;
	for (int i = 1; i <= teacher_count; i++)
	{
		sum += t[i].student_cnt;

		if (t[i].student_cnt == 0)
		{
			ban_t[i] = true;
			ban_vec.push_back(i);
		}
	}

	for (int i = 1; i <= teacher_count; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];

			//不进入分组规划的老师直接跳过（其实不跳过也不影响结果）
			if (ban_t[i])
				continue;

			if (j >= t[i].student_cnt)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i].student_cnt] + t[i].student_cnt);
			}
		}
	}

	//记录老师是否完成分组
	map<int, bool> finish;
	//理想的每组人数
	int diff = sum / group_count;
	//根据规划结果倒推每个小组具体是哪些教师
	for (int g = 1; g <= group_count; g++)
	{
		int i = teacher_count, j = diff * g;

		if (g == group_count)
			j = sum;

		while (i > 0 && j > 0)
		{
			//不进入分组规划的老师不进入分组结果倒推中
			if (ban_t[i])
			{
				i--;
				continue;
			}

			if (dp[i][j] == dp[i - 1][j - t[i].student_cnt] + t[i].student_cnt)
			{
				if (!finish[i])
				{
					gi[g].group.push_back(i);
					finish[i] = true;

					Teacher tmp = t[i];
					//记录该组各称职人数
					gi[g].title[tmp.level]++;

					//记录该组教师研究方向
					for (int r = 0; r < tmp.research_cnt; r++)
						gi[g].research[tmp.research[r]]++;
				}

				j -= t[i].student_cnt;
			}
			i--;
		}

		gi[g].teacher_cnt = gi[g].group.size();
	}

	printf("1、 按学生人数差最小得出的分组如下：\n");
	printf("\n");
	printGroup();

	cout << "------------------------------------------" << endl;

	//按教师人数排序，最前面的小组教师人数最少
	sort(gi + 1, gi + group_count, cmp_g);

	//剩余待分配的教师人数
	int remain_cnt = ban_vec.size();
	while (remain_cnt > 0)
	{
		for (int g = 1; g <= group_count; g++)
		{
			//两组之间教师相差人数+1
			int tdiff = 1;
			if (g + 1 < group_count)
				tdiff = gi[g + 1].teacher_cnt - gi[g].teacher_cnt + 1;

			//按职称分配组
			while (tdiff--)
			{
				if (remain_cnt <= 0)
					break;

				int i = 0;
				//在待分配教师容器内找一个在该组内不存在某职称的教师
				do
				{
					//获取当前待分配的教师职称并判断在gi[g]组内是否存在
					Teacher ban_t_tmp = t[ban_vec[i]];
					int lv = ban_t_tmp.level;

					//该组内不存在该教师职称则将该教师加入该组
					if (gi[g].title[lv] == 0)
						break;

					i++;
				} while (i < remain_cnt);

				//如果待分配教师容器内所有教师职称在该组内都存在，则取第一个教师
				if (i >= remain_cnt)
					i = 0;

				//将教师加入分组并刷新组内教师数量
				gi[g].group.push_back(ban_vec[i]);
				gi[g].teacher_cnt = gi[g].group.size();

				//删除待分配教师容器中的教师ID
				ban_vec.erase(std::begin(ban_vec) + i);

				remain_cnt--;
			}
		}
	}

	printf("2、 加入外援教师得出的分组如下：\n");
	printf("\n");
	printGroup();

	cout << "------------------------------------------" << endl;

	for (int i = 1; i <= group_count; i++)
	{
		//研究方向标号是1 - 11
		for (int r = 1; r <= 11; r++)
		{
			//如果该组某个领域没有教师，就查找一下其它组是否有多个该研究方向的教师
			if (gi[i].research[r] == 0)
			{
				for (int it1 = 0; it1 < gi[i].teacher_cnt; it1++)
				{
					Teacher iT1 = t[gi[i].group[it1]];

					for (int j = 1; j <= group_count; j++)
					{
						if (i == j)
							continue;

						//存在多个该研究方向的教师
						//找一下是哪个教师，并且判断一下是否带的学生数量相同，相同则交换一下老师
						if (gi[j].research[r] > 1)
						{
							//遍历该组教师
							for (int it2 = 0; it2 < gi[j].teacher_cnt; it2++)
							{
								Teacher iT2 = t[gi[j].group[it2]];

								bool findit = false;
								for (int r2 = 0; r2 < iT2.research_cnt; r2++)
								{
									if (iT2.research[r2] == r && (iT1.student_cnt == iT2.student_cnt))
									{
										findit = true;
										break;
									}
								}

								//找到了
								if (findit)
								{
									gi[i].research[r]++;
									gi[j].research[r]--;

									//查找两个小组容器中的教师ID并进行交换
									int index1 = 0, index2 = 0;

									vector<int>::iterator iter1 = find(gi[i].group.begin(), gi[i].group.end(), iT1.index);
									if (iter1 != gi[i].group.end())
										index1 = *iter1;

									vector<int>::iterator iter2 = find(gi[j].group.begin(), gi[j].group.end(), iT2.index);
									if (iter2 != gi[j].group.end())
										index2 = *iter2;

									if (index1 && index2)
									{
										*iter1 = index2;
										*iter2 = index1;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("3、 尝试优化各组教师研究领域后得出的分组如下：\n");
	printf("\n");
	printGroup();
}