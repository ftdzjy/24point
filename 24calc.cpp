/*
@desc:
 招银网络20180925软开C/C++编程题第三题
	经典的24点游戏，从扑克牌中挑出1-9的所有牌，然后拿到其中4张牌，可以任意将这四个牌进行
	/*+-组合，若能组合得到24点则赢了。
	输入描述：4张牌的值，例如，
	1 2 3 4
	输出描述：能够得到24点为true，否则false，如上例，（1*2*3*4）
	true
 思路：
	将所有可能组合的结果算出来，采用递归，过程
	第i个数与剩余数的组合结果进行/*+-的组合，并存入结果数组。
	例如，求(1234)的组合结果，即1(/*-+)(234),2(/*-+)(134),3(/*-+)(214),4(/*-+)(231)，这里假设先求1(/*-+)(234)，则先求(234)
			(234)进行的是2(/*-+)(34),3(/*-+)(24),4(/*-+)(23)，因此分别求出选中数为2,3,4时剩余数组合结果，然后进行/*-+
			求(34),(24),(23)，。。。以此类推；
	因此过程是，先从输入数组选中一个，然后将剩余的进行求组合结果，然后将选中数与该结果(/*+-)即可
				若输入数组只有一个元素，直接返回该元素值即可。
@update:
 date			author			desc
 2018/09/25		zjy				done
*/
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

#define __DEBUG__


#ifdef __DEBUG__
int calc(vector<char> nums, vector<float> &result, vector<string> &pro){
#else
int calc(vector<char> nums, vector<float> &result){
#endif
	int i,j,k;
	float tmpf;
#ifdef __DEBUG__
	char cstr[108] = {0};
	string tmpstr;
#endif

	if(nums.size() == 1){
		result.push_back(nums[0]);
#ifdef __DEBUG__
		sprintf(cstr,"%d",nums[0]);
		pro.push_back(cstr);
#endif
		return 0;
	}

	for(i = 0; i < nums.size(); i++){
		vector<char> tmps;
		vector<float> tmpre;
#ifdef __DEBUG__
		vector<string> tmpstrs;
#endif
		for(j = 0; j < nums.size(); j++){
			if(i != j)
				tmps.push_back(nums[j]);
		}
#ifdef __DEBUG__
		calc(tmps,tmpre,tmpstrs);
#else
		calc(tmps,tmpre);
#endif
		for(j = 0; j < 4; j++){			
			switch(j){
			case 0:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] + tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d + ",nums[i]);
					tmpstr = cstr + tmpstrs[k];
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 1:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] - tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d - ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 2:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] * tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d * ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 3:
				for(k = 0;k < tmpre.size();k++){
					if(tmpre[k] == 0)
						continue;
					tmpf = nums[i] / tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d / ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			}
		}
	}
	return 0;
}

int main(){
	vector<char> nums;
	vector<float> result;
	vector<string> pro;
	int flag = 0;

	nums.push_back(1);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(4);
#ifdef __DEBUG__
	calc(nums,result,pro);
#else
	calc(nums,result);
#endif

	for(int i = 0;i < result.size(); i++){
		if(fabs(result[i]- 24) < 0.1 && result[i] > 0){
			flag = 1;
#ifdef __DEBUG__
			cout<<"true:"<<result[i]<<" "<<pro[i]<<endl;
#else
			cout<<"true"<<endl;
			break;
#endif
		}
	}
	if(i == result.size() && flag == 0)
		cout<<"false"<<endl;

	return 0;
}