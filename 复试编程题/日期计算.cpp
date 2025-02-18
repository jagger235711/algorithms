//
// Created by jagger on 25-2-18.
//
/***
 *
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。返回该日期是当年的第几天。



示例 1：

输入：date = "2019-01-09"
输出：9
解释：给定日期是2019年的第九天。
示例 2：

输入：date = "2019-02-10"
输出：41


提示：

date.length == 10
date[4] == date[7] == '-'，其他的 date[i] 都是数字
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日
 *
 */

//注意闰年的判定 闰年的判定方法为：year是400的倍数，或者year是4的倍数且不是100的倍数。
#include<iostream>
using namespace std;

int main()
{
    string date;
    int listOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    int count = 0;
    cin >> date;

    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));

    for (int i = 0; i < month - 1; i++)
    {
        count += listOfMonth[i];
    }
    if ((month > 2) && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))count++;
    cout << count + day << endl;

    return 0;
}
